cmake_minimum_required(VERSION 3.16)

project(QTableViewWithHeader LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS core Widgets)

add_executable(QTableViewWithHeader
  main.cpp
  tableviewwithheader.h tableviewwithheader.cpp
  depechemodel.h depechemodel.cpp
  EnumConverters.h
)
target_link_libraries(QTableViewWithHeader Qt${QT_VERSION_MAJOR}::Widgets)

include(GNUInstallDirs)
install(TARGETS QTableViewWithHeader
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
