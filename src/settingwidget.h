#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class settingWidget;
}

class settingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit settingWidget(QWidget *parent = nullptr);
    ~settingWidget();
    void setMaxMineLabel();//设置标签显示最大雷数

private slots:

    void on_btn_cancel_clicked();

    void on_btn_yes_clicked();

    void on_spinBox_h_valueChanged(int arg1);

    void on_spinBox_w_valueChanged(const QString &arg1);

signals:
    void cancelSignal();
    void yesSignal(int w,int h,int m);

private:
    Ui::settingWidget *ui;
    int height;
    int width;
    int mine;
};

#endif // SETTINGWIDGET_H
