/* TODO: change all "struct Address"/etc to "Address"/etc using typedef */
/* we can make this MUCH more efficient */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* preprocessor constants */
#define MAX_DATA 512
#define MAX_ROWS 100

/* define our structs and their elements */
typedef struct Address {

	/* elements of struct Address */
	int id;
	int set;
	int data;
	char name[MAX_DATA];
	char email[MAX_DATA];
} Address;

typedef struct Database {

	/* element of struct Database */
	int rowcount;
	Address rows[MAX_ROWS];
} Database;

typedef struct Connection {

	/* elements of struct Connection */
	FILE *file;
	Database *db;
} Connection;

/* prototypes */
void die(Connection *conn, const char *message);
void Address_print(Address *addr);
void Database_load(Connection *conn);
Connection *Database_open(const char *filename, char mode);
void Database_close(Connection *conn);
void Database_write(Connection *conn);
void Database_create(Connection *conn);
void Database_set(Connection *conn, int id, const char *name, const char *email);
void Database_get(Connection *conn, int id);
void Database_delete(Connection *conn, int id);

void die(Connection *conn, const char *message) {

	/* check if our error number is set */
	if(errno) {

		/* print the error message to STDERR */
		perror(message);
	} else {

		/* print the error for the user */
		printf("ERROR: %s\n", message);
	}

	/* if it exists */
	if(conn) {

		/* close the Database */
		Database_close(conn);
	}

	/* we're all done here, but something went wrong */
	exit(1);
}

void Address_print(Address *addr) {

	/* print some data from our Address */
	printf("%d, %s, %s\n", addr->id, addr->name, addr->email);
}

void Database_load(Connection *conn) {

	/* read in some binary from our connection 
	 * read in our database as a binary stream using fread,
	 * reads in 1 struct Database from conn->file into conn->db
	/*/
	int rc = fread(conn->db, sizeof(Database), 1, conn->file);

	/* if we don't get back a number of items printed
	 * or get a shotr item count/zero, print the error
	/*/
	if(!rc) die(conn, "Failed to load database.");
}

Connection *Database_open(const char *filename, char mode) {

	/* initialize a new Connection and allocate it in memory */
	Connection *conn = malloc(sizeof(Connection));

	/* make sure we don't get a null pointer back */
	if(!conn) die(conn, "Memory Error");

	/* allocate the database in memory */
	conn->db = malloc(sizeof(Database));

	/* make sure we don't get a null pointer back */
	if(!conn->db) die(conn, "Memory Error");

	/* check our mode value */
	if(mode == 'c') {

		/* open our file with write options */
		conn->file = fopen(filename, "w");
	} else {

		/* open our file with read options */
		conn->file = fopen(filename, "r+");

		/* make sure we get a file descriptor back */
		if(conn->file) {

			/* call our function Database_load on our Connection */
			Database_load(conn);
		}
	}

	/* otherwise it's an error */
	if(!conn->file) die(conn, "Failed to open the file");

	/* we're done here */
	return conn;
}

void Database_close(Connection *conn) {

	/* if the Connection exists, close it and deallocate it */
	if(conn) {

		/* if it exists in our structure still, close/dealloc it */
		if(conn->file) fclose(conn->file);
		if(conn->db) free(conn->db);

		/* dealloc the database */
		free(conn);
	}
	/* we're done here */
}

void Database_write(Connection *conn) {

	/* call rewind on our file
	 * rewind resets the file position indicator of the current stream,
	 * pointed to by conn->file, to the beginning of the stream
	/*/
	rewind(conn->file);

	/* write out a binary from our Connection
	 * writes out our Database to our file stream
	 * writes 1 item of size struct Database to stream conn->file,
	 * from conn->db
	/*/
	int rc = fwrite(conn->db, sizeof(Database), 1, conn->file);

	/* if we don't get back a number of items printed,
	 * or a short number count/zero, print the error
	/*/
	if(!rc) die(conn, "Failed to write database.");

	/* flush our file stream and its buffered data */
	rc = fflush(conn->file);

	/* if fflush() returns with EOF, print the error */
	if(rc < 0) die(conn, "Cannot flush database.");

	/* we're done here */
}

void Database_create(Connection *conn) {

	/* iterator declared and initialized here */
	int i = 0;

	for (i = 0; i < MAX_ROWS; i++) {

		/* initialize a new prototype Address */
		Address addr = {.id = i, .set = 0};

		/* assign it to our Connection */
		conn->db->rows[i] = addr;
	}

		/* we're done here */
}

void Database_set(Connection *conn, int id, const char *name, const char *email) {

	/* make a pointer for our database */
	Address *addr = &conn->db->rows[id];

	/* if it's already there, print the error */
	if(addr->set) die(conn, "Already set, delete it first");

	/* otherwise, we can set it here */
	addr->set = 1;

	/* BUG */
	char *res = strncpy(addr->name, name, MAX_DATA);

	/* show bug */
	if(!res) die(conn, "Name copy failed!");

	/* grab the email address now */
	res = strncpy(addr->email, email, MAX_DATA);

	/* if we didn't get an email address, print the error */
	if(!res) die(conn, "Email copy failed!");

	/* we're done here */
}

void Database_get(Connection *conn, int id) {

	/* grab our database */
	Address *addr = &conn->db->rows[id];

	/* if there's an address there */
	if(addr->set) {

		/* print the address */
		Address_print(addr);
	} else {

		/* it's an error */
		die(conn, "ID is not set!");
	}

	/* we're done here */
}

void Database_delete(Connection *conn, int id) {

	/* make a prototype Address */
	Address addr = {.id = id, .set = 0};

	/* put our new address into the database */
	conn->db->rows[id] = addr;

	/* we're done here */
}

void Database_list (Connection *conn) {

	/* iterator declared and initialized here */
	int i = 0;

	/* get a pointer for our database */
	Database *db = conn->db;

	for (i = 0; i < MAX_ROWS; i++) {

		/* grab an address from our database */
		Address *cur = &db->rows[i];

		/* if the address is set */
		if(cur->set) {

			/* print the address */
			Address_print(cur);
		}
	}

	/* we're done here */
}

int main(int argc, char *argv[]) {

	/* if we have too few arguments, print the error */
	if(argc < 3) die(NULL, "USAGE: ex18 <dbfile> <action> [actionparams]");

	/* grab our arguments */
	char *filename = argv[1];
	char action = argv[2][0];

	/* open our database and give it a pointer */
	Connection *conn = Database_open(filename, action);

	/* id declared and initialized here */
	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die(conn, "There's not that many records.");

	/* big ol' switch case for what we want done to this database */
	switch(action) {
		case 'c':

			/* create and write the database */
			Database_create(conn);
			Database_write(conn);
			break;
		case 'g':

			/* get the database */
			if(argc != 4) die(conn, "Need an id to get");

			Database_get(conn, id);
			break;
		case 's':

			/* set the database */
			if(argc != 6) die(conn, "Need id, name, email to set");

			Database_set(conn, id, argv[4], argv[5]);
			Database_write(conn);
			break;
		case 'd':

			/* delete the database */
			if(argc != 4) die(conn, "Need id to delete");

			Database_delete(conn, id);
			Database_write(conn);
			break;
		case 'l':

			/* list out the database */
			Database_list(conn);
			break;
		default:
			die(conn, "Invalid action, only: c=create, g=get, s=set, d=del, l=list");
	}

	/* close the database */
	Database_close(conn);

	/* we're all done here */
	return 0;
}