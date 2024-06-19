#ifndef VIEWSTRATEGY_H
#define VIEWSTRATEGY_H

#include <QWidget>
#include <QStandardItemModel>

#include "groupstrategyresult.h"

#include <QLocale>

class ViewStrategy
{
protected:
    QWidget *m_widget;

    static QLocale qLocaleForSizeFormatting;

    QString percentageQString(double curValue, double total);

public:
    virtual ~ViewStrategy();

    QWidget *widget();

    virtual void adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result) = 0;

};

#endif // VIEWSTRATEGY_H
