import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    property int testValue : 0

    SwipeView {
        id: swipeView
        anchors.fill: parent
        currentIndex: tabBar.currentIndex

        Page1 {
        }

        Page {
            Label {
                text: qsTr("Second page")
                anchors.centerIn: parent
            }
        }
    }

    footer: TabBar {
        id: tabBar
        currentIndex: swipeView.currentIndex
        TabButton {
            text: qsTr("First")
        }
        TabButton {
            text: qsTr("Second")
        }
    }

    Rectangle{
        width: 100
        height: 100
        color: "blue"
        x: 500
        y: 300
        transform: Rotation {
            origin.x: 50;
            origin.y: 50;
            angle: testValue
        }
    }

    Timer
    {
        interval: 10
        running : true
        repeat: true
        onTriggered:{
            testValue++
            if (testValue == 359)
            {
                testValue = 0
            }
        }
    }
}
