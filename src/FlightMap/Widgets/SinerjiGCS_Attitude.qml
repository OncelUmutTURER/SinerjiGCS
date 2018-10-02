import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root
    width: size
    height: size

    property real size: _defaultSize
    property var vehicle: null

    property bool showPitch:    true
    property bool showHeading:  false

    property real _rollAngle:   vehicle ? vehicle.roll.rawValue  : 0
    property real _pitchAngle:  vehicle ? vehicle.pitch.rawValue : 0

    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_background_screws.svg"
    }

    Item {
        id: attitude

        anchors.centerIn: parent.Center
        transform: Rotation {
            origin.x: root.width / 2
            origin.y: root.width / 2
            angle: -_rollAngle
        }

        Image {
            id: attitude_roll_1
            width: size
            height: size
            source: "/FlightInstrumentImages/attitude_roll_1.svg"
        }

        Image {
            id: attitude_pitch
            width: size
            height: size

            source: "/FlightInstrumentImages/attitude_pitch.svg"
            transform: Translate {
                y: (_pitchAngle * 0.7)
            }
        }

        Image {
            id: attitude_roll_2
            width: size
            height: size
            smooth: true
            source: "/FlightInstrumentImages/attitude_roll_2.svg"
        }
    }

    Image {
        id: attitude_foreground_1
        width: size
        height: size
        source: "/FlightInstrumentImages/attitude_foreground_1.svg"
        smooth: true
    }

    Image {
        id: attitude_foreground_2
        width: size
        height: size
        source: "/FlightInstrumentImages/attitude_foreground_2.svg"
        smooth: true
    }

    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_foreground.svg"
    }
}
