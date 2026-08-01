cmake_minimum_required(VERSION 3.20)

project(RenderingEngine)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(math_lib
    src/math/quad.cpp
    src/math/vec3.cpp
    src/math/point.cpp
    src/math/operations.cpp
)

target_include_directories(math_lib PUBLIC src)

add_library(rendering_lib
    src/rendering/colors.cpp
    src/rendering/canvas.cpp
)

target_include_directories(rendering_lib PUBLIC src)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE math_lib rendering_lib)

add_executable(tests
    tests/main.cpp
    tests/test_quad.cpp
    tests/test_colors.cpp
    tests/test_canvas.cpp
)

target_link_libraries(tests PRIVATE math_lib rendering_lib)
target_include_directories(tests PRIVATE external)
