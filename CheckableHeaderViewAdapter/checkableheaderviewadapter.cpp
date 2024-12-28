/**
 * @file CheckableHeaderViewAdapter.cpp
 * @brief This is the definition of the cheackable HeaderView.
 *
 * @copyright © 2024 by Hatem Nabli
 **/

#include "checkableheaderviewadapter.h"
#include <QPainter>
#include <QMouseEvent>

namespace {
    static constexpr int margin = 4;
}

void CheckableHeaderViewAdapter::paintSection(QPainter *painter, const QRect &rect, int logicIndex) const
{
    // Paint the background as we later narrow the area the QHeaderView itself paints.
    const QVariant backgroundBrush = model()->headerData(logicIndex, orientation(), Qt::BackgroundRole);

    painter->save();
    QStyleOptionHeader opt;
    initStyleOption(&opt);
    opt.rect = rect;
    if (!backgroundBrush.isNull()) {
        opt.palette.setBrush(QPalette::Button, backgroundBrush.value<QBrush>());
        opt.palette.setBrush(QPalette::Window, backgroundBrush.value<QBrush>());
    }
    style()->drawControl(QStyle::CE_Header, &opt, painter, this);
    painter->restore();

    // paint the section sdjusted to the right
    painter->save();
    QHeaderView::paintSection(painter, rect.adjusted(checkBoxAreaWidth(), 0, 0, 0), logicIndex);
    painter->restore();

    // paint the check box
    QStyleOptionButton option;
    const int size = checkBoxSize();
    option.rect = QRect(rect.left() + margin, rect.top() + (rect.height() - size) / 2, size, size);
    if (model()->headerData(logicIndex, orientation(), Qt::CheckStateRole) == Qt::Checked)
        option.state = QStyle::State_On | QStyle::State_Enabled;
    else
        option.state = QStyle::State_Off | QStyle::State_Enabled;
    style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter);

}

QSize CheckableHeaderViewAdapter::sizeHint() const
{
    return QHeaderView::sizeHint() + QSize(checkBoxAreaWidth(), 0);
}

void CheckableHeaderViewAdapter::mousePressEvent(QMouseEvent *event)
{
    const int index = logicalIndexAt(event->pos());
    if (index == -1) {
        QHeaderView::mousePressEvent(event);
        return;
    }

    if (event->pos().x() > checkBoxAreaWidth()) {
        QHeaderView::mousePressEvent(event);
        return;
    }

    const Qt::CheckState state =
        model()->headerData(index, orientation(), Qt::CheckStateRole).value<Qt::CheckState>();
    model()->setHeaderData(index, orientation(), state == Qt::Checked ? Qt::Unchecked : Qt::Checked, Qt::CheckStateRole);

}

int CheckableHeaderViewAdapter::checkBoxSize() const
{
    return fontMetrics().height();
}

int CheckableHeaderViewAdapter::checkBoxAreaWidth() const
{
    return checkBoxSize() + 2 * margin;
}

