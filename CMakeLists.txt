



cmake_minimum_required(VERSION 3.16)
project(markdowntexteditor)

set(CMAKE_AUTOMOC ON)

set(HEADERS
        include/MainWindow.hpp
        include/MarkdownEditor.hpp

)

set(SOURCES
        src/main.cpp
        src/MainWindow.cpp
        src/MarkdownEditor.cpp

)

set(CMAKE_PREFIX_PATH "C:/Qt/6.10.2/mingw_64/bin")
find_package(Qt6 COMPONENTS REQUIRED Widgets Gui Core)

add_executable(markdowntexteditor
        ${HEADERS}
        ${SOURCES}
)

target_include_directories(markdowntexteditor PRIVATE include)
target_link_libraries(markdowntexteditor PRIVATE
        Qt6::Widgets
        Qt6::Gui
        Qt6::Core
)