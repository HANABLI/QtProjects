#include "checkableheaderviewadapter.h"
#include "depechemodel.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>
#include <QTableView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto top = new QWidget;

    auto table = new QTableView;
    auto model = new DepecheModel(table);

    table->setModel(model);
    auto headerview = new CheckableHeaderViewAdapter(Qt::Vertical);
    headerview->setSectionsClickable(true);
    headerview->setHighlightSections(true);
    table->setVerticalHeader(headerview);

    auto vLay = new QVBoxLayout(top);
    vLay->addWidget(table);

    auto hLay = new QHBoxLayout;
    vLay->addLayout(hLay);
    hLay->addStretch(1);

    auto button = new QPushButton("Play Songs");
    hLay->addWidget(button);

    QObject::connect(button, &QPushButton::clicked, [model] {
        for (auto &album: model->selectedAlbums()) {
            qDebug().noquote() << "♫♫" << album << "♪♪";
        }
    });

    top->resize(800, 400);
    top->show();

    return a.exec();
}
