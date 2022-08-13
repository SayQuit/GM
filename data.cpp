#include "data.h"
#define Card_Size 250,370

Data::Data()
{

    /*************************************************************************************************/
    /**************************设置主角的各种数据：精力、san值、经验值、知识、等级***************************/
    /*************************************************************************************************/
    this->energy=100;
    this->san=0;
    this->exp=0;
    this->knowledge=0;
    this->level=1;

    /********************************************************/
    /**************************设置资料卡***************/
    /******************************************************/
    this->DataCard=new QPushButton;
    this->DataCard->setFixedSize(Card_Size);
    this->DataCard->move(595,265);




    /********************************************************/
    /**************************设置头像***************/
    /******************************************************/
    this->PlayerPixmap=new QPushButton();
    this->PlayerPixmap->setIcon(QIcon(":/Klein/Player.jpg"));
    this->PlayerPixmap->setIconSize(QSize(100,100));
    this->PlayerPixmap->move((250-100)/2,20);


    this->Close_Datacard=new CloseButton(250-30,0);//关闭按钮




    //*************************************************//
    //******************将文字放入资料卡******************//
    //************************************************//
    QString DataString=("等级:");
    DataString.append(QString::number(this->level));
    DataString.append("\n");
    DataString.append("经验值:");
    DataString.append(QString::number(this->exp));
    DataString.append("\n");
    DataString.append("精力:");
    DataString.append(QString::number(this->energy));
    DataString.append("\n");
    DataString.append("San值:");
    DataString.append(QString::number(this->san));
    DataString.append("\n");
    DataString.append("知识:");
    DataString.append(QString::number(this->knowledge));
    DataString.append("\n");
    this->DataCard->setText(DataString);
    this->DataCard->hide();
    this->Close_Datacard->setParent(this->DataCard);
    this->PlayerPixmap->setParent(this->DataCard);

    //connect(this->Close_Datacard,&QPushButton::clicked,this,&Data::Close_Datacard);














}


//*******************************************************************//
//*更新资料卡文字，如果不更新会造成数据实际改变但是资料卡上的数据还是原来的的问题*//
//******************************************************************//
bool Data::Update_Card()
{

    QString DataString=("等级:");
    DataString.append(QString::number(this->level));
    DataString.append("\n");
    DataString.append("经验值:");
    DataString.append(QString::number(this->exp));
    DataString.append("\n");
    DataString.append("精力:");
    DataString.append(QString::number(this->energy));
    DataString.append("\n");
    DataString.append("San值:");
    DataString.append(QString::number(this->san));
    DataString.append("\n");
    DataString.append("知识:");
    DataString.append(QString::number(this->knowledge));
    DataString.append("\n");
    this->DataCard->setText(DataString);

    return 1;

}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//





//*******************************************************************************************************//
//*******更新知识和经验值，add表示每次增加的值，由其它传参而来，每次暂定精力-10，以后可以写重构函数改变减少的精力*******//
//******************************************************************************************************//
bool Data::updateKnowledge(int add)
{
    this->knowledge+=add;
    this->energy-=10;
    if(this->Update_Card())return 1;

}
bool Data::updateExp(int add)
{
    this->exp+=add;
    this->energy-=10;
    if(this->Update_Card())return 1;
}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//








//*******************************************************************//
//*************************返回按钮，connect要用*************************//
//******************************************************************//
CloseButton *Data::getClose_Datacard()
{
    return this->Close_Datacard;
}
QPushButton *Data::getDataCard()
{
    return this->DataCard;
}
//*********************************************************************************************//
/***********************************************************************************************/
//*********************************************************************************************//
