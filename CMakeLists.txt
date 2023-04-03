cmake_minimum_required(VERSION 3.10)
project(ContainersTests)

set(GTEST_INCLUDE_DIR "C:/Users/5003020/OneDrive - Envista/_MyPCFiles/Desktop/OTUS/vcpkg-master/vcpkg-master/installed/x64-windows/include")
set(GTEST_MAIN_LIBRARY "C:/Users/5003020/OneDrive - Envista/_MyPCFiles/Desktop/OTUS/vcpkg-master/vcpkg-master/installed/x64-windows/lib/manual-link/gtest_main.lib")
set(GTEST_LIBRARY "C:/Users/5003020/OneDrive - Envista/_MyPCFiles/Desktop/OTUS/vcpkg-master/vcpkg-master/installed/x64-windows/lib/gtest.lib")

include_directories(${GTEST_INCLUDE_DIR})

enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

add_executable(ContainersTests
    tests_main.cpp
    sequential_container.hpp
    sequential_container.cpp
    linked_container.hpp
    linked_container.cpp
)

target_link_libraries(ContainersTests PRIVATE ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

add_test(NAME ContainersTests COMMAND ContainersTests WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})


include(CTest)
include(GoogleTest)
gtest_add_tests(TARGET ContainersTests)
