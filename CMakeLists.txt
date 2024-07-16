cmake_minimum_required(VERSION 3.16)
project(mediaApp LANGUAGES CXX)

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
find_package(Qt6 COMPONENTS AppManWindowPrivate)

qt_add_executable(mediaApp
    mdaengine.h
    mdaengine.cpp
    main.cpp
)

add_subdirectory(models)
add_subdirectory(screens)
target_include_directories(${PROJECT_NAME} PRIVATE ./)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Qt::Quick
    Qt::DBus
    Qt::QuickPrivate
    Qt::DBus
    Qt::AppManLauncherPrivate
    Qt::AppManMainPrivate
    Qt::AppManWindowPrivate
    mediascreen
    mediamodel
)

install(FILES
    icon.png
    info.yaml
    DESTINATION
    /apps/mediaApp
)

install(TARGETS ${PROJECT_NAME}
    DESTINATION /apps/mediaApp
)


