cmake_minimum_required(VERSION 3.10)

set(PROJECT "Schema2Json")

project(${PROJECT})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Arrow REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(_SOURCES "test/SchemaJsonConv_Test.cpp" "src/SchemaJsonConv.cpp")
set(_HEADERS "src/SchemaJsonConv.h")
add_executable(${PROJECT} ${_SOURCES} ${_HEADERS})

target_link_libraries(${PROJECT} arrow_shared ${GTEST_LIBRARIES} pthread)
