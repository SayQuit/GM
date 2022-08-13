#include "button.h"
#include<QPushButton>

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
//********************button类包含大部分游戏内的button***************************//
//*********************************************************************************************//
//*********************************************************************************************//
Button::Button()
{
    this->Close_Map=new CloseButton(700-30,0);                                                          //关闭地图的按钮
    this->BigMap=new NormalButton(Map_Size,370,93.875,QIcon(":/Background/London.jpg"),Map_Size);       //大地图窗口




    this->East_Area=new NormalButton(80,40,500,300,QString("东区街道"));                                    //进入东区街道场景按钮
    this->Home=new NormalButton(80,40,500,250,QString("房间"));                                           //进入房间场景按钮
    this->Police_Office=new NormalButton(80,40,180,300,QString("警察局"));                                 //进入警察局场景按钮



    this->MapButton=new NormalButton(ButtonSize,MapButtonMove,QString("地图"));                              //打开地图的按钮
    this->DataButton=new NormalButton(ButtonSize,DataButtonMove,QString("资料"));                         //打开资料卡的按钮


    //******************设置按钮的位置************************
    this->Close_Map->setParent(this->BigMap);
    this->Home->setParent(this->BigMap);
    this->East_Area->setParent(this->BigMap);
    this->Police_Office->setParent(this->BigMap);
    //****************************************************


    this->BigMap->hide();   //地图初始是隐藏的



}
Button::Button(QWidget *parent)
{

    //***************************同上，实际应用的是这里***************************
    this->Close_Map=new CloseButton(700-30,0);                                                              //关闭地图的按钮
    this->BigMap=new NormalButton(Map_Size,370,93.875,QIcon(":/Background/London.jpg"),Map_Size);           //大地图窗口


    this->East_Area=new NormalButton(80,40,500,300,QString("东区街道"));                                     //进入东区街道场景按钮
    this->Home=new NormalButton(80,40,500,250,QString("房间"));                                               //进入房间场景按钮
    this->Police_Office=new NormalButton(80,40,180,300,QString("警察局"));                                     //进入警察局场景按钮


    this->MapButton=new NormalButton(ButtonSize,MapButtonMove,QString("地图"));                               //打开地图的按钮
    this->DataButton=new NormalButton(ButtonSize,DataButtonMove,QString("资料"));                             //打开资料卡的按钮





    //******************设置按钮的位置************************
    this->Close_Map->setParent(this->BigMap);
    this->Home->setParent(this->BigMap);
    this->East_Area->setParent(this->BigMap);
    this->Police_Office->setParent(this->BigMap);
    this->setParent(parent);
     //****************************************************


    this->BigMap->hide();//地图初始是隐藏的




}

bool Button::setParent(QWidget *parent)
{

    //******************将大地图、地图按钮、资料卡按钮设置到qwidget里面******************
    this->BigMap->setParent(parent);
    this->DataButton->setParent(parent);
    this->MapButton->setParent(parent);
}

bool Button::BigMap_show()
{

    /********************打开地图*********************/
    this->BigMap->show();
}
bool Button::BigMap_hide()
{
    /********************关闭地图*********************/
    this->BigMap->hide();
}



//*********************************************************************************************//
//*********************************************************************************************//
//********************Normalbutton继承于QPushButton，提供一个接口实现各种button***************************//
//*********************************************************************************************//
//*********************************************************************************************//
//********************第一个构造函数提供一个有文字的button***************************//
//********************第二个构造函数提供一个有图片的button***************************//
//*********************************************************************************************//
//*********************************************************************************************//

NormalButton::NormalButton(int Size_x,int Size_y,int move_x,int move_y,QString Text)
{

    this->setFixedSize(Size_x,Size_y);//设置大小
    this->move(move_x,move_y);        //设置位置
    this->setText(Text);              //设置文本

}

NormalButton::NormalButton(int Size_x,int Size_y,int move_x,int move_y,QIcon Pixmap,int IconSize_x,int IconSize_y)
{


    this->setFixedSize(Size_x,Size_y);                  //设置大小
    this->setIconSize(QSize(IconSize_x,IconSize_y));    //设置图标大小
    this->move(move_x,move_y);                          //设置位置
    this->setIcon(Pixmap);                              //设置图标


}

//*********************************************************************************************//
/*****************这里的几个用于返回各种按钮*******************************************************/
//*********************************************************************************************//
NormalButton *Button::getBigMap()
{
    return this->BigMap;
}

NormalButton *Button::getHome()
{
    return this->Home;
}

NormalButton *Button::getEast_Area()
{
    return this->East_Area;
}

NormalButton *Button::getPolice_Office()
{
    return this->Police_Office;
}

NormalButton *Button::getMapButton()
{
    return this->MapButton;
}

NormalButton *Button::getDataButton()
{
    return this->DataButton;
}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//




//*********************************************************************************************//
//*********************************************************************************************//
//********************CloseButton继承于QPushButton，提供一个关闭的图标button，这个button是相同的***************************//
//*********************************************************************************************//
//*********************************************************************************************//

CloseButton::CloseButton(int x,int y)
{

    this->move(x,y);                                        //设置位置
    this->setIcon(QIcon(":/Scene/cancelIcon.png"));         //设置×图标
    this->setIconSize(QSize(30,30));                        //设置×大小
    this->setFixedSize(30,30);                              //设置大小
    this->setFlat(true);                                    //去除边框
}
CloseButton::CloseButton(QWidget *parent,int x,int y)
{
    this->setParent(parent);                        //设置父亲
    this->move(x,y);                                //设置位置
    this->setIcon(QIcon(":/Scene/cancelIcon.png")); //设置×图标
    this->setIconSize(QSize(30,30));                //设置×大小
    this->setFixedSize(30,30);                      //设置大小
    this->setFlat(true);                            //去除边框



}

/********************返回关闭按钮************************/
CloseButton *Button::getClose_Map()
{
    return this->Close_Map;

}










