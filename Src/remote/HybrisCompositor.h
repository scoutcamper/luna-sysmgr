/* @@@LICENSE
*
* Copyright (c) 2013 Simon Busch <morphis@gravedo.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* LICENSE@@@ */

#ifndef HYBRISBUFFERSERVER_H_
#define HYBRISBUFFERSERVER_H_

#include <QString>
#include <QSocketNotifier>
#include <QString>

class HybrisCompositor : public QObject
{
	Q_OBJECT
public:
	static HybrisCompositor* instance();

private Q_SLOTS:
	void onNewConnection();
	void onClientDisconnected();

private:
	HybrisCompositor();
	~HybrisCompositor();

	void setup();

	QString m_socketPath;
	int m_socketFd;
	QSocketNotifier *m_socketNotifier;
};

class HybrisCompositorRemoteClient : public QObject
{
	Q_OBJECT
public:
	HybrisCompositorRemoteClient(HybrisCompositor *parent, int socketDescriptor);

Q_SIGNALS:
	void disconnected();

private Q_SLOTS:
	void onIncomingData();

private:
	HybrisCompositor *m_parent;
	int m_socketFd;
	QSocketNotifier *m_socketNotifier;
};

#endif /* HYBRISBUFFERSERVER_H_ */
