import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root

    property real size: 400
    property var vehicle: null

    property real roll: vehicle ? vehicle.roll.rawValue : 0
    property real pitch: vehicle ? vehicle.pitch.rawValue : 0

    width: size
    height: size

    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/instrumentImages/indicator_background_screws.svg"
    }

    Item {
        id: attitude

        anchors.centerIn: parent.Center
        transform: Rotation {
            origin.x: size / 2
            origin.y: size / 2
            angle: roll
        }

        Image {
            id: attitude_roll_1
            width: size
            height: size
            source: "/instrumentImages/attitude_roll_1.svg"
        }

        Image {
            id: attitude_pitch
            width: size
            height: size

            source: "/instrumentImages/attitude_pitch.svg"
            transform: Translate {
                y: (pitch * 0.7)
            }
        }

        Image {
            id: attitude_roll_2
            width: size
            height: size
            smooth: true
            source: "/instrumentImages/attitude_roll_2.svg"
        }
    }

    Image {
        id: attitude_foreground_1
        width: size
        height: size
        source: "/instrumentImages/attitude_foreground_1.svg"
        smooth: true
    }

    Image {
        id: attitude_foreground_2
        width: size
        height: size
        source: "/instrumentImages/attitude_foreground_2.svg"
        smooth: true
    }

    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/instrumentImages/indicator_foreground.svg"
    }
}
