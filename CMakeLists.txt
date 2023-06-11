cmake_minimum_required(VERSION 3.0)

project(MOS6502 CXX)

include_directories(${CMAKE_SOURCE_DIR}/include) #set include dir for projects

set(SRCS_cpu src/cpu/cpu.cpp
        src/cpu/addressing_mode.cpp
        src/cpu/flag.cpp
        src/cpu/interruptions.cpp
        src/cpu/memory.cpp
        src/cpu/opcode_arithmetic.cpp
        src/cpu/opcode_branching.cpp
        src/cpu/opcode_cmp.cpp
        src/cpu/opcode_ctrl.cpp
        src/cpu/opcode_flag.cpp
        src/cpu/opcode_shift.cpp
        src/cpu/opcode_stack.cpp
        src/cpu/opcode_transfer.cpp
        src/cpu/stack.cpp)  #all sources file for CPU mos6502



add_library(mos6502_cpu ${SRCS_cpu})

#add_compile_definitions(DEBUG_INFO)
#add_executable(<name> srcs)
#target_link_libraries(<name> mos6502_cpu)
