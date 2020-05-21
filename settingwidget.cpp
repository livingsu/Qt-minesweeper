#include "settingwidget.h"
#include "ui_settingwidget.h"

settingWidget::settingWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::settingWidget)
{
    ui->setupUi(this);

}

settingWidget::~settingWidget()
{
    delete ui;
}

void settingWidget::on_btn_cancel_clicked()
{
    this->hide();
    emit cancelSignal();
}

void settingWidget::on_btn_yes_clicked()
{
    this->hide();
    qDebug()<<"setting:"<<ui->spinBox_w->value()<<","<<ui->spinBox_h->value()<<","<<ui->spinBox_m->value();


    emit yesSignal(ui->spinBox_w->value(),ui->spinBox_h->value(),ui->spinBox_m->value());
}

void settingWidget::on_spinBox_h_valueChanged(int arg1)
{
    setMaxMineLabel();
}

void settingWidget::on_spinBox_w_valueChanged(const QString &arg1)
{
    setMaxMineLabel();
}

void settingWidget::setMaxMineLabel(){
    QString str="雷数(10~";
    str+=QString::number(ui->spinBox_w->value()*ui->spinBox_h->value()-1);
    str+=")(M):";
    this->ui->label_m->setText(str);
    this->ui->spinBox_m->setMaximum(ui->spinBox_w->value()*ui->spinBox_h->value()-1);
}
