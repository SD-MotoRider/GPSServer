#include "GPSServer.h"

#include "GPSThread.h"

GPSServer::GPSServer() :
	QTcpServer(Q_NULLPTR)
{
	listen(QHostAddress::Any, );
}

void GPSServer::incomingConnection
(
	qintptr socketDescriptor
)
{
	GPSThread* gpsThread = new GPSThread(socketDescriptor);
	connect(gpsThread, &QThread::finished, gpsThread, &QObject::deleteLater);
	gpsThread->start();
}
