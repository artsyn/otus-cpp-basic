cmake_minimum_required(VERSION 3.12)

project(2_guess_number.cpp)

add_executable(guess_number
    2_guess_number.cpp
)

set_target_properties(guess_number PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)