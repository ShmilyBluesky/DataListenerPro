#include "wnd1.h"
#include "ui_wnd1.h"
#include "global_datalistener_define.h"
#include "idatalistener.h"
#include <QDateTime>

// 定义处理函数
inline void accept4Wnd1(int iDataType, Wnd1* wnd)
{
    if (wnd && DLDT_Data2 == iDataType)
        wnd->updateText();
}
// 定义类"DL4Wnd1"及其全局对象"gdl4Wnd1"
DEFINE_DATA_LISTENER(Wnd1)


Wnd1::Wnd1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wnd1)
{
    ui->setupUi(this);

    // 注册
    gdl4Wnd1.regListener(DLDT_Data2, this);
}

Wnd1::~Wnd1()
{
    delete ui;
}

void Wnd1::updateText()
{
    ui->lbl_res->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
}

void Wnd1::on_btn_process_clicked()
{
    // 通知数据更新
    gdl4Wnd1.notify(DLDT_Data1);
}
