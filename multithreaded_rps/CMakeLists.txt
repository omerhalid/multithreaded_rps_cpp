cmake_minimum_required(VERSION 3.10)
project(MultithreadedRPS)

enable_testing()

# Set the runtime library to Multi-threaded Debug DLL (/MDd) for all targets in debug mode
if (MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/MDd")
    set(CMAKE_C_FLAGS_DEBUG "/MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "/MD")
    set(CMAKE_C_FLAGS_RELEASE "/MD")
endif()

add_subdirectory(server)
add_subdirectory(client)
add_subdirectory(unit_test)

if(WIN32)
    add_definitions(-DWIN32_LEAN_AND_MEAN)
endif()
