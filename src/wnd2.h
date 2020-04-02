#ifndef WND2_H
#define WND2_H

#include <QWidget>

namespace Ui {
class Wnd2;
}

class Wnd2 : public QWidget
{
    Q_OBJECT

public:
    explicit Wnd2(QWidget *parent = nullptr);
    ~Wnd2();

public:
    void updateText();

private slots:
    void on_btn_process_clicked();

private:
    Ui::Wnd2 *ui;
};

#endif // WND2_H
