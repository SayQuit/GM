#include "klein.h"
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QDebug>


//************************************************//
//****************实际用的是第三个********************//
//************************************************//
Klein::Klein()
{
    this->KleinPixmap.load(":/Klein/kleinS2.png");
    this->kleinData=new Data;
}
Klein::Klein(QGraphicsScene *Scene)
{
    this->KleinPixmap.load(":/Klein/kleinS2.png");
    this->kleinData=new Data;
    Scene->addItem(this);
}
Klein::Klein(QGraphicsScene *Scene,int x,int y)
{
    this->setPos(x,y);
    Scene->addItem(this);
    this->KleinPixmap.load(":/Klein/kleinS2.png");
    this->kleinData=new Data;
}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//









//************************************************//
//******角色前进需要的3个函数，不清楚实际作用*******//
//************************************************//

void Klein::advance(int phase)
{

    //qDebug()<<this->x()<<" "<<this->y();
}
QRectF Klein::boundingRect() const
{
    return QRectF(0,0,10,10);
}
void Klein::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   painter->drawPixmap(0,0,this->KleinPixmap);
}

//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//








//************************************************//
//******角色行走的逻辑函数*******************************//
//************************************************//



//***********设置前进后新的位置***********//
void Klein::Actionchoose(int ListChoose, char DirectionChoose)
{
    int MTSleftrignt=0,MTSupdown=0;
    if(DirectionChoose=='W')
    {
       MTSupdown=-3;
    }
    else if(DirectionChoose=='S')
    {
       MTSupdown=3;
    }
    else if(DirectionChoose=='A')
    {
       MTSleftrignt=-3;
    }
    else if(DirectionChoose=='D')
    {
       MTSleftrignt=3;
    }
    this->setPos(mapToScene(MTSleftrignt,MTSupdown));
    this->kleinmove(ListChoose,DirectionChoose);
}



/************选择前进方向的主角图片************/
void Klein::kleinmove(int ListChoose, char DirectionChoose)
{
    if(DirectionChoose=='W')
    {
        this->kleinmove_up(ListChoose);
    }
    else if(DirectionChoose=='S')
    {
        this->kleinmove_down(ListChoose);
    }
    else if(DirectionChoose=='A')
    {
        this->kleinmove_left(ListChoose);
    }
    else if(DirectionChoose=='D')
    {
        this->kleinmove_right(ListChoose);
    }

}

//************下面四个函数是前进时形成动画的函数，主要是通过该处的选择不同图片以及外部的Qtimer来实现*****************/
void Klein::kleinmove_up(int ListChoose)
{
    QStringList Actlist;
    Actlist

            <<":/Klein/kleinW1.png"
            <<":/Klein/kleinW2.png"
            <<":/Klein/kleinW3.png";
    this->KleinPixmap.load(Actlist[ListChoose]);
}
void Klein::kleinmove_down(int ListChoose)
{
    QStringList Actlist;
    Actlist

            <<":/Klein/kleinS1.png"
            <<":/Klein/kleinS2.png"
            <<":/Klein/kleinS3.png";
    this->KleinPixmap.load(Actlist[ListChoose]);


}void Klein::kleinmove_left(int ListChoose)
{
    QStringList Actlist;
    Actlist

            <<":/Klein/kleinA1.png"
            <<":/Klein/kleinA2.png"
            <<":/Klein/kleinA3.png";
    this->KleinPixmap.load(Actlist[ListChoose]);


}
void Klein::kleinmove_right(int ListChoose)
{
    QStringList Actlist;
    Actlist

            <<":/Klein/kleinD1.png"
            <<":/Klein/kleinD2.png"
            <<":/Klein/kleinD3.png";
    this->KleinPixmap.load(Actlist[ListChoose]);


}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//







//********主角阅读函数*******//
bool Klein::kleinreading(int ID)
{

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));

    this->kleinData->updateKnowledge(qrand() % 5);//这里使用随机数操作
    return 1;
}



//************资料卡的展示、关闭和设置父类**************//
bool Klein::DatacardShow()
{
    this->kleinData->getDataCard()->show();
    return true;
}
bool Klein::DatacardHide()
{
    this->kleinData->getDataCard()->hide();
    return true;

}
bool Klein::DataCard_setParent(QWidget *parent)
{
    this->kleinData->getDataCard()->setParent(parent);//这里可以改成data里面设置吗？？
    return true;

}



//**********获取角色数据，以后可能改成直接获取这个角色类**************//
Data *Klein::getKleinData()
{
    return this->kleinData;
}
