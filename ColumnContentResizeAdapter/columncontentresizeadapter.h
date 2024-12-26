#ifndef COLUMNCONTENTRESIZEADAPTER_H
#define COLUMNCONTENTRESIZEADAPTER_H
/**
  * @file columncontentresizeadapter.h
  * 
  * This file contains the definition of the ColumnContentResizeAdapter class
  * needed to adapt the contetnt of a column to its size.
  *
  * 
  */
#pragma once
#include <QAbstractTableModel>
class QTableView;
class QTreeView;
class QHeaderView;


class ColumnContentResizeAdapter : public QAbstractTableModel
{
    Q_OBJECT
    //Constructor
public:
    explicit ColumnContentResizeAdapter(QTableView *tableView = nullptr);
    explicit ColumnContentResizeAdapter(QTreeView *treeView = nullptr);

    // Methods
public:
    int rowCount(const QModelIndex &index) const override;
    int columnCount(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    static QString headerDataToString(const QVariant &variant);

private slots:
    /**
     * @brief inittialize
     * This method is invoked asynchronously as the model might not be set
     * at the time the constructor is called.
     */
    void initialize();

private:
    QHeaderView *m_headerView = nullptr;
    QAbstractItemModel *m_sourceModel = nullptr;
};

#endif // COLUMNCONTENTRESIZEADAPTER_H
