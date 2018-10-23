#ifndef PROGRESSIVEFILECOPIER_H
#define PROGRESSIVEFILECOPIER_H

#include <QThread>

class ProgressiveFileCopier : public QThread
{
    Q_OBJECT
    Q_PROPERTY(double minimum READ minimum NOTIFY minimumChanged)
    Q_PROPERTY(double maximum READ maximum NOTIFY maximumChanged)
    Q_PROPERTY(double progress READ progress NOTIFY progressChanged)

public:
    ProgressiveFileCopier(QObject *parent = nullptr);

    Q_INVOKABLE void copy(const QString &sourceFolder, const QString &destFolder);
    double minimum() const;
    double maximum() const;
    double progress() const;

signals:
    void minimumChanged(double minimum);
    void maximumChanged(double maximum);
    void progressChanged(double value);

private:
    QStringList getFolderContents(const QString &sourceFolder) const;
    qint64 fileSize(const QString &sourceFolder, const QStringList &fileList);
    void copyFiles();

    virtual void run() Q_DECL_OVERRIDE;

    QString mSourceFolder;
    QString mDestFolder;
    QStringList mFileList;
    double mMinimum;
    double mMaximum;
    double mProgress;
};

#endif // PROGRESSIVEFILECOPIER_H
