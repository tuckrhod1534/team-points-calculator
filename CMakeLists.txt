cmake_minimum_required(VERSION 3.21.3)

project(teampointscalc CXX)

add_executable(teampointscalc
    src/pointSystem.cpp
    src/pointSystem.h
    src/team.cpp
    src/team.h
    src/teamPointsCalc.cpp
    src/teamPointsCalc.h
)
