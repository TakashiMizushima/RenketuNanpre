#include"stonecreateclass.h"
stonecreateclass::stonecreateclass()
{
    px=new SudokuPuzzle;
    for(int i=0;i<9;i++)
    {
        poslist[i].x=0;
        poslist[i].y=0;
        poslist[i].lock=false;
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=0;
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            poslist[i*3+j].x=i;
            poslist[i*3+j].y=j;
            poslist[i*3+j].lock=false;
        }
    }
}
stonecreateclass::~stonecreateclass()
{
    delete px;
}
int hu2=0;
void stonecreateclass::datacreated(int xx,int yy)
{
    int y1=1;int y2=2;int y3=0;
    int x1=1;int x2=2;int x3=0;
    int sa=0;
    srand((hu2++)+time(NULL));
    int vec=rand()%4;
    if(xx==0 && yy==0){x1=1;x2=2;x3=0;y1=1;y2=2;y3=0;sa=3;}
    if(xx==1 && yy==0){x1=4;x2=5;x3=3;y1=1;y2=2;y3=0;sa=3;}
    if(xx==2 && yy==0){x1=7;x2=8;x3=6;y1=1;y2=2;y3=0;sa=-6;}
    if(xx==0 && yy==1){x1=1;x2=2;x3=0;y1=4;y2=5;y3=3;sa=3;}
    if(xx==1 && yy==1){x1=4;x2=5;x3=3;y1=4;y2=5;y3=3;sa=3;}
    if(xx==2 && yy==1){x1=7;x2=8;x3=6;y1=4;y2=5;y3=3;sa=-6;}
    if(xx==0 && yy==2){x1=1;x2=2;x3=0;y1=7;y2=8;y3=6;sa=3;}
    if(xx==1 && yy==2){x1=4;x2=5;x3=3;y1=7;y2=8;y3=6;sa=3;}
    if(xx==2 && yy==2){x1=7;x2=8;x3=6;y1=7;y2=8;y3=6;sa=-6;}
    if(vec==0)
    {
    if(isput(x3+sa,y1,data[x3][y3].num)){data[x3+sa][y1].num=data[x3][y3].num;}
    if(isput(x1+sa,y1,data[x1][y3].num)){data[x1+sa][y1].num=data[x1][y3].num;}
    if(isput(x2+sa,y2,data[x2][y3].num)){data[x2+sa][y2].num=data[x2][y3].num;}
    if(isput(x3+sa,y2,data[x3][y1].num)){data[x3+sa][y2].num=data[x3][y1].num;}
    if(isput(x1+sa,y2,data[x1][y1].num)){data[x1+sa][y2].num=data[x1][y1].num;}
    if(isput(x2+sa,y3,data[x2][y1].num)){data[x2+sa][y3].num=data[x2][y1].num;}
    if(isput(x3+sa,y3,data[x3][y2].num)){data[x3+sa][y3].num=data[x3][y2].num;}
    if(isput(x1+sa,y3,data[x1][y2].num)){data[x1+sa][y3].num=data[x1][y2].num;}
    if(isput(x2+sa,y1,data[x2][y2].num)){data[x2+sa][y1].num=data[x2][y2].num;}
    }
    if(vec==1)
    {
    if(isput(x3+sa,y2,data[x3][y3].num)){data[x3+sa][y2].num=data[x3][y3].num;}
    if(isput(x1+sa,y2,data[x1][y3].num)){data[x1+sa][y2].num=data[x1][y3].num;}
    if(isput(x2+sa,y1,data[x2][y3].num)){data[x2+sa][y1].num=data[x2][y3].num;}
    if(isput(x3+sa,y3,data[x3][y1].num)){data[x3+sa][y3].num=data[x3][y1].num;}
    if(isput(x1+sa,y3,data[x1][y1].num)){data[x1+sa][y3].num=data[x1][y1].num;}
    if(isput(x2+sa,y2,data[x2][y1].num)){data[x2+sa][y2].num=data[x2][y1].num;}
    if(isput(x3+sa,y1,data[x3][y2].num)){data[x3+sa][y1].num=data[x3][y2].num;}
    if(isput(x1+sa,y1,data[x1][y2].num)){data[x1+sa][y1].num=data[x1][y2].num;}
    if(isput(x2+sa,y3,data[x2][y2].num)){data[x2+sa][y3].num=data[x2][y2].num;}
    }
    if(vec==2)
    {
    if(isput(x3+sa,y2,data[x3][y3].num)){data[x3+sa][y2].num=data[x3][y3].num;}
    if(isput(x1+sa,y1,data[x1][y3].num)){data[x1+sa][y1].num=data[x1][y3].num;}
    if(isput(x2+sa,y2,data[x2][y3].num)){data[x2+sa][y2].num=data[x2][y3].num;}
    if(isput(x3+sa,y3,data[x3][y1].num)){data[x3+sa][y3].num=data[x3][y1].num;}
    if(isput(x1+sa,y2,data[x1][y1].num)){data[x1+sa][y2].num=data[x1][y1].num;}
    if(isput(x2+sa,y3,data[x2][y1].num)){data[x2+sa][y3].num=data[x2][y1].num;}
    if(isput(x3+sa,y1,data[x3][y2].num)){data[x3+sa][y1].num=data[x3][y2].num;}
    if(isput(x1+sa,y3,data[x1][y2].num)){data[x1+sa][y3].num=data[x1][y2].num;}
    if(isput(x2+sa,y1,data[x2][y2].num)){data[x2+sa][y1].num=data[x2][y2].num;}
    }
    if(vec==3)
    {
    if(isput(x3+sa,y1,data[x3][y3].num)){data[x3+sa][y1].num=data[x3][y3].num;}
    if(isput(x1+sa,y2,data[x1][y3].num)){data[x1+sa][y2].num=data[x1][y3].num;}
    if(isput(x2+sa,y1,data[x2][y3].num)){data[x2+sa][y1].num=data[x2][y3].num;}
    if(isput(x3+sa,y2,data[x3][y1].num)){data[x3+sa][y2].num=data[x3][y1].num;}
    if(isput(x1+sa,y3,data[x1][y1].num)){data[x1+sa][y3].num=data[x1][y1].num;}
    if(isput(x2+sa,y2,data[x2][y1].num)){data[x2+sa][y2].num=data[x2][y1].num;}
    if(isput(x3+sa,y3,data[x3][y2].num)){data[x3+sa][y3].num=data[x3][y2].num;}
    if(isput(x1+sa,y1,data[x1][y2].num)){data[x1+sa][y1].num=data[x1][y2].num;}
    if(isput(x2+sa,y3,data[x2][y2].num)){data[x2+sa][y3].num=data[x2][y2].num;}
    }
}

