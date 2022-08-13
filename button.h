#ifndef BUTTON_H
#define BUTTON_H
#include<QPushButton>
#include<QGraphicsView>
#include<QWidget>
#ifndef PlaywindowArraySize_x
#define PlaywindowArraySize_x 16
#endif
#ifndef PlaywindowArraySize_y
#define PlaywindowArraySize_y 15
#endif
#define Map_Size 700,712.25
#define PlaywindowSize 1440,900
#ifndef SCREEN_X
#define SCREEN_X 1440
#endif
#ifndef SCREEN_Y
#define SCREEN_Y 900
#endif

#ifndef MAPARRAT_X
#define MAPARRAT_X 16
#endif
#ifndef MAPARRAT_Y
#define MAPARRAT_Y 15
#endif

//*********************************************************************************************//
//*********************************************************************************************//
//********************Normalbutton继承于QPushButton，提供一个接口实现各种button***************************//
//*********************************************************************************************//
//*********************************************************************************************//
//********************第一个构造函数提供一个有文字的button***************************//
//********************第二个构造函数提供一个有图片的button***************************//
//*********************************************************************************************//
//*********************************************************************************************//

class NormalButton:public QPushButton
{
public:
    NormalButton(int Size_x,int Size_y,int move_x,int move_y,QString Text);
    NormalButton(int Size_x,int Size_y,int move_x,int move_y,QIcon Pixmap,int IconSize_x,int IconSize_y);

};

//*********************************************************************************************//
//*********************************************************************************************//
//********************CloseButton继承于QPushButton，提供一个关闭的图标button，这个button是相同的***************************//
//*********************************************************************************************//
//*********************************************************************************************//

class CloseButton:public QPushButton
{
public:
    CloseButton(int,int);
    CloseButton(QWidget *parent,int,int);
};


//*********************************************************************************************//
//*********************************************************************************************//
//********************button类包含大部分游戏内的button***************************//
//*********************************************************************************************//
//*********************************************************************************************//
class Button
{
private:

    NormalButton *BigMap;
    NormalButton *Home;
    NormalButton *East_Area;
    NormalButton *Police_Office;
    NormalButton *MapButton;
    NormalButton *DataButton;
    CloseButton *Close_Map;



    //********************各种button的get、show***************************//


public:

    bool BigMap_show();
    bool BigMap_hide();
    bool setParent(QWidget *parent);

    Button();
    Button(QWidget *parent);

    NormalButton *getBigMap();
    NormalButton *getHome();
    NormalButton *getEast_Area();
    NormalButton *getPolice_Office();
    NormalButton *getMapButton();
    NormalButton *getDataButton();
    CloseButton *getClose_Map();

};



#endif // BUTTON_H



