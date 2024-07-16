qt_add_library(mediamodel STATIC)
qt_add_qml_module(mediamodel
    URI "media.models"
    VERSION 1.0
    NO_PLUGIN
    NO_GENERATE_QMLTYPES
    SOURCES
    mdamodel.h mdamodel.cpp
)