void stonecreateclass::datacreatee(int xx,int yy)
{
    int y1=1;int y2=2;int y3=0;
    int x1=1;int x2=2;int x3=0;
    int sa=0;
    srand((hu2++)+time(NULL));
    int vec=rand()%4;
    if(xx==0 && yy==0){x1=1;x2=2;x3=0;y1=1;y2=2;y3=0;sa=3;}
    if(xx==0 && yy==1){x1=4;x2=5;x3=3;y1=1;y2=2;y3=0;sa=3;}
    if(xx==0 && yy==2){x1=7;x2=8;x3=6;y1=1;y2=2;y3=0;sa=-6;}
    if(xx==1 && yy==0){x1=1;x2=2;x3=0;y1=4;y2=5;y3=3;sa=3;}
    if(xx==1 && yy==1){x1=4;x2=5;x3=3;y1=4;y2=5;y3=3;sa=3;}
    if(xx==1 && yy==2){x1=7;x2=8;x3=6;y1=4;y2=5;y3=3;sa=-6;}
    if(xx==2 && yy==0){x1=1;x2=2;x3=0;y1=7;y2=8;y3=6;sa=3;}
    if(xx==2 && yy==1){x1=4;x2=5;x3=3;y1=7;y2=8;y3=6;sa=3;}
    if(xx==2 && yy==2){x1=7;x2=8;x3=6;y1=7;y2=8;y3=6;sa=-6;}
    if(vec==0)
    {
    if(isput(y1,x3+sa,data[y3][x3].num)){data[y1][x3+sa].num=data[y3][x3].num;}
    if(isput(y1,x1+sa,data[y3][x1].num)){data[y1][x1+sa].num=data[y3][x1].num;}
    if(isput(y2,x2+sa,data[y3][x2].num)){data[y2][x2+sa].num=data[y3][x2].num;}
    if(isput(y2,x3+sa,data[y1][x3].num)){data[y2][x3+sa].num=data[y1][x3].num;}
    if(isput(y2,x1+sa,data[y1][x1].num)){data[y2][x1+sa].num=data[y1][x1].num;}
    if(isput(y3,x2+sa,data[y1][x2].num)){data[y3][x2+sa].num=data[y1][x2].num;}
    if(isput(y3,x3+sa,data[y2][x3].num)){data[y3][x3+sa].num=data[y2][x3].num;}
    if(isput(y3,x1+sa,data[y2][x1].num)){data[y3][x1+sa].num=data[y2][x1].num;}
    if(isput(y1,x2+sa,data[y2][x2].num)){data[y1][x2+sa].num=data[y2][x2].num;}
    }
    if(vec==1)
    {
    if(isput(y2,x3+sa,data[y3][x3].num)){data[y2][x3+sa].num=data[y3][x3].num;}
    if(isput(y2,x1+sa,data[y3][x1].num)){data[y2][x1+sa].num=data[y3][x1].num;}
    if(isput(y1,x2+sa,data[y3][x2].num)){data[y1][x2+sa].num=data[y3][x2].num;}
    if(isput(y3,x3+sa,data[y1][x3].num)){data[y3][x3+sa].num=data[y1][x3].num;}
    if(isput(y3,x1+sa,data[y1][x1].num)){data[y3][x1+sa].num=data[y1][x1].num;}
    if(isput(y2,x2+sa,data[y1][x2].num)){data[y2][x2+sa].num=data[y1][x2].num;}
    if(isput(y1,x3+sa,data[y2][x3].num)){data[y1][x3+sa].num=data[y2][x3].num;}
    if(isput(y1,x1+sa,data[y2][x1].num)){data[y1][x1+sa].num=data[y2][x1].num;}
    if(isput(y3,x2+sa,data[y2][x2].num)){data[y3][x2+sa].num=data[y2][x2].num;}
    }
    if(vec==2)
    {
    if(isput(y2,x3+sa,data[y3][x3].num)){data[y2][x3+sa].num=data[y3][x3].num;}
    if(isput(y1,x1+sa,data[y3][x1].num)){data[y1][x1+sa].num=data[y3][x1].num;}
    if(isput(y2,x2+sa,data[y3][x2].num)){data[y2][x2+sa].num=data[y3][x2].num;}
    if(isput(y3,x3+sa,data[y1][x3].num)){data[y3][x3+sa].num=data[y1][x3].num;}
    if(isput(y2,x1+sa,data[y1][x1].num)){data[y2][x1+sa].num=data[y1][x1].num;}
    if(isput(y3,x2+sa,data[y1][x2].num)){data[y3][x2+sa].num=data[y1][x2].num;}
    if(isput(y1,x3+sa,data[y2][x3].num)){data[y1][x3+sa].num=data[y2][x3].num;}
    if(isput(y3,x1+sa,data[y2][x1].num)){data[y3][x1+sa].num=data[y2][x1].num;}
    if(isput(y1,x2+sa,data[y2][x2].num)){data[y1][x2+sa].num=data[y2][x2].num;}
    }
    if(vec==3)
    {
    if(isput(y1,x3+sa,data[y3][x3].num)){data[y1][x3+sa].num=data[y3][x3].num;}
    if(isput(y2,x1+sa,data[y3][x1].num)){data[y2][x1+sa].num=data[y3][x1].num;}
    if(isput(y1,x2+sa,data[y3][x2].num)){data[y1][x2+sa].num=data[y3][x2].num;}
    if(isput(y2,x3+sa,data[y1][x3].num)){data[y2][x3+sa].num=data[y1][x3].num;}
    if(isput(y3,x1+sa,data[y1][x1].num)){data[y3][x1+sa].num=data[y1][x1].num;}
    if(isput(y2,x2+sa,data[y1][x2].num)){data[y2][x2+sa].num=data[y1][x2].num;}
    if(isput(y3,x3+sa,data[y2][x3].num)){data[y3][x3+sa].num=data[y2][x3].num;}
    if(isput(y1,x1+sa,data[y2][x1].num)){data[y1][x1+sa].num=data[y2][x1].num;}
    if(isput(y3,x2+sa,data[y2][x2].num)){data[y3][x2+sa].num=data[y2][x2].num;}
    }
}
void stonecreateclass::posdataset(int ix,int iy,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9)
{
    int index=ix*3+iy;
    //if(poslist[index].lock==true){return;}
    //poslist[index].lock=true;
    data[poslist[index].x*3+0][poslist[index].y*3+0].num=n1;
    data[poslist[index].x*3+1][poslist[index].y*3+0].num=n4;
    data[poslist[index].x*3+2][poslist[index].y*3+0].num=n7;
    data[poslist[index].x*3+0][poslist[index].y*3+1].num=n2;
    data[poslist[index].x*3+1][poslist[index].y*3+1].num=n5;
    data[poslist[index].x*3+2][poslist[index].y*3+1].num=n8;
    data[poslist[index].x*3+0][poslist[index].y*3+2].num=n3;
    data[poslist[index].x*3+1][poslist[index].y*3+2].num=n6;
    data[poslist[index].x*3+2][poslist[index].y*3+2].num=n9;
    //poslist[index].lock=true;
    startpos=index;
}
bool stonecreateclass::isput(int x,int y,int num)
{
    if(data[x][y].num!=0){return false;}
    for(int i=0;i<9;i++)
    {
        if(data[x][i].num!=0 && data[x][i].num==num){return false;}
        if(data[i][y].num!=0 && data[i][y].num==num){return false;}
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(data[(x/3)*3+i][(y/3)*3+j].num!=0 && data[(x/3)*3+i][(y/3)*3+j].num==num){return false;}
        }
    }
    return true;
}
int pcnt2=0;
bool stonecreateclass::datacreate()
{
    line1:
    if(pcnt2==800){pcnt2=0;return false;}
    pcnt2++;
    datacreated(startpos/3,startpos%3);
    datacreatee(startpos/3,startpos%3);
    if(datacreatec()==false){goto line1;}
    return true;
}
int mn2=0;

