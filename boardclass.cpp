#include"boardclass.h"

boardclass::boardclass()
{
    chipsize.setHeight(30);
    chipsize.setWidth(30);
    drawpos.setX(30);
    drawpos.setY(30);
    drawadjust.setX(35);
    drawadjust.setY(35);
    clickLen.setWidth(0);
    clickLen.setHeight(0);
    curentsekinum=0;
    enable.mousepress=true;
    enable.draw=true;
    data=new CHIPDATA**[9];
    dataclone=new CHIPDATA**[9];
    for(int i=0;i<9;i++)
    {
        data[i]=new CHIPDATA*[9];
        dataclone[i]=new CHIPDATA*[9];
        for(int j=0;j<9;j++)
        {
            data[i][j]=new CHIPDATA[9];
            dataclone[i][j]=new CHIPDATA[9];
            data[i][j]->num=0;
            data[i][j]->index=0;
            data[i][j]->xx=0;
            data[i][j]->yy=0;
            data[i][j]->lock=false;
            dataclone[i][j]->num=0;
            dataclone[i][j]->index=0;
            dataclone[i][j]->xx=0;
            dataclone[i][j]->yy=0;
            dataclone[i][j]->lock=false;
        }
    }
    erasecount=0;
}
void boardclass::clear()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            delete[] data[i][j];
            delete[] dataclone[i][j];
        }
        delete[] data[i];
        delete[] dataclone[i];
    }
    delete[] data;
    delete[] dataclone;
    chipsize.setHeight(30);
    chipsize.setWidth(30);
    drawpos.setX(30);
    drawpos.setY(30);
    drawadjust.setX(35);
    drawadjust.setY(35);
    clickLen.setWidth(0);
    clickLen.setHeight(0);
    curentsekinum=0;
    enable.mousepress=true;
    enable.draw=true;
}
boardclass::~boardclass()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            delete[] data[i][j];
            delete[] dataclone[i][j];
        }
        delete[] data[i];
        delete[] dataclone[i];
    }
    delete[] data;
    delete[] dataclone;
}
void boardclass::indexset(int mid)
{
    index=mid;
}
void boardclass::dataset(int x,int y,int num)
{
    data[x][y]->num=num;
}
int boardclass::dataget(int x,int y)
{
    return data[x][y]->num;
}
boardclass::CHIPDATA *boardclass::datagetelse(int x,int y)
{
    return data[x][y];
}
void boardclass::paintEvent(QPaintEvent *eve,QPainter *painter)
{
    LinePaint(eve,painter);
    indexPaint(eve,painter);
    NumberPaint(eve,painter);
    CirclePaint(eve,painter);
}
void boardclass::LinePaint(QPaintEvent *eve,QPainter *painter)
{
    eve=eve;
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
    int cx=chipsize.width();
    int cy=chipsize.height();
    for(int i=0;i<10;i++)
    {
        painter->drawLine(drawpos.x()+drawadjust.x()+i*cx,drawpos.y()+drawadjust.y(),drawpos.x()+drawadjust.x()+i*cx,drawpos.y()+drawadjust.y()+cy*9);
        painter->drawLine(drawpos.x()+drawadjust.x(),drawpos.y()+drawadjust.y()+i*cy,drawpos.x()+drawadjust.x()+cx*9,drawpos.y()+drawadjust.y()+i*cy);
        if(i%3==0)
        {
            painter->drawLine(drawpos.x()+drawadjust.x()+i*cx+2,drawpos.y()+drawadjust.y(),drawpos.x()+drawadjust.x()+i*cx+2,drawpos.y()+drawadjust.y()+cy*9);
            painter->drawLine(drawpos.x()+drawadjust.x(),drawpos.y()+drawadjust.y()+i*cy+2,drawpos.x()+drawadjust.x()+cx*9,drawpos.y()+drawadjust.y()+i*cy+2);
        }
    }
}
void boardclass::indexPaint(QPaintEvent *eve,QPainter *painter)
{
    eve=eve;
    painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine , Qt::RoundCap));
    painter->setFont(QFont("メイリオ",12));
    char indexstr[15];
    memset(indexstr,0,10);
    sprintf(indexstr,"%d",index);
    painter->drawText(drawpos.x()+40,drawpos.y()+30,QString(indexstr));
}

