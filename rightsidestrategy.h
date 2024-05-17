#ifndef RIGHTSIDESTRATEGY_H
#define RIGHTSIDESTRATEGY_H

#include <QString>
#include <QtCharts/QAbstractSeries>
#include <QAbstractItemView>
#include <QMainWindow>

using namespace QtCharts;

class RightSideStrategy
{
public:
    enum VIEW_OR_SERIES {
        VIEW,
        SERIES,
        BLANK
    };

protected:
    VIEW_OR_SERIES m_viewOrSeries;
    QAbstractSeries *m_series = nullptr;
    QAbstractItemView *m_view = nullptr;

public:
    VIEW_OR_SERIES viewOrSeries();
    QAbstractSeries* series();
    QAbstractItemView* view();

    RightSideStrategy() = default;
    ~RightSideStrategy();

/*public slots:
    void getApplied(QMainWindow *mainWindow);*/
};

#endif // RIGHTSIDESTRATEGY_H
