#ifndef WIDGET_H
#define WIDGET_H
#include<QPushButton>
#include <QWidget>
#include "playwindow.h"
namespace Ui {
class Widget;
}
/*这里都是开始时候的那行按钮和图片的类，和游戏里的东西无关，懒得注释了......有时间再注释吧*/
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    QPushButton *NewAGame;
    QPushButton *ReadGame;
    QPushButton *BackToMainWindow;


    QPushButton *GameBeginButton;
    QPushButton *GameExitButton;

    QPushButton *ExitMakeSure;
    QPushButton *ExitMakeSure_Yes;
    QPushButton *ExitMakeSure_No;


    Playwindow *Player;
    //Widget *GMwindows2;

    void EnterSecondWin();
    void EnterFirstWin();
    void Exitwin();
    void GameBegin();


private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
