#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QTimer>
#include <myscene.h>
#include "settingwidget.h"
#include "lookitem.h"
#include "numscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionPrimary_triggered();
    void on_actionNew_triggered();
    void on_actionMid_triggered();
    void on_actionSenior_triggered();
    void on_actionExit_triggered();
    void on_actionCustom_triggered();
    void customSet(int w,int h,int m);//自定义
    void on_actionAbout_triggered();

public slots:
    void initializeGame(){scene->initialize();}
    void startTimer(){restTime=999;timer->start(1000);updateTimeScene();}
    void updateTimeScene();//更新剩余时间
    void updateMineScene();

private:
    Ui::MainWindow *ui;
    settingWidget *setting;
    myScene *scene;
    QGraphicsScene *lookScene;//表情
    numScene *timeScene;//剩余时间(从999秒倒计时)
    numScene *mineScene;//剩余地雷数(全部地雷数-已标记数)
    QTimer *timer;//计时器
    int restTime=999;//剩余秒数
};
#endif // MAINWINDOW_H
