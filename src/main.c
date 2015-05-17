#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//project includes
#include <persist.h>


int createDb() {
	int cr;
	cr = sqlite3_open(DB, &db);

	if (cr) {
		fprintf(stderr, "%s %s\n", CNTCREATE, sqlite3_errmsg(db));
		sqlite3_close(db);
		return 0;
	}
	char *zErrMs = 0;
	if(!createBookTable(zErrMs)){
		return 0;
	}

	sqlite3_close(db);
	return 1;
}

int checkDbExist() {
	if ((fopen(DB, "r")) != NULL) {
		return 1;
	}
	return 0;
}

int main(int argc, char **argv) {

	if (!checkDbExist()) {
		char word[3];
		printf("%s\n%s", NODB, NEEDTOCREATE);
		fgets(word, 2, stdin);
		if ((toupper(word[0]) == YES) && (createDb())) {
			printf("%s %s\n", DB, CREATEDSUCC);
			printf("%s %s\n", "All tables", CREATEDSUCC);
		} else {
			exit(0);
		}
	} else {

	}

	//char *zErrMsg = 0;
	/*
	 int rc;
	 if (argc != 3) {
	 fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
	 return (1);
	 }
	 rc = sqlite3_open(argv[1], &db);
	 if (rc) {
	 fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	 sqlite3_close(db);
	 return (1);
	 }
	 rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
	 if (rc != SQLITE_OK) {
	 fprintf(stderr, "SQL error: %s\n", zErrMsg);
	 sqlite3_free(zErrMsg);
	 }
	 sqlite3_close(db);*/
	return 0;
}
