#ifndef TABLEVIEWWITHHEADER_H
#define TABLEVIEWWITHHEADER_H

#pragma once

#include <QTableView>
class QLabel;

class TableViewWithHeader : public QWidget
{
    Q_OBJECT
public:
    TableViewWithHeader(QWidget *parent = nullptr);

    class HeaderSpanInfo
    {
    public:
        int firstColumn;
        int lastColum;
        QString title;
        QColor color;
    private:
        QLabel *label;
        friend class TableViewWithHeader;
    };
    void addHeader(HeaderSpanInfo info);

    // is this a good idea?! Requeres you to write (*view)->
    QTableView *operator->() const;

    // Alternative add key methods
    void setModel(QAbstractItemModel *model);
private:
    void processLayoutTitles();

private:
    QWidget *m_headerArea = nullptr;
    QTableView *m_tableView = nullptr;
    QVector<HeaderSpanInfo> m_headerSpanInfo;
};

#endif // TABLEVIEWWITHHEADER_H
