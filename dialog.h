#ifndef DIALOG_H
#define DIALOG_H
#include <QString>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QGraphicsItem>

//*********************************************************************************************//
//*********************************************************************************************//
//********************dialog类是玩家触碰到人物时弹出的对话框，可能以后会增加其他属性***************************//
//*********************************************************************************************//
//*********************************************************************************************//


class Dialog:public QGraphicsPixmapItem
{
private:
    QLabel *content;  //对话内容
    QLabel *PressF;   //按F的提示
public:
    Dialog(QString text,QPixmap pixmap,int x_position,int y_position,QWidget *parent);  //构造函数，需要提供text内容，
                                                                           //pixmap为固定的对话框,对话框位置，QGraphicsScene父类


    void Hide();//隐藏以上所有
    void Show();//显示以上所有
    void OnlyShowPressF();//显示按F提示
    void OnlyShowcont();//显示内容
    bool isPressFHidden();//判断按F提示是否显示
};






#endif // DIALOG_H
