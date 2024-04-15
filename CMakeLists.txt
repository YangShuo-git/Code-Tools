cmake_minimum_required(VERSION 3.16.3)
project(DesignPatten)

# 可以开启debug模式
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

#dependenicecs
set(THIRD_PARTY_LIBS
        )

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)
