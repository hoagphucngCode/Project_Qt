cmake_minimum_required(VERSION 3.16)

project(MediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick Multimedia REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(TAGLIB REQUIRED taglib)

qt_add_executable(appMediaPlayer
    main.cpp
)

if(QT_KNOWN_POLICY_<policy_name>)
    qt_policy(SET <policy_name> NEW)
endif()

qt_add_qml_module(appMediaPlayer
    URI MediaPlayer
    VERSION 1.0
    QML_FILES 
        main.qml
        screen/features/MusicPlayer.qml
        screen/components/music/Controller.qml
        screen/components/music/List.qml
        screen/components/music/Player.qml
        screen/components/music/IconButton.qml
        screen/utils.js
    SOURCES
        src/common.h                  src/common.cpp
        src/handler/media_handler.h   src/handler/media_handler.cpp
        src/provider/image_provider.h src/provider/image_provider.cpp
        src/utils/tagmeta.h           src/utils/tagmeta.cpp
)


set_target_properties(appMediaPlayer PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appMediaPlayer
    PRIVATE Qt6::Quick Qt6::Multimedia)
target_link_libraries(appMediaPlayer
    PRIVATE ${TAGLIB_LIBRARIES})
include(CMakePrintHelpers)
cmake_print_variables(TAGLIB_CFLAGS)
cmake_print_variables(TAGLIB_CFLAGS_OTHER)
cmake_print_variables(TAGLIB_LIBRARIES)

include(GNUInstallDirs)
install(TARGETS appMediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
