#ifndef CREATEQU_H_
#define CREATEQU_H_
#define NUMOFTABLES 5
//Book
//| Id | Book_Id | Name | Author | Price | Purchase_Date | *Status | *Place | Have | Comments |
#define TBOOK "BOOK"
#define BOOK_QU "CREATE TABLE BOOK("\
"ID INT PRIMARY KEY     NOT NULL,"\
"BOOK_ID        CHAR(10),"\
"NAME           CHAR(100),"\
"AUTHOR         CHAR(50),"\
"PRICE          REAL,"\
"PURCHASE_DA    DATE,"\
"STATUS         INT,"\
"PLACE          INT,"\
"HAVE           INT,"\
"COMMENT        TEXT);"

typedef struct Books {
	int book_id;
	char book_given_id[10];
	char name[100];
	char author[50];
	double price;
	char date[25];
	int status_id;
	int place_id;
	int have;
	char comment[200];
} Book;

//Borrow
//| Id | *U_Id | *B_Id | Br_date | Re_date | Du_Date | #6
#define TBORROW "BORROW"
#define BORROW_QU "CREATE TABLE BORROW("\
"ID INT PRIMARY KEY     NOT NULL,"\
"USER_ID			INT,"\
"BOOK_ID			INT,"\
"BORROW_DATE		DATE,"\
"RETURN_DATE		DATE,"\
"DUE_DATE		DATE);"

typedef struct Borrows {
	int borrow_id;
	int user_id;
	int book_id;
	char borrow_date[25];
	char return_date[25];
	char due_date[25];
} Borrow;

//*Status
//| Id | Type |
#define TSTATUS "STATUS"
#define STATUS_QU "CREATE TABLE STATUS("\
"ID INT PRIMARY KEY     NOT NULL,"\
"Type			CHAR(10));"

typedef struct Statuss {
	int status_id;
	char type[10];
} Status;

//*Place
//| Id | Name | Address |
#define TPLACE "PLACE"
#define PLACE_QU "CREATE TABLE PLACE("\
"ID INT PRIMARY KEY     NOT NULL,"\
"NAME			CHAR(50),"\
"ADDRESS		CHAR(100));"

typedef struct Places {
	int place_id;
	char name[50];
	char address[100];
} Place;

//SELECT name FROM sqlite_master WHERE type='table';
//*Users
//| Id | Name | Role |
#define TUSERS "USERS"
#define USERS_QU "CREATE TABLE USERS("\
"ID INT PRIMARY KEY     NOT NULL,"\
"NAME			CHAR(50),"\
"ROLE			INT);"

typedef struct Users {
	int user_id;
	char name[50];
	int role;
} User;

#define COUNT_QU "SELECT COUNT(ID) FROM "

#endif /* CREATEQU_H_ */
