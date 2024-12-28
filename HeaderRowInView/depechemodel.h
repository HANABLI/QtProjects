#ifndef DEPECHEMODEL_H
#define DEPECHEMODEL_H

#pragma once
#include <QAbstractListModel>

class DepecheModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit DepecheModel(QObject *parent = nullptr);

    enum class Column {
        Album,
        Year,
        RecordLabel,
        CD,
        CS,
        LP,
        DCC,
        MD,
        download,
        UK,
        AUS,
        AUT,
        FRA,
        GER,
        ITA,
        NLD,
        SWE,
        SWI,
        US,
        COLUMNCOUNT
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    struct Data
    {
        QString album;
        int year;
        QString recordLabel;
        bool CD;
        bool CS;
        bool LP;
        bool DCC;
        bool MD;
        bool download;
        int UK;
        int AUS;
        int AUT;
        int FRA;
        int GER;
        int ITA;
        int NLD;
        int SWE;
        int SWI;
        int US;
    };
    QVector<Data> m_data;
    QVector<bool> m_selected;
};

#endif // DEPECHEMODEL_H
