#include "hostslistmodel.h"

#include <QColor>
#include <QDebug>
#include <QFont>
#include <QFile>
#include <QCoreApplication>
#include <QSize>

HostsListModel::HostsListModel(QObject *parent)
    : QAbstractListModel(parent)
    , m_conf("sdkmanager", "SDK manager")
{
    QFile file(QCoreApplication::applicationDirPath()+ "/" "hosts.txt");
    if(file.exists() && file.open(QIODevice::ReadOnly))
    {
        unsigned i=0;
        while(!file.atEnd())
        {
            pairType pair(file.readLine().trimmed(),
                          m_conf.contains(QString("key%1").arg(i)) ?
                              m_conf.value(QString("key%1").arg(i)).toBool() : true);
            m_hosts.push_back(pair);
            i++;
        }
        file.close();
    }
}

int HostsListModel::rowCount(const QModelIndex & /* parent */) const
{
    return m_hosts.size();
}
QVariant HostsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
            return QVariant();
    switch(role){
    case Qt::DisplayRole:
       return m_hosts.at(index.row()).first;
    case Qt::FontRole:
    {
        QFont font;
        font.setBold(m_hosts.at(index.row()).second ? true : false);
        return font;
    }
    case Qt::SizeHintRole:
    {
        QSize defSize;
        defSize.setHeight(30);
        return defSize;
    }
    case Qt::CheckStateRole:
        return m_hosts.at(index.row()).second ?
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
    if(value.toBool())
        m_hosts[index.row()].second = true;
    else
        m_hosts[index.row()].second = false;
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

void HostsListModel::onExit()
{
    for(int i=0; i<m_hosts.size(); i++)
    {
        m_conf.setValue(QString("key%1").arg(i), m_hosts.at(i).second);
    }
}

void HostsListModel::onClickText(const QModelIndex &index)
{
    bool curState = this->itemData(index).value(Qt::CheckStateRole).toBool();
    setData(index, !curState, Qt::CheckStateRole);
}

QString HostsListModel::getHosts()
{
    QString str = "";
    for(int i=0; i<m_hosts.size(); i++)
    {
        if(m_hosts.at(i).second)
        {
            str+=m_hosts.at(i).first+" ";
        }
    }
    return str;
}
