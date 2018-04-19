#include "GPSThread.h"

#include <QByteArray>
#include <QDataStream>

GPSThread::GPSThread
(
	int socketDescriptor
) :
	_socketDescriptor(socketDescriptor)
{

}

void GPSThread::run()
{
	QTcpSocket tcpSocket;

	if (tcpSocket.setSocketDescriptor(_socketDescriptor))
	{_running = true;

		while (_running)
		{
			QByteArray block;
			QDataStream out(&block, QIODevice::WriteOnly);
			out.setVersion(QDataStream::Qt_4_0);

			tcpSocket.write(block);
			tcpSocket.disconnectFromHost();
			tcpSocket.waitForDisconnected();
		}
	}
	else
	{
		emit error(tcpSocket.error());
	}
}
