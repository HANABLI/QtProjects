#include <QApplication>
#include <QVBoxLayout>
#include <QTableView>
#include <QTextEdit>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    auto top = std::make_shared<QWidget>();
    auto tableView = std::make_shared<QTableView>();
    auto textEdit = std::make_shared<QTextEdit>();
    textEdit->setText("This edit is needed to show the table in a layout ");

    auto layout = std::make_shared<QVBoxLayout>(top.get());
    layout->addWidget(tableView.get());
    layout->addWidget(textEdit.get());
    top->resize(800, 800);

    constexpr int rows = 10;
    constexpr int columns = 5;
    QStandardItemModel model(rows, columns);
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            model.setItem(row, column, std::make_unique<QStandardItem>(QString("(%1, %2)").arg(row).arg(column)).release());
        }
    }
    tableView->setModel(&model);
    auto verticalHeader = tableView->verticalHeader();
    auto horizontalHeader = tableView->horizontalHeader();

    if (false) {
        // this is haow to stretch last column
        horizontalHeader->setStretchLastSection(true);

        // this is have no sense, but we got rid of the empty space
        verticalHeader->setStretchLastSection(true);
    }

    if (true) {
        // Stretching other columns not just the last one

        for (int row = 0; row < rows; ++row) {
            verticalHeader->setSectionResizeMode(row, QHeaderView::Stretch);
            for (int column = 0; column < columns; ++column) {
                horizontalHeader->setSectionResizeMode(column, QHeaderView::Stretch);
                model.item(row, column)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            }
        }

        // horizontalHeader->setSectionResizeMode(2, QHeaderView::Stretch);
        // horizontalHeader->setSectionResizeMode(3, QHeaderView::ResizeToContents);
    }

    if (false) {
        // compress columns.
        horizontalHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
    }

    if (false) {
        // compress rows.
        verticalHeader->setSectionResizeMode(QHeaderView::ResizeToContents);
    }

    if (false) {
        // Resizing to content initally, but still allowing the columns to be resized later.
        horizontalHeader->setResizeContentsPrecision(-1);
        for (int column = 0; column < columns; ++column) {
            tableView->resizeColumnToContents(column);
        }
        horizontalHeader->setStretchLastSection(true);
    }

    if (true) {
        // Fix the size of the view so it can show without scrollbars
        //tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        //tableView->setSizePolicy({QSizePolicy::Preferred, QSizePolicy::Fixed});

        auto timer = new QTimer;
        timer->setInterval(2000);
        QObject::connect(timer, &QTimer::timeout, [&] {
            model.setRowCount(model.rowCount() + 1);
            auto row = model.rowCount() - 1;
            QEventLoop loop;
            verticalHeader->setSectionResizeMode(row, QHeaderView::Stretch);
            for (int column = 0; column < columns; ++column) {
                horizontalHeader->setSectionResizeMode(column, QHeaderView::Stretch);
                model.setItem(row, column, std::make_unique<QStandardItem>(QString("(%1, %2)").arg(row).arg(column)).release());
                model.item(row, column)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
                QCoreApplication::processEvents();
            }
            loop.quit();

        });
        timer->start();
    }

    top->show();
    return a.exec();
}
