#ifndef GROUPSTRATEGY_H
#define GROUPSTRATEGY_H

#include "groupstrategyresult.h"

#include <QDirIterator>
#include <QString>

class GroupStrategy
{
public:
    virtual GroupStrategyResult use(QString path) = 0;
};

#endif // GROUPSTRATEGY_H
