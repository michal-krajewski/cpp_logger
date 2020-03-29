//
// Created by Atreses on 29/03/2020.
//

#include "BookService.h"

BookService::BookService() {
    bookStorage = Storage<Book*>();
}

Book *BookService::getBook(int id) {
    return this->bookStorage.get(id);
}

void BookService::deleteBook(int id) {
    this->bookStorage.deleteByIndex(id);
}

int BookService::addBook(Book *book) {
    return this->bookStorage.add(book);
}

void BookService::updateBook(int id, Book *book) {
    this->getBook(id)->setTitle(book->getTitle());
    this->getBook(id)->setAuthor(book->getAuthor());
}
