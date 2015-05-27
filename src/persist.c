#include <persist.h>

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i < argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		printf("%s", argv[i] ? argv[i] : "NULL");
	}
	return 0;
}

void errorHandler(char *mess) {
	fprintf(stderr, "%s: %s\n", SQLERROR, mess);
	sqlite3_free(mess);
}

int countTableValues() {
	char *zErrMsg = 0;
	char countQuery[30];
	int cq, i;

	const char *mnu_array[] = { SHOW_BOOK_COUNT, SHOW_PLACE_COUNT,
			SHOW_USER_COUNT, SHOW_STATUS_COUNT, SHOW_BORROW_COUNT };
	const char *count_array[] = { TBOOK, TPLACE, TUSERS, TSTATUS, TBORROW };
	for (i = 0; i < NUMOFTABLES; i++) {

		printf("%s[",mnu_array[i]);
		strcpy(countQuery, COUNT_QU);
		strcat(countQuery, count_array[i]);

		cq = sqlite3_exec(db, countQuery, callback, 0, &zErrMsg);

		if (cq != SQLITE_OK) {
			errorHandler(zErrMsg);
			return 0;
		}
		printf("]\n");
	}
	return 0;
}

int createBookTable(char *zErrMsg) {
	int bc, i;

	const char *Query_array[] = { BOOK_QU, BORROW_QU, STATUS_QU, USERS_QU,
	PLACE_QU };
	for (i = 0; i < NUMOFTABLES; i++) {
		bc = sqlite3_exec(db, Query_array[i], NULL, 0, &zErrMsg);
		if (bc != SQLITE_OK) {
			errorHandler(zErrMsg);
			return 0;
		}
	}
	return 1;
}
