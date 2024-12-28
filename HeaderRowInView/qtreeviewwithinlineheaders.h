#ifndef QTREEVIEWWITHINLINEHEADERS_H
#define QTREEVIEWWITHINLINEHEADERS_H

#include <QTreeView>

class QTreeViewWithInlineHeaders : public QTreeView
{
    Q_OBJECT
public:
    using QTreeView::QTreeView;
    void setModel(QAbstractItemModel *model) override;
private:
    void setupSpans();
};

#endif // QTREEVIEWWITHINLINEHEADERS_H
