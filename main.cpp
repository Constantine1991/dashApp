#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "serialport.h"
#include "radialbar.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<SerialPort>("SerialPortLib", 1, 0, "SerialPort");
    qmlRegisterType<RadialBar>("RadialBarLib", 1, 0, "RadialBar");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}