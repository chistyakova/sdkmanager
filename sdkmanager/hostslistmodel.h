#ifndef HOSTSLISTMODEL_H
#define HOSTSLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QModelIndex>
#include <QVariant>
#include <QPair>
#include <QSettings>

typedef QPair<QString, bool> pairType;

class HostsListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    HostsListModel(QObject *parent = 0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    void onExit();
    QString getHosts();
public slots:
    void onClickText(const QModelIndex &index);
private:
    QVector<pairType> m_hosts;
    QSettings         m_conf;
};

#endif // HOSTSLISTMODEL_H
