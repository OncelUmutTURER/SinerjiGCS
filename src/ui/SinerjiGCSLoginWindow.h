#ifndef SINERJIGCSLOGINWINDOW_H
#define SINERJIGCSLOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class SinerjiGCSLoginWindow;
}

class SinerjiGCSLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SinerjiGCSLoginWindow(QWidget *parent = nullptr);
    ~SinerjiGCSLoginWindow();

private slots:
    void on_btnLogin_clicked();

private:
    Ui::SinerjiGCSLoginWindow *ui;
};

#endif // SINERJIGCSLOGINWINDOW_H
