#include <QApplication>
#include "depechemodel.h"
#include "EnumConverters.h"
#include "tableviewwithheader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TableViewWithHeader *view = new TableViewWithHeader;
    DepecheModel *model = new DepecheModel;

    (*view)->setModel(model);


        TableViewWithHeader::HeaderSpanInfo info;
        info.firstColumn = +DepecheModel::Column::CD;
        info.lastColum = +DepecheModel::Column::download;
        info.title = "Media Released On";
        info.color = Qt::green;
        view->addHeader(std::move(info));



        TableViewWithHeader::HeaderSpanInfo info1;
        info1.firstColumn = +DepecheModel::Column::UK;
        info1.lastColum = +DepecheModel::Column::US;
        info1.title = "Peak Chart Position";
        info1.color = QColor(Qt::blue).lighter(180);
        view->addHeader(std::move(info1));

    view->resize(1000, 600);
    view->show();
    return a.exec();
}
