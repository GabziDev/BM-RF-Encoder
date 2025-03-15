cmake_minimum_required(VERSION 3.11)
project(BM_RF_Encoder C)

set(CMAKE_C_STANDARD 11)

add_executable(BM_RF_Encoder src/main.c
        src/include/morse.h
)
