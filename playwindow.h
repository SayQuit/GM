#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include<QTimer>
#include <QMouseEvent>
#include "klein.h"
#include <QLabel>
#include "map.h"
#include"klein.h"
#include"dialog.h"
#ifndef PlaywindowSize_x
#define PlaywindowSize_x 16
#endif
#ifndef PlaywindowSize_y
#define PlaywindowSize_y 15
#endif


class Playwindow:public QGraphicsView
{
private:
    QTimer *timer;
    QLabel *HitWall;
    Klein *kleinM;
    Map *WinMap;
    QGraphicsScene *EastArea;
    Button *WinButton;
public:
    Playwindow();

    //Dialog *WinDialog;

    //QPushButton *CloseButton;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool HitWall_Judge(int,int);
    bool Reading(QKeyEvent *event);

    void clickMap();
    bool OpenMap();
    bool CloseMap();
    bool GotoOtherPlace(Map);
    bool GotoEastArea();
    bool GotoHome();
    bool OpenDataCard();
    bool CloseDataCard();
    bool GotoPoliceOffice();
    bool setButtonParent();
    bool KleinCollide(QKeyEvent *event);
    bool ConnectRunning();




  //  void mousePressEvent(QMouseEvent *event);

    //void resizeEvent();

    void PlayerRunning(QKeyEvent *event);
    void PlayerStop(QKeyEvent *event);


private:

};

#endif // PLAYWINDOW_H
