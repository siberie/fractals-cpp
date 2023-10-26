cmake_minimum_required(VERSION 3.26)
project(fractals3)

set(CMAKE_CXX_STANDARD 23)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(vendor/nlohmann_json)

add_executable(fractals3 src/main.cpp vendor/EasyBMP/EasyBMP.cpp)
target_link_libraries(fractals3 PRIVATE nlohmann_json::nlohmann_json)
