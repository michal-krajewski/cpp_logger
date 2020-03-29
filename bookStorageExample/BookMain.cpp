//
// Created by Atreses on 29/03/2020.
//

#include "book/BookService.h"
#include "BookConfig.h"
#include "../logger/config/Config.h"
#include "../logger/config/Property.h"
#include "../logger/LoggerConfigurer.h"
#include "../logger/Logger.h"

#include <iostream>

int main() {

    auto config = LoggerConfigurer::config();
    auto console = config->getPropertyFor(CONSOLE_LOGGER);
    console->enable();
    console->addSupport(ERROR);

    auto http = config->getPropertyFor(HTTP_LOGGER);
    http->enable();
    http->addSupport(ERROR);
    http->addSupport(INFO);
    http->setProperty(URL, "http://localhost:3000/test");
    LoggerConfigurer::configureLogger();

    BookConfig::applyLoggerConfig();

    BookService service = BookService();

    int lotrId = service.addBook(new Book("Lord of the rings", "J.R.R. Tolkien"));
    int anotherBookId = service.addBook(new Book("Another book", "Author"));

    std::cout << "Book title: " << service.getBook(anotherBookId)->getTitle();

    return 0;
}