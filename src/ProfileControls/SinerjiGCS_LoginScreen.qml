import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.0

Item {
    id: loginScreen
    width: 310
    height: 175

    Rectangle {
        id: rBackground
        x: 0
        y: 0
        width: 310
        height: 175
        color:  qgcPal.window
        border.color:   qgcPal.text

        GridLayout {
            x: 8
            y: 8
            rows: 3
            columns: 3

            Label {
                id: lblUserName
                text: qsTr("Kullanıcı Adı:")
                Layout.columnSpan: 2
            }

            TextField {
                id: tfUserName
                text: qsTr("")
                placeholderText: "Kullanıcı Adı.."
            }

            Label {
                id: lblPassword
                text: qsTr("Şifre:")
            }

            Item {
                id: spacer
                Layout.preferredHeight: 14
                Layout.preferredWidth: 14
            }

            TextField {
                id: tfPassword
                text: qsTr("")
                placeholderText: "Şifre.."
                echoMode: TextInput.PasswordEchoOnEdit
            }

            Button {
                id: btnLogin
                text: qsTr("Giriş Yap")
                Layout.columnSpan: 3
                Layout.preferredHeight: 40
                Layout.preferredWidth: 291

                onClicked: {
                    if(tfUserName.text == "Umut" && tfPassword.text == "1234")
                        console.log("Doğru");
                    else
                        console.log("Yanlış");
                }
            }
        }
    }

//    Connections {
//        target: btnLogin
//        onClicked: print("clicked")
//    }

}
