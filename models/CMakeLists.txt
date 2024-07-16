qt_add_library(climatemodel STATIC)
qt_add_qml_module(climatemodel
    URI "climate.models"
    VERSION 1.0
    NO_PLUGIN
    NO_GENERATE_QMLTYPES
    SOURCES
    climodel.h climodel.cpp
)
