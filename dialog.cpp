#include "dialog.h"


Dialog::Dialog(QString text, QPixmap pixmap, int x_position, int y_position,QWidget *parent)
{


    this->content=new QLabel;//对话内容的设置
    this->content->setParent(parent);
    this->content->setText(text);
    this->content->move(x_position+10+10,y_position-70+10);

    this->PressF=new QLabel;//按F的提示的设置
    this->PressF->setParent(parent);
    this->PressF->setText("按F互动");
    this->PressF->move(x_position+10,y_position-10);

    this->setPos(x_position+10,y_position-70);
    this->setPixmap(pixmap);
    this->Hide();



}

/********隐藏和展示所有********/
void Dialog::Hide()
{
    this->PressF->hide();
    this->content->hide();
    this->hide();
}

void Dialog::Show()
{
    this->PressF->show();
    this->content->show();
    this->show();
}



/********只展示按F1********/
void Dialog::OnlyShowPressF()
{
    this->PressF->show();
    this->content->hide();
    this->hide();
}


/********只展示内容********/
void Dialog::OnlyShowcont()
{
    this->PressF->hide();
    this->content->show();
    this->show();
}


bool Dialog::isPressFHidden()
{
    if(this->PressF->isHidden())return true;
    else return false;
}


