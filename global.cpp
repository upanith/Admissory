#include "global.h"
#include <QString>
#include <QProcess>

QString Global::getBIOSserial(void){

    QProcess p(0);
    p.start("cmd", QStringList()<<"/c"<<"wmic bios get SerialNumber");
    p.waitForStarted();
    p.waitForFinished();

    QString strTemp = QString::fromLocal8Bit(p.readAllStandardOutput());

    strTemp = strTemp.trimmed();

    QString BIOSserial = strTemp.right(10);

    return BIOSserial;
}
