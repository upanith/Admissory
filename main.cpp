#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QtCore/QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QString>

QString getBIOSserial(void){

    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"wmic bios get SerialNumber");
    p.waitForStarted();
    p.waitForFinished();

    QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());

    strTemp = strTemp.trimmed();

    QString BIOSserial = strTemp.right(10);

    return BIOSserial;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString BIOSSerial = getBIOSserial();

    qDebug() << BIOSSerial;

    QPixmap pixmap(":/images/splash.png");
    QSplashScreen splash(pixmap, Qt::FramelessWindowHint);
    splash.show();

    QCoreApplication::processEvents();

    MainWindow w;
    QTimer::singleShot(5000,&splash,&QWidget::close);
    QTimer::singleShot(5000,&w,SLOT(show()));

    return a.exec();
}

