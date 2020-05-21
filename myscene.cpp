#include "myscene.h"

myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{

    this->initialize();
}

void myScene::initialize(){

    this->clear();

    for(int i=0;i<MAX_WIDTH;++i){//状态初始化
        for(int j=0;j<MAX_HEIGHT;++j){
            this->items[i][j]=new myItem();
            this->items[i][j]->setPos(i*20,j*20);
            this->items[i][j]->setRowAndCol(i,j);
            connect(this->items[i][j],&myItem::stepOnMine,this,&myScene::gameOver);
            connect(this->items[i][j],&myItem::stepOnNone,this,&myScene::findBlocks);
            connect(this->items[i][j],&myItem::doubleClickSignal,this,&myScene::doubleClick);
            connect(this->items[i][j],&myItem::checkSignal,this,&myScene::checkGame);
            connect(this->items[i][j],&myItem::markChangedSignal,this,&myScene::markChange);
            this->items[i][j]->setMine(false);
            this->items[i][j]->setSweeped(false);
            this->items[i][j]->setNumOfMines(0);
            this->items[i][j]->setMark(false);
            this->items[i][j]->setStepMine(false);
        }
    }


    for(int i=0;i<width;++i){//显示大小
        for(int j=0;j<height;++j){
            this->addItem(this->items[i][j]);
        }
    }
    int mineNum=0;
    while(mineNum<this->mine){//设置地雷位置
        int x=QRandomGenerator::global()->bounded(width);
        int y=QRandomGenerator::global()->bounded(height);
        if(!this->items[x][y]->isMine()){
            this->items[x][y]->setMine(true);
            mineNum++;
        }
    }

    int nx,ny,numOfMines;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};

    for(int i=0;i<width;++i){//设置周围砖块数
        for(int j=0;j<height;++j){
            numOfMines=0;

            for(int k=0;k<8;++k){
                nx=i+dx[k];
                ny=j+dy[k];
                if(0<=nx&&nx<width&&0<=ny&&ny<height){
                    if(this->items[nx][ny]->isMine())numOfMines++;
                }
            }
            this->items[i][j]->setNumOfMines(numOfMines);
        }
    }

    for(int i=0;i<width;++i)
        for(int j=0;j<height;++j)
            items[i][j]->updateItem();

    emit reinitializeSignal(0);
}

void myScene::gameOver(int row,int col){
    qDebug()<<"游戏结束！";
    emit gameOverSignal(1);

    for(int i=0;i<width;++i){//显示其余的地雷
        for(int j=0;j<height;++j){
            if(items[i][j]->isMine()&&!(i==row&&j==col)){
                items[i][j]->setSweeped(true);
                items[i][j]->updateItem();
            }
        }
    }

    QMessageBox msg;
    msg.setIcon(QMessageBox::Critical);
    msg.setText("游戏结束！");
    msg.setStandardButtons(QMessageBox::Yes);
    msg.exec();

    qDebug()<<"重新初始化";

    initialize();
}

void myScene::findBlocks(int row,int col){
    items[row][col]->setSweeped(true);//模拟点击

    if(items[row][col]->getNumOfMines()!=0)return;//有数字的方块就不展开了

    int nx,ny;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;++i){
        nx=row+dx[i];
        ny=col+dy[i];
        if(0<=nx&&nx<width&&0<=ny&&ny<height&&!items[nx][ny]->isSweeped()){
            findBlocks(nx,ny);
        }
    }
}

void myScene::doubleClick(int row,int col){
    int flags=0,mines=0;
    int nx,ny;
    int dx[8]={-1,-1,-1,0,0,1,1,1};
    int dy[8]={-1,0,1,-1,1,-1,0,1};
    for(int i=0;i<8;++i){
        nx=row+dx[i];
        ny=col+dy[i];
        if(0<=nx&&nx<width&&0<=ny&&ny<height&&!items[nx][ny]->isSweeped()){
            if(items[nx][ny]->isMine())mines++;
            if(items[nx][ny]->isMarked())flags++;

        }
    }
    if(flags==mines){
        for(int i=0;i<8;++i){
            nx=row+dx[i];
            ny=col+dy[i];
            if(0<=nx&&nx<width&&0<=ny&&ny<height&&!items[nx][ny]->isSweeped()&&!items[nx][ny]->isMarked()){
                  items[nx][ny]->simulateLeftClick();
            }
        }
    }
}

void myScene::checkGame(){
    int block=0;
    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            if(items[i][j]->isSweeped()&&!items[i][j]->isMine()){
                block++;
            }
        }
    }
    if(block==(height*width-mine)){
        emit victorySignal(2);

        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("恭喜你成功了！");
        msg.setStandardButtons(QMessageBox::Yes);
        msg.exec();

       // for(int i=0;i<MAX_WIDTH;++i)
         //   for(int j=0;j<MAX_HEIGHT;++j)
           //     delete items[i][j];

        initialize();
    }
}

int myScene::getRestMines(){
    int marks=0;
    for(int i=0;i<width;++i){
        for(int j=0;j<height;++j){
            if(!items[i][j]->isSweeped()&&items[i][j]->isMarked())marks++;
        }
    }
    return mine-marks;
}


