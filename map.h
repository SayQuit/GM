#ifndef MAP_H
#define MAP_H

#include<QString>
#include<QPushButton>
#include<QGraphicsItem>
#include"npc.h"
#include"GameEnum.h"
#include"button.h"
#ifndef GAMEENUM_H
#define GAMEENUM_H
#endif
#ifndef MAPHEADER_H
#define MAPHEADER_H
#endif


//*********************************************************************************************//
//*********************************************************************************************//
//********************map类有了地图场景的切换作用***************************//
//*********************************************************************************************//
//*********************************************************************************************//
class Map
{
private:
    Coordinate *MapPos; //角色进入该地图的初始位置坐标
    int **ItsMap;   //通过数组设置墙体阻挡角色在某些地方前进  ***********要不改成wall？*************
    QString Address;//场景图片的路径
    PLACE ID; //地图的名字
    int NpcNumber; //地图里npc的数量
    Npc *NpcInScene[5];//地图npc

public:
    Map(QWidget *parent,QGraphicsScene *Scene,Data *UserData);

    QString getAddress(); //获取场景图片的路径
    Coordinate DifferMapPos(PLACE CoordID);//返回角色进入该地图的初始位置坐标



    int getx();//获取角色进入该地图的初始位置坐标的x坐标
    int gety();//获取角色进入该地图的初始位置坐标的y坐标
    int getNpcNumber();//获取地图里npc的数量
    bool isZero(int x,int y);//判断是否前方为墙体(0)
    PLACE getID();//返回地图名字

    bool ShowNpcDia(QGraphicsItem *CollideItem,QKeyEvent *event);//碰撞到npc时展示npc对话
    bool HideNpcDia();//离开npc时隐藏npc对话

    Map ChangeMap(PLACE nextID,QWidget *parent,QGraphicsScene *Scene,Data *UserData);//改变地图场景
    ACTION Detect(int x,int y);//检测某些行为  ********后面可能会删除
    ACTION Detect();

    bool ChangeNpc(PLACE nextID,QWidget *parent,QGraphicsScene *Scene,Data *UserData);//改变场景后改变npc
    int** getMapArray(PLACE nextID);//获取地图墙体数组
    QString getSceneAdress(PLACE ID);//获取地图场景图片

};


#endif // MAP_H

