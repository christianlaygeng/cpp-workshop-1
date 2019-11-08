#include "catch.hpp"

#include <my_vector.hpp>

using namespace acmtse;

TEST_CASE("Size constructor returns uninitialized vector") {
    my_vector<int> vec(100);
    REQUIRE(vec.size() == 0);
    REQUIRE(vec.capacity() == 100);
}

TEST_CASE("Copy constructor copies uninitialized vector") {
    my_vector<int> vec(100);
    my_vector<int> cpy(vec);
    REQUIRE(cpy.size() == 0);
    REQUIRE(cpy.capacity() == 100);
}
