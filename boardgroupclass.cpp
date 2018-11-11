#include"boardgroupclass.h"

void boardgroupclass::boardclassadd()
{
    boardclass *brd=new boardclass;
    brd->index=brdgroup.size();
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            brd->data[i][j]->xx=i/3;
            brd->data[i][j]->yy=j/3;
        }
    }
    brdgroup.push_back(brd);
}
void boardgroupclass::clear()
{
    for(int i=0;i<brdgroup.size();i++)
    {
        brdgroup[i]->clear();
    }
    brdgroup.clear();
}
void boardgroupclass::paintEvent(QPaintEvent *eve,QPainter *painter)
{
    int cnt=brdgroup.size();
    for(unsigned int i=0;i<cnt;i++)
    {
        brdgroup[i]->paintEvent(eve,painter);
    }
}
boardgroupclass::boardgroupclass()
{
    curentbrdnum=0;
}
void boardgroupclass::mousePressEvent(QMouseEvent *event)
{
    if(brdgroup.size()==0){return;}
    for(unsigned int i=0;i<brdgroup.size();i++)
    {
        if(brdgroup[i]->mouseRangeIs(event->pos())==false){curentbrdnum=-1;}
        else{curentbrdnum=i;break;}
    }
    if(curentbrdnum==-1){return;}
    brdgroup[curentbrdnum]->mousePressEvent(event);
}
void boardgroupclass::mouseMoveEvent(QMouseEvent *event)
{
    brdgroup[curentbrdnum]->mouseMoveEvent(event);
}
void boardgroupclass::mouseReleaseEvent(QMouseEvent *event)
{
    brdgroup[curentbrdnum]->mouseReleaseEvent(event);
}
boardclass *boardgroupclass::curentboardget()
{
    return brdgroup[curentbrdnum];
}
void boardgroupclass::curentboardindexset(int index)
{
    curentbrdnum=index;
}
boardclass *boardgroupclass::boardget(int index)
{
    return brdgroup[index];
}
QPoint boardgroupclass::areanumberget(QPoint click,int *index,int *x,int *y,int cnt)
{
    int cntx=brdgroup.size();
    QPoint posa;
    posa.setX(-1);
    posa.setY(-1);
    for(unsigned int i=0;i<cntx;i++)
    {
        int x1=brdgroup[i]->areanumberget(click).x();
        int y1=brdgroup[i]->areanumberget(click).y();
        if(x1!=-1 && cnt==0)
        {
            cnt--;
            posa.setX(x1);
            posa.setY(y1);
            *x=x1;
            *y=y1;
            *index=i;
            return posa;
        }
    }
    *index=-1;
    return posa;
}
