cmake_minimum_required(VERSION 3.16)

project(HeaderRowInView LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(HeaderRowInView
  main.cpp
  qtableviewwithinlineheaders.h qtableviewwithinlineheaders.cpp
  depechemodel.h depechemodel.cpp EnumConverters.h
  enums.h
  qtreeviewwithinlineheaders.h qtreeviewwithinlineheaders.cpp
)
target_link_libraries(HeaderRowInView Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS HeaderRowInView
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
