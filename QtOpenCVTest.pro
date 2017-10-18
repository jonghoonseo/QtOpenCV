TEMPLATE = app

QT += qml quick widgets gui

CONFIG += c++11

SOURCES += main.cpp \
    cvprocessor.cpp \
    cvcanvas.cpp \
    utils.cpp

RESOURCES += qml.qrc
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    cvprocessor.h \
    cvcanvas.h \
    utils.h

unix{

    # Unix Configuration

    CONFIG += link_pkgconfig
    PKGCONFIG += opencv

#    defineTest(deployOpenCV){}

}
