cmake_minimum_required(VERSION 3.10.2)
project(proginC C)

set(CMAKE_C_STANDARD 11)

add_executable(proginC
        ITS/Matrices/dynamics.h
        ITS/Matrices/printMatrix.c
        ITS/Matrices/multiplication.c
        ITS/Matrices/diagonals.c
        ITS/Matrices/transpose.c
        ITS/Matrices/scalar.c
		

#        ITS/Matrices/src/q_mul.c
        ITS/Matrices/src/q8.c

)
