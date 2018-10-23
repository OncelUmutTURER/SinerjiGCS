#include "ProgressiveFileCopier.h"
#include <QThread>
#include <QFileInfo>
#include <QDir>

ProgressiveFileCopier::ProgressiveFileCopier(QObject *parent) : QThread(parent), mMinimum(0), mMaximum(0), mProgress(0)
{

}

void ProgressiveFileCopier::copy(const QString &sourceFolder, const QString &destFolder)
{
    if (isRunning())
        return;

    mSourceFolder = sourceFolder;
    mDestFolder = destFolder;
    mFileList = getFolderContents(sourceFolder);
    mMinimum = 0;
    mMaximum = fileSize(sourceFolder, mFileList);
    emit minimumChanged(mMinimum);
    emit maximumChanged(mMaximum);

    start();
}

double ProgressiveFileCopier::minimum() const
{
    return mMinimum;
}

double ProgressiveFileCopier::maximum() const
{
    return mMaximum;
}

double ProgressiveFileCopier::progress() const
{
    return mProgress;
}

QStringList ProgressiveFileCopier::getFolderContents(const QString &sourceFolder) const
{
    QStringList fileList;
    std::function<bool(const QString&, const QString&)> folderContents;
    folderContents = [&](const QString &sourceFolder, const QString &destFolder)->bool {
        QDir sourceDir(sourceFolder);

        if (!sourceDir.exists())
            return false;

        foreach (const QFileInfo &fileInfo, sourceDir.entryInfoList(QDir::NoDotAndDotDot | QDir::NoSymLinks | QDir::Dirs | QDir::Files)) {
            QString srcFilePath = fileInfo.filePath();
            QString dstFilePath = destFolder.isEmpty() ? fileInfo.fileName() : destFolder + QDir::separator() + fileInfo.fileName();
            if (fileInfo.isDir()) {
                if (!folderContents(srcFilePath, dstFilePath))
                    return false;
            } else {
                fileList.append(dstFilePath);
            }
        }

        return true;
    };

    if (folderContents(sourceFolder, QString()))
        return fileList;
    else
        return QStringList();
}

qint64 ProgressiveFileCopier::fileSize(const QString &sourceFolder, const QStringList &fileList)
{
    qint64 total = 0;

    foreach (const QString &fileName, fileList)
        total += QFile(sourceFolder + QDir::separator() + fileName).size();

    return total;
}

void ProgressiveFileCopier::copyFiles()
{
    qint64 bufferSize = 4194304;
    QByteArray buffer = NULL;
    mProgress = 0;
    emit progressChanged(mProgress);

    foreach (const QString &fileName, mFileList) {
        QString srcFilePath = mSourceFolder + QDir::separator() + fileName;
        QString dstFilePath = mDestFolder + QDir::separator() + fileName;
        QFile srcFile(srcFilePath);
        QFile dstFile(dstFilePath);

        QFileInfo dst(dstFilePath);
        QDir dir = dst.dir();
        if (!dst.isDir() && !dir.exists())
            dir.mkpath(dir.path());

        if (srcFile.open(QIODevice::ReadOnly) && dstFile.open(QIODevice::WriteOnly)) {
            qint64 internalBufferSize = srcFile.size() < bufferSize ? srcFile.size() : bufferSize;

            while (1) {
                buffer = srcFile.read(internalBufferSize);
                if (buffer.isEmpty())
                    break;

                dstFile.write(buffer);
                mProgress += internalBufferSize;
                emit progressChanged(mProgress);
            }
            srcFile.close();
            dstFile.close();
        }
    }
    emit progressChanged(mMaximum);
}

void ProgressiveFileCopier::run()
{
    copyFiles();
}



