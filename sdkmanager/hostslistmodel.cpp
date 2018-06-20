#include "hostslistmodel.h"

#include <QColor>
#include <QDebug>
#include <QFont>

HostsListModel::HostsListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    QStringList strList;
    strList << "monitor" << "mouse" << "keyboard" << "hard disk drive"
                << "graphic card" << "sound card" << "memory" << "motherboard";

    for(int i=0; i<strList.size(); i++)
    {
        QPair<QString, bool> pair(strList.at(i), true);
        hosts.push_back(pair);
    }
}

int HostsListModel::rowCount(const QModelIndex & /* parent */) const
{
    return 8;
}
QVariant HostsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();
    switch(role){
    case Qt::DisplayRole:
       return hosts.at(index.row()).first;
    case Qt::FontRole:
    {
        QFont font;
        font.setBold(hosts.at(index.row()).second ? true : false);
        return font;
    }
    case Qt::CheckStateRole:
        return hosts.at(index.row()).second ?
                    Qt::Checked : Qt::Unchecked;
    default:
        // Вот тут вернул QVartian вместо того что было, видимо предыдущий варинат только для QStringListModel
        return QVariant();// QAbstractListModel::data(index, role);
    }
}

bool HostsListModel::setData(const QModelIndex &index,
                                const QVariant &value, int role){
    qDebug()<<"setData";
    if(!index.isValid() || role != Qt::CheckStateRole)
        return false;

    if(value == Qt::Checked)
        hosts[index.row()].second = true;
    else
        hosts[index.row()].second = false;

    emit dataChanged(index, index);
    return true;
}

Qt::ItemFlags HostsListModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = QAbstractListModel::flags(index);
    if (index.isValid())
            return defaultFlags | Qt::ItemIsUserCheckable;

    return defaultFlags;
}