bool stonecreateclass::datacreatec()
{
    int a=0;
    for(int i=0;i<9;i++)
    {
        if(poslist[i].lock==false){poslist[i].lock=true;a=i;break;}
    }
    int ml[3];int nl[3];for(int a=0;a<3;a++){ml[a]=a;nl[a]=a;}
    for(int k=0;k<100;k++)
    {
        srand((mn2++)+time(NULL));
        int as1=rand()%3;
        int bs1=rand()%3;
        int as2=rand()%3;
        int bs2=rand()%3;
        int tm=ml[as1];ml[as1]=ml[as2];ml[as2]=tm;
        int tn=nl[bs1];nl[bs1]=nl[bs2];nl[bs2]=tn;
    }
    for(int m=0;m<3;m++)
    {
        int n=0;
        for(int i=0;i<9;i++)
        {
            if(isput(poslist[a].x*3+ml[m],poslist[a].y*3+nl[n],i+1)==true)
            {
                data[poslist[a].x*3+ml[m]][poslist[a].y*3+nl[n]].num=i+1;
            }
        }

    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            px->setBoardValue(i,j,data[i][j].num);
        }
    }
    if(px->solve()==false){return false;}
    return true;
}
void stonecreateclass::boardclassset(boardclass *bd)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=bd->dataget(i,j);
        }
    }
}

void stonecreateclass::boardclassget(boardclass *bd)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=px->dataget(i,j);
            bd->dataset(i,j,data[i][j].num);
        }
    }
}
