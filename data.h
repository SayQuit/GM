#ifndef DATA_H
#define DATA_H
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QString>
#include"button.h"
#ifndef SIZE
#define SIZE 250,150
#endif
#ifndef MapButtonMove
#define MapButtonMove 40,500
#endif
#ifndef DataButtonMove
#define DataButtonMove 40,550
#endif
#ifndef ButtonSize
#define ButtonSize 100,45
#endif

//*********************************************************************************************//
//*********************************************************************************************//
//********************DATA类包含了玩家拥有的所有数据***************************//
//*********************************************************************************************//
//*********************************************************************************************//

class Data
{
private:
    QPushButton *DataCard;  //角色资料卡
    QPushButton *PlayerPixmap; //角色头像
    CloseButton *Close_Datacard;  //关闭角色卡button
    int energy;  //角色能量
    int san;   //角色san值
    int knowledge;  //角色知识
    int level;  //角色等级

public:
    Data();


    int exp;  //角色经验值  ************后面要改到private里************

    bool Update_Card();  //更新资料卡函数，每次data更新后资料卡上还保留上一次data的数值，必须更新
    bool updateKnowledge(int);  //知识值改变
    bool updateExp(int); //经验值改变

    //button的get函数
    CloseButton *getClose_Datacard();
    QPushButton *getDataCard();
};

#endif // DATA_H
