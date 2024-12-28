#include "qtableviewwithinlineheaders.h"
#include "enums.h"
#include "EnumConverters.h"

void QTableViewWithInlineHeaders::setModel(QAbstractItemModel *model)
{
    QTableView::setModel(model);
    setupSpans();
}

void QTableViewWithInlineHeaders::setupSpans()
{
    auto model = this->model();
    clearSpans();
    for (int row = 0, rows = model->rowCount(); row < rows; ++row) {
        if (model->index(row, 0).data(+GlobalRole::IsTitleRow).toBool())
            setSpan(row, 0, 1, model->columnCount());
    }
}


