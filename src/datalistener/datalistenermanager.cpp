#include "datalistenermanager.h"
#include "idatalistener.h"

// 全局定义
DataListenerManager gDataListenerMgr;

DataListenerManager::DataListenerManager(QObject *parent) :
    QObject(parent)
{

}

DataListenerManager::~DataListenerManager()
{

}

bool DataListenerManager::regListener(int iDataType, IDataListener *interface)
{
    if (0 == interface)
        return false;

    foreach (const Info4DataListener& info, m_listDataListeners)
    {
        if (info.iDataType == iDataType && info.interface == interface)
            return false;
    }

    Info4DataListener info(iDataType, interface);
    m_listDataListeners.push_back(info);
}

void DataListenerManager::notify(int iDataType)
{
    foreach (const Info4DataListener& info, m_listDataListeners)
    {
        if (info.iDataType == iDataType)
            info.interface->accept(iDataType);
    }
}
