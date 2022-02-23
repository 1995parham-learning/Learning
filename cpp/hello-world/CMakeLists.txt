cmake_minimum_required (VERSION 3.0.0)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

project (HELLO-WORLD)

add_executable (a.out main.cpp)

target_compile_features (a.out PRIVATE cxx_std_20)

target_link_libraries (a.out fmt)
