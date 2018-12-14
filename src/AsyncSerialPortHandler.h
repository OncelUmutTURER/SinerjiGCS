#ifndef ASYNCSERIALPORTHANDLER_H
#define ASYNCSERIALPORTHANDLER_H

#include <QObject>

#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <QTimer>

class AsyncSerialPortHandler : public QObject
{
    Q_OBJECT

public:
    explicit AsyncSerialPortHandler(QSerialPort *serialPort, bool isWriter, QObject *parent = nullptr);
    void write(const QByteArray &writeData);

signals:

public slots:

private slots:
    void handleReadyRead();
    void handleBytesWritten(qint64 bytes);
    void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;
    QByteArray m_writeData;
    QTextStream m_standardOutput;
    qint64 m_bytesWritten = 0;
    QTimer m_timer;
    bool m_isWriter;

};

#endif // ASYNCSERIALPORTHANDLER_H
