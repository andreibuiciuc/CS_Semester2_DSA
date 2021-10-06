cmake_minimum_required(VERSION 3.17)
project(Lab4_DSA)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lab4_DSA
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)
