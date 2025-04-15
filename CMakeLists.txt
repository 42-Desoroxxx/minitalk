cmake_minimum_required(VERSION 3.22.1)
project(minitalk C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -O3 -ffast-math -march=native -flto")

add_subdirectory(Libft)

add_executable(server src/server.c)
target_include_directories(server PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_link_libraries(server PRIVATE Libft)

add_executable(client src/client.c)
target_include_directories(client PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/includes)
target_link_libraries(client PRIVATE Libft)
