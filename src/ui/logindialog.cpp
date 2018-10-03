#include "MainWindow.h"
#include "logindialog.h"
#include "ui_logindialog.h"
#include <QPushButton>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
    ui->buttonBox->button(QDialogButtonBox::Ok)->setVisible(false); //ButtonBox'ı no-button olacak şekilde ayarladığımızda uygulama patlıyor. Bu nedenle var olan tek button'u hide() ediyoruz.
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

/*
void LoginDialog::on_buttonBox_clicked(QAbstractButton *button)
{
    if(static_cast<QPushButton*>(button) == ui->buttonBox->button(QDialogButtonBox::Ok) ){
        if(ui->txtUserName->text() == "Umut" && ui->txtPassword->text() == "1234")
            this->done(QDialog::Accepted);
    }
}
*/

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
