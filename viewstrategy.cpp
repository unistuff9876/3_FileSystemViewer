#include "viewstrategy.h"

#include <QDebug>

QLocale ViewStrategy::qLocaleForSizeFormatting;

QString ViewStrategy::percentageQString(double curValue, double total)
{
    double curPercentage = (curValue / total) * 100.0;

    if (total == 0) {
        return "--";
    }
    if (curPercentage < 1 && curPercentage > 0) {
        return "<1%";
    }
    else if (curPercentage != 100 && curPercentage > 99.9) {
        return ">99.9%";
    }
    else {
        //2 digits after decimal
        return QString::number(curPercentage, 'g', 3) + "%";
    }
}

ViewStrategy::~ViewStrategy()
{
    delete m_widget;
}

QWidget *ViewStrategy::widget()
{
    return m_widget;
}
