cmake_minimum_required(VERSION 3.15)
project(logs)

set(CMAKE_CXX_STANDARD 14)

add_executable(logs main.cpp Logger.cpp Logger.h LoggerFactory.cpp LoggerFactory.h)