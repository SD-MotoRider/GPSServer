#ifndef GPSSERVER_H
#define GPSSERVER_H

// MIT License
//
// Copyright (c) 2018 Michael Simpson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include "GPSThread.h"

#include <QTcpServer>

class GPSServer :
	public QTcpServer
{
	Q_OBJECT

public:
	static GPSServer* getInstance()
	{
		static GPSServer* instance(Q_NULLPTR);
		if (instance == Q_NULLPTR)
		{
			instance = new GPSServer;
		}

		return instance;
	}

	void stop(void);

protected:
	void incomingConnection(qintptr socketDescriptor) override;

private:
	GPSServer();
	GPSServer(GPSServer const&) = delete;
	void operator=(GPSServer const&) = delete;

	GPSThreads					_gpsThreads;
};

#endif // GPSSERVER_H

