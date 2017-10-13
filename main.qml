import QtQuick 2.6
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2

import kr.jseo.dsm 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: fileDialog.open()
            }
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    CVProcessor {
        id: cvProcessor
    }

    CVCanvas {
        id: img
        width: 640
        height: 480

        pixmap: cvProcessor.qimage
    }

    FileDialog {
        id: fileDialog

        title: "Please choose a file"
        folder: shortcuts.home
        onAccepted: {
            console.log("You chose: " + fileDialog.fileUrls)
            cvProcessor.fileName = fileDialog.fileUrl
        }
        onRejected: {
            console.log("Canceled")
        }
    }
}
