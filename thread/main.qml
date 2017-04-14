import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1000
    height: 480
    title: qsTr("Hello World")
    property int testValue : 0
    property int makeCount: 100000
    //list view
    ListView
    {
        id: testListView
        width: 500
        height: 400
        delegate:testDelegate
        model:TestListModel

    }

    Component{
        id: testDelegate
        Item{
            height: 90
            width: 100
            Text{
                x: 0
                text:listCount
            }
            Text{
                x: 100
                text:listText1
            }
            Text{
                x: 200
                text:listText2
            }
            Text{
                x: 300
                text:listText3
            }
            Rectangle{

                anchors.fill: parent
                color: "red"
                opacity: 0.1 * index
            }
        }
    }

    ListModel{
        id: testListModel
        ListElement{
            name: "index1"
            index: 1
        }
        ListElement{
            name: "index2"
            index: 2
        }
        ListElement{
            name: "index3"
            index: 3
        }
        ListElement{
            name: "index4"
            index: 4
        }
    }

    Rectangle{
        x: 400
        y: 200
        width: 100
        height: 100
        Text{
            text:"All Clear"
            color: "black"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                TestList.allRemoveListModel()
            }
        }
    }

    Rectangle{
        x: 600
        y: 200
        width: 100
        height: 100
        Text{
            text:"add Item (+1000)"
            color: "black"
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                TestList.addListModelThread(makeCount)
            }
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



    //animation
}
