cmake_minimum_required(VERSION 3.16)

project(poolDesign LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(poolDesign
  main.cpp
  interfaces/iPool.h
  interfaces/iPoolItem.h
  pools/mypool.h pools/mypool.cpp
  pools/mypoolitem.h pools/mypoolitem.cpp

)
target_link_libraries(poolDesign Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS poolDesign
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
