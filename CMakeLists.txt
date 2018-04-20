cmake_minimum_required(VERSION 3.9)
project(fillit)

set(CMAKE_CXX_STANDARD 11)

add_executable(fillit
        fil_valid.txt
        fillit.h
        ft_bzero.c
        ft_putchar.c
        ft_putstr.c
        ft_strcpy.c
        ft_strlen.c
        security.c
        sOperations.c
        traktor.c backtrack.c)
