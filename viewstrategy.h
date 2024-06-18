#ifndef VIEWSTRATEGY_H
#define VIEWSTRATEGY_H

#include <QWidget>

#include "groupstrategyresult.h"

#include "mainwindow.h"

class ViewStrategy
{

    QWidget *m_widget;

public:
    virtual ~ViewStrategy();

    QWidget &widget();

    virtual void update(GroupStrategyResult groupStrategyResult) = 0;
};

#endif // VIEWSTRATEGY_H
