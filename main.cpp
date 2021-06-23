#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QtCore/QCoreApplication>
#include <QProcess>
#include <QDebug>
#include <QString>
#include "global.h"
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString BIOS_Serial = Global::getBIOSserial();

    //qDebug() << BIOS_Serial;

    QPixmap pixmap(":/images/splash.png");
    QSplashScreen splash(pixmap, Qt::FramelessWindowHint);
    splash.show();

    QCoreApplication::processEvents();

    if(BIOS_Serial=="CND5260X1D") {
        MainWindow w;
        w.setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowSystemMenuHint | Qt::WindowCloseButtonHint);
        QTimer::singleShot(2500,&splash,&QWidget::close);
        QTimer::singleShot(2000,&w,SLOT(show()));

        return a.exec();
    } else {
        QMessageBox msg;
        msg.setText("This PC is not athorized to run this application!");
        msg.setInformativeText("Please contact developer for more information.");
        msg.setIcon(QMessageBox::Critical);
        msg.exec();
        a.quit();
    }
}

