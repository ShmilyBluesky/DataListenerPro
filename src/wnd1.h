#ifndef WND1_H
#define WND1_H

#include <QWidget>

namespace Ui {
class Wnd1;
}

class Wnd1 : public QWidget
{
    Q_OBJECT

public:
    explicit Wnd1(QWidget *parent = nullptr);
    ~Wnd1();

public:
    void updateText();

private slots:
    void on_btn_process_clicked();

private:
    Ui::Wnd1 *ui;
};

#endif // WND1_H
