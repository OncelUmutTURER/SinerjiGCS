import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root

    property real size: 400
    property var vehicle: null

    property var altitude: vehicle ? vehicle.altitudeRelative.rawValue : 0

    width: size
    height: size

    //    Image {
    //        id: indicator_background_dashboard
    //        width: size
    //        height: size
    //        source: "/instrumentImages/indicator_background_dashboard.svg"
    //    }
    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/instrumentImages/indicator_background_screws.svg"
    }
    Image {
        id: altimeter_pressure_inhg
        width: size
        height: size
        rotation: (1000 * 0.0295300 - 27.1) * 60
        source: "/instrumentImages/altimeter_pressure_inhg.svg"
    }

    Image {
        id: altimeter_pressure_mbar
        width: size
        height: size
        rotation: -75 * 1.8
        source: "/instrumentImages/altimeter_pressure_mbar.svg"
    }

    Image {
        id: altimeter_background
        width: size
        height: size
        smooth: true

        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        source: "/instrumentImages/altimeter_background.svg"
    }

    Image {
        id: altimeter_hand_10000ft
        width: size
        height: size
        rotation: altitude / 1000 * 360
        source: "/instrumentImages/altimeter_hand_10000ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        Behavior on rotation {
            NumberAnimation {
                duration: 1000
            }
        }
    }

    Image {
        id: altimeter_foreground
        width: size
        height: size
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        source: "/instrumentImages/altimeter_foreground.svg"
    }

    Image {
        id: altimeter_hand_1000ft
        width: size
        height: size
        rotation: altitude / 100 * 360
        source: "/instrumentImages/altimeter_hand_1000ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        Behavior on rotation {
            NumberAnimation {
                duration: 1000
            }
        }
    }

    Image {
        id: altimeter_hand_100ft
        width: size
        height: size
        rotation: altitude / 10 * 360
        source: "/instrumentImages/altimeter_hand_100ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }

        Behavior on rotation {
            NumberAnimation {
                duration: 1000
            }
        }
    }

    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/instrumentImages/indicator_foreground.svg"
    }
}
