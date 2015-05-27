#ifndef PERSIST_H_
#define PERSIST_H_
#include <sqlite3.h>
#include <createqu.h>
#include <property.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global
sqlite3 *db;

int creatBookTable(char *zErrMsg);
int countTableValues();

#endif /* PERSIST_H_ */

//static int callback(void *NotUsed, int argc, char **argv, char **azColName);
