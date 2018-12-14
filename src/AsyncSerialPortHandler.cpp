#include "AsyncSerialPortHandler.h"

#include <QCoreApplication>

AsyncSerialPortHandler::AsyncSerialPortHandler(QSerialPort *serialPort, bool isWriter, QObject *parent) :
    QObject(parent),
    m_serialPort(serialPort),
    m_standardOutput(stdout)
{
    m_isWriter = isWriter;

    if(m_isWriter)      //writer mode
    {
        m_timer.setSingleShot(true);
        connect(m_serialPort, &QSerialPort::bytesWritten, this, &AsyncSerialPortHandler::handleBytesWritten);
        connect(m_serialPort, &QSerialPort::errorOccurred, this, &AsyncSerialPortHandler::handleError);
        connect(&m_timer, &QTimer::timeout, this, &AsyncSerialPortHandler::handleTimeout);

    }
    else                //reader mode
    {
        connect(m_serialPort, &QSerialPort::readyRead, this, &AsyncSerialPortHandler::handleReadyRead);
        connect(m_serialPort, &QSerialPort::errorOccurred, this, &AsyncSerialPortHandler::handleError);
        connect(&m_timer, &QTimer::timeout, this, &AsyncSerialPortHandler::handleTimeout);

        m_timer.start(5000);
    }
}

void AsyncSerialPortHandler::handleReadyRead()
{
    m_readData.append(m_serialPort->readAll());

    if (!m_timer.isActive())
        m_timer.start(5000);
}

void AsyncSerialPortHandler::handleBytesWritten(qint64 bytes)
{
    m_bytesWritten += bytes;
    if (m_bytesWritten == m_writeData.size()) {
        m_bytesWritten = 0;
        m_standardOutput << QObject::tr("Data successfully sent to port %1")
                            .arg(m_serialPort->portName()) << endl;
        QCoreApplication::quit();
    }
}

void AsyncSerialPortHandler::handleTimeout()
{
    if(m_isWriter)
    {
        m_standardOutput << QObject::tr("Operation timed out for port %1, error: %2")
                               .arg(m_serialPort->portName())
                               .arg(m_serialPort->errorString())
                         << endl;

       QCoreApplication::exit(1);
    }
    else
    {
        if (m_readData.isEmpty()) {
            m_standardOutput << QObject::tr("No data was currently available "
                                            "for reading from port %1")
                                .arg(m_serialPort->portName())
                             << endl;
        } else {
            m_standardOutput << QObject::tr("Data successfully received from port %1")
                                .arg(m_serialPort->portName())
                             << endl;
            m_standardOutput << m_readData << endl;
        }

        QCoreApplication::quit();
    }
}

void AsyncSerialPortHandler::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    }
    else if (serialPortError == QSerialPort::WriteError) {
        m_standardOutput << QObject::tr("An I/O error occurred while writing"
                                        " the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    }
}

void AsyncSerialPortHandler::write(const QByteArray &writeData)
{
    m_writeData = writeData;

    const qint64 bytesWritten = m_serialPort->write(writeData);

    if (bytesWritten == -1) {
        m_standardOutput << QObject::tr("Failed to write the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    } else if (bytesWritten != m_writeData.size()) {
        m_standardOutput << QObject::tr("Failed to write all the data to port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << endl;
        QCoreApplication::exit(1);
    }

    m_timer.start(5000);
}
