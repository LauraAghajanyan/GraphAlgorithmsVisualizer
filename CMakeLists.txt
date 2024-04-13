cmake_minimum_required(VERSION 3.16)
project(graphs LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS Core)
find_package(Qt5 COMPONENTS Gui)
find_package(Qt5 COMPONENTS Widgets)
#find_package(OpenCV REQUIRED)

find_program(CMAKE_CXX_CLANG_TIDY_EXECUTABLE NAMES clang-tidy)
if (NOT CMAKE_CXX_CLANG_TIDY_EXECUTABLE)
  message("clang-tidy not found")
else()
  message("clang-tidy found")
  set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()

#qt5_add_resources(RESOURCE_FILES resources.qrc)

add_executable(graphs
    main.cpp
    mainwindow.h
    mainwindow.cpp
    StartWidget.h
    StartWidget.cpp
    SelectWidget.h
    SelectWidget.cpp
    AdjInWidget.h
    AdjInWidget.cpp
    IncInWidget.h
    IncInWidget.cpp
    FunInWidget.h
    FunInWidget.cpp
    VisualizeWidget.h
    VisualizeWidget.cpp
)
set_target_properties(graphs PROPERTIES
    WIN32_EXECUTABLE TRUE
    #MACOSX_BUNDLE TRUE
)
target_link_libraries(graphs PUBLIC
    Qt::Core
    Qt::Gui
    Qt::Widgets

)