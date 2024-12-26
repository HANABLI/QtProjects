#include "ColumnContentResizeAdapter.h"
#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStandardItemModel model(5, 3);
    QStringList randomData{"Depeche Mode", "The Cure", "Naiive",      "Nitzer Ebb", "Erasure",
                           "Virkelyst",    "16",       "Hjørring",    "Denmark",    "The Earth",
                           "Laura",        "Louise",   "Anne Helene", "Jesper",     "NAN"};

    for (int col = 0; col < model.columnCount(); ++col) {
        for (int row = 0; row < model.rowCount(); ++row) {
            QString txt = randomData.at((row + col * 5) % randomData.length());
            model.setData(model.index(row, col), txt);
        }
    }

    model.setHeaderData(0, Qt::Horizontal, QStringList{"Bands from the 80th", "80th bands", "Bands", "80th"});
    model.setHeaderData(1, Qt::Horizontal, QStringList{"My patch of the universe", "Here I live", "Location"});
    model.setHeaderData(2, Qt::Horizontal, QStringList{"My Family", "Just us", "us", "-"});

    QTableView table;
    new ColumnContentResizeAdapter(&table);
    table.setModel(&model);
    table.show();
    return a.exec();
}
