#include "playwindow.h"
#include <QPalette>
#include <QPixmap>
#include <widget.h>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QGraphicsObject>
#include <QObject>
#include <QMouseEvent>
#include <QLabel>
#include <qlabel.h>

#define PlaywindowSize 1440,900
#ifndef SCREEN_X
#define SCREEN_X 1440
#endif
#ifndef SCREEN_Y
#define SCREEN_Y 900
#endif

#define Movespeed 20
#ifndef PlaywindowSize_x
#define PlaywindowSize_x 16
#endif
#ifndef PlaywindowSize_y
#define PlaywindowSize_y 15
#endif

#ifndef MAPARRAT_X
#define MAPARRAT_X 16
#endif
#ifndef MAPARRAT_Y
#define MAPARRAT_Y 15
#endif


int frequency=6;
int action=0;

Playwindow::Playwindow()
{





    this->EastArea=new QGraphicsScene;
    this->kleinM=new Klein(this->EastArea);
    this->WinMap=new Map(this,this->EastArea,this->kleinM->getKleinData());
    this->kleinM->setPos(this->WinMap->getx(),this->WinMap->gety());



    this->setScene(this->EastArea);
    this->setSceneRect(0,0,PlaywindowSize);
    this->setBackgroundBrush(QBrush(QPixmap(this->WinMap->getAddress()).scaled(PlaywindowSize)));




    this->WinButton=new Button(this);





    //****************//
    //******要改******//
    //****************//
    this->HitWall=new QLabel("撞墙",this);
    this->HitWall->setStyleSheet("color:red;");
    this->HitWall->hide();
    //****************//
    //****************//
    //****************//

    this->ConnectRunning();
    this->setButtonParent();


}

void Playwindow::keyPressEvent(QKeyEvent *event)
{
    //qDebug()<<this->x()<<" "<<this->y()<<endl;

    this->PlayerRunning(event);

    //***************************改*********************************//
    this->Reading(event);//***************************改*********************************//
    //***************************改*********************************//



}

void Playwindow::PlayerRunning(QKeyEvent *event)
{

    //***************************改*********************************//
    //***************************改*********************************//
    //***************************改*********************************//
    //***************************改*********************************//
    //***************************改*********************************//


    if(this->WinMap->Detect(this->kleinM->x(),this->kleinM->y())==OPENINGMAP)
    {
        this->WinButton->BigMap_show();
    }

    this->KleinCollide(event);

    if(event->key()==Qt::Key_W&&this->HitWall_Judge(0,-5))
    {

        timer=new QTimer;
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(advance()));
        this->kleinM->Actionchoose(action/frequency,'W');
        action++;
        if(action==frequency*3)action=0;
        timer->start(Movespeed);
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(update()));


    }
    else if(event->key()==Qt::Key_S&&this->HitWall_Judge(0,5))
    {
        timer=new QTimer;
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(advance()));
        this->kleinM->Actionchoose(action/frequency,'S');
        action++;
        if(action==frequency*3)action=0;
        timer->start(Movespeed);
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(update()));


    }
    else if(event->key()==Qt::Key_A&&this->HitWall_Judge(-5,0))
    {
        timer=new QTimer;
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(advance()));
        this->kleinM->Actionchoose(action/frequency,'A');
        action++;
        if(action==frequency*3)action=0;
        timer->start(Movespeed);
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(update()));


    }
    else if(event->key()==Qt::Key_D&&this->HitWall_Judge(5,0))
    {
        timer=new QTimer;
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(advance()));
        this->kleinM->Actionchoose(action/frequency,'D');
        action++;
        if(action==frequency*3)action=0;
        timer->start(Movespeed);
        connect(timer,SIGNAL(timeout()),EastArea,SLOT(update()));


    }
}

void::Playwindow::keyReleaseEvent(QKeyEvent *event)
{
    this->PlayerStop(event);
    this->HitWall->hide();
    //this->WinMap->HideNpcDia();
}

