import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root
    width: size
    height: size

    property real size: _defaultSize
    property var vehicle: null

    property var _altitude: vehicle ? vehicle.altitudeRelative.rawValue : 0


    //    Image {
    //        id: indicator_background_dashboard
    //        width: size
    //        height: size
    //        source: "/FlightInstrumentImages/indicator_background_dashboard.svg"
    //    }
    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_background_screws.svg"
        visible: showScrews
    }
    Image {
        id: altimeter_pressure_inhg
        width: size
        height: size
        rotation: (1000 * 0.0295300 - 27.1) * 60
        source: "/FlightInstrumentImages/altimeter_pressure_inhg.svg"
    }

    Image {
        id: altimeter_pressure_mbar
        width: size
        height: size
        rotation: -75 * 1.8
        source: "/FlightInstrumentImages/altimeter_pressure_mbar.svg"
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
        source: "/FlightInstrumentImages/altimeter_background.svg"
    }

    Image {
        id: altimeter_hand_10000ft
        width: size
        height: size
        rotation: _altitude / 1000 * 360
        source: "/FlightInstrumentImages/altimeter_hand_10000ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        Behavior on rotation {
            NumberAnimation {
                duration: 500
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
        source: "/FlightInstrumentImages/altimeter_foreground.svg"
    }

    Image {
        id: altimeter_hand_1000ft
        width: size
        height: size
        rotation: _altitude / 100 * 360
        source: "/FlightInstrumentImages/altimeter_hand_1000ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }
        Behavior on rotation {
            NumberAnimation {
                duration: 500
            }
        }
    }

    Image {
        id: altimeter_hand_100ft
        width: size
        height: size
        rotation: _altitude / 10 * 360
        source: "/FlightInstrumentImages/altimeter_hand_100ft.svg"
        smooth: true
        layer.enabled: true
        layer.effect: DropShadow {
            verticalOffset: 2
            horizontalOffset: 2
        }

        Behavior on rotation {
            NumberAnimation {
                duration: 500
            }
        }
    }

    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_foreground.svg"
    }
}
