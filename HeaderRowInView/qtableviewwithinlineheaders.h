#ifndef QTABLEVIEWWITHINLINEHEADERS_H
#define QTABLEVIEWWITHINLINEHEADERS_H

#include <QTableView>

class QTableViewWithInlineHeaders : public QTableView
{
    Q_OBJECT
public:
    using QTableView::QTableView;
    void setModel(QAbstractItemModel *model) override;

private:
    void setupSpans();
};

#endif // QTABLEVIEWWITHINLINEHEADERS_H
