//
// Created by Atreses on 29/03/2020.
//

#include "Book.h"

Book::Book(string title, string author) {
    this->title = title;
    this->author = author;
}

Book::Book(Book &other) {
    this->author = other.author;
    this->title = other.title;
}

string Book::getTitle() {
    return this->title;
}

string Book::getAuthor() {
    return this->author;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthor(string author) {
    this->author = author;
}

Book::~Book() = default;


