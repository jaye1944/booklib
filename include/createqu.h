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


#endif /* CREATEQU_H_ */
