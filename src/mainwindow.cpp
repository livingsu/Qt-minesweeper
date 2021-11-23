#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->scene=new myScene;
    this->lookScene=new QGraphicsScene;
    this->mineScene=new numScene;
    this->timeScene=new numScene;
    this->timer=new QTimer;

    //设置剩余时间和剩余地雷显示
    connect(this->scene,&myScene::reinitializeSignal,this,&MainWindow::startTimer);
    connect(this->timer,&QTimer::timeout,this,&MainWindow::updateTimeScene);
    this->ui->graphicsView_time->setScene(this->timeScene);
    this->ui->graphicsView_mines->setScene(this->mineScene);
    connect(this->scene,&myScene::markChangedSignal,this,&MainWindow::updateMineScene);
    connect(this->scene,&myScene::reinitializeSignal,this,&MainWindow::updateMineScene);

    //设置表情
    lookItem *lItem=new lookItem;
    this->lookScene->addItem(lItem);
    connect(lItem,&lookItem::restart,this,&MainWindow::initializeGame);
    connect(this->scene,&myScene::victorySignal,lItem,&lookItem::setLook);
    connect(this->scene,&myScene::gameOverSignal,lItem,&lookItem::setLook);
    connect(this->scene,&myScene::reinitializeSignal,lItem,&lookItem::setLook);
    this->ui->graphicsView_look->setScene(this->lookScene);

    //自定义菜单
    this->setting=new settingWidget;
    this->setting->hide();

    this->ui->graphicsView->setScene(this->scene);
    this->ui->graphicsView->setGeometry(0,30,100,100);
    //去掉滚动框
    this->ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView_time->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView_time->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView_mines->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->ui->graphicsView_mines->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //初始大小为9*9,10
    on_actionPrimary_triggered();

    connect(this->setting,&settingWidget::cancelSignal,this,&MainWindow::show);
    connect(this->setting,&settingWidget::yesSignal,this,&MainWindow::customSet);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_actionNew_triggered()
{
    this->scene->initialize();
}
void MainWindow::on_actionPrimary_triggered()
{
    customSet(9,9,10);
}
void MainWindow::on_actionMid_triggered()
{
    customSet(16,16,40);
}

void MainWindow::on_actionSenior_triggered()
{
    customSet(30,16,99);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionCustom_triggered()
{
    this->hide();
    this->setting->show();
}

void MainWindow::customSet(int w,int h,int m){
    this->show();
    //设置表情,剩余时间,剩余地雷
    updateMineScene();

    this->ui->graphicsView_mines->setGeometry(0,0,60,30);
    this->ui->graphicsView_time->setGeometry(20*w+5-60,0,60,30);
    this->ui->graphicsView_look->setGeometry((20*w+5)/2-15,0,30,30);
    //设置地图
    this->scene->setMap(w,h,m);
    this->scene->initialize();
    this->setFixedSize(20*w+5,20*h+5+50);

    this->ui->graphicsView->setFixedSize(20*w+5,20*h+5);
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox msg;
    msg.setWindowTitle(QObject::tr("About"));
    msg.setText(QObject::tr("Simulate the Minesweeper game that comes with the Windows.<br />Developer: livingsu<br />qq:1753843140"));
    msg.exec();
}

void MainWindow::updateTimeScene(){
    this->timeScene->setNumer(restTime);

    if(restTime==0){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setWindowTitle(":(");
        msg.setText(QObject::tr("Time is up! The game is over!"));
        msg.setStandardButtons(QMessageBox::Ok);
        msg.exec();

        this->scene->initialize();
    }else restTime--;
}

void MainWindow::updateMineScene(){
    qDebug()<<"Mines left:"<<this->scene->getRestMines();

    this->mineScene->setNumer(this->scene->getRestMines());
}
