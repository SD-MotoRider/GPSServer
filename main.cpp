#include "GPSWindow.h"
#include "GPSServer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	int result(0);

	QApplication a(argc, argv);

	GPSWindow w;
	w.show();

	GPSServer* gpsServer = GPSServer::getInstance();

	result = a.exec();

	gpsServer->stop();

	return result;
}
