cmake_minimum_required(VERSION 3.14)
project(OS_Project)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES Main.cpp)

include_directories(core)
include_directories(core/diskSimulation)

add_executable(OS_Project
        core/diskSimulation/Block.cpp
        core/diskSimulation/Block.h
        core/diskSimulation/Disk.cpp
        core/diskSimulation/Disk.h
        core/diskSimulation/FormatType.h
        core/diskSimulation/MBR.cpp
        core/diskSimulation/MBR.h
        core/diskSimulation/Partition.cpp
        core/diskSimulation/Partition.h
        core/main.cpp
        )
