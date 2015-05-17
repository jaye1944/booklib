#ifndef CREATEQU_H_
#define CREATEQU_H_
//Book
//| Id | Book_Id | Name | Author | Price | Purchase_Date | *Status | *Place | Have | Comments |
#define BOOK_Qu "CREATE TABLE BOOK("\
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

//Borrow
//| Id | *U_Id | *B_Id | Br_date | Re_date | Du_Date | #5

#define BORROW_QU "CREATE TABLE BORROW("\
"ID INT PRIMARY KEY     NOT NULL,"\
"U_ID			INT,"\
"B_ID			INT,"\
"BR_DATE		DATE,"\
"RT_DATE		DATE,"\
"DU_DATE		DATE);"

//*Status
//| Id | Type |
#define STATUS_QU "CREATE TABLE STATUS("\
"ID INT PRIMARY KEY     NOT NULL,"\
"Type			CHAR(10));"

//*Place
//| Id | Name | Address |
#define PLACE_QU "CREATE TABLE PLACE("\
"ID INT PRIMARY KEY     NOT NULL,"\
"NAME			CHAR(50),"\
"ADDRESS		CHAR(100));"

//*Users
//| Id | Name | Role |
#define USERS_QU "CREATE TABLE USERS("\
"ID INT PRIMARY KEY     NOT NULL,"\
"NAME			CHAR(50),"\
"ROLE			INT);"

#endif /* CREATEQU_H_ */
