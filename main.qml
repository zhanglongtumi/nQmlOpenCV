import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    title: qsTr("Hello World")
    width: 800
    height: 800
    visible: true
    Rectangle {
        width: 640
        height: 480
        Image {
            id: image
            source: "image://videoCapture/hoge"
        }
        Timer {
            property int cnt: 0
            interval: 80
            running: true
            repeat: true
            onTriggered:  {
                if (image.status === Image.Ready) {
                    image.source = "image://videoCapture/" + cnt;
                    ++cnt;
                }
            }
        }
    }
}
