/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/
import QtQuick 2.9
import QtPositioning 5.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import QtGraphicalEffects 1.0

import QtQuick.Controls.Styles 1.4
import QtQuick.Controls.Private 1.0

import QGroundControl 1.0
import QGroundControl.ScreenTools 1.0
import QGroundControl.Controls 1.0
import QGroundControl.Palette 1.0
import QGroundControl.Vehicle 1.0
import QGroundControl.Controllers 1.0
import QGroundControl.FactSystem 1.0
import QGroundControl.FactControls 1.0


/// Gimbal page for Instrument Panel PageView
Column {

    width: pageWidth
    spacing: ScreenTools.defaultFontPixelHeight * 0.25

    property var _activeVehicle: QGroundControl.multiVehicleManager.activeVehicle

    property bool showSettingsIcon: _activeVehicle ? true : false

    function showSettings() {
        mainLayout.visible = !mainLayout.visible
        gimbalControls.visible = !gimbalControls.visible
    }

    property string videoCameraIcon: "/qmlimages/camera_video.svg"
    property string videoStopIcon: "/res/Stop"
    property string photoTakeIcon: "/qmlimages/camera_photo.svg"
    property string zoomInIcon: "/res/zoomIn"
    property string zoomOutIcon: "/res/zoomOut"
//    property bool cameraMode: !_activeVehicle.mount_VideoModeActive
//    property bool videoActive: _activeVehicle.mount_RecordingVideo
//    property bool zoomInActive: _activeVehicle.mount_zoomInActive
//    property bool zoomOutActive: _activeVehicle.mount_zoomOutActive

    ColumnLayout {
        id: mainLayout
        enabled: _activeVehicle

        anchors.horizontalCenter: parent.horizontalCenter

        QGCGroupBox {
            id: rowBox
            transformOrigin: Item.Center
            Layout.fillWidth: true

            RowLayout {
                id: rowLayout
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                RowLayout {
                    ButtonGroup {
                        id: tabPositionGroup
                    }
                    RadioButton {
                        id: radioButton
                        text: "Photo"
                        checked: !_activeVehicle.mount_VideoModeActive
                        ButtonGroup.group: tabPositionGroup
                        /*
                        onCheckedChanged: {
//                            cameraModeStatusText.text = "Take a photo"
                            if (checked && _activeVehicle.mount_VideoModeActive) {
                                if (_activeVehicle.mount_RecordingVideo) {
//                                    videoButtonIcon.source = videoCameraIcon
//                                    videoButtonIcon.color = "gray"
                                    _activeVehicle.mount_RecordingVideo = false
//                                    _activeVehicle.setVideoRecordStatus(videoActive ? 1 : 0)
//                                    _activeVehicle.cameraCapture() //stop active recording before changing mode
                                }
                                _activeVehicle.mount_VideoModeActive = false
//                                _activeVehicle.cameraModeChange()
                            }
                        }
                        */
                    }
                    RadioButton {
                        text: "Video"
                        checked: _activeVehicle.mount_VideoModeActive
                        ButtonGroup.group: tabPositionGroup

                        onCheckedChanged: {
//                            cameraModeStatusText.text = "Record a video"
                            if (!checked && _activeVehicle.mount_RecordingVideo) {
                                _activeVehicle.mount_RecordingVideo = false
                            }

                            _activeVehicle.mount_VideoModeActive = checked
                        }
                    }
                }
            }
        }

        QGCGroupBox {
            Layout.fillWidth: true
            RowLayout {
                Button {
                    // Take Photo
                    id: captureButton
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    visible: !_activeVehicle.mount_VideoModeActive

                    onClicked: {
                        //console.log("TAKE A PHOTO EVENT")
                        _activeVehicle.cameraCapture()
                    }

                    background: Rectangle {
                        implicitWidth: 40
                        implicitHeight: 40
                        border.width: 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: captureButton.pressed ? "#aaa" : "#ccc"
                            }
                            GradientStop {
                                position: 1
                                color: captureButton.pressed ? "#ccc" : "#aaa"
                            }
                        }
                    }
                    Image {
                        id: captureButtonIcon
                        source: photoTakeIcon

                        anchors.horizontalCenter: captureButton.horizontalCenter
                        anchors.verticalCenter: captureButton.verticalCenter
                        property int size: 25 // default

                        sourceSize.width: size
                        sourceSize.height: size

                        ColorOverlay {
                            id: captureButtoncolorOverlay
                            anchors.fill: captureButtonIcon
                            source: captureButtonIcon
                            color: captureButton.pressed ? "red" : "gray"
                        }
                    }

                }
                Button {
                    // Video
                    id: videoButton
                    checkable: true

                    checked: _activeVehicle.mount_RecordingVideo
                    visible: _activeVehicle.mount_VideoModeActive

                    onCheckedChanged: {
                        _activeVehicle.mount_RecordingVideo = checked

//                        videoButtonIcon.source = videoActive ? videoCameraIcon : videoStopIcon
//                        videoButtonIcon.color = videoActive ? "gray" : "red"
//                        cameraModeStatusText.text = !videoActive ? "Recording.." : "Record a video"
//                        videoActive = !videoActive

                        //console.log("RECORD VIDEO EVENT")
//                        _activeVehicle.setVideoRecordStatus(videoActive ? 1 : 0)
//                        _activeVehicle.cameraCapture()
                    }
                    background: Rectangle {
                        implicitWidth: 40
                        implicitHeight: 40
                        border.width: 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: _activeVehicle.mount_RecordingVideo ? "#aaa" : "#ccc"
                            }
                            GradientStop {
                                position: 1
                                color: _activeVehicle.mount_RecordingVideo ? "#ccc" : "#aaa"
                            }
                        }
                    }

                    Image {
                        id: videoButtonIcon

                        property alias color: videoButtoncolorOverlay.color
                        property int size: 30

                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter

                        source: _activeVehicle.mount_RecordingVideo ? videoStopIcon : videoCameraIcon
                        sourceSize.width: size
                        sourceSize.height: size

                        property bool timeTick: true
                        Timer {
                            id: textTimer
                            interval: 700
                            repeat: _activeVehicle.mount_RecordingVideo
                            running: _activeVehicle.mount_RecordingVideo
                            triggeredOnStart: _activeVehicle.mount_RecordingVideo
                            onTriggered: videoButtonIcon.set()
                            onRunningChanged: videoButtonIcon.stop()
                        }
                        function set() {
                            if (timeTick) {
                                videoButtonIcon.color = "red"
                            } else {
                                videoButtonIcon.color = "gray"
                            }
                            timeTick = !timeTick
                        }
                        function stop() {
                            if(!videoButton.checked)
                                videoButtonIcon.color = "gray"
                        }
                    }
                    ColorOverlay {
                        id: videoButtoncolorOverlay
                        anchors.fill: videoButtonIcon
                        source: videoButtonIcon
                        color: _activeVehicle.mount_RecordingVideo ? "red" : "gray"
                    }
                }
                Label {
                    id: cameraModeStatusText
                    text: _activeVehicle.mount_VideoModeActive ? (_activeVehicle.mount_RecordingVideo ? "Recording.." : "Record a video") : "Take a photo"
                    font.pointSize: 11
                }
            }
        }

        QGCGroupBox {
            RowLayout {
                Button {
                    id: btnZoomInId
                    checkable: true
                    checked: _activeVehicle.mount_zoomInActive

                    Image {
                        id: zoomInButtonIcon
                        source: zoomInIcon
                        property alias color: zoomInColorOverlay.color
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        property int size: 22
                        sourceSize.width: size
                        sourceSize.height: size
                    }
                    ColorOverlay {
                        id: zoomInColorOverlay
                        anchors.fill: zoomInButtonIcon
                        source: zoomInButtonIcon
                        color: _activeVehicle.mount_zoomInActive ? "red" : "gray"
                    }

                    background: Rectangle {
                        implicitWidth: 40
                        implicitHeight: 40
                        border.width: 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: _activeVehicle.mount_zoomInActive ? "#aaa" : "#ccc"
                            }

                            GradientStop {
                                position: 1
                                color: _activeVehicle.mount_zoomInActive ? "#ccc" : "#aaa"
                            }
                        }
                    }
                    onCheckedChanged: {
                        _activeVehicle.mount_zoomOutActive = false
                        _activeVehicle.mount_zoomInActive = checked
//                        checked ? _activeVehicle.cameraZoomIn() : _activeVehicle.cameraZoomStop()
                    }
                }
                Label {
                    text: "Zoom Camera"
                    font.pointSize: 11
                }
                Button {
                    id: btnZoomOutId
                    checkable: true
                    checked: _activeVehicle.mount_zoomOutActive
                    Image {
                        id: zoomOutButtonIcon
                        source: zoomOutIcon
                        property alias color: zoomOutColorOverlay.color
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        property int size: 22
                        sourceSize.width: size
                        sourceSize.height: size
                    }
                    ColorOverlay {
                        id: zoomOutColorOverlay
                        anchors.fill: zoomOutButtonIcon
                        source: zoomOutButtonIcon
                        color: _activeVehicle.mount_zoomOutActive ? "red" : "gray"
                    }

                    background: Rectangle {
                        implicitWidth: 40
                        implicitHeight: 40
                        border.width: 1
                        border.color: "#888"
                        radius: 4
                        gradient: Gradient {
                            GradientStop {
                                position: 0
                                color: _activeVehicle.mount_zoomOutActive ? "#aaa" : "#ccc"
                            }

                            GradientStop {
                                position: 1
                                color: _activeVehicle.mount_zoomOutActive ? "#ccc" : "#aaa"
                            }
                        }
                    }
                    onCheckedChanged: {
                        _activeVehicle.mount_zoomInActive = false
                        _activeVehicle.mount_zoomOutActive = checked
//                        checked ? _activeVehicle.cameraZoomOut() : _activeVehicle.cameraZoomStop()
                    }
                }
            }
        }
    }

    ColumnLayout {
        id: gimbalControls
        visible: false
        enabled: _activeVehicle

//        width: 240
//        height: 240

        anchors.horizontalCenter: parent.horizontalCenter

        Image {
            id: image

            property string defaultControls: "/qmlimages/SinerjiGCS_GimbalControls.svg"
            source: defaultControls

//            anchors.fill: parent
            Layout.alignment: Qt.AlignCenter

            MouseArea {
                id: mouseArea_up
                x: gimbalControls.width / 3 // 80
                y: 0
                width: gimbalControls.width / 3 //80
                height: gimbalControls.width / 3 //80
                cursorShape: "PointingHandCursor"
                onPressed: {
                    cursorShape = "ClosedHandCursor"
                    image.source = "/qmlimages/SinerjiGCS_GimbalControls_up.svg"
                }
                onReleased: {
                    cursorShape = "PointingHandCursor"
                    image.source = parent.defaultControls
                }
                onClicked: _activeVehicle.rotateGimbal(1)
            }

            MouseArea {
                id: mouseArea_right
                x: gimbalControls.width * 2 / 3 //160
                y: gimbalControls.width / 3 //80
                width: gimbalControls.width / 3 //80
                height: gimbalControls.width / 3 //80
                cursorShape: "PointingHandCursor"
                onPressed: {
                    cursorShape = "ClosedHandCursor"
                    image.source = "/qmlimages/SinerjiGCS_GimbalControls_right.svg"
                }
                onReleased: {
                    cursorShape = "PointingHandCursor"
                    image.source = parent.defaultControls
                }
                onClicked: _activeVehicle.rotateGimbal(2)
            }

            MouseArea {
                id: mouseArea_down
                x: gimbalControls.width / 3 //80
                y: gimbalControls.width * 2 / 3 //160
                width: gimbalControls.width / 3 //80
                height: gimbalControls.width / 3 //80
                cursorShape: "PointingHandCursor"
                onPressed: {
                    cursorShape = "ClosedHandCursor"
                    image.source = "/qmlimages/SinerjiGCS_GimbalControls_down.svg"
                }
                onReleased: {
                    cursorShape = "PointingHandCursor"
                    image.source = parent.defaultControls
                }
                onClicked: _activeVehicle.rotateGimbal(3)
            }

            MouseArea {
                id: mouseArea_left
                x: 0
                y: gimbalControls.width / 3 //80
                width: gimbalControls.width / 3 //80
                height: gimbalControls.width / 3 //80
                cursorShape: "PointingHandCursor"
                onPressed: {
                    cursorShape = "ClosedHandCursor"
                    image.source = "/qmlimages/SinerjiGCS_GimbalControls_left.svg"
                }
                onReleased: {
                    cursorShape = "PointingHandCursor"
                    image.source = parent.defaultControls
                }
                onClicked: _activeVehicle.rotateGimbal(4)
            }

            MouseArea {
                id: mouseArea_center
                x: gimbalControls.width / 3 //80
                y: gimbalControls.width / 3 //80
                width: gimbalControls.width / 3 //80
                height: gimbalControls.width / 3 //80
                cursorShape: "PointingHandCursor"
                onPressed: {
                    cursorShape = "ClosedHandCursor"
                    image.source = "/qmlimages/SinerjiGCS_GimbalControls_center.svg"
                }
                onReleased: {
                    cursorShape = "PointingHandCursor"
                    image.source = parent.defaultControls
                }
                onClicked: _activeVehicle.rotateGimbal(0)
            }
        }
    }
}
