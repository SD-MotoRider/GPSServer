#include "GPSWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	GPSWindow w;
	w.show();

	GPSServer gpsServer;

	return a.exec();
}
