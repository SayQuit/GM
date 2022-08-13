#ifndef NPC_H
#define NPC_H
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsScene>
#include "dialog.h"
#include "game.h"
#include <GameEnum.h>
#include <QDebug>
#include <QKeyEvent>

//*********************************************************************************************//
//*********************************************************************************************//
//********************坐标类，记录角色的坐标***************************//
//*********************************************************************************************//
//*********************************************************************************************//

class Coordinate
{
private:

    int x;//坐标x坐标
    int y;//坐标y坐标
public:
    Coordinate();
    Coordinate(int x_in,int y_in);

    //获取和设置x、y坐标的位置
    int getx();
    int gety();
    bool setx(int x_in);
    bool sety(int y_in);

    Coordinate* getCoord();//获取该坐标
    bool setCoord(int x_in,int y_in);//设置该坐标

};

//*********************************************************************************************//
//*********************************************************************************************//
//********************npc类，继承于QGraphicsPixmapItem，各种npc都继承于此***************************//
//*********************************************************************************************//
//*********************************************************************************************//


class Npc:public QGraphicsPixmapItem
{
public:
    Npc();
    virtual ~Npc()=0;//纯虚析构函数，npc析构时不会运行该函数

    Dialog *getDialog();//获取角色对话
    virtual bool Action()=0;//与角色对话时的行为，纯虚函数
    bool showDialog(QKeyEvent *event);//展示角色对话
    bool hideDialog();//隐藏角色对话
    QString getNpcAddress(ROLE NpcID);//获取npc图像路径
    Coordinate DifferNpcPos(ROLE CoordID);//获取不同npc的地址
protected:
    QPixmap *NpcPixmap;//npc的pixmap
    Coordinate *Position;//npc的位置
    Dialog *Dialogue;//npc的对话
    ROLE NpcID; //npc名字

    //ROLE thisRole;




};


class Donne:public Npc      //npc邓恩，主角所在警察小队的队长
{
public:
    Donne();
    Donne(QWidget *parent,QGraphicsScene *Scene);
    bool Action();


};
class Mirror:public Npc
{
public:
    Mirror();
    Mirror(QWidget *parent,QGraphicsScene *Scene,Data *UserData);
    bool Action();
    void show_Game();//游戏的接口，从这里进入小游戏

private:
    Game *MirrorGame;//包含的游戏类

};


#endif // NPC_H


