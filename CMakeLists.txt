cmake_minimum_required(VERSION 3.21.3)

project(teampointscalc CXX)

enable_testing()

add_executable(teampointscalc
    src/pointSystem.cpp
    src/pointSystem.h
    src/team.cpp
    src/team.h
    src/teamPointsCalc.cpp
)

target_compile_features(teampointscalc PRIVATE cxx_std_11)

# tests target
add_executable(tests src/tests/team_tests.cpp)
target_compile_features(tests PRIVATE cxx_std_11)

find_package(GTest REQUIRED)

target_link_libraries(tests GTest::gtest)
include(GoogleTest)
gtest_add_tests(TARGET tests)