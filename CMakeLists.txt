cmake_minimum_required(VERSION 3.16)
project(ray_tracing_algorithm C)

set(CMAKE_C_STANDARD 99)

include_directories(include)
add_executable(ray_tracing_algorithm src/main.c src/ray.c)
target_link_libraries(ray_tracing_algorithm m)