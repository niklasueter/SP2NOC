cmake_minimum_required(VERSION 3.5.1)
project(sp2noc)

set(SYSTEMC_PATH /usr/local/systemc-2.3.3)
set(VERILATOR_PATH /usr/share/verilator)

include_directories(${SYSTEMC_PATH}/include ${VERILATOR_PATH}/include)

find_library(systemc systemc ${SYSTEMC_PATH}/lib-linux64)
link_directories(${SYSTEMC_PATH}/lib-linux64)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(sp2noc main.cpp)

target_link_libraries(sp2noc systemc)
