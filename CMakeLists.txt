cmake_minimum_required(VERSION 3.15)
project(logs)

set(CMAKE_CXX_STANDARD 14)

set(libcurl_INCLUDE_DIR "/usr/local/opt/curl/include")
link_directories(${libcurl_INCLUDE_DIR})

add_executable(logs SimpleExample.cpp logger/Logger.cpp logger/Logger.h logger/LoggerConfigurer.cpp logger/LoggerConfigurer.h logger/message/ILogMessage.h logger/message/RawLogMessage.cpp logger/message/RawLogMessage.h logger/distribution/ILogDistributor.h logger/distribution/ConsoleLogDistributor.cpp logger/distribution/ConsoleLogDistributor.h logger/distribution/FileLogDistributor.cpp logger/distribution/FileLogDistributor.h logger/distribution/HttpLogDistributor.cpp logger/distribution/HttpLogDistributor.h logger/util/DateTime.cpp logger/util/DateTime.h logger/util/StringConverter.cpp logger/util/StringConverter.h logger/message/DateTimeLogMessage.cpp logger/message/DateTimeLogMessage.h logger/util/List.h logger/config/Config.cpp logger/config/Config.h logger/config/Property.cpp logger/config/Property.h bookStorageExample/book/Storage.h bookStorageExample/book/Book.cpp bookStorageExample/book/Book.h bookStorageExample/book/BookService.cpp bookStorageExample/book/BookService.h bookStorageExample/BookConfig.cpp bookStorageExample/BookConfig.h bookStorageExample/BookMain.cpp)
target_link_libraries(logs libcurl.a)