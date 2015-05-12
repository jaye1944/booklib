#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <ctype.h>
#include <property.h>

//Global
sqlite3 *db;

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int createDb() {
	int cr;
	cr = sqlite3_open(DB, &db);
	sqlite3_close(db);
	if (cr) {
		fprintf(stderr, "%s %s\n",CNTCREATE, sqlite3_errmsg(db));
		return 0;
	}
	return 1;
}

int checkDbExist() {
	//FILE *file;
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
		word[0] = toupper(word[0]);
		if ((word[0] == YES)&&(createDb())) {
			printf("%s %s\n", DB, CREATEDSUCC);
		}
	} else {

	}

	//sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
	//printf("%s\n ", DB);
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
	sqlite3_close(db);
	return 0;
}
