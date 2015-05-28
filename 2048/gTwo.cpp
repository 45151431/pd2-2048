#include"gTwo.h"

gTwo::gTwo(QLabel*result,QLabel*score,QLabel*best,QLabel*label1,QLabel*label2,QLabel*label3,QLabel*label4,QLabel*label5,QLabel*label6,QLabel*label7,QLabel*label8,QLabel*label9,QLabel*label10,QLabel*label11,QLabel*label12,QLabel*label13,QLabel*label14,QLabel*label15,QLabel*label16)
{
    srand(time(NULL));
    this->label[0][0]=result;
    this->label[0][1]=score;
    this->label[1][0]=best;
    this->label[1][1]=label1;
    this->label[1][2]=label2;
    this->label[1][3]=label3;
    this->label[1][4]=label4;
    this->label[2][1]=label5;
    this->label[2][2]=label6;
    this->label[2][3]=label7;
    this->label[2][4]=label8;
    this->label[3][1]=label9;
    this->label[3][2]=label10;
    this->label[3][3]=label11;
    this->label[3][4]=label12;
    this->label[4][1]=label13;
    this->label[4][2]=label14;
    this->label[4][3]=label15;
    this->label[4][4]=label16;
    block_palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(0,220,220));
    result_palette.setColor(QPalette::Active, static_cast<QPalette::ColorRole>(10), QColor(85,250,0));
    Best=0;
    begin();
}
void gTwo::begin()
{
    Score=0;
    max=4;
    IsStop=false;
    label[0][0]->setAutoFillBackground(false);
    memset(empt, '\0', sizeof(empt));
    label[0][0]->setText(empt);
    label[0][1]->setText("0");
    memset(save, 0, sizeof(save));
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
        {
            label[i][j]->setAutoFillBackground(true);
            label[i][j]->setPalette(block_palette);
            memset(empt, '\0', sizeof(empt));
            label[i][j]->setText(empt);
        }
    sprintf(str, "%d", 2);
    int ran1, ran2;
    ran1=rand()%16;
    do
    {
        ran2=rand()%16;
    }
    while(ran2==ran1);
    label[(ran1/4)+1][ran1%4+1]->setText(str);
    save[(ran1/4)+1][ran1%4+1]=2;
    label[(ran2/4)+1][ran2%4+1]->setText(str);
    save[(ran2/4)+1][ran2%4+1]=2;
    return;
}
void gTwo::run_Up()
{
    if(!IsUp())
        return;
    memset(flag, 0, sizeof(flag));
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
        {
            if(save[j][i]==0)
                continue;
            for(int k=j-1; k>0; k--)
            {
                if(save[k][i]==0)
                {
                    if(k==1)
                    {
                        save[k][i]=save[j][i];
                        save[j][i]=0;
                        break;
                    }
                    else
                        continue;
                }
                else if(save[k][i]==save[j][i]&&flag[k][i]==false)
                {
                    save[k][i]*=2;
                    flag[k][i]=true;
                    save[j][i]=0;
                    break;
                }
                else
                {
                    if(k!=j-1)
                    {
                        save[k+1][i]=save[j][i];
                        save[j][i]=0;
                    }
                    break;
                }
            }
        }
    create_new();
    return;
}
void gTwo::run_Down()
{
    if(!IsDown())
        return;
    memset(flag, 0, sizeof(flag));
    for(int i=1; i<5; i++)
        for(int j=4; j>0; j--)
        {
            if(save[j][i]==0)
                continue;
            for(int k=j+1; k<5; k++)
            {
                if(save[k][i]==0)
                {
                    if(k==4)
                    {
                        save[k][i]=save[j][i];
                        save[j][i]=0;
                        break;
                    }
                    else
                        continue;
                }
                else if(save[k][i]==save[j][i]&&flag[k][i]==false)
                {
                    save[k][i]*=2;
                    flag[k][i]=true;
                    save[j][i]=0;
                    break;
                }
                else
                {
                    if(k!=j+1)
                    {
                        save[k-1][i]=save[j][i];
                        save[j][i]=0;
                    }
                    break;
                }
            }
        }
    create_new();
    return;
}
void gTwo::run_Left()
{
    if(!IsLeft())
        return;
    memset(flag, 0, sizeof(flag));
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
        {
            if(save[i][j]==0)
                continue;
            for(int k=j-1; k>0; k--)
            {
                if(save[i][k]==0)
                {
                    if(k==1)
                    {
                        save[i][k]=save[i][j];
                        save[i][j]=0;
                        break;
                    }
                    else
                        continue;
                }
                else if(save[i][k]==save[i][j]&&flag[i][k]==false)
                {
                    save[i][k]*=2;
                    flag[i][k]=true;
                    save[i][j]=0;
                    break;
                }
                else
                {
                    if(k!=j-1)
                    {
                        save[i][k+1]=save[i][j];
                        save[i][j]=0;
                    }
                    break;
                }
            }
        }
    create_new();
    return;
}
void gTwo::run_Right()
{
    if(!IsRight())
        return;
    memset(flag, 0, sizeof(flag));
    for(int i=1; i<5; i++)
        for(int j=4; j>0; j--)
        {
            if(save[i][j]==0)
                continue;
            for(int k=j+1; k<5; k++)
            {
                if(save[i][k]==0)
                {
                    if(k==4)
                    {
                        save[i][k]=save[i][j];
                        save[i][j]=0;
                        break;
                    }
                    else
                        continue;
                }
                else if(save[i][k]==save[i][j]&&flag[i][k]==false)
                {
                    save[i][k]*=2;
                    flag[i][k]=true;
                    save[i][j]=0;
                    break;
                }
                else
                {
                    if(k!=j+1)
                    {
                        save[i][k-1]=save[i][j];
                        save[i][j]=0;
                    }
                    break;
                }
            }
        }
    create_new();
    return;
}
void gTwo::create_new()
{
    Score+=10;
    int fill=0;
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
            if(save[i][j]!=0)
                fill++;
    if(fill==16)
        return;
    int ran_x, ran_y, ran_num;
    do
    {
        ran_x=rand()%4+1;
        ran_y=rand()%4+1;
    }
    while(save[ran_x][ran_y]!=0);
    ran_num=(rand()%2+1)*2;
    sprintf(str, "%d", ran_num);
    save[ran_x][ran_y]=ran_num;
    return;
}
void gTwo::check()
{
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
            if(save[i][j]>max)
            {
                max=save[i][j];
                Score*=2;
            }
    sprintf(str, "%d", Score);
    label[0][1]->setText(str);
    if(Score>Best)
    {
        Best=Score;
        sprintf(str, "%d", Best);
        label[1][0]->setText(str);
    }
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
        {
            if(save[i][j]==0)
            {
                memset(empt, '\0', sizeof(empt));
                label[i][j]->setText(empt);
            }
            else
            {
                sprintf(str, "%d", save[i][j]);
                label[i][j]->setText(str);
            }
        }
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
            if(save[i][j]==2048)
            {
                label[0][0]->setAutoFillBackground(true);
                label[0][0]->setPalette(result_palette);
                label[0][0]->setText("WINNING");
                IsStop=true;
                return;
            }
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
            if(save[i][j]==0)
                return;
    for(int i=1; i<5; i++)
        for(int j=1; j<5; j++)
        {
            if(i-1!=0&&save[i][j]==save[i-1][j])
                return;
            if(j-1!=0&&save[i][j]==save[i][j-1])
                return;
            if(i+1!=5&&save[i][j]==save[i+1][j])
                return;
            if(j+1!=5&&save[i][j]==save[i][j+1])
                return;
        }
    label[0][0]->setAutoFillBackground(true);
    label[0][0]->setPalette(result_palette);
    label[0][0]->setText("GameOver");
    IsStop=true;
    return;
}
bool gTwo::IsUp()
{
    for(int i=1; i<5; i++)
    {
        int j;
        for(j=1; j<4; j++)
            if(save[j][i]!=0&&save[j][i]==save[j+1][i])
                return true;
        for(j=1; j<5; j++)
            if(save[j][i]==0)
                break;
        for(; j<5; j++)
            if(save[j][i]!=0)
                return true;
    }
    return false;
}
bool gTwo::IsDown()
{
    for(int i=1; i<5; i++)
    {
        int j;
        for(j=1; j<4; j++)
            if(save[j][i]!=0&&save[j][i]==save[j+1][i])
                return true;
        for(j=4; j>=0; j--)
            if(save[j][i]==0)
                break;
        for(; j>=0; j--)
            if(save[j][i]!=0)
                return true;
    }
    return false;
}
bool gTwo::IsLeft()
{
    for(int i=1; i<5; i++)
    {
        int j;
        for(j=1; j<4; j++)
            if(save[i][j]!=0&&save[i][j]==save[i][j+1])
                return true;
        for(j=1; j<5; j++)
            if(save[i][j]==0)
                break;
        for(; j<5; j++)
            if(save[i][j]!=0)
                return true;
    }
    return false;
}
bool gTwo::IsRight()
{
    for(int i=1; i<5; i++)
    {
        int j;
        for(j=1; j<4; j++)
            if(save[i][j]!=0&&save[i][j]==save[i][j+1])
                return true;
        for(j=4; j>=0; j--)
            if(save[i][j]==0)
                break;
        for(; j>=0; j--)
            if(save[i][j]!=0)
                return true;
    }
    return false;
}
