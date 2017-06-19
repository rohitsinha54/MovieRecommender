cmake_minimum_required(VERSION 3.7)
project(MovieRecommender)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES HashNode.h HashMap.h LongHashKey.h main.cpp File.h Movies.h UserRatings.h)
set(RESOURCE_FILES movies.csv ratings.csv)
add_executable(MovieRecommender ${SOURCE_FILES})