#ifndef GROUPSTRATEGYFILEEXTENSIONS_H
#define GROUPSTRATEGYFILEEXTENSIONS_H

#include "groupstrategy.h"

class GroupStrategyFileExtensions : public GroupStrategy
{
public:
    GroupStrategyFileExtensions() = default;

    GroupStrategyResult use(QString path) final;
};

#endif // GROUPSTRATEGYFILEEXTENSIONS_H
