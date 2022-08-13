#ifndef GAME_H
#define GAME_H
#include <QTime>
#include <QtGlobal>
#include <QKeyEvent>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsPixmapItem>
#include "button.h"
#include <QDebug>
#include <QLabel>
#include "data.h"
#ifndef GAMEWINDOW
#define GAMEWINDOW 780
#endif
#ifndef GAMEMOVE
#define GAMEMOVE 320,50
#endif





//*********************************************************************************************//
//*********************************************************************************************//
//********************2048类，游戏2048的实现，继承于QGraphicsView***************************************************//
//*********************************************************************************************//
//*********************************************************************************************//
class TZFEGame:public QGraphicsView
{
private:
    int **IDArray;                    //游戏的4×4棋盘上各个格子的数值，从0、2、4、8、16...一直到2的22次方
    QGraphicsPixmapItem *Photo[16];   //游戏的4×4棋盘上各个格子的显示图片
    QGraphicsScene *GameBackground;   //游戏的白板背景图片
    QString *ScoreStr;                //游戏内的分数，由int转化而来
    QLabel *ScoreLabel;               //游戏内的文字提示



public:
    int Score;                      //游戏分数int，******************以后要改到private里******************
    CloseButton *CloseBtn;          //关闭游戏的按钮，******************以后要改到private里******************
    QLabel *StrToLabel();           //显示游戏文字的label，******************以后要改到private里******************


    TZFEGame();

    bool isFull();                  //判断游戏的格子是否已满，无法增加新的格子
    bool isWin();                   //判断游戏是否胜利
    bool Running(QKeyEvent *Direction);//游戏运行的主函数，游戏的各种逻辑行为在这里，由keyPressEvent传递Direction
    void keyPressEvent(QKeyEvent *event);//按下键盘运行主函数
    bool Change();           //改变所有格子的图片,***QT的下面的3-应用程序输出一直输出nullpixmap的问题可能出现在这或者getPhotoAdress***
    QString getPhotoAdress(int ID);//return pixmap的路径,***QT的下面的3-应用程序输出一直输出nullpixmap的问题可能出现在这或者Change***
    int get_Zero();       //返回格子为空的数量
    int set_TwoPos();     //随机设置一个空格子的idarray为2，返回数组position
    int getScore();       //获取并且返回游戏分数
    bool addScore(int ID);//增加游戏分数
    bool ShowScore();     //展示游戏分数
    void Init();          //游戏结束后初始化游戏数据，以便下一次游玩


};








//*********************************************************************************************//
//*********************************************************************************************//
//********************游戏类包含游戏内可玩的游戏，包括2048等***************************//
//*********************************************************************************************//
//*********************************************************************************************//


class Game:public QWidget
{
private:


    NormalButton *GameButton;  //2048游戏按钮     **********以后肯定会改名***********
    CloseButton *Close;        //2048游戏关闭按钮
    CloseButton *StmClose;     //游戏结束窗口关闭按钮
    Data *data;             //玩家的数据传参到这里 **********以后这里可能直接改为klein类***********
    QWidget *Settlement; //游戏结束窗口   //**********最好把名字改了...**********
    QLabel *ScoreTips;   //分数显示信息

public:
    TZFEGame *TZFE;


    Game(QWidget *parent,Data *);
    bool CloseMainWindow();  //关闭游戏主窗口
    bool TZFE_Begin();       //开始2048游戏
    bool CloseGame();        //关闭游戏
    bool SetSettlement(int);  //设置游戏结束窗口显示的信息
    bool CloseSettlement();   //关闭游戏结束窗口


};
#endif // GAME_H
