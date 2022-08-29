cmake_minimum_required(VERSION 3.14)
project(GraphLibrary)

find_package(Git)

set(CMAKE_CXX_STANDARD 17)
include_directories("include")
file(GLOB sources "source/**/*.cpp")
add_library(GraphLibrary ${sources})

add_custom_target(GitTraceAdd
        COMMAND "${GIT_EXECUTABLE}" add -A . --ignore-errors
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_custom_target(GitTraceCommit
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify -m "compile"
        --author="tracer-ps3-2021 <tracer-ps3-2021@nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")
add_dependencies(GitTraceCommit GitTraceAdd) # Avoid data race
add_dependencies(GraphLibrary GitTraceCommit)
add_custom_command(TARGET GraphLibrary POST_BUILD
        COMMAND "${GIT_EXECUTABLE}"
        commit -q --allow-empty --no-verify -m "compile succeed"
        --author="tracer-ps3-2021 <tracer-ps3-2021@nju.edu.cn>"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")

# Your custom tests below
add_executable(Test01 tests/01-hello-world.cpp)
target_link_libraries(Test01 GraphLibrary)
