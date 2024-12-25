#include "headersortingadapter.h"
#include <QApplication>
#include <QHeaderView>
#include <QEvent>
#include <QMouseEvent>
#include <QTableView>


HeaderSortingAdapter::HeaderSortingAdapter(QTableView *table) : QObject(table), m_tableView(table)
{

    QHeaderView *headerVeiw = table->horizontalHeader();
    headerVeiw->setSortIndicator(-1, Qt::AscendingOrder);
    headerVeiw->setSortIndicatorShown(false);
    headerVeiw->viewport()->installEventFilter(this);
}

bool HeaderSortingAdapter::eventFilter(QObject *watched, QEvent *event) {
    auto mouseEvent = [event] { return static_cast<QMouseEvent *>(event);};
    auto headerView = [this] { return m_tableView->horizontalHeader();};

    switch (event->type()) {
    case QEvent::MouseButtonPress: {
        if (mouseEvent()->button() != Qt::LeftButton)
            return false;
        m_pressPosition = mouseEvent()->pos();
        break;
    }
    case QEvent::MouseMove: {
        if (mouseEvent()->buttons().testFlag(Qt::LeftButton)
            && (m_pressPosition - mouseEvent()->pos()).manhattanLength()
            > qApp->startDragDistance()) {
            m_isMoving = headerView()->sectionsMovable();
        }
        break;
    }
    case QEvent::MouseButtonRelease: {
        if (mouseEvent()->button() != Qt::LeftButton)
            return false;

        if (m_isMoving) {
            m_isMoving = false;
            return false;
        }

        auto header = headerView();
        const int indexAtCursor = header->logicalIndexAt(mouseEvent()->pos());

        if (indexAtCursor == -1)
            ;
        else if (header->sortIndicatorSection() != indexAtCursor) {
            header->setSortIndicator(indexAtCursor, Qt::AscendingOrder);
            header->setSortIndicatorShown(true);
        } else if (header->sortIndicatorOrder() == Qt::AscendingOrder) {
            header->setSortIndicator(indexAtCursor, Qt::DescendingOrder);
        } else {
            header->setSortIndicator(-1, Qt::AscendingOrder);
            header->setSortIndicatorShown(false);
        }
        emit header->sectionClicked(indexAtCursor);
        return true;
    }
    default:
        break;
    }
    return false;
}


