#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "uncover.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Uncover u("/Users/sani/workspace/qtquick/catena/catene.txt");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("u", &u);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
