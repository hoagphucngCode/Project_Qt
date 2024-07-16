#ifndef COMMON_H
#define COMMON_H

#include <QQmlApplicationEngine>

#define LOG qInfo() << __FUNCTION__ << ":"

void configQmlContextBefore(QQmlApplicationEngine &engine);
void configQmlContextAfter(QQmlApplicationEngine &engine);

#endif // !COMMON_H
