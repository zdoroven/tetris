import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    id: window
    visible: true
    width: 500
    height: 700
    minimumHeight: 700
    maximumHeight: 700
    minimumWidth: 500
    maximumWidth: 500
    opacity: 1
    title: qsTr("NFS")

    function growncalculate(x) {
        if(car.x > 0 && car.x < 50) car.xv = -1
        if(car.x >= 50 && car.x < 100) car.xv = 1
        if(car.x > 100 && car.x < 150) car.xv = -1
        if(car.x >= 150 && car.x < 200) car.xv = 1
        if(car.x > 200 && car.x < 250) car.xv = -1
        if(car.x >= 250 && car.x < 300) car.xv = 1
        if(car.x > 300 && car.x < 350) car.xv = -1
        if(car.x >= 350 && car.x < 400) car.xv = 1
        if(car.x == 0) car.xv = 0
        if(car.x == 100) car.xv = 0
        if(car.x == 200) car.xv = 0
        if(car.x == 300) car.xv = 0
        if(car.x == 400) car.xv = 0
        return car.xv
    }
    Image {
        id: background
        anchors.fill: parent
        source: "spacemouse.png"
        sourceSize.height: 700
        sourceSize.width: 500
    }

    Image {
        id: car
        x: 200
        y: 80
        width: 100
        height: 150
        fillMode: car.PreserveAspectFit
        source: "qrc:/car2.png"
        rotation:180
        focus: true
        property int yv:1
        property int xv:0
        Keys.onPressed: {
            if(event.isAutoRepeat) return;
            switch (event.key) {
            case Qt.Key_Left: xv-=2; break;
            case Qt.Key_Right: xv+=2; break;
            case Qt.Key_Down: yv+=2; break;
            }
        }
        Keys.onReleased: {
            if (event.isAutoRepeat) return;
            switch (event.key) {
            case Qt.Key_Left: xv+=2; break;
            case Qt.Key_Right: xv-=2; break;
            case Qt.Key_Down: yv-=2; break;
           }
        }
    }
    Timer{
            interval:10
            running: true
            repeat: true
            onTriggered:{
                if(car.y == 550){
                    car.yv = 0
                    car.xv = growncalculate(car.x)
                } else car.y+=car.yv;
                if(car.x == 0 && car.xv > 0) car.x+=car.xv
                if(car.x == 400 && car.xv < 0) car.x+=car.xv
                if(car.x > 0 && car.x < 400) car.x+=car.xv

            }
    }
}
