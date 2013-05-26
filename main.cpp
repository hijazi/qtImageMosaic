#include <QtGui/QApplication>
#include "mainwindow.h"
#include "imagehandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    ImageHandler imageHandler;
    imageHandler.Run();

//    w.show();

    return a.exec();
}
