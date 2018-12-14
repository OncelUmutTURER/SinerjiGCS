#include "MainWindow.h"
#include "logindialog.h"
#include "ui_logindialog.h"
#include "arduinocommunication.h"
#include "carduino.h"
#include <string>
#include <iostream>
#include <QPushButton>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_btnLogin_clicked()
{
    if((ui->txtUserName->text() == "Umut" || ui->txtUserName->text() == "Öncel") && ui->txtPassword->text() == "1234")
    {
        QString pilotName = ui->txtUserName->text();

        qApp->property("loggedInUser") = pilotName;

        QList<QMenu*> menus = MainWindow::instance()->menuBar()->findChildren<QMenu*>();
        foreach(QMenu* m,menus)
        {
            if(m->objectName()=="menuPilot")
            {
                m->setTitle("Pilot: " + pilotName);
                break;
            }
        }

//        connectArduino();

        accept(); //closes dialog window
    }
}
/*
void LoginDialog::connectArduino()
{
    cArduino arduino2(ArduinoBaundRate::B9600bps);
    ArduinoCommunication _arduinocommunication2(false,false,false,false,false,"0",false,0);
//        arduino2.open(ArduinoBaundRate::B9600bps);
//        arduino2.write("KYHVTHTYLALLSLC3GPFHDB77");
//        arduino2.close();
    string userInput ="";
    if(!arduino2.isOpen())
    {
        _arduinocommunication2.SetArduinoConnection(false);
    }
    else
    {
        arduino2.open(ArduinoBaundRate::B9600bps);
        _arduinocommunication2.SetValueApplicationStart(true);
        userInput = _arduinocommunication2.GetValue();
        arduino2.write(userInput);
        //        string arduinoOutput="";
        //        if(!arduino2.read(arduinoOutput))//read witch timeout!
        //        {
        //            cerr<<"TIMEOUT!"<<endl;
        //        }
        //        else
        //        {
        //            cout<<arduinoOutput<<endl;
        //        }
        arduino2.close();
    }
}
*/
