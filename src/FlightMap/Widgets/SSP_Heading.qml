import QtQuick 2.3
import QtGraphicalEffects 1.0
import Qt.labs.calendar 1.0

Item {
    id: root
    width: size
    height: size

    property real size: _defaultSize
    property var vehicle: null

    property real _heading: vehicle ? vehicle.heading.rawValue : 0

    Image {
        id: indicator_background_screws
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_background_screws.svg"
        visible: showScrews
    }

    Item {
        id: indicator_inner
        anchors.centerIn: parent.Center

        Image {
            id: heading_background
            width: size
            height: size
            source: "/FlightInstrumentImages/heading_background.svg"
            visible: showScrews
        }

        Image {
            id: heading_yaw
            width: size
            height: size
            source: "/FlightInstrumentImages/heading_yaw.svg"

            //rotation: -heading

            transform: Rotation {
                origin.x:       heading_yaw.width  / 2
                origin.y:       heading_yaw.height / 2
                angle:          -_heading
            }

        }
        //        Image {
        //            id: heading_beacon_2
        //            width: size
        //            height: size
        //            source: "/FlightInstrumentImages/heading_beacon_2.svg"
        //        }
        //        Image {
        //            id: heading_beacon_1
        //            width: size
        //            height: size
        //            source: "/FlightInstrumentImages/heading_beacon_1.svg"
        //        }

        Image {
            id: heading_markings
            width: size
            height: size
            source: "/FlightInstrumentImages/heading_markings.svg"
        }
    }
    Image {
        id: indicator_foreground
        width: size
        height: size
        source: "/FlightInstrumentImages/indicator_foreground.svg"
    }
}
