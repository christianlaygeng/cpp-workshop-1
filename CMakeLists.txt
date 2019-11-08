cmake_minimum_required (VERSION 3.7)
project(cppworkshop1)

include(cmake/Catch.cmake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB sources 
    "src/*.cpp"
)
file(GLOB test_sources 
    "test/*.cpp"
)

add_library(workshop STATIC ${sources})

add_executable(tests ${test_sources})
target_link_libraries(tests workshop)
target_include_directories(tests PRIVATE "src")

include(CTest)
catch_discover_tests(tests)