void boardclass::NumberPaint(QPaintEvent *eve,QPainter *painter)
{
    eve=eve;
    int cx=chipsize.width();
    int cy=chipsize.height();
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(data[i][j]->num!=0)
            {
                if(chipsize.width()==30)
                {
                    painter->setFont(QFont("メイリオ",12));
                    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
                    if(data[i][j]->num!=0)
                    {
                        painter->drawText(drawpos.x()+drawadjust.x()+i*cx+12,drawpos.y()+drawadjust.y()+j*cy+5,cx,cy,true,QString::number(data[i][j]->num));
                    }
                }
                if(chipsize.width()==20)
                {
                    painter->setFont(QFont("メイリオ",8));
                    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
                    if(data[i][j]->num!=0)
                    {
                        painter->drawText(drawpos.x()+drawadjust.x()+i*cx+8,drawpos.y()+drawadjust.y()+j*cy+3,cx,cy,true,QString::number(data[i][j]->num));
                    }
                }

            }
        }
    }
}
void boardclass::CirclePaint(QPaintEvent *eve,QPainter *painter)
{
    eve=eve;
    if(enable.circledraw==false){return;}
    painter->setRenderHint(QPainter::Antialiasing, true);//アンチエイリアスセット
    static int rnd=0;
    srand((rnd++)+time(NULL));
    //painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    for(int i=0;i<clicklist.size();i++)
    {
        painter->setPen(QPen(rand()%2==0?Qt::yellow:Qt::green, 3, Qt::SolidLine , Qt::RoundCap));
        painter->drawEllipse(clicklist[i].x()-20+rand()%15,clicklist[i].y()-20+rand()%15,40,40);
    }
}
bool boardclass::mousePressEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return false;}
    clickPos=event->pos();
    int n1=9;int n2=9;
    if(!(clickPos.x()>drawpos.x()+drawadjust.x() && drawpos.x()+chipsize.width()*n1+drawadjust.x()>clickPos.x() || clickPos.y()>drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()>clickPos.y())){return false;}
    //if((clickPos.x()<drawpos.x()+drawadjust.x() || drawpos.x()+chipsize.width()*n1+drawadjust.x()<clickPos.x()) && (clickPos.y()<drawpos.y()+drawadjust.y()) && (drawpos.y()+chipsize.height()*n2+drawadjust.y()<clickPos.y())){return false;}
    clickLen.setWidth(clickPos.x()-drawpos.x());
    clickLen.setHeight(clickPos.y()-drawpos.y());
    drawpos.setX(((clickPos.x()-clickLen.width())/chipsize.width())*chipsize.width());
    drawpos.setY(((clickPos.y()-clickLen.height())/chipsize.height())*chipsize.height());
    circlemousePressEvent(event);
    return true;
}
void boardclass::mouseMoveEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    clickPos=event->pos();
    int n1=9;int n2=9;

    if(clickPos.x()<drawpos.x()+drawadjust.x() || drawpos.x()+chipsize.width()*n1+drawadjust.x()<clickPos.x() || clickPos.y()<drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()<clickPos.y()){return;}
    drawpos.setX(((clickPos.x()-clickLen.width())/chipsize.width())*chipsize.width());
    drawpos.setY(((clickPos.y()-clickLen.height())/chipsize.height())*chipsize.height());
    circlemouseMoveEvent(event);
}
void boardclass::mouseReleaseEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    clickPos=event->pos();
    int n1=9;int n2=9;
    if(clickPos.x()<drawpos.x()+drawadjust.x() || drawpos.x()+chipsize.width()*n1+drawadjust.x()<clickPos.x() || clickPos.y()<drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()<clickPos.y()){return;}
    drawpos.setX(((clickPos.x()-clickLen.width())/chipsize.width())*chipsize.width());
    drawpos.setY(((clickPos.y()-clickLen.height())/chipsize.height())*chipsize.height());
    circlemouseReleaseEvent(event);
}
bool boardclass::mouseRangeIs(QPoint p)
{
    if(enable.mousepress==false){return false;}
    int n1=9;int n2=9;
    if(p.x()>=drawpos.x()+drawadjust.x() && drawpos.x()+chipsize.width()*n1+drawadjust.x()>p.x() && p.y()>drawpos.y()+drawadjust.y() && drawpos.y()+chipsize.height()*n2+drawadjust.y()>p.y()){return true;}
    return false;
}
bool boardclass::isput(int x,int y,int num)
{
    if(dataget(x,y)!=0){return false;}
    for(int i=0;i<9;i++)
    {
        if(y!=i && dataget(x,i)!=0 && dataget(x,i)==num){return false;}
        if(x!=i && dataget(i,y)!=0 && dataget(i,y)==num){return false;}
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(dataget((x/3)*3+i,(y/3)*3+j)!=0 && dataget((x/3)*3+i,(y/3)*3+j)==num){return false;}
        }
    }
    int numl[9];
    for(int i=0;i<9;i++){numl[i]=0;}
    //for(int i=0;i<9;i++){for(int j=0;j<9;j++){numl[stoneget(i,j)-1]++;}}
    //if(numl[num-1]>=8){return false;}//8 or 9 ?
    return true;
}
bool boardclass::isput3(int x,int y,int num)
{
    if(dataget(x,y)!=0){return false;}
    for(int i=0;i<9;i++)
    {
        if(y!=i && dataget(x,i)!=0 && dataget(x,i)==num){return false;}
        if(x!=i && dataget(i,y)!=0 && dataget(i,y)==num){return false;}
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(x!=(x/3)*3+i && y!=(y/3)*3+j && dataget((x/3)*3+i,(y/3)*3+j)!=0 && dataget((x/3)*3+i,(y/3)*3+j)==num){return false;}
        }
    }
    int numl[9];
    for(int i=0;i<9;i++){numl[i]=0;}
    //for(int i=0;i<9;i++){for(int j=0;j<9;j++){numl[stoneget(i,j)-1]++;}}
    //if(numl[num-1]>=8){return false;}//8 or 9 ?
    return true;
}
bool boardclass::isput2(int x,int y,int num)
{
    for(int i=0;i<9;i++)
    {
        if(y!=i && dataget(x,i)!=0 && dataget(x,i)==num){return false;}
        if(x!=i && dataget(i,y)!=0 && dataget(i,y)==num){return false;}
    }
    //for(int i=0;i<9;i++){for(int j=0;j<9;j++){numl[stoneget(i,j)-1]++;}}
    //if(numl[num-1]>=8){return false;}//8 or 9 ?
    return true;
}
bool boardclass::circlemousePressEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return false;}
    clickPos=event->pos();
    int n1=9;int n2=9;
    if(!(clickPos.x()>drawpos.x()+drawadjust.x() && drawpos.x()+chipsize.width()*n1+drawadjust.x()>clickPos.x() || clickPos.y()>drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()>clickPos.y())){return false;}
    for(int i=0;i<clicklist.size();i++)
    {
        QSize sl;
        sl.setWidth(clicklist[i].x()-drawpos.x());
        sl.setHeight(clicklist[i].y()-drawpos.y());
        sharelen.push_back(sl);
    }
    return true;
}
void boardclass::circlemouseMoveEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    clickPos=event->pos();
    int n1=9;int n2=9;
    if(clickPos.x()<drawpos.x()+drawadjust.x() || drawpos.x()+chipsize.width()*n1+drawadjust.x()<clickPos.x() || clickPos.y()<drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()<clickPos.y()){return;}
    for(int i=0;i<clicklist.size();i++)
    {
        clicklist[i].setX(sharelen[i].width()+drawpos.x());
        clicklist[i].setY(sharelen[i].height()+drawpos.y());
    }
}
void boardclass::circlemouseReleaseEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    clickPos=event->pos();
    int n1=9;int n2=9;
    if(clickPos.x()<drawpos.x()+drawadjust.x() || drawpos.x()+chipsize.width()*n1+drawadjust.x()<clickPos.x() || clickPos.y()<drawpos.y()+drawadjust.y() || drawpos.y()+chipsize.height()*n2+drawadjust.y()<clickPos.y()){return;}
    for(int i=0;i<clicklist.size();i++)
    {
        clicklist[i].setX(sharelen[i].width()+drawpos.x());
        clicklist[i].setY(sharelen[i].height()+drawpos.y());
    }
}
void boardclass::datacloneset(int x,int y,int num)
{
    dataclone[x][y]->num=num;
}
int boardclass::datacloneget(int x,int y)
{
    return dataclone[x][y]->num;
}
void boardclass::datacloneing()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            dataclone[i][j]->num=data[i][j]->num;
        }
    }
}
void boardclass::dataclonebacking()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j]->num=dataclone[i][j]->num;
        }
    }
}
QPoint boardclass::areanumberget(QPoint click)
{
    QPoint posa;
    posa.setX(-1);
    posa.setY(-1);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(click.x()>=drawpos.x()+chipsize.width()*3*i && click.x()<drawpos.x()+chipsize.width()*3*(i+1))
            {
                if(click.y()>=drawpos.y()+chipsize.height()*3*j && click.y()<drawpos.y()+chipsize.height()*3*(j+1))
                {
                    posa.setX(i);
                    posa.setY(j);
                    return posa;
                }
            }
        }
    }
    return posa;
}
void boardclass::makerandom()
{
    int brd[9][9];
    //maincreate(brd);
    for(int i=0;i<0;i++)
    {
        for(int j=0;j<9;j++)
        {
            dataset(i,j,brd[i][j]);
        }
    }
}
void boardclass::dataseterase(int x,int y)
{
    erasednum=dataget(x,y);
    if(erasednum!=0){erasecount++;}
    erasedpos.setX(x);
    erasedpos.setY(y);
    dataset(x,y,0);
}
void boardclass::dataseteraserandom()
{
    static int tt=0;
    srand(time(NULL)+(tt++));
    int x=rand()%9;
    int y=rand()%9;
    dataseterase(x,y);
}
void boardclass::dataseteraserestore()
{
    dataset(erasedpos.x(),erasedpos.y(),erasednum);
}
