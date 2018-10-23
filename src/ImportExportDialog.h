#ifndef IMPORTEXPORTDIALOG_H
#define IMPORTEXPORTDIALOG_H

#include <QDialog>

namespace Ui {
class ImportExportDialog;
}

class ImportExportDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImportExportDialog(QWidget *parent = 0);
    ~ImportExportDialog();

private slots:
    void on_btnImport_FlightLogs_clicked();

    void on_btnExport_FlightLogs_clicked();

    void on_btnImport_VideoRecordings_clicked();

    void on_btnImport_GeoData_clicked();

private:
    Ui::ImportExportDialog *ui;
};

#endif // IMPORTEXPORTDIALOG_H
