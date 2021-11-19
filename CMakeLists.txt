cmake_minimum_required(VERSION 3.20.0)

project(Minesweeper VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
 
find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(MINESWEEPER_LANG "EN" CACHE STRING "Language of the application.")
set(MINESWEEPER_LANG_OPTIONS
    "EN"
    "CN"
)
set_property(CACHE MINESWEEPER_LANG PROPERTY STRINGS ${MINESWEEPER_LANG_OPTIONS})

set(MINESWEEPER_SRC
    "lookitem.cpp"
    "main.cpp"
    "mainwindow.cpp"
    "myitem.cpp"
    "myscene.cpp"
    "numitem.cpp"
    "numscene.cpp"
    "settingwidget.cpp"
    "languages.cpp"
    "img.qrc"
)
add_executable(main ${MINESWEEPER_SRC})

target_link_libraries(main Qt5::Widgets
)
