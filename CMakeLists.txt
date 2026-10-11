cmake_minimum_required(VERSION 3.15)

# Navnet på dit projekt
project(Indkoebsassistent CXX)

# Bed om C++20 (da du brugte /std:c++20 i din tidligere kommando)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find alle .cpp filer i din core mappe
# Note: I større projekter er det bedst at liste dem manuelt, men GLOB er nemmest her
file(GLOB SOURCES "core/*.cpp")

# Opret en eksekverbar fil (dit testprogram) ud fra filerne
add_executable(test_program ${SOURCES})

# Fortæl compileren, hvor den skal lede efter dine .h (header) filer
target_include_directories(test_program PRIVATE core)