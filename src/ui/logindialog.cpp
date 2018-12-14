#include "MainWindow.h"
#include "logindialog.h"
#include "ui_logindialog.h"
#include "arduinocommunication.h"
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

        accept(); //closes dialog window
    }
}
