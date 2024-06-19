#include "groupstrategyfileextensions.h"

#include <QMap>
#include <QDebug>

GroupStrategyResult GroupStrategyFileExtensions::use(QString path)
{
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    QMap<QString, qint64> extensionsNamesAndSizeSumsMap;
    qint64 totalFileSize = 0;

    while (it.hasNext()) {
        it.next();
        QFileInfo currentFileInfo = it.fileInfo();

        qint64 currentFileSize = currentFileInfo.size();

        totalFileSize += currentFileSize;
        QString currentExtension = currentFileInfo.suffix();
        currentExtension.push_front("*."); //aware this is slow
        extensionsNamesAndSizeSumsMap[currentExtension] += currentFileSize;
    }

    //all addition done, append *. prefix to extensions
    //would've, time waste now

    return GroupStrategyResult(extensionsNamesAndSizeSumsMap, totalFileSize);
}

/*void GroupStrategyFileExtensions::modifyNameColumnEntry(QString &str)
{
    str.push_front("*.");
}*/
