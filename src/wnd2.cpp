#include "wnd2.h"
#include "ui_wnd2.h"
#include "global_datalistener_define.h"
#include "idatalistener.h"
#include <QDateTime>

// 定义处理函数
inline void accept4Wnd2(int iDataType, Wnd2* wnd)
{
    if (wnd && DLDT_Data1 == iDataType)
        wnd->updateText();
}
// 定义类"DL4Wnd2"及其全局对象"gdl4Wnd2"
DEFINE_DATA_LISTENER(Wnd2)


Wnd2::Wnd2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Wnd2)
{
    ui->setupUi(this);

    // 注册
    gdl4Wnd2.regListener(DLDT_Data1, this);
}

Wnd2::~Wnd2()
{
    delete ui;
}

void Wnd2::updateText()
{
    ui->lbl_res->setText(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz"));
}

void Wnd2::on_btn_process_clicked()
{
    // 通知数据更新
    gdl4Wnd2.notify(DLDT_Data2);
}
