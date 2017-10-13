#include <QApplication>
#include <QQmlApplicationEngine>

#include <cvprocessor.h>
#include <cvcanvas.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<CVProcessor>("kr.jseo.dsm", 1, 0, "CVProcessor");
    qmlRegisterType<CVCanvas>("kr.jseo.dsm", 1, 0, "CVCanvas");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
