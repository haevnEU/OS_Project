cmake_minimum_required(VERSION 3.14)
project(OS_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(core)
include_directories(core_old/include)
include_directories(ui)
include_directories(ui/pages)

add_executable(OS_Project
        core/api.cpp
        core/api.h
        core/block.cpp
        core/block.h
        core/disk.cpp
        core/disk.h
        #core/inode.cpp
        #core/inode.h
        #core/inodetable.cpp
        #core/inodetable.h
        core/main.cpp
        core/masterbootrecord.cpp
        core/masterbootrecord.h
        core/partition.cpp
        core/partition.h
        core/FAT.cpp
        core/FAT.h
        core/FileSystem.cpp
        core/FileSystem.h core/File.cpp core/File.h)
