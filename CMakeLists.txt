cmake_minimum_required(VERSION 3.5)
project(Qdatastream CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt6 REQUIRED Core)
  
ADD_EXECUTABLE(write_file write_file.cpp)
TARGET_LINK_LIBRARIES(write_file Qt6::Core)

ADD_EXECUTABLE(read_file read_file.cpp)
TARGET_LINK_LIBRARIES(read_file Qt6::Core)
