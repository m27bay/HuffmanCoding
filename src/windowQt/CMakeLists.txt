cmake_minimum_required(VERSION 3.5)

project(windowQt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(windowQt SHARED
    main.cpp
    Mainwindow.cpp
    Mainwindow.hpp
    Titlewidget.cpp
    Titlewidget.hpp
    Treewidget.cpp
    Treewidget.hpp
  )
else()
  add_executable(windowQt
    main.cpp
    Mainwindow.cpp
    Mainwindow.hpp
    Titlewidget.cpp
    Titlewidget.hpp
    Treewidget.cpp
    Treewidget.cpp
    Treewidget.hpp
    Mytextedit.cpp
    Mytextedit.hpp
    Mybutton.cpp
    Mybutton.hpp
    ../lib/Parser.cpp
    ../lib/Parser.hpp
    ../lib/Tree.cpp
    ../lib/Tree.hpp
    ../lib/Writer.hpp
    ../lib/Writer.cpp
    ../test/Test.cpp
    ../test/Test.hpp
  )
endif()

target_link_libraries(windowQt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
