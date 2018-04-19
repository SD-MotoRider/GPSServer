#include "GPSWindow.h"

#include <QMenu>

GPSWindow::GPSWindow(QWidget *parent) :
	QDialog(parent),
	_systemTrayIcon(Q_NULLPTR)
{
	setupUi(this);

	_showUiAction = new QAction(tr("Show UI"), this);
	_quitAction = new QAction(tr("Quit"), this);

	_systemTrayMenu = new QMenu(this);
	_systemTrayMenu->addAction(_showUiAction);
	_systemTrayMenu->addSeparator();
	_systemTrayMenu->addAction(_quitAction);

	_systemTrayIcon = new QSystemTrayIcon(this);
	_systemTrayIcon->setIcon(QIcon(":/resources/GPSServer.png"));
	_systemTrayIcon->setContextMenu(_systemTrayMenu);
	_systemTrayIcon->show();
}

GPSWindow::~GPSWindow()
{
}
