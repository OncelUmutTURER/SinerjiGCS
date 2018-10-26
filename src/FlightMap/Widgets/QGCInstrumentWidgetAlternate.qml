/****************************************************************************
 *
 *   (c) 2009-2016 QGROUNDCONTROL PROJECT <http://www.qgroundcontrol.org>
 *
 * QGroundControl is licensed according to the terms in the file
 * COPYING.md in the root of the source code directory.
 *
 ****************************************************************************/


import QtQuick 2.3

import QGroundControl               1.0
import QGroundControl.Controls      1.0
import QGroundControl.ScreenTools   1.0
import QGroundControl.FactSystem    1.0
import QGroundControl.FlightMap     1.0
import QGroundControl.Palette       1.0

/// Instrument panel shown when virtual thumbsticks are visible
Rectangle {    
    property real backgroundOpacity: 0.75
    property bool showScrews: backgroundOpacity < 0.5 ? false : true

    id:             root    
    height:         maxHeight * 0.6 <= 300 ? 300 : maxHeight * 0.6
    width:          height / 3      //getPreferredInstrumentWidth() //100                                               //alt alta 3 adet KARE indicator olduğundan
    radius:         _outerRadius
    color:          Qt.hsla(qgcPal.window.hslHue, qgcPal.window.hslSaturation, qgcPal.window.hslLightness, backgroundOpacity) //Qt.hsla(0,0,0,0.5)
    border.width:   showScrews ? 1 : 0
    border.color:   _isSatellite ? qgcPal.mapWidgetBorderLight : qgcPal.mapWidgetBorderDark

    property var    _qgcView:           qgcView
    property real   _innerRadius:       (width - (_topBottomMargin * 3)) / 4                                            //25 | 23.125
    property real   _outerRadius:       _innerRadius + _topBottomMargin                                                 //25 | 25.625
    property real   _defaultSize:       ScreenTools.defaultFontPixelHeight * (9)                                        //162
    property real   _sizeRatio:         ScreenTools.isTinyScreen ? (width / _defaultSize) * 0.5 : width / _defaultSize  //0.62
    property real   _bigFontSize:       ScreenTools.defaultFontPointSize * 2.5  * _sizeRatio
    property real   _normalFontSize:    ScreenTools.defaultFontPointSize * 1.5  * _sizeRatio
    property real   _labelFontSize:     ScreenTools.defaultFontPointSize * 0.75 * _sizeRatio
    property real   _spacing:           ScreenTools.defaultFontPixelHeight * 0.33                                       //5.94
    property real   _topBottomMargin:   (width * 0.05) / 2                                                              //0 | 2.5
    property real   _availableValueHeight: maxHeight - (root.height + _valuesItem.anchors.topMargin)                    //118.25
    property var    _activeVehicle:     QGroundControl.multiVehicleManager.activeVehicle

    QGCPalette { id: qgcPal }

    SSP_Altimeter {
        id: altimeter
        //anchors.leftMargin: _topBottomMargin
        anchors.topMargin: _topBottomMargin
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        size: parent.width  //_innerRadius * 4
        vehicle: _activeVehicle
    }

    SSP_Attitude {
        id: attitude
        //anchors.leftMargin: _spacing  //anchors.topMargin: _spacing
        anchors.top: altimeter.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        size: parent.width  //_innerRadius * 4
        vehicle: _activeVehicle
    }

    SSP_Heading {
        id: heading
        //anchors.leftMargin: _spacing  //anchors.topMargin: _spacing
        anchors.top: attitude.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        size: parent.width  //_innerRadius * 4
        vehicle: _activeVehicle
    }

/*
    QGCAttitudeWidget {
        id:                 attitude
        anchors.leftMargin: _topBottomMargin
        anchors.left:       parent.left
        size:               _innerRadius * 2
        vehicle:            _activeVehicle
        anchors.verticalCenter: parent.verticalCenter
    }

    QGCCompassWidget {
        id:                 compass
        anchors.leftMargin: _spacing
        anchors.left:       attitude.right
        size:               _innerRadius * 2
        vehicle:            _activeVehicle
        anchors.verticalCenter: parent.verticalCenter
    }
*/
    Item {
        id:                 _valuesItem
        anchors.topMargin:  ScreenTools.defaultFontPixelHeight / 4        
        anchors.top:        parent.bottom
        anchors.right:      parent.right
        width:              getPreferredInstrumentWidth()
        height:             _valuesWidget.height
        visible:            widgetRoot.showValues

        Rectangle {
            anchors.fill:   _valuesWidget
            color:          qgcPal.window
        }

        PageView {
            id:                 _valuesWidget
            anchors.margins:    1
            anchors.left:       parent.left
            anchors.right:      parent.right
            qgcView:            root._qgcView
            maxHeight:          _availableValueHeight
        }
    }
}
