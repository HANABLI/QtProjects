#include "columncontentresizeadapter.h"
#include <QTableView>
#include <QTreeView>
#include <QHeaderView>

ColumnContentResizeAdapter::ColumnContentResizeAdapter(QTableView *tableView) : QAbstractTableModel(tableView)
{
    m_headerView = tableView->horizontalHeader();
    QMetaObject::invokeMethod(this, &ColumnContentResizeAdapter::initialize, Qt::QueuedConnection);
}

ColumnContentResizeAdapter::ColumnContentResizeAdapter(QTreeView *treeView) : QAbstractTableModel(treeView)
{
    m_headerView = treeView->header();
    QMetaObject::invokeMethod(this, &ColumnContentResizeAdapter::initialize, Qt::QueuedConnection);
}

int ColumnContentResizeAdapter::rowCount(const QModelIndex &index) const
{
    return 0;
}

int ColumnContentResizeAdapter::columnCount(const QModelIndex &index) const
{
    Q_ASSERT(!index.isValid());
    Q_UNUSED(index);
    if (!m_sourceModel)
        return 0;
    else
        return m_sourceModel->columnCount();
}

QVariant ColumnContentResizeAdapter::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (!m_sourceModel) {
        return {};
    }

    const QStringList myList = m_sourceModel->headerData(section, orientation, Qt::DisplayRole).toStringList();

    if (role == Qt::DisplayRole) {
        const auto font =
            m_sourceModel->headerData(section, orientation, Qt::FontRole).value<QFont>();
        for (const auto &headerText : myList) {
            const int width = QFontMetrics(font).boundingRect(headerText).width();
            if (width < m_headerView->sectionSize(section) - 10)
                return headerText;
        }

        if (!myList.empty())
            return myList.last();
    } else if (role == Qt::ToolTipRole) {
        QString fullText;
        if (!myList.isEmpty()) {
            fullText = myList.first();
        }
        const QString modelToolTip =
            m_sourceModel->headerData(section, orientation, Qt::ToolTipRole).toString();

        if (headerData(section, orientation, Qt::DisplayRole).toString() != fullText || !modelToolTip.isEmpty()) {
            QString toolTip;
            if (!fullText.isEmpty())
                toolTip = QString("<b>%1</b>").arg(fullText);
            if (!modelToolTip.isEmpty())
                toolTip += QString("<br/>%1").arg(modelToolTip);
            return toolTip;
        }
    }

    return m_sourceModel->headerData(section, orientation, role);
}

QVariant ColumnContentResizeAdapter::data(const QModelIndex &, int ) const {
    return {};
}

void ColumnContentResizeAdapter::initialize()
{
    m_sourceModel = m_headerView->model();

    if (!m_sourceModel) {
        auto view = qobject_cast<QAbstractItemView *>(m_headerView->parentWidget());
        if (view) {
            m_sourceModel = view->model();
        }
    }

    if (!m_sourceModel) {
        return;
    }

    beginResetModel();
    m_headerView->setModel(this);
    endResetModel();

    connect(m_sourceModel, &QAbstractItemModel::modelAboutToBeReset, this, &ColumnContentResizeAdapter::beginResetModel);
    connect(m_sourceModel, &QAbstractItemModel::modelReset, this, &ColumnContentResizeAdapter::endResetModel);

    connect(m_sourceModel, &QAbstractItemModel::columnsAboutToBeInserted, this, &ColumnContentResizeAdapter::beginResetModel);
    connect(m_sourceModel, &QAbstractItemModel::columnsInserted, this, &ColumnContentResizeAdapter::endResetModel);

    connect(m_sourceModel, &QAbstractItemModel::columnsAboutToBeMoved, this, &ColumnContentResizeAdapter::beginResetModel);
    connect(m_sourceModel, &QAbstractItemModel::columnsMoved, this, &ColumnContentResizeAdapter::endResetModel);

    connect(m_sourceModel, &QAbstractItemModel::columnsAboutToBeRemoved, this, &ColumnContentResizeAdapter::beginResetModel);
    connect(m_sourceModel, &QAbstractItemModel::columnsRemoved, this, &ColumnContentResizeAdapter::endResetModel);
}


