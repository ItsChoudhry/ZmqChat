cmake_minimum_required(VERSION 3.3)
project(Server)

FIND_FILE(ZMQLIB libzmq.so /usr/local/lib)
IF(NOT ZMQLIB)
    MESSAGE(SEND_ERROR "Ah.. Cannot find library libzmq.so.")
ENDIF(NOT ZMQLIB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES main.cpp)

add_executable(Server ${SOURCE_FILES})

# libzmq.so
TARGET_LINK_LIBRARIES( Server ${ZMQLIB})
