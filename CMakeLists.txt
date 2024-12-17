cmake_minimum_required(VERSION 3.29)
project(Axe_Game)

set(CMAKE_CXX_STANDARD 20)

# raylib 경로 설정
include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(Axe_Game main.cpp)

# raylib 링크
target_link_libraries(Axe_Game raylib)


find_package(SFML 2.6.2 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Axe_Game sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

# Mac specific settings
if (APPLE)
    target_link_libraries(Axe_Game "-framework IOKit")
    target_link_libraries(Axe_Game "-framework Cocoa")
    target_link_libraries(Axe_Game "-framework OpenGL")
endif()