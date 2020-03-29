//
// Created by Atreses on 29/03/2020.
//

#ifndef LOGS_BOOKSERVICE_H
#define LOGS_BOOKSERVICE_H


#include "Storage.h"
#include "Book.h"

class BookService {
public:
    BookService();
    Book* getBook(int id);
    void deleteBook(int id);
    int addBook(Book *book);
    void updateBook(int id, Book *book);

private:
    Storage<Book*> bookStorage;
};


#endif //LOGS_BOOKSERVICE_H
