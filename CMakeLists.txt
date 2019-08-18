cmake_minimum_required(VERSION 3.14)
project(OS_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(core/include)

add_executable(OS_Project
        core/include/Block.h
        core/include/Definitionsh.h
        core/include/Disk.h
        core/src/Block.cpp
        core/src/Disk.cpp
        core/src/MBR.cpp
        core/include/MBR.h core/include/Partition.h core/src/Partition.cpp core/include/Filesystem.h)
