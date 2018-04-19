#include "GPSWindow.h"

GPSWindow::GPSWindow(QWidget *parent) :
	QDialog(parent),
	_systemTrayIcon(Q_NULLPTR)
{
	setupUi(this);

	_systemTrayMenu = new QMenu(this);
	_systemTrayMenu->addAction(minimizeAction);
	_systemTrayMenu->addAction(maximizeAction);
	_systemTrayMenu->addAction(restoreAction);
	_systemTrayMenu->addSeparator();
	_systemTrayMenu->addAction(quitAction);

	_systemTrayIcon = new QSystemTrayIcon(this);
	_systemTrayIcon->setContextMenu(_systemTrayMenu);
}

GPSWindow::~GPSWindow()
{
}
