cmake_minimum_required(VERSION 3.10)
project(hz_lib_external)

find_package(hazelcast-cpp-client CONFIG REQUIRED)

add_executable(hz_lib_external main.cpp)

target_link_libraries(hz_lib_external PRIVATE hazelcast-cpp-client::hazelcast-cpp-client)