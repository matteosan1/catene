import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id:mainWindow
    visible: true
    width: 800
    height: 600
    title: qsTr("Catene...")

    property color textColor: "white"

    Image {
        anchors.fill: parent
        source: "file://Users/sani/workspace/qtquick/catena/images.jpg"
    }

    //Text {
    //    id: punteggio
    //    text: "Punteggio: %1".arg(u.punti)
    //    font.family: "Chalkduster"
    //    font.pointSize: 34
    //    //width: textContainer.width
    //    color: textColor
    //    anchors.left:parent.left
    //}

//    Rectangle {
//        id: textContainer
//        width: 300
//        height: 300
//        anchors.centerIn: parent

        Grid {
            anchors.centerIn: parent
            columns: 2
            spacing: 30

            Rectangle {
                id: dummy1
                height: 50
                width: 50
                opacity: 0
            }

            Text {
                id: text1
                text: u.catena[0]
                font.family: "Chalkduster"
                font.pointSize: 85
                color: textColor
            }

            MyButton {
                id: suggeriento2Button
                visible: true
                buttonText: "SUGGERIMENTO"
                buttonColor: "green"
                height: 50
                width: 50
                enabled: true;
                onClicked: {
                    u.suggerimento(1)
                    u.suggerimento(2)
                }
            }

            Text {
                id: text2
                text: u.catena[1]
                font.family: "Chalkduster"
                font.pointSize: 85
                color: textColor
            }

            Rectangle {
                id: dummy25
                height: 30
                width: 30
                opacity:0
            }
            //MyButton {
            //    id: suggeriento3Button
            //    visible: true
            //    buttonText: "SUGGERIMENTO"
            //    buttonColor: "green"
            //    height: 50
            //    width: 50
            //    enabled: true;
            //    onClicked: {
            //        u.suggerimento(2)
            //    }
            //}

            Text {
                id: text3
                text: u.catena[2]
                font.family: "Chalkduster"
                font.pointSize: 85
                color: textColor
            }

            Rectangle {
                id: dummy2
                height: 30
                width: 30
                opacity:0
            }

            Text {
                id: text4
                text: u.catena[3]
                font.family: "Chalkduster"
                font.pointSize: 85
                color: textColor
//                anchors.left: parent.left
//                anchors.topMargin: 10
//                anchors.top: text3.bottom
            }
        }
    //}

    MyButton {
        id: indovinatoButton
        anchors.bottom: parent.bottom
        buttonText: "CAMBIA CATENA"
        height: 100
        width: 100
        enabled: true;

        onClicked: {
            u.change()
        }
    }

    MyButton {
        id: sbagliatoButton
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        buttonText: "MOSTRA TUTTO"

        height: 100
        width: 100

        enabled: true;
        onClicked: {
            u.mostraTutto();
        }
    }
}
