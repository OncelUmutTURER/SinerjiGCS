import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root

    property real size: 400
    property var vehicle: null

    property real heading: vehicle ? vehicle.heading.rawValue : 0

    width: size
    height: size

    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/instrumentImages/indicator_background_screws.svg"
    }

    Item {
        id: indicator_inner
        anchors.centerIn: parent.Center

        Image {
            id: heading_background
            width: size
            height: size
            source: "/instrumentImages/heading_background.svg"
        }

        Image {
            id: heading_yaw
            width: size
            height: size
            rotation: -heading
            source: "/instrumentImages/heading_yaw.svg"
        }
        //        Image {
        //            id: heading_beacon_2
        //            width: size
        //            height: size
        //            source: "/instrumentImages/heading_beacon_2.svg"
        //        }
        //        Image {
        //            id: heading_beacon_1
        //            width: size
        //            height: size
        //            source: "/instrumentImages/heading_beacon_1.svg"
        //        }
        Image {
            id: heading_markings
            width: size
            height: size
            source: "/instrumentImages/heading_markings.svg"
        }
    }
    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/instrumentImages/indicator_foreground.svg"
    }
}
