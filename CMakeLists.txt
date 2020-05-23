cmake_minimum_required(VERSION 3.15)
project(final_pj)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH qt5.14/5.14.0/gcc_64)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED
        Core
        Gui
        Widgets
        )

include_directories(
        qt5.14/5.14.0/gcc_64/include
)

link_directories(
        qt5.14/5.14.0/gcc_64/lib
)

add_executable(final_pj main.cpp demo.cpp)
target_link_libraries(final_pj Qt5::Widgets)
