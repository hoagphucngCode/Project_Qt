qt_add_library(mediascreen STATIC)

set(QML_SOURCES
    mdascreen.qml
)

qt6_add_qml_module(mediascreen
    URI "media.screens"
    VERSION 1.0
    NO_PLUGIN
    NO_GENERATE_QMLTYPES
    QML_FILES
    ${QML_SOURCES}
)

target_include_directories(mediascreen PUBLIC ./)

target_link_libraries(mediascreen PRIVATE mediamodel)

find_package(Qt6 COMPONENTS Core)
find_package(Qt6 COMPONENTS Gui)
find_package(Qt6 COMPONENTS Qml)
find_package(Qt6 COMPONENTS Quick)
find_package(Qt6 COMPONENTS DBus)
find_package(Qt6 COMPONENTS AppManLauncherPrivate)
find_package(Qt6 COMPONENTS AppManMainPrivate)
find_package(Qt6 COMPONENTS AppManWindowPrivate)

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
