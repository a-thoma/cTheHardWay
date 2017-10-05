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