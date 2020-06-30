cmake_minimum_required(VERSION 3.5.1)
project(sp2noc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VERILATED_PATH ${CMAKE_SOURCE_DIR}/verilog/rtl/obj_dir)
set(SYSTEMC_PATH /usr/local/systemc-2.3.3)
set(VERILATOR_PATH /usr/share/verilator)

# INCLUDES
include_directories(${SYSTEMC_PATH}/include)
include_directories(${VERILATOR_PATH}/include)
include_directories(${VERILATED_PATH})

# LIBRARIES
find_library(systemc systemc ${SYSTEMC_PATH}/lib-linux64)

link_directories(${SYSTEMC_PATH}/lib-linux64)

# VERILATOR
execute_process(COMMAND verilator --sc WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/verilog/rtl/counter.v RESULT_VARIABLE result)
message(STATUS "${result}")

add_executable(sp2noc main.cpp
        ${VERILATED_PATH}/Vcounter.cpp
        ${VERILATED_PATH}/Vfifo.cpp
        ${VERILATOR_PATH}/include/verilated.cpp
        src/Flit.h src/INOCCore.cpp src/INOCCore.h src/NOC.cpp src/NOC.h)

target_link_libraries(sp2noc systemc)
target_link_libraries(sp2noc ${VERILATED_PATH}/Vcounter__ALL.a ${VERILATED_PATH}/Vfifo__ALL.a)