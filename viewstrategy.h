#ifndef VIEWSTRATEGY_H
#define VIEWSTRATEGY_H

#include <QWidget>

#include "groupstrategyresult.h"

#include "mainwindow.h"

class ViewStrategy
{
public:
    ViewStrategy();

    ~ViewStrategy();

    QWidget *m_widget;

    virtual void setAsCurrent() = 0;
    virtual void unsetAsCurrent() = 0;
    virtual void update(GroupStrategyResult groupStrategyResult) = 0;
};

#endif // VIEWSTRATEGY_H
