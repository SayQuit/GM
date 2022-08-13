#include "game.h"

Game::Game(QWidget *parent,Data *UserData)
{

    this->TZFE=new TZFEGame;
    this->data=UserData;
    this->GameButton=new NormalButton(100,40,400/2-100/2,100,"2048");
    this->GameButton->setParent(this);



    this->Settlement=new QWidget;
    this->Settlement->setFixedSize(400,400);
    this->StmClose=new CloseButton(this->Settlement,370,0);
    this->Settlement->hide();
    this->Settlement->setWindowFlags(Qt::FramelessWindowHint);
    this->ScoreTips=new QLabel(this->Settlement);
    //this->setStyleSheet("QWidget{border:none}");
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFixedSize(400,400);
    this->Close=new CloseButton(this,370,0);

    connect(this->GameButton,&QPushButton::clicked,this,&Game::TZFE_Begin);
    connect(this->Close,&QPushButton::clicked,this,&Game::CloseMainWindow);
    connect(this->TZFE->CloseBtn,&QPushButton::clicked,this,&Game::CloseGame);
    connect(this->StmClose,&QPushButton::clicked,this,&Game::CloseSettlement);
}
bool Game::TZFE_Begin()
{
    this->TZFE->show();
    this->hide();
    return true;
}
bool Game::CloseMainWindow()
{
    this->hide();
}
bool Game::SetSettlement(int ItsScore)
{
    this->Settlement->hide();
    QString ScoreString;
    ScoreString.append("游戏得分:");
    ScoreString.append(QString::number(ItsScore));
    ScoreString.append("\n获得经验:");
    ScoreString.append(QString::number(ItsScore));
    ScoreString.append("\n精力-10");

    this->ScoreTips->setText(ScoreString);

    this->Settlement->show();
}
bool Game::CloseSettlement()
{
    this->Settlement->hide();
}
bool Game::CloseGame()
{
    this->data->updateExp(this->TZFE->Score);
    this->show();
    this->SetSettlement(this->TZFE->Score);
    this->Settlement->show();
    this->TZFE->Init(); //这里应该写出一个tzfe_END的函数
    this->TZFE->hide();
}






















TZFEGame::TZFEGame()
{
    this->setFixedSize(820,820);
    //this->move(GAMEMOVE);
    this->setWindowTitle("2048GM版");
    this->Score=0;
    this->GameBackground=new QGraphicsScene;
    this->setScene(this->GameBackground);
    this->setSceneRect(0,0,810,810);
    //this->setStyleSheet("QWidget{border:none}");

    this->ScoreStr=new QString;



    this->CloseBtn=new CloseButton(this,790,0);

    this->ScoreLabel=new QLabel;
    this->ScoreLabel->setParent(this);
    this->ScoreLabel->move(0,0);
    this->ScoreLabel->setText(*this->ScoreStr);
    this->ShowScore();

    this->setWindowFlags(Qt::FramelessWindowHint);

    this->IDArray = new int*[4];
    for (int i = 0; i < 4; i++)
    {
        IDArray[i] = new int[4];
    }
    int x_Pos=0,y_Pos=40;
    for (int i = 0; i < 16; i++)
    {
        this->Photo[i]=new QGraphicsPixmapItem;
        this->Photo[i]->setPos(x_Pos,y_Pos);

        this->GameBackground->addItem(this->Photo[i]);

        x_Pos+=GAMEWINDOW/4;
        if((i+1)%4==0)
        {
            x_Pos=0;
            y_Pos+=GAMEWINDOW/4;
        }



    }
    this->Init();







}

QLabel *TZFEGame::StrToLabel()
{



}




bool TZFEGame::isFull()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (this->IDArray[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool TZFEGame::isWin()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (this->IDArray[i][j] == 4194304)
            {
                return true;
            }
        }
    }
    return false;
}

void TZFEGame::keyPressEvent(QKeyEvent *event)
{
    this->Running(event);
    if(this->isWin())
    {

        this->ScoreStr->append("游戏结束，你赢了！\n");
        this->ShowScore();

    }
    else if(this->isFull())
    {
        this->ScoreStr->append("游戏结束，你输了！\n");
        this->ShowScore();

    }
}
void TZFEGame::Init()
{

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            IDArray[i][j] = 0;

        }
    }


    for (int i = 0; i < 16; i++)
    {
        //this->Photo[i]=new QGraphicsPixmapItem;
        this->Photo[i]->setPixmap(QPixmap(QString(this->getPhotoAdress(0))).scaled(GAMEWINDOW/4,GAMEWINDOW/4));



    }
    this->Score=0;
    this->ShowScore();
}

