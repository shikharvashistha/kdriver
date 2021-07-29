cmake_minimum_required(VERSION 3.20.0)

project (shell)

add_executable(a main.c) 

enable_testing()

add_test(test a) 