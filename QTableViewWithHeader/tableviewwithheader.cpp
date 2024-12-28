#include "tableviewwithheader.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include <QScrollBar>
#include <QPalette>
#include <QLabel>

TableViewWithHeader::TableViewWithHeader(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    m_headerArea = new QWidget;
    layout->addWidget(m_headerArea);

    m_tableView = new QTableView;
    layout->addWidget(m_tableView);

    connect(m_tableView->horizontalHeader(), &QHeaderView::sectionResized, this, &TableViewWithHeader::processLayoutTitles);
    connect(m_tableView->horizontalScrollBar(), &QScrollBar::valueChanged, this, &TableViewWithHeader::processLayoutTitles);
}

void TableViewWithHeader::addHeader(HeaderSpanInfo spanInfo) {
    auto label = new QLabel(spanInfo.title, m_headerArea);

    label->setAutoFillBackground(true);
    //Palette setup
    QPalette pal;
    pal.setBrush(QPalette::Window, spanInfo.color);
    label->setPalette(pal);

    //Font setup
    QFont font = label->font();
    font.setPointSize(font.pointSize() * 1.5);
    label->setFont(font);

    label->setAlignment(Qt::AlignCenter);

    spanInfo.label = label;
    m_headerSpanInfo.append(std::move(spanInfo));
    processLayoutTitles();
}

QTableView *TableViewWithHeader::operator->() const {
    return m_tableView;
}

void TableViewWithHeader::setModel(QAbstractItemModel *model) {
    m_tableView->setModel(model);
}

void TableViewWithHeader::processLayoutTitles()
{
    auto *header = m_tableView->horizontalHeader();
    const int offset = m_tableView->viewport()->x() - 1;

    int height = 0;
    for (const HeaderSpanInfo &info: std::as_const(m_headerSpanInfo)) {
        height = std::max(height, info.label->height());
    }
    for (const HeaderSpanInfo &info: std::as_const(m_headerSpanInfo)) {
        const int start = header->sectionViewportPosition(info.firstColumn);
        const int end = header->sectionViewportPosition(info.lastColum) + header->sectionSize(info.lastColum);
        info.label->move(start + offset, 0);
        info.label->resize(end - start, height);
    }
    m_headerArea->setFixedHeight(height);
}
