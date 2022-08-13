#include "npc.h"

Npc::Npc()
{
    this->Position=new Coordinate;
}

Npc::~Npc()
{

}


Coordinate::Coordinate()
{
}
Coordinate::Coordinate(int x_in,int y_in)
{
    this->x=x_in;
    this->y=y_in;
}

int Coordinate::getx()
{
    return this->x;
}
int Coordinate::gety()
{
    return this->y;
}
bool Coordinate::setx(int x_in)
{
    this->x=x_in;
    return true;
}

bool Coordinate::sety(int y_in)
{
     this->y=y_in;
    return true;
}
Coordinate* Coordinate::getCoord()
{
    return this;
}

bool Coordinate::setCoord(int x_in,int y_in)
{
    this->setx(x_in);
    this->sety(y_in);
}




bool Npc::showDialog(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Enter)
    {
        this->Action();
    }
    else if(event->key()==Qt::Key_F)
    {
        this->Dialogue->OnlyShowcont();
    }
    else if(event->key()==Qt::Key_W||event->key()==Qt::Key_A||event->key()==Qt::Key_S||event->key()==Qt::Key_D)
    {
        this->Dialogue->OnlyShowPressF();
    }
    return true;
}
bool Npc::hideDialog()
{

    this->Dialogue->Hide();
    return true;
}
Dialog *Npc::getDialog()
{
    return this->Dialogue;

}
QString Npc::getNpcAddress(ROLE NpcID)
{
    switch(NpcID)
    {
        case DONNE:return QString(":/Donne.png");break;
        case MIRROR:return QString(":/photo/Mirror.png");break;
        default:return NULL;
    }
}
Coordinate Npc::DifferNpcPos(ROLE CoordID)
{
    switch(NpcID)
    {
        case DONNE:return Coordinate(770,200);break;
        case MIRROR:return Coordinate(1000,50);break;
        default:return Coordinate(0,0);
    }
}

Donne::Donne()
{

}
Donne::Donne(QWidget *parent,QGraphicsScene *Scene)
{


    this->NpcID=DONNE;
    this->NpcPixmap=new QPixmap(QString(this->getNpcAddress(this->NpcID)));
    this->Position->setCoord(this->DifferNpcPos(this->NpcID).getx(),this->DifferNpcPos(this->NpcID).gety());
    this->setPixmap(*this->NpcPixmap);
    this->setPos(this->Position->getx(),this->Position->gety());
    this->Dialogue=new Dialog(QString("你好"),QString(":/Box.png"),this->x(),this->y(),parent);
    Scene->addItem(this);

}
bool Donne::Action()
{
    return 1;
}

Mirror::Mirror()
{

}
Mirror::Mirror(QWidget *parent,QGraphicsScene *Scene,Data *UserData)
{

    this->NpcID=MIRROR;
    this->MirrorGame=new Game(parent,UserData);
    this->NpcPixmap=new QPixmap(QString(this->getNpcAddress(this->NpcID)));
    this->Position->setCoord(this->DifferNpcPos(this->NpcID).getx(),this->DifferNpcPos(this->NpcID).gety());
    this->setPixmap(*this->NpcPixmap);
    this->setPos(this->Position->getx(),this->Position->gety());
    this->Dialogue=new Dialog(QString("你好"),QString(":/Box.png"),this->x(),this->y(),parent);
    Scene->addItem(this);

}
void Mirror::show_Game()
{

}
bool Mirror::Action()
{


    this->MirrorGame->show();
    return true;
}




