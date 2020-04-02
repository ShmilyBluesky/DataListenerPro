#include "idatalistener.h"

// 构造函数
IDataListener::IDataListener()
{

}

// 析构函数
IDataListener::~IDataListener()
{

}

// 注册数据
bool IDataListener::regListener(int iDataType, IDataListener *interface)
{
    if (0 == interface)
        gDataListenerMgr.regListener(iDataType, this);
    else
        gDataListenerMgr.regListener(iDataType, interface);
}

// 接收通知
void IDataListener::accept(int iDataType)
{
    Q_UNUSED(iDataType)
}

// 通知
void IDataListener::notify(int iDataType)
{
    gDataListenerMgr.notify(iDataType);
}
