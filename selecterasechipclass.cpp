#include "selecterasechipclass.h"

selecterasechipclass::selecterasechipclass(QWidget *parent) : QMainWindow(parent)
{

}
void selecterasechipclass::init()
{
    //1->erase 0->save
    dataset(0,1,0,1,0,1,0,1,0);
    dataset(1,0,1,0,1,0,1,0,1);
    dataset(0,1,0,1,1,1,0,1,0);
    dataset(1,0,1,0,0,0,1,0,1);
    dataset(0,1,0,1,1,0,1,0,0);
    dataset(1,0,0,0,1,1,0,1,1);
    dataset(0,1,1,1,1,0,1,0,1);
    dataset(0,1,1,1,1,0,0,0,1);
    dataset(1,0,1,0,1,0,0,1,0);
    dataset(0,1,0,1,0,1,1,0,1);
}
void selecterasechipclass::dataset(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9)
{
        DATA dat;
        dat.chip[0][0]=a1;
        dat.chip[1][0]=a2;
        dat.chip[2][0]=a3;
        dat.chip[0][1]=a4;
        dat.chip[1][1]=a5;
        dat.chip[2][1]=a6;
        dat.chip[0][2]=a7;
        dat.chip[1][2]=a8;
        dat.chip[2][2]=a9;
        list.push_back(dat);
}

void selecterasechipclass::paintEvent(QPaintEvent *event)//描画イベント
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
    painter.setBrush(QBrush(Qt::transparent, Qt::SolidPattern));
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            painter.drawRect(i*20,j*20,20,20);
        }
    }
    int n=0;int m2=0;int r1=0;int r2=0;
    for(int m=0;m<list.size();m++)
    {
        painter.setPen(QPen(Qt::red, 1, Qt::SolidLine , Qt::RoundCap));
        for(int a=0;a<3;a++)
        {
            for(int b=0;b<3;b++)
            {
                if(list[m].chip[a][b]==1)
                {

                    painter.setBrush(QBrush(QColor(160,255,255,80), Qt::SolidPattern));
                }
                else
                {
                    painter.setBrush(QBrush(QColor(255,160,255,80), Qt::SolidPattern));
                }
                painter.drawRect((a+r1+m2*3)*20,(b+r2+n*3)*20,20,20);
            }
        }
        r2++;
        if(m%4==3)
        {
            m2=0;
            n++;
        }
        else
        {
            m2++;
        }


    }
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            painter.drawRect(i*60,j*60,60,60);
        }
    }

}
void selecterasechipclass::mousePressEvent(QMouseEvent *e)
{

}
