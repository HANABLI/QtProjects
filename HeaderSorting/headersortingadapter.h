#ifndef HEADERSORTINGADAPTER_H
#define HEADERSORTINGADAPTER_H

#include <QObject>
#include <QPoint>
#include <memory>

class QTableView;

class HeaderSortingAdapter : public QObject
{
    Q_OBJECT
public:
    HeaderSortingAdapter(QTableView *table);
    bool eventFilter(QObject *watched, QEvent *event) override;


private:
    /**
     * @brief m_tableView
     */
    QTableView *m_tableView = nullptr;
    /**
     * @brief m_pressPosition
     */
    QPoint m_pressPosition;
    /**
     * @brief m_isMoving
     */
    bool m_isMoving = false;

};

#endif // HEADERSORTINGADAPTER_H
