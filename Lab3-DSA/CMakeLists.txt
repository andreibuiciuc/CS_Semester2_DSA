cmake_minimum_required(VERSION 3.17)
project(Lab3_DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab3_DSA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        IndexedList.cpp
        IndexedList.h
        ListIterator.cpp
        ListIterator.h
        ShortTest.cpp
        ShortTest.h)
