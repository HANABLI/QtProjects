#include <QCoreApplication>
#include <QMenu>
#include <QApplication>
#include <QStringList>
#include <QHeaderView>
#include <QTableView>
#include <QRandomGenerator>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>

#include "headersortingadapter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    const QStringList columnNames{"Monkeys", "Apples", "Compilers", "Girls", "Fruits", "Vegetables"};
    constexpr int rowCount = 100;
    constexpr int columnCount = 6;
    
    QRandomGenerator myGenerator;
    
    QStandardItemModel model(rowCount, columnCount);
    for (auto column = 0; column < columnCount; ++column) {
        model.setHeaderData(column, Qt::Horizontal, columnNames.at(column));
        for (auto row = 0; row < rowCount; ++row) {
            model.setData(model.index(row, column), myGenerator.bounded(0, 1000));
            model.setHeaderData(row, Qt::Vertical, QString("row %1").arg(row + 1));
        }
    }

    QSortFilterProxyModel sortProxy;
    sortProxy.setSourceModel(&model);

    QTableView view;
    view.setSortingEnabled(true);
    view.horizontalHeader()->setSectionsMovable(true);
    view.setModel(&sortProxy);

    view.horizontalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    QObject::connect(view.horizontalHeader(), &QHeaderView::customContextMenuRequested, []{
        QMenu menu;
        menu.addAction("Amazing");
        menu.addAction("Cool stuff!");
        menu.exec(QCursor::pos());
    });

    HeaderSortingAdapter adapter(&view);

    view.resize(600, 400);
    view.show();

    return a.exec();
}
