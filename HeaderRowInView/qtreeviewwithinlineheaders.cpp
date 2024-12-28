#include "qtreeviewwithinlineheaders.h"
#include "enums.h"
#include "EnumConverters.h"

void QTreeViewWithInlineHeaders::setModel(QAbstractItemModel *model) {
    QTreeView::setModel(model);
    setupSpans();
}

void QTreeViewWithInlineHeaders::setupSpans() {
    auto model = this->model();

    for (auto row = 0, rows = model->rowCount(); row < rows; ++row) {
        auto index = model->index(row, 0);
        if (index.data(+GlobalRole::IsTitleRow).toBool()) {
            setFirstColumnSpanned(row, QModelIndex(), true);
        }
    }
}
