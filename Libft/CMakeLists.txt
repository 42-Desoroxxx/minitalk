cmake_minimum_required(VERSION 3.22.1)
project(Libft C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto")

set(SOURCE_FILES
	src/ft_atoi.c
	src/ft_bzero.c
	src/ft_calloc.c
	src/ft_calloc.c
	src/ft_isalnum.c
	src/ft_isalpha.c
	src/ft_isascii.c
	src/ft_isdigit.c
	src/ft_isprint.c
	src/ft_itoa.c
	src/ft_lstadd_back.c
	src/ft_lstadd_front.c
	src/ft_lstclear.c
	src/ft_lstdelone.c
	src/ft_lstiter.c
	src/ft_lstlast.c
	src/ft_lstmap.c
	src/ft_lstnew.c
	src/ft_lstsize.c
	src/ft_memchr.c
	src/ft_memcmp.c
	src/ft_memcpy.c
	src/ft_memmove.c
	src/ft_memset.c
	src/print/ft_print_basic.c
	src/print/ft_print_special.c
	src/print/ft_printf.c
	src/ft_putchar_fd.c
	src/ft_putendl_fd.c
	src/ft_putnbr_fd.c
	src/ft_putstr_fd.c
	src/ft_split.c
	src/ft_strchr.c
	src/ft_strdup.c
	src/ft_striteri.c
	src/ft_strjoin.c
	src/ft_strlcat.c
	src/ft_strlcpy.c
	src/ft_strlen.c
	src/ft_strmapi.c
	src/ft_strncmp.c
	src/ft_strnstr.c
	src/ft_strrchr.c
	src/ft_strtrim.c
	src/ft_substr.c
	src/ft_tolower.c
	src/ft_toupper.c
	src/get_next_line.c
	src/get_next_line_utils.c
	includes/s_memory.h
	src/memory/s_alloc.c
	)

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
