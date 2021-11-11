cmake_minimum_required(VERSION 3.10)
project(printf C)

set(CMAKE_C_STANDARD 99)
set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(printf main.c
		src/ft_isdigit.c
		src/ft_isflag.c
		src/ft_isprint_type.c
		src/ft_parser.c
		src/ft_strlen.c
		ft_printf.c
		ft_printf.h
		src/ft_print_char.c
		src/ft_memset.c
		src/ft_putnchar.c
		src/ft_print_percent.c
		src/ft_print_int.c
		src/ft_print_uint.c
		src/ft_print_str.c
		src/ft_print_hex.c
		src/ft_print_ptr.c)
