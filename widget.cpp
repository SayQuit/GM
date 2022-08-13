#include "widget.h"
#include "ui_widget.h"

#include <QPushButton>
#include <QDebug>
#include <QPixmap>
#include <QPalette>

#include<QKeyEvent>

#define SIZE 250,150
#define PLACE1 100,100
#define PLACE2 100,300
#define PLACE3 100,500
#define MAINWINDOWMOVE 240,60
#ifndef Mainwindow
#define Mainwindow 1440,900
#endif

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPalette Background;
    Background.setBrush(QPalette::Background,QBrush(QPixmap(":/Background/Background.jpg").scaled(Mainwindow)));
    this->setPalette(Background);



    GameBeginButton=new QPushButton;
    GameBeginButton->show();
    GameBeginButton->setFixedSize(SIZE);
    GameBeginButton->setText("开始游戏");
    GameBeginButton->setParent(this);
    GameBeginButton->move(PLACE1);
    connect(GameBeginButton,&QPushButton::clicked,this,&Widget::EnterSecondWin);



    GameExitButton=new QPushButton;
    GameExitButton->setParent(this);
    GameExitButton->setFixedSize(SIZE);
    GameExitButton->setText("退出");
    GameExitButton->move(PLACE2);
    GameExitButton->show();
    connect(GameExitButton,&QPushButton::clicked,this,&Widget::Exitwin);


    ExitMakeSure=new QPushButton;
    ExitMakeSure->setFixedSize(400,200);
    ExitMakeSure->move(720,450);
    ExitMakeSure->setWindowTitle("确认退出");
    ExitMakeSure->setParent(this);
    ExitMakeSure->hide();



    ExitMakeSure_Yes=new QPushButton;
    ExitMakeSure_No=new QPushButton;

    ExitMakeSure_Yes->setParent(ExitMakeSure);
    ExitMakeSure_Yes->setText("确认");
    ExitMakeSure_Yes->move(70,60);
    ExitMakeSure_Yes->setFixedSize(80,40);
    connect(ExitMakeSure_Yes,&QPushButton::clicked,ExitMakeSure,&QWidget::close);
    connect(ExitMakeSure_Yes,&QPushButton::clicked,this,&QWidget::close);

    ExitMakeSure_No->setParent(ExitMakeSure);
    ExitMakeSure_No->setText("取消");
    ExitMakeSure_No->move(250,60);
    ExitMakeSure_No->setFixedSize(80,40);
    connect(ExitMakeSure_No,&QPushButton::clicked,ExitMakeSure,&QWidget::close);

//界面切换



    NewAGame=new QPushButton;
    NewAGame->setFixedSize(SIZE);
    NewAGame->move(PLACE1);
    NewAGame->setText("新建游戏");
    NewAGame->setParent(this);
    connect(NewAGame,&QPushButton::clicked,this,&Widget::GameBegin);
    this->NewAGame->hide();
//
    ReadGame=new QPushButton;
    ReadGame->setText("读取游戏");
    ReadGame->setFixedSize(SIZE);
    ReadGame->setParent(this);
    ReadGame->move(PLACE2);
    this->ReadGame->hide();


    BackToMainWindow=new QPushButton;
    BackToMainWindow->setFixedSize(SIZE);
    BackToMainWindow->setParent(this);
    BackToMainWindow->setText("返回主界面");
    BackToMainWindow->move(PLACE3);
    connect(BackToMainWindow,&QPushButton::clicked,this,&Widget::EnterFirstWin);
    this->BackToMainWindow->hide();

    this->Player=new Playwindow;
    this->Player->setFixedSize(Mainwindow);
    this->Player->move(MAINWINDOWMOVE);
    this->setWindowTitle("诡秘世界");

}

void Widget::EnterSecondWin()
{
    this->GameBeginButton->hide();
    this->GameExitButton->hide();
    this->NewAGame->show();
    this->ReadGame->show();
    this->BackToMainWindow->show();
}

void Widget::EnterFirstWin()
{
    this->GameBeginButton->show();
    this->GameExitButton->show();
    this->NewAGame->hide();
    this->ReadGame->hide();
    this->BackToMainWindow->hide();
}

void Widget::Exitwin()
{
    this->ExitMakeSure->show();
}

void Widget::GameBegin()
{
    this->hide();
    this->Player->show();
}

Widget::~Widget()
{
    delete ui;
}