bool TZFEGame::Running(QKeyEvent *Direction)
{



        //Print();

    this->ShowScore();
    int lockindex[4][4];//锁住某个位置使得之后移动到此位置的图片停下，防止这个位置之前被合为一张的又与移来的图片合体

    if(this->isFull()||this->isWin())return true;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            lockindex[i][j] = 0;

        }
    }


    if (Direction->key() == Qt::Key_A)
    {
        for (int i = 0; i < 4; i++)//两层循环
        {
            for (int j = 0; j < 4; j++)
            {
                while (j != 0 && this->IDArray[i][j - 1] == 0 && this->IDArray[i][j] != 0 )
                {
                    this->IDArray[i][j - 1] = this->IDArray[i][j];//如果左边有位置则左移
                    this->IDArray[i][j] = 0;
                    j--;
                }
                //如果左边没位置则判断两个图片是否一致
                if (j != 0 && this->IDArray[i][j - 1] == this->IDArray[i][j] && this->IDArray[i][j] != 0&& lockindex[i][j - 1]!=1)
                {
                    this->IDArray[i][j] = 0;
                    this->IDArray[i][j - 1] *= 2;//两个图片合为一张
                    lockindex[i][j - 1] = 1;
                    this->addScore(this->IDArray[i][j-1]);
                }

            }
        }

    }
    else if (Direction->key() == Qt::Key_W)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                while (j != 0 && this->IDArray[j - 1][i] == 0 && this->IDArray[j][i] != 0)
                {
                    this->IDArray[j - 1][i] = this->IDArray[j][i];
                    this->IDArray[j][i] = 0;
                    j--;
                }
                if (j != 0 && this->IDArray[j - 1][i] == this->IDArray[j][i] && this->IDArray[j][i] != 0&& lockindex[j - 1][i] != 1)
                {
                    this->IDArray[j][i] = 0;
                    this->IDArray[j - 1][i] *= 2;
                    lockindex[j - 1][i] = 1;
                    this->addScore(this->IDArray[j-1][i]);
                }

            }
        }

    }
    else if (Direction->key() == Qt::Key_D)
    {
        for (int i = 3; i >=0; i--)
        {
            for (int j = 3; j >=0; j--)
            {
                while (j != 3 && this->IDArray[i][j + 1] == 0 && this->IDArray[i][j] != 0)
                {
                    this->IDArray[i][j + 1] = this->IDArray[i][j];
                    this->IDArray[i][j] = 0;
                    j++;
                }
                if (j != 3 && this->IDArray[i][j + 1] == this->IDArray[i][j] && this->IDArray[i][j] != 0&& lockindex[i][j + 1] != 1)
                {
                    this->IDArray[i][j] = 0;
                    this->IDArray[i][j + 1] *= 2;
                    lockindex[i][j + 1] = 1;
                    this->addScore(this->IDArray[i][j+1]);
                }

            }
        }

    }
    else if (Direction->key() == Qt::Key_S)
    {
        for (int i = 3; i >= 0; i--)
        {
            for (int j = 3; j >= 0; j--)
            {
                while (j != 3 && this->IDArray[j + 1][i] == 0 && this->IDArray[j][i] != 0)
                {
                    this->IDArray[j + 1][i] = this->IDArray[j][i];
                    this->IDArray[j][i] = 0;
                    j++;
                }
                if (j != 3 && this->IDArray[j + 1][i] == this->IDArray[j][i] && this->IDArray[j][i] != 0&& lockindex[j + 1][i] != 1)
                {
                    this->IDArray[j][i] = 0;
                    this->IDArray[j + 1][i] *= 2;
                    lockindex[j + 1][i] = 1;
                    this->addScore(this->IDArray[j+1][i]);
                }

            }
        }

    }
    int Two = this->set_TwoPos();
    this->IDArray[Two / 4][Two % 4] = 2;
    this->Change();
    this->ShowScore();





}
QString TZFEGame::getPhotoAdress(int ID)
{
    switch(ID)
    {
        case 0:return QString(":/new/prefix1/2048/2048_0.jpg");break;
        case 2:return QString(":/new/prefix1/2048/2048_1.jpg");break;
        case 4:return QString(":/new/prefix1/2048/2048_2.jpg");break;
        case 8:return QString(":/new/prefix1/2048/2048_3.jpg");break;
        case 16:return QString(":/new/prefix1/2048/2048_4.jpg");break;
        case 32:return QString(":/new/prefix1/2048/2048_5.jpg");break;
        case 64:return QString(":/new/prefix1/2048/2048_6.jpg");break;
        case 128:return QString(":/new/prefix1/2048/2048_7.jpg");break;
        case 256:return QString(":/new/prefix1/2048/2048_8.jpg");break;
        case 512:return QString(":/new/prefix1/2048/2048_9.jpg");break;
        case 1024:return QString(":/new/prefix1/2048/2048_10.jpg");break;
        case 2048:return QString(":/new/prefix1/2048/2048_11.jpg");break;
        case 4096:return QString(":/new/prefix1/2048/2048_12.jpg");break;
        case 8192:return QString(":/new/prefix1/2048/2048_13.jpg");break;
        case 16384:return QString(":/new/prefix1/2048/2048_14.jpg");break;
        case 32768:return QString(":/new/prefix1/2048/2048_15.jpg");break;
        case 65536:return QString(":/new/prefix1/2048/2048_16.jpg");break;
        case 131072:return QString(":/new/prefix1/2048/2048_17.jpg");break;
        case 262144:return QString(":/new/prefix1/2048/2048_18.jpg");break;
        case 524288:return QString(":/new/prefix1/2048/2048_19.jpg");break;
        case 1048576:return QString(":/new/prefix1/2048/2048_20.jpg");break;
        case 2097152:return QString(":/new/prefix1/2048/2048_21.jpg");break;
        case 4194304:return QString(":/new/prefix1/2048/2048_22.jpg");break;

        default:return NULL;

    }
}
bool TZFEGame::addScore(int ID)
{
    qDebug()<<ID;
    switch(ID)
    {
        case 2:this->Score+=1;break;
        case 4:this->Score+=1;break;
        case 8:this->Score+=1;break;
        case 16:this->Score+=2;break;
        case 32:this->Score+=2;break;
        case 64:this->Score+=2;break;
        case 128:this->Score+=3;break;
        case 256:this->Score+=3;break;
        case 512:this->Score+=3;break;
        case 1024:this->Score+=4;break;
        case 2048:this->Score+=4;break;
        case 4096:this->Score+=4;break;
        case 8192:this->Score+=4;break;
        case 16384:this->Score+=5;break;
        case 32768:this->Score+=5;break;
        case 65536:this->Score+=5;break;
        case 131072:this->Score+=6;break;
        case 262144:this->Score+=6;break;
        case 524288:this->Score+=6;break;
        case 1048576:this->Score+=7;break;
        case 2097152:this->Score+=7;break;
        case 4194304:this->Score+=7;break;

        default:this->Score+=0;break;

    }
    return true;
}
int TZFEGame::getScore()
{
    return this->Score;
}

bool TZFEGame::Change()
{
    for(int i=0;i<16;i++)
    {
        this->Photo[i]->setPixmap(QPixmap(this->getPhotoAdress(this->IDArray[i/4][i%4])).scaled(GAMEWINDOW/4,GAMEWINDOW/4));
    }
}
int TZFEGame::get_Zero()
{
    int zero=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->IDArray[i][j]==0)
            {
                zero++;
            }
        }
    }
    return zero;
}

int TZFEGame::set_TwoPos()
{
    int zeroNum=this->get_Zero();
    int *zeroArray=new int[zeroNum];
    int k=0;

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(this->IDArray[i][j]==0)
            {
                zeroArray[k]=i*4+j;
                k++;
            }
        }
    }
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return zeroArray[qrand() % zeroNum];





}
bool TZFEGame::ShowScore()
{




    this->ScoreStr->append("分数:");
    this->ScoreStr->append(QString::number(this->Score));
    ScoreLabel->hide();
    ScoreLabel->setText(*this->ScoreStr);
    ScoreLabel->show();
    *this->ScoreStr="";

}






























