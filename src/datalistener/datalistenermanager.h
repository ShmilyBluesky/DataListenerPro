#ifndef DATALISTENERMANAGER_H
#define DATALISTENERMANAGER_H

#include <QObject>
#include <QList>

class IDataListener;

struct Info4DataListener
{
    int iDataType; // 数据类型
    IDataListener *interface; // 接口

    Info4DataListener(int tmpDataType = 0, IDataListener *tmpIDataListener = 0) :
        iDataType(tmpDataType),
        interface(tmpIDataListener)
    {
    }
};

class DataListenerManager : public QObject
{
    Q_OBJECT
public:
    explicit DataListenerManager(QObject *parent = nullptr);
    ~DataListenerManager();

    // 注册数据
    bool regListener(int iDataType, IDataListener *interface);
    // 通知
    void notify(int iDataType);

signals:

public slots:

private:
    QList<Info4DataListener> m_listDataListeners; // 数据
};

// 声明全局定义
extern DataListenerManager gDataListenerMgr;

#endif // DATALISTENERMANAGER_H
