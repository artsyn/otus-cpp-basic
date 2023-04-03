cmake_minimum_required(VERSION 3.10)

project(p_words CXX)

add_executable(p_words
    topk_words.cpp

)

target_include_directories(p_words PRIVATE include)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR
    CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(p_words PRIVATE 
        -g
        -Wall
        -Wextra
        -Werror
        -pedantic
    )
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(p_words PRIVATE
        /EHsc
        /W4
        /WX
    )
endif()

target_compile_features(p_words PUBLIC cxx_std_17)
