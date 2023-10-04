# CMakeList.txt : CMake project for 30-3-queries-with-arguments, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

project ("30-3-queries-with-arguments")

# Add source to this project's executable.
add_executable (30-3-queries-with-arguments "main.cpp")

target_link_libraries(30-3-queries-with-arguments PRIVATE cpr::cpr)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 30-3-queries-with-arguments PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