void::Playwindow::PlayerStop(QKeyEvent *event)
{

    if(event->key()==Qt::Key_W)
    {

        this->kleinM->kleinmove(1,'W');



    }
    else if(event->key()==Qt::Key_S)
    {

        this->kleinM->kleinmove(1,'S');


    }
    else if(event->key()==Qt::Key_A)
    {

        this->kleinM->kleinmove(1,'A');




    }
    else if(event->key()==Qt::Key_D)
    {

        this->kleinM->kleinmove(1,'D');

    }
}

bool Playwindow::HitWall_Judge(int x_next,int y_next)
{
    int y=(this->kleinM->y()+y_next)*MAPARRAT_Y/SCREEN_Y;
    int x=(this->kleinM->x()+x_next)*MAPARRAT_X/SCREEN_X;
    if(this->WinMap->isZero(x,y))//如果是0
    {

        HitWall->setGeometry(this->kleinM->x(),this->kleinM->y()-70,100,100);
        HitWall->show();

    }

    return !this->WinMap->isZero(x,y);//返回非0

}




bool Playwindow::GotoOtherPlace(Map M)
{
    this->setBackgroundBrush(QBrush(QPixmap(M.getAddress()).scaled(PlaywindowSize)));
    kleinM->setPos(M.getx(),M.gety());
    this->WinButton->BigMap_hide();
    this->update();
    return 1;


}
 bool Playwindow::GotoEastArea()
 {
     this->GotoOtherPlace(this->WinMap->ChangeMap(EASTAREA,this,this->EastArea,this->kleinM->getKleinData()));
     return 1;
 }

 bool Playwindow::OpenMap()
 {
     this->WinButton->BigMap_show();
     return 1;
 }

 bool Playwindow::GotoHome()
 {

     this->GotoOtherPlace(this->WinMap->ChangeMap(MYROOM,this,this->EastArea,this->kleinM->getKleinData()));
     return 1;
 }

 bool Playwindow::GotoPoliceOffice()
 {

     this->GotoOtherPlace(this->WinMap->ChangeMap(POLICEOFFICE,this,this->EastArea,this->kleinM->getKleinData()));

     /******************************************
      *************人物初始化*********************
     *********************************************/
     return 1;
 }


 bool Playwindow::OpenDataCard()
 {
     this->kleinM->DatacardShow();
     return 1;
 }

 bool Playwindow::CloseDataCard()
 {
     this->kleinM->DatacardHide();
     return 1;
 }
 bool Playwindow::CloseMap()
 {
     this->WinButton->BigMap_hide();
     return 1;
 }

 bool Playwindow::Reading(QKeyEvent *event)
 {
     if(event->key()==Qt::Key_R&&this->WinMap->Detect(this->kleinM->x(),this->kleinM->y())==READING)
     {
         if(kleinM->kleinreading(this->WinMap->getID()))
         {

             //this->WinDialog->ShowRead();
             return 1;
         }
     }
     return 0;
 }
 bool Playwindow::setButtonParent()
 {
    this->kleinM->DataCard_setParent(this);
    return true;
 }
 bool Playwindow::KleinCollide(QKeyEvent *event)
 {



     this->WinMap->ShowNpcDia(this->kleinM,event);


     return true;
 }
bool Playwindow::ConnectRunning()
{

    connect(this->WinButton->getMapButton(),&QPushButton::clicked,this,&Playwindow::OpenMap);
    connect(this->WinButton->getHome(),&QPushButton::clicked,this,&Playwindow::GotoHome);
    connect(this->WinButton->getEast_Area(),&QPushButton::clicked,this,&Playwindow::GotoEastArea);
    connect(this->WinButton->getPolice_Office(),&QPushButton::clicked,this,&Playwindow::GotoPoliceOffice);
    connect(this->WinButton->getDataButton(),&QPushButton::clicked,this,&Playwindow::OpenDataCard);
    connect(this->WinButton->getClose_Map(),&QPushButton::clicked,this,&Playwindow::CloseMap);
    connect(this->kleinM->getKleinData()->getClose_Datacard(),&QPushButton::clicked,this,&Playwindow::CloseDataCard);
    return true;
}

