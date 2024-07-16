# Khai báo climatescreen library
qt_add_library(climatescreen STATIC)
# Danh sách các tệp QML
set(QML_SOURCES
    climatescreen.qml
    MiddleBar.qml
    HeatSeats.qml
    AdjustTemp.qml
    Climate.qml
)
qt_add_resources(climatescreen "climatescreen"
    PREFIX "/"
    FILES
    climatescreen.qml
    MiddleBar.qml
    HeatSeats.qml
    AdjustTemp.qml
    Climate.qml
)


qt_add_resources(climatescreen "images"
    PREFIX "/"
    FILES
        assets/Icon/arrow-up.png
        assets/Icon/Technolog.jpg
        assets/Icon/arrow-up_gray.png
        assets/Icon/fan.png
        assets/Icon/fan_white.png
        assets/Icon/heated_seats_gray.png
        assets/Icon/heated_seats_white.png
        assets/Icon/heater_gray.png
        assets/Icon/heater_white.png
        assets/Icon/Rear_gray.png
        assets/Icon/Rear_white.png
        assets/Icon/upper.png
        assets/Icon/Lower_gray.png
        assets/Icon/Lower_white.png
        assets/Icon/upper_gray.png
        assets/Icon/upper_white.png
        assets/Icon/HeatSeat_Behind_white.png
        assets/Icon/HeatSeat_Behind_gray.png
        MiddleBar.qml
        HeatSeats.qml
        AdjustTemp.qml
        Climate.qml
)
target_include_directories(climatescreen PUBLIC ./)
# Liên kết với các thư viện cần thiết
find_package(Qt6 6.2 REQUIRED COMPONENTS)


