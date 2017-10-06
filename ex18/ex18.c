/* TODO: change all "struct Address"/etc to "Address"/etc using typedef */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/* preprocessor constants */
#define MAX_DATA 512
#define MAX_ROWS 100

/* prototypes */
void die(const char *message);
void Address_print(struct Address *addr);
void Database_load(struct Connection *conn);
struct Connection *Database_open(const char *filename, char mode);
void Database_close(struct Connection *conn);
void Database_write(struct Connection *conn);
void Database_create(struct Connection *conn);
void Database_set(struct Connection *conn, int id, const char *name, const char *email);
void Database_get(struct Connection *conn, int id);
void Database_delete(struct Connection *conn, int id);

/* define our structs and their elements */
struct Address {

	/* elements of struct Address */
	int id;
	int set;
	char name[MAX_DATA];
	char email[MAX_DATA];
};

struct Database {

	/* element of struct Database */
	struct Address rows[MAX_ROWS];
};

struct Connection {

	/* elements of struct Connection */
	File *file;
	struct Database *db;
};

void die(const char *message) {

	/* check if our error number is set */
	if(errno) {

		/* print the error message to STDERR */
		perror(message);
	} else {

		/* print the error for the user */
		printf("ERROR: %s\n", message);
	}

	/* we're done */
	exit(1);
}

void Address_print(struct Address *addr) {

	/* print some data from our Address */
	printf("%d, %s, %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn) {

	/* read in some binary from our connection 
	 * read in our database as a binary stream using fread,
	 * reads in 1 struct Database from conn->file into conn->db
	/*/
	int rc = fread(conn->db, dizeof(struct Database), 1, conn->file);

	/* if we can't load this database, print the error */
	if(rc != 1) die("Failed to load database.");
}

struct Connection *Database_open(const char *filename, char mode) {

	/* initialize a new Connection and allocate it in memory */
	struct Connection *conn = malloc(sizeof(struct Connection));

	/* make sure we don't get a null pointer back */
	if(!conn) die("Memory Error");

	/* allocate the database in memory */
	conn->db = malloc(sizeof(struct Database));

	/* make sure we don't get a null pointer back */
	if(!conn->db) die("Memory Error");

	/* check our mode value */
	if(mode == 'c') {

		/* open our file with write options */
		conn->file = fopen(filename "w");
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
	if(!conn->file) die("Failed to open the file");

	/* we're done here */
	return conn;
}

void Database_close(struct Connection *conn) {

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

void Database_write(struct Connection *conn) {

	/* call rewind on our file
	 * rewind resets the file position indicator of the current stream,
	 * pointed to by conn->file, to the beginning of the stream
	/*/
	rewind(conn->file);
}

int main(int argc, const char *argv[]) {


	/* we're all done here */
	return 0;
}