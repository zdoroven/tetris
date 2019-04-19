import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 500
    height: 700
    color: "#729fcf"
    title: qsTr("tetris")

    Image {
        id: car
        x: 211
        y: 147
        width: 66
        height: 103
        fillMode: car.PreserveAspectFit
        source: "qrc:/car2.png"
        rotation:180
        focus: true
        property int yv:0
        property int xv:0
        Keys.onPressed: {
            if(event.isAutoRepeat) return;
            switch (event.key) {
            case Qt.Key_Left: xv-=2; break;
            case Qt.Key_Right: xv+=2; break;
            case Qt.Key_Down: yv+=2; break;
            case Qt.Key_Up: yv-=6; break;
            }
        }
        Keys.onReleased: {
            if (event.isAutoRepeat) return;
            switch (event.key) {
            case Qt.Key_Left: xv+=2; break;
            case Qt.Key_Right: xv-=2; break;
            case Qt.Key_Down: yv-=2; break;
            case Qt.Key_Up: yv+=6; break;
            }
        }
    }
    Timer{
            interval:10
            running: true
            repeat: true
            onTriggered:{
                car.x+=car.xv
                car.y+=car.yv
            }
        }
}
