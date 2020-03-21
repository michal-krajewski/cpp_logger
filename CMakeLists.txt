cmake_minimum_required(VERSION 3.15)
project(logs)

set(CMAKE_CXX_STANDARD 14)

add_executable(logs main.cpp logger/Logger.cpp logger/Logger.h logger/LoggerFactory.cpp logger/LoggerFactory.h logger/message/ILogMessage.h logger/message/RawLogMessage.cpp logger/message/RawLogMessage.h)