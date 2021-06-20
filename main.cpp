#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap("C:/Users/upani/Desktop/Admissory.png");
    QSplashScreen splash(pixmap, Qt::FramelessWindowHint);
    splash.show();

    QCoreApplication::processEvents();

    MainWindow w;
    QTimer::singleShot(5000,&splash,&QWidget::close);
    QTimer::singleShot(5000,&w,SLOT(show()));

    return a.exec();
}
