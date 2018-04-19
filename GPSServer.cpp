#include "GPSServer.h"

#include "ServerConst.h"

GPSServer::GPSServer() :
	QTcpServer(Q_NULLPTR)
{
	listen(QHostAddress::Any, kGPSPort);
}

void GPSServer::incomingConnection
(
	qintptr socketDescriptor
)
{
	GPSThread* gpsThread = new GPSThread(socketDescriptor);
	connect(gpsThread, &QThread::finished, gpsThread, &QObject::deleteLater);
	gpsThread->start();

	_gpsThreads.push_back(gpsThread);
}

void GPSServer::stop()
{
	if (isListening())
	{
		auto gpsThread = _gpsThreads.begin();
		while (gpsThread != _gpsThreads.end())
		{
			(*gpsThread)->stop();

			gpsThread++;
		}


	}
}
