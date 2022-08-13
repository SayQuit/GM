#ifndef KLEIN_H
#define KLEIN_H
#include <QPixmap>
#include <QPainter>
#include <QGraphicsItem>
#include <QKeyEvent>
#include<QGraphicsScene>
#include <QWidget>
#include "data.h"
#include <QTime>
#include <QtGlobal>
//*********************************************************************************************//
//*********************************************************************************************//
//********************klein类是玩家类，继承于QGraphicsItem***************************//
//*********************************************************************************************//
//*********************************************************************************************//
class Klein:public QGraphicsItem
{
private:
    QPixmap KleinPixmap; //klein的pixmap头像
    Data *kleinData;  //Klein的数据

public:
    Klein(QGraphicsScene *Scene,int x,int y);
    Klein();
    Klein(QGraphicsScene *Scene);

    void kleinmove_up(int ListChoose); //玩家向上行走
    void kleinmove_down(int ListChoose);//玩家向下行走
    void kleinmove_left(int ListChoose);//玩家向左行走
    void kleinmove_right(int ListChoose);//玩家向右行走
    bool kleinreading(int);//玩家的阅读行为
    void kleinmove(int ListChoose,char DirectionChoose);//玩家行走，向上面四个函数传参



    void advance(int phase);//玩家可以行走的要求的一个函数，不是很明白它的作用
    void Actionchoose(int ListChoose, char DirectionChoose);//通过char类选择不同的方向
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);//绘图函数，不是很明白它的作用
    virtual QRectF boundingRect() const;//不是很明白它的作用..........

    bool DatacardShow();//展示datacard
    bool DatacardHide();//隐藏datacard
    bool DataCard_setParent(QWidget *parent);//设置datacard的父类

    Data *getKleinData();//获取data

};

#endif // KLEIN_H
