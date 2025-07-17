cmake_minimum_required(VERSION 3.20)

# ▼ vcpkg ツールチェインを project() より前に必ず設定
set(CMAKE_TOOLCHAIN_FILE
    "${CMAKE_CURRENT_LIST_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "")

project(MyGame LANGUAGES CXX)

add_executable(MyGame src/main.cpp)
target_link_libraries(MyGame PRIVATE EnTT::EnTT)

# オプション：警告を厳しく／C++20 指定
target_compile_features(MyGame PRIVATE cxx_std_20)
if(MSVC)
    target_compile_options(MyGame PRIVATE /W4 /permissive-)
else()
    target_compile_options(MyGame PRIVATE -Wall -Wextra -Wpedantic)
endif()
