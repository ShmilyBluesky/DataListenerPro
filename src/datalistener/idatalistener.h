#ifndef IDATALISTENER_H
#define IDATALISTENER_H

#include <QHash>
#include "datalistenermanager.h"

#define MYDEFINE(arg1, arg2) arg1 + arg2 \
    + arg1 + arg2

// 接口类
class IDataListener
{
public:
    // 构造函数
    IDataListener();
    // 析构函数
    virtual ~IDataListener();

    // 注册数据
    bool regListener(int iDataType, IDataListener *interface = 0);
    // 接收通知
    virtual void accept(int iDataType);
    // 通知
    void notify(int iDataType);
};

/*******************************************************************************
   定义listener
   使用方法如下：
        // 定义处理函数
        inline void accept4Wnd(int iDataType, Wnd* wnd)
        {
            if (wnd && DLDT_Data2 == iDataType)
            {
            }
        }
        // 定义类"DL4Wnd"及其全局对象"gdl4Wnd"
        DEFINE_DATA_LISTENER(Wnd)
        // 注册
        gdl4Wnd.regListener(1, this);
        // 通知数据更新
        gdl4Wnd.notify(1);
*******************************************************************************/
#define DEFINE_DATA_LISTENER(arg1) \
class DL4##arg1 : public IDataListener \
{ \
public: \
    DL4##arg1() : m_obj(0) {} \
    ~DL4##arg1() {} \
    void regListener(int iDataType, arg1 *obj) \
    { \
        m_obj = obj; \
        IDataListener::regListener(iDataType); \
    } \
    void accept(int iDataType) \
    { \
        accept4##arg1(iDataType, m_obj); \
    } \
private: \
    bool regListener(int iDataType, IDataListener *interface = 0); \
public: \
    arg1 *m_obj; \
}; \
DL4##arg1 gdl4##arg1;

#endif // IDATALISTENER_H
