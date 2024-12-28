#ifndef CHECKABLEHEADERVIEWADAPTER_H
#define CHECKABLEHEADERVIEWADAPTER_H
/**
 * @file CheckableHeaderViewAdapter.h
 *
 * @brief This declares a QHeaderView replacemement that supports check boxes in headers.
 *        The model must support Qt::CheckStateRole role in headerData and setHeaderData
 *
 * @copyright © 2024 by Hatem Nabli
 **/
#pragma once
#include <QHeaderView>


    class CheckableHeaderViewAdapter : public QHeaderView
    {
        Q_OBJECT
    public:
        using QHeaderView::QHeaderView;
        /**
         * @brief sizeHint
         * @return
         */
        QSize sizeHint() const override;

    protected:
        /**
         * @brief paintSection
         * @param peinter
         * @param rect
         * @param logicIndex
         */
        void paintSection(QPainter *peinter, const QRect &rect, int logicIndex) const override;
        /**
         * @brief mousePressEvent
         * @param event
         */
        void mousePressEvent(QMouseEvent *event) override;

    private:
        /**
         * @brief checkBoxSize
         * @return
         */
        int checkBoxSize() const;
        /**
         * @brief checkBoxAreaWidth
         * @return
         */
        int checkBoxAreaWidth() const;
    };

#endif // CHECKABLEHEADERVIEWADAPTER_H
