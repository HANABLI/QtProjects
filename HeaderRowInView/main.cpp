#include <QApplication>
#include "depechemodel.h"
#include "qtableviewwithinlineheaders.h"
#include "qtreeviewwithinlineheaders.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto model = new DepecheModel();
    auto table = new QTableViewWithInlineHeaders;
    auto tree = new QTreeViewWithInlineHeaders;
    table->setModel(model);
    table->resize(1000, 600);
    table->show();

    tree->setModel(model);
    tree->resize(1000, 600);
    tree->show();
    return a.exec();
}
