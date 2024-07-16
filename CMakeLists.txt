cmake_minimum_required(VERSION 3.16)
project(climateApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Qml)
find_package(Qt6 COMPONENTS Quick)
find_package(Qt6 COMPONENTS DBus)
find_package(Qt6 COMPONENTS AppManLauncherPrivate)
find_package(Qt6 COMPONENTS AppManMainPrivate)

qt_add_executable(climateApp
    climateengine.h
    climateengine.cpp
    main.cpp
)

add_subdirectory(models)
add_subdirectory(screens)

target_include_directories(${PROJECT_NAME} PRIVATE ./)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Quick
    Qt6::DBus
    Qt6::QuickPrivate
    Qt6::DBus
    Qt6::AppManLauncherPrivate
    climatescreen
    climatemodel
)

install(FILES
    icon.png
    info.yaml
    DESTINATION
    /apps/climateApp
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION /apps/climateApp
)
