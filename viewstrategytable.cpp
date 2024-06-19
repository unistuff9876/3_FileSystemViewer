#include "viewstrategytable.h"

#include "mainwindow.h"

#include <QTableView>
#include <QDebug>

ViewStrategyTable::ViewStrategyTable()
{
    m_widget = new QTableView;
}

void ViewStrategyTable::adaptAndApplyData(QStandardItemModel *model, GroupStrategyResult result)
{
    model->clear();
    //3 cols : name, size, percentage
    model->setColumnCount(3);
    model->setRowCount(result.itemCount());

    for (int row = 0; row < model->rowCount(); ++row) {
        model->setItem(row, 0, new QStandardItem(result.names()[row]));
        model->setItem(row, 1, new QStandardItem
            (ViewStrategy::qLocaleForSizeFormatting.formattedDataSize(result.sizes()[row])));
        model->setItem(row, 2, new QStandardItem(percentageQString(result.sizes()[row], result.totalSize())));
    }

    //setting model
    reinterpret_cast<QTableView*>(m_widget)->setModel(model);
}
