#include <persist.h>
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int createBookTable(char *zErrMsg) {
	int bc, boc, st, uc, pc;
	bc = sqlite3_exec(db, BOOK_Qu, callback, 0, &zErrMsg);
	if (bc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return 0;
	}
	boc = sqlite3_exec(db, BORROW_QU, callback, 0, &zErrMsg);
	if (boc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return 0;
	}

	st = sqlite3_exec(db, STATUS_QU, callback, 0, &zErrMsg);
	if (st != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return 0;
	}

	uc = sqlite3_exec(db, USERS_QU, callback, 0, &zErrMsg);
	if (uc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return 0;
	}

	pc = sqlite3_exec(db, PLACE_QU, callback, 0, &zErrMsg);
	if (pc != SQLITE_OK) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		return 0;
	}


	return 1;
}
