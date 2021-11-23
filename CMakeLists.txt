cmake_minimum_required(VERSION 3.20.0)

project(Minesweeper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
 
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(MINESWEEPER_LANG "en" CACHE STRING "Language of the application.")
set(MINESWEEPER_LANG_OPTIONS
    "en"
    "cn"
    "cz"
)
set_property(CACHE MINESWEEPER_LANG PROPERTY STRINGS ${MINESWEEPER_LANG_OPTIONS})

add_definitions(-DMINESWEEPER_LANG="${MINESWEEPER_LANG}")
add_definitions(-DMINESWEEPER_SRC="${CMAKE_CURRENT_LIST_DIR}")

set(MINESWEEPER_SRC
    "src/main.cpp"
    "src/lookitem.cpp"
    "src/mainwindow.cpp"
    "src/myitem.cpp"
    "src/myscene.cpp"
    "src/numitem.cpp"
    "src/numscene.cpp"
    "src/settingwidget.cpp"
    "img.qrc"
    "lang.qrc"
)
add_executable(qtm ${MINESWEEPER_SRC})

target_link_libraries(qtm Qt5::Widgets
)
