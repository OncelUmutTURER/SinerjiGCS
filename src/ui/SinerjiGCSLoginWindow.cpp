#include "SinerjiGCSLoginWindow.h"
#include "ui_SinerjiGCSLoginWindow.h"

#include <QMessageBox>

SinerjiGCSLoginWindow::SinerjiGCSLoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SinerjiGCSLoginWindow)
{
    ui->setupUi(this);
}

SinerjiGCSLoginWindow::~SinerjiGCSLoginWindow()
{
    delete ui;
}

void SinerjiGCSLoginWindow::on_btnLogin_clicked()
{
    if(ui->leUserName->text() == "Umut" && ui->lePassword->text() == "1234")
        //QMessageBox::information(this, "Giriş", "Giriş Başarılı");
        qApp->property("loggedInUser").setValue(ui->leUserName->text());
    else
        QMessageBox::information(this, "Giriş", "Giriş Başarısız");
}
