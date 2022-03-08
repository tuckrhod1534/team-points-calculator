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
