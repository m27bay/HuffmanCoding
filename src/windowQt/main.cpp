#include "Mainwindow.hpp"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //
    int sizeX = app.desktop()->width();
    int sizeY = app.desktop()->height();
    if(sizeX > 1920) {
        sizeX = 1920;
    }
    if(sizeY > 1080) {
        sizeY = 1080;
    }

    //
    MainWindow w;
    w.setWidth(sizeX); w.setHeight(sizeY);
    w.setup();
    w.show();
    return app.exec();
}
