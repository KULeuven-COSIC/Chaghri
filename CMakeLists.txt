cmake_minimum_required(VERSION 3.10.2 FATAL_ERROR)
## Use -std=c++14 as default.
set(CMAKE_CXX_STANDARD 14)
## Disable C++ extensions
set(CMAKE_CXX_EXTENSIONS OFF)
## Require full C++ standard
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(helib 1.1.0 EXACT REQUIRED)

add_executable(chaghri chaghri.cpp Test_CHAGHRI.cpp simpleCHAGHRI.cpp)
target_link_libraries(chaghri helib)









