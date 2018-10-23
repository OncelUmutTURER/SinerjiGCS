#include "ImportExportDialog.h"
#include "ui_ImportExportDialog.h"

#include <QFileDialog>
#include <QDebug>

#include "QGCApplication.h"
#include "SettingsManager.h"

#include "ProgressiveFileCopier.h"

ImportExportDialog::ImportExportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImportExportDialog)
{
    ui->setupUi(this);
}

ImportExportDialog::~ImportExportDialog()
{
    delete ui;
}

void ImportExportDialog::on_btnImport_FlightLogs_clicked()
{
    QString destinationPath = qgcApp()->toolbox()->settingsManager()->appSettings()->savePath()->rawValueString();
    qDebug() << "import dir:" << destinationPath;

    QString sourcePath = QFileDialog::getExistingDirectory(this, "Select ApplicationStore Directory To Import", QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug() << "source dir:" << sourcePath;

    ProgressiveFileCopier* cpr = new ProgressiveFileCopier();
    QObject::connect(cpr, &ProgressiveFileCopier::minimumChanged, ui->pBar_ImportExport, &QProgressBar::setMinimum);
    QObject::connect(cpr, &ProgressiveFileCopier::maximumChanged, ui->pBar_ImportExport, &QProgressBar::setMaximum);
    QObject::connect(cpr, &ProgressiveFileCopier::progressChanged, ui->pBar_ImportExport, &QProgressBar::setValue);

    cpr->copy(sourcePath,destinationPath);
}

void ImportExportDialog::on_btnExport_FlightLogs_clicked()
{
    QString destinationPath = QFileDialog::getExistingDirectory(this, "Select Directory To Export Flight Logs", QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug() << "export dir:" << destinationPath;

    QString sourcePath = qgcApp()->toolbox()->settingsManager()->appSettings()->savePath()->rawValueString();
    qDebug() << "source dir:" << sourcePath;

    ProgressiveFileCopier* cpr = new ProgressiveFileCopier();
    QObject::connect(cpr, &ProgressiveFileCopier::minimumChanged, ui->pBar_ImportExport, &QProgressBar::setMinimum);
    QObject::connect(cpr, &ProgressiveFileCopier::maximumChanged, ui->pBar_ImportExport, &QProgressBar::setMaximum);
    QObject::connect(cpr, &ProgressiveFileCopier::progressChanged, ui->pBar_ImportExport, &QProgressBar::setValue);

    cpr->copy(sourcePath,destinationPath);
}

void ImportExportDialog::on_btnImport_VideoRecordings_clicked()
{
    QString destinationPath = qgcApp()->toolbox()->settingsManager()->appSettings()->savePath()->rawValueString() + QDir::separator() + AppSettings::videoDirectory  + QDir::separator() + "DroneVideo";
    qDebug() << "import dir:" << destinationPath;

    QString sourcePath = QFileDialog::getExistingDirectory(this, "Select Directory of Drone Video Recordings for Importing", QDir::homePath(), QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    qDebug() << "source dir:" << sourcePath;

    ProgressiveFileCopier* cpr = new ProgressiveFileCopier();
    QObject::connect(cpr, &ProgressiveFileCopier::minimumChanged, ui->pBar_ImportExport, &QProgressBar::setMinimum);
    QObject::connect(cpr, &ProgressiveFileCopier::maximumChanged, ui->pBar_ImportExport, &QProgressBar::setMaximum);
    QObject::connect(cpr, &ProgressiveFileCopier::progressChanged, ui->pBar_ImportExport, &QProgressBar::setValue);

    cpr->copy(sourcePath,destinationPath);
}

void ImportExportDialog::on_btnImport_GeoData_clicked()
{

}
