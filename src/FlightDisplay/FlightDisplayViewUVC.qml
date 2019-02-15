/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/

import QtQuick                  2.3
import QtMultimedia             5.8 //5.5

import QGroundControl           1.0
import QGroundControl.ScreenTools       1.0
import QGroundControl.Controls          1.0

Rectangle {

    property bool   _recordingVideo:        false
    property bool   _videoRunning:          true
    property string _savePath: QGroundControl.settingsManager.appSettings.videoSavePath + "/";

    anchors.fill:       parent
    color:              Qt.rgba(0,0,0,0.75)
    Camera {
        id:             camera
        deviceId:       QGroundControl.videoManager.videoSourceID
        captureMode:    Camera.CaptureVideo //Camera.CaptureViewfinder

        videoRecorder.muted: true
        videoRecorder.audioSampleRate: 44100
        videoRecorder.audioBitRate: 80
        videoRecorder.audioChannels: 1
        videoRecorder.audioCodec: "audio/mpeg, mpegversion=(int)4"
        videoRecorder.outputLocation: _savePath
        videoRecorder.frameRate: 30
        videoRecorder.videoCodec: "video/x-h264"
        videoRecorder.mediaContainer: "video/x-matroska"
    }
    VideoOutput {
        source:         camera
        anchors.fill:   parent
        fillMode:       VideoOutput.PreserveAspectCrop
        visible:        !QGroundControl.videoManager.isGStreamer
    }
    onVisibleChanged: {
        if(visible)
            camera.start()
        else
            camera.stop()
    }




    /////////////////////////////

    // Button to start/stop video recording
    Item {
        anchors.left:      parent.right
        anchors.bottom:     parent.bottom
        height:             ScreenTools.defaultFontPixelHeight * 2
        width:              height
        visible:            QGroundControl.settingsManager.videoSettings.showRecControl.rawValue
        Rectangle {
            id:                 recordVideoBtnBackground
            anchors.top:        parent.top
            anchors.bottom:     parent.bottom
            width:              height
            radius:             _recordingVideo ? 0 : height
            color:              _videoRunning ? "red" : "gray"
            SequentialAnimation on opacity {
                running:        _recordingVideo
                loops:          Animation.Infinite
                PropertyAnimation { to: 0.5; duration: 500 }
                PropertyAnimation { to: 1.0; duration: 500 }
            }
        }
        QGCColoredImage {
            anchors.top:                parent.top
            anchors.bottom:             parent.bottom
            anchors.horizontalCenter:   parent.horizontalCenter
            width:                      height * 0.625
            sourceSize.width:           width
            source:                     "/qmlimages/CameraIcon.svg"
            visible:                    recordVideoBtnBackground.visible
            fillMode:                   Image.PreserveAspectFit
            color:                      "white"
        }
        MouseArea {
            anchors.fill:   parent
            enabled:        _videoRunning
            onClicked: {
                if (_recordingVideo) {
                    camera.videoRecorder.stop()
                    // reset blinking animation
                    recordVideoBtnBackground.opacity = 1
                    _recordingVideo = false;
                } else {
                    camera.videoRecorder.outputLocation = _savePath + Qt.formatDateTime(new Date(), "yyyy-MM-dd_hh.mm.ss");
                    camera.videoRecorder.record()
                    _recordingVideo = true;
                }
            }
        }
    }
}
