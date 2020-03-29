//
// Created by Atreses on 29/03/2020.
//

#ifndef LOGS_BOOK_H
#define LOGS_BOOK_H

#include <iostream>

using namespace std;

class Book {
public:
    Book(string title, string author);
    Book(Book &other);
    ~Book();
    string getTitle();
    string getAuthor();
    void setTitle(string title);
    void setAuthor(string author);

private:
    string title;
    string author;
};


#endif //LOGS_BOOK_H
