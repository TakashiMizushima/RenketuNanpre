#include"ndataset.h"
ndataset::ndataset()
{
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
            data2[i][j].num=0;
        }
    }
}
void ndataset::poslistset()
{
    for(int i=0;i<3;i++)
    {        for(int j=0;j<3;j++)
        {
            poslist[i*3+j].x=i;
            poslist[i*3+j].y=j;
            poslist[i*3+j].lock=false;
        }
    }
    return;
}
int hu=0;
void ndataset::datacreated(int xx,int yy)
{
    int y1=1;int y2=2;int y3=0;
    int x1=1;int x2=2;int x3=0;
    int sa=0;
    srand((hu++)+time(NULL));
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
    if(isput(x3+sa,y1,data2[x3][y3].num)){data2[x3+sa][y1].num=data2[x3][y3].num;}
    if(isput(x1+sa,y1,data2[x1][y3].num)){data2[x1+sa][y1].num=data2[x1][y3].num;}
    if(isput(x2+sa,y2,data2[x2][y3].num)){data2[x2+sa][y2].num=data2[x2][y3].num;}
    if(isput(x3+sa,y2,data2[x3][y1].num)){data2[x3+sa][y2].num=data2[x3][y1].num;}
    if(isput(x1+sa,y2,data2[x1][y1].num)){data2[x1+sa][y2].num=data2[x1][y1].num;}
    if(isput(x2+sa,y3,data2[x2][y1].num)){data2[x2+sa][y3].num=data2[x2][y1].num;}
    if(isput(x3+sa,y3,data2[x3][y2].num)){data2[x3+sa][y3].num=data2[x3][y2].num;}
    if(isput(x1+sa,y3,data2[x1][y2].num)){data2[x1+sa][y3].num=data2[x1][y2].num;}
    if(isput(x2+sa,y1,data2[x2][y2].num)){data2[x2+sa][y1].num=data2[x2][y2].num;}
    }
    if(vec==1)
    {
    if(isput(x3+sa,y2,data2[x3][y3].num)){data2[x3+sa][y2].num=data2[x3][y3].num;}
    if(isput(x1+sa,y2,data2[x1][y3].num)){data2[x1+sa][y2].num=data2[x1][y3].num;}
    if(isput(x2+sa,y1,data2[x2][y3].num)){data2[x2+sa][y1].num=data2[x2][y3].num;}
    if(isput(x3+sa,y3,data2[x3][y1].num)){data2[x3+sa][y3].num=data2[x3][y1].num;}
    if(isput(x1+sa,y3,data2[x1][y1].num)){data2[x1+sa][y3].num=data2[x1][y1].num;}
    if(isput(x2+sa,y2,data2[x2][y1].num)){data2[x2+sa][y2].num=data2[x2][y1].num;}
    if(isput(x3+sa,y1,data2[x3][y2].num)){data2[x3+sa][y1].num=data2[x3][y2].num;}
    if(isput(x1+sa,y1,data2[x1][y2].num)){data2[x1+sa][y1].num=data2[x1][y2].num;}
    if(isput(x2+sa,y3,data2[x2][y2].num)){data2[x2+sa][y3].num=data2[x2][y2].num;}
    }
    if(vec==2)
    {
    if(isput(x3+sa,y2,data2[x3][y3].num)){data2[x3+sa][y2].num=data2[x3][y3].num;}
    if(isput(x1+sa,y1,data2[x1][y3].num)){data2[x1+sa][y1].num=data2[x1][y3].num;}
    if(isput(x2+sa,y2,data2[x2][y3].num)){data2[x2+sa][y2].num=data2[x2][y3].num;}
    if(isput(x3+sa,y3,data2[x3][y1].num)){data2[x3+sa][y3].num=data2[x3][y1].num;}
    if(isput(x1+sa,y2,data2[x1][y1].num)){data2[x1+sa][y2].num=data2[x1][y1].num;}
    if(isput(x2+sa,y3,data2[x2][y1].num)){data2[x2+sa][y3].num=data2[x2][y1].num;}
    if(isput(x3+sa,y1,data2[x3][y2].num)){data2[x3+sa][y1].num=data2[x3][y2].num;}
    if(isput(x1+sa,y3,data2[x1][y2].num)){data2[x1+sa][y3].num=data2[x1][y2].num;}
    if(isput(x2+sa,y1,data2[x2][y2].num)){data2[x2+sa][y1].num=data2[x2][y2].num;}
    }
    if(vec==3)
    {
    if(isput(x3+sa,y1,data2[x3][y3].num)){data2[x3+sa][y1].num=data2[x3][y3].num;}
    if(isput(x1+sa,y2,data2[x1][y3].num)){data2[x1+sa][y2].num=data2[x1][y3].num;}
    if(isput(x2+sa,y1,data2[x2][y3].num)){data2[x2+sa][y1].num=data2[x2][y3].num;}
    if(isput(x3+sa,y2,data2[x3][y1].num)){data2[x3+sa][y2].num=data2[x3][y1].num;}
    if(isput(x1+sa,y3,data2[x1][y1].num)){data2[x1+sa][y3].num=data2[x1][y1].num;}
    if(isput(x2+sa,y2,data2[x2][y1].num)){data2[x2+sa][y2].num=data2[x2][y1].num;}
    if(isput(x3+sa,y3,data2[x3][y2].num)){data2[x3+sa][y3].num=data2[x3][y2].num;}
    if(isput(x1+sa,y1,data2[x1][y2].num)){data2[x1+sa][y1].num=data2[x1][y2].num;}
    if(isput(x2+sa,y3,data2[x2][y2].num)){data2[x2+sa][y3].num=data2[x2][y2].num;}
    }
}

void ndataset::datacreatee(int xx,int yy)
{
    int y1=1;int y2=2;int y3=0;
    int x1=1;int x2=2;int x3=0;
    int sa=0;
    srand((hu++)+time(NULL));
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
    if(isput(y1,x3+sa,data2[y3][x3].num)){data2[y1][x3+sa].num=data2[y3][x3].num;}
    if(isput(y1,x1+sa,data2[y3][x1].num)){data2[y1][x1+sa].num=data2[y3][x1].num;}
    if(isput(y2,x2+sa,data2[y3][x2].num)){data2[y2][x2+sa].num=data2[y3][x2].num;}
    if(isput(y2,x3+sa,data2[y1][x3].num)){data2[y2][x3+sa].num=data2[y1][x3].num;}
    if(isput(y2,x1+sa,data2[y1][x1].num)){data2[y2][x1+sa].num=data2[y1][x1].num;}
    if(isput(y3,x2+sa,data2[y1][x2].num)){data2[y3][x2+sa].num=data2[y1][x2].num;}
    if(isput(y3,x3+sa,data2[y2][x3].num)){data2[y3][x3+sa].num=data2[y2][x3].num;}
    if(isput(y3,x1+sa,data2[y2][x1].num)){data2[y3][x1+sa].num=data2[y2][x1].num;}
    if(isput(y1,x2+sa,data2[y2][x2].num)){data2[y1][x2+sa].num=data2[y2][x2].num;}
    }
    if(vec==1)
    {
    if(isput(y2,x3+sa,data2[y3][x3].num)){data2[y2][x3+sa].num=data2[y3][x3].num;}
    if(isput(y2,x1+sa,data2[y3][x1].num)){data2[y2][x1+sa].num=data2[y3][x1].num;}
    if(isput(y1,x2+sa,data2[y3][x2].num)){data2[y1][x2+sa].num=data2[y3][x2].num;}
    if(isput(y3,x3+sa,data2[y1][x3].num)){data2[y3][x3+sa].num=data2[y1][x3].num;}
    if(isput(y3,x1+sa,data2[y1][x1].num)){data2[y3][x1+sa].num=data2[y1][x1].num;}
    if(isput(y2,x2+sa,data2[y1][x2].num)){data2[y2][x2+sa].num=data2[y1][x2].num;}
    if(isput(y1,x3+sa,data2[y2][x3].num)){data2[y1][x3+sa].num=data2[y2][x3].num;}
    if(isput(y1,x1+sa,data2[y2][x1].num)){data2[y1][x1+sa].num=data2[y2][x1].num;}
    if(isput(y3,x2+sa,data2[y2][x2].num)){data2[y3][x2+sa].num=data2[y2][x2].num;}
    }
    if(vec==2)
    {
    if(isput(y2,x3+sa,data2[y3][x3].num)){data2[y2][x3+sa].num=data2[y3][x3].num;}
    if(isput(y1,x1+sa,data2[y3][x1].num)){data2[y1][x1+sa].num=data2[y3][x1].num;}
    if(isput(y2,x2+sa,data2[y3][x2].num)){data2[y2][x2+sa].num=data2[y3][x2].num;}
    if(isput(y3,x3+sa,data2[y1][x3].num)){data2[y3][x3+sa].num=data2[y1][x3].num;}
    if(isput(y2,x1+sa,data2[y1][x1].num)){data2[y2][x1+sa].num=data2[y1][x1].num;}
    if(isput(y3,x2+sa,data2[y1][x2].num)){data2[y3][x2+sa].num=data2[y1][x2].num;}
    if(isput(y1,x3+sa,data2[y2][x3].num)){data2[y1][x3+sa].num=data2[y2][x3].num;}
    if(isput(y3,x1+sa,data2[y2][x1].num)){data2[y3][x1+sa].num=data2[y2][x1].num;}
    if(isput(y1,x2+sa,data2[y2][x2].num)){data2[y1][x2+sa].num=data2[y2][x2].num;}
    }
    if(vec==3)
    {
    if(isput(y1,x3+sa,data2[y3][x3].num)){data2[y1][x3+sa].num=data2[y3][x3].num;}
    if(isput(y2,x1+sa,data2[y3][x1].num)){data2[y2][x1+sa].num=data2[y3][x1].num;}
    if(isput(y1,x2+sa,data2[y3][x2].num)){data2[y1][x2+sa].num=data2[y3][x2].num;}
    if(isput(y2,x3+sa,data2[y1][x3].num)){data2[y2][x3+sa].num=data2[y1][x3].num;}
    if(isput(y3,x1+sa,data2[y1][x1].num)){data2[y3][x1+sa].num=data2[y1][x1].num;}
    if(isput(y2,x2+sa,data2[y1][x2].num)){data2[y2][x2+sa].num=data2[y1][x2].num;}
    if(isput(y3,x3+sa,data2[y2][x3].num)){data2[y3][x3+sa].num=data2[y2][x3].num;}
    if(isput(y1,x1+sa,data2[y2][x1].num)){data2[y1][x1+sa].num=data2[y2][x1].num;}
    if(isput(y3,x2+sa,data2[y2][x2].num)){data2[y3][x2+sa].num=data2[y2][x2].num;}
    }
}
void ndataset::posdataset(int ix,int iy,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9)
{
    int index=ix*3+iy;
    //if(poslist[index].lock==true){return;}
    //poslist[index].lock=true;
    data2[poslist[index].x*3+0][poslist[index].y*3+0].num=n1;
    data2[poslist[index].x*3+1][poslist[index].y*3+0].num=n4;
    data2[poslist[index].x*3+2][poslist[index].y*3+0].num=n7;
    data2[poslist[index].x*3+0][poslist[index].y*3+1].num=n2;
    data2[poslist[index].x*3+1][poslist[index].y*3+1].num=n5;
    data2[poslist[index].x*3+2][poslist[index].y*3+1].num=n8;
    data2[poslist[index].x*3+0][poslist[index].y*3+2].num=n3;
    data2[poslist[index].x*3+1][poslist[index].y*3+2].num=n6;
    data2[poslist[index].x*3+2][poslist[index].y*3+2].num=n9;
    //poslist[index].lock=true;
    startpos=index;
}
bool ndataset::isput(int x,int y,int num)
{
    if(data2[x][y].num!=0){return false;}
    for(int i=0;i<9;i++)
    {
        if(data2[x][i].num!=0 && data2[x][i].num==num){return false;}
        if(data2[i][y].num!=0 && data2[i][y].num==num){return false;}
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(data2[(x/3)*3+i][(y/3)*3+j].num!=0 && data2[(x/3)*3+i][(y/3)*3+j].num==num){return false;}
        }
    }
    return true;
}
int pcnt=0;
bool ndataset::datacreate()
{
    line1:
    if(pcnt==800){pcnt=0;return false;}
    pcnt++;
    datacreated(startpos/3,startpos%3);
    datacreatee(startpos/3,startpos%3);
    if(datacreatec()==false){goto line1;}
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            bd->dataset(i,j,data2[i][j].num);
        }
    }
    return true;
}
int mn=0;
void ndataset::datacreatea(int index)
{
    if(index==startpos){poslist[index].lock=false;}
    if(poslist[index].lock==true){return;}
    int x=poslist[index].x;
    int y=poslist[index].y;
    poslist[index].lock=true;
    int x2;int x3;int y2;int y3;bool b1=true;bool b2=false;bool b3=false;int i2;int i3;
    srand((mn++)+time(NULL));
    int rmn=rand()%4;
    if(rmn==0)
    {
        if(x==0){x2=1;x3=2;}if(x==1){x2=2;x3=0;}if(x==2){x2=0;x3=1;}
        if(y==0){y2=1;y3=2;}if(y==1){y2=2;y3=0;}if(y==2){y2=0;y3=1;}
    }
    if(rmn==1)
    {
        if(x==0){x2=2;x3=1;}if(x==1){x2=0;x3=2;}if(x==2){x2=1;x3=0;}
        if(y==0){y2=2;y3=1;}if(y==1){y2=0;y3=2;}if(y==2){y2=1;y3=0;}
    }
    if(rmn==2)
    {
        if(x==0){x2=2;x3=1;}if(x==1){x2=0;x3=2;}if(x==2){x2=1;x3=0;}
        if(y==0){y2=1;y3=2;}if(y==1){y2=2;y3=0;}if(y==2){y2=0;y3=1;}
    }
    if(rmn==3)
    {
        if(x==0){x2=1;x3=2;}if(x==1){x2=2;x3=0;}if(x==2){x2=0;x3=1;}
        if(y==0){y2=2;y3=1;}if(y==1){y2=0;y3=2;}if(y==2){y2=1;y3=0;}
    }
    mn++;
    for(int i=0;i<9;i++)
    {
        if(poslist[i].lock==true && b2==false && poslist[i].x==x2 && poslist[i].y==y){b2=true;i2=i;}
        if(poslist[i].lock==true && b3==false && poslist[i].x==x3 && poslist[i].y==y){b3=true;i3=i;}
    }
    int numlist[9][9];
    if(b2==true || b3==true)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int m=0;m<9;m++){numlist[i][m]=m+1;}
                numlist[i][data2[i][j].num-1]=0;
                for(int a=0;a<100;a++)
                {
                    srand((mn++)+time(NULL));
                    int a1=rand()%9;
                    int a2=rand()%9;
                    int t=numlist[i][a1];
                    numlist[i][a1]=numlist[i][a2];
                    numlist[i][a2]=t;

                }
                for(int k=0;k<9;k++)
                {
                    if(numlist[i][k]!=0 && isput(poslist[index].x*3+i,poslist[index].y*3+j,k+1))
                    {
                        data2[poslist[index].x*3+i][poslist[index].y*3+j].num=k+1;
                        numlist[i][k]=0;
                    }
                }
            }
        }
    }
}
void ndataset::datacreateb(int index)
{
    if(index==startpos){poslist[index].lock=false;}
    if(poslist[index].lock==true){return;}
    int x=poslist[index].x;
    int y=poslist[index].y;
    poslist[index].lock=true;
    int x2;int x3;int y2;int y3;bool b1=true;bool b2=false;bool b3=false;int i2;int i3;
    srand((mn++)+time(NULL));
    int rmn=rand()%4;
    if(rmn==0)
    {
        if(x==0){x2=1;x3=2;}if(x==1){x2=2;x3=0;}if(x==2){x2=0;x3=1;}
        if(y==0){y2=1;y3=2;}if(y==1){y2=2;y3=0;}if(y==2){y2=0;y3=1;}
    }
    if(rmn==1)
    {
        if(x==0){x2=2;x3=1;}if(x==1){x2=0;x3=2;}if(x==2){x2=1;x3=0;}
        if(y==0){y2=2;y3=1;}if(y==1){y2=0;y3=2;}if(y==2){y2=1;y3=0;}
    }
    if(rmn==2)
    {
        if(x==0){x2=2;x3=1;}if(x==1){x2=0;x3=2;}if(x==2){x2=1;x3=0;}
        if(y==0){y2=1;y3=2;}if(y==1){y2=2;y3=0;}if(y==2){y2=0;y3=1;}
    }
    if(rmn==3)
    {
        if(x==0){x2=1;x3=2;}if(x==1){x2=2;x3=0;}if(x==2){x2=0;x3=1;}
        if(y==0){y2=2;y3=1;}if(y==1){y2=0;y3=2;}if(y==2){y2=1;y3=0;}
    }
    mn++;
    for(int i=0;i<9;i++)
    {
        if(poslist[i].lock==true && b2==false && poslist[i].x==x && poslist[i].y==y2){b2=true;i2=i;}
        if(poslist[i].lock==true && b3==false && poslist[i].x==x && poslist[i].y==y3){b3=true;i3=i;}
    }
    int numlist[9][9];
    if(b2==true || b3==true)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int m=0;m<9;m++){numlist[i][m]=m+1;}
                numlist[i][data2[j][i].num-1]=0;
                for(int a=0;a<100;a++)
                {
                    srand((mn++)+time(NULL));
                    int a1=rand()%9;
                    int a2=rand()%9;
                    int t=numlist[i][a1];
                    numlist[i][a1]=numlist[i][a2];
                    numlist[i][a2]=t;

                }
                for(int k=0;k<9;k++)
                {
                    if(numlist[i][k]!=0 && isput(poslist[index].x*3+j,poslist[index].y*3+i,k+1))
                    {
                        data2[poslist[index].x*3+j][poslist[index].y*3+i].num=k+1;
                        numlist[i][k]=0;
                    }
                }
            }
        }
    }
}

bool ndataset::datacreatec()
{
    int a=0;
    for(int i=0;i<9;i++)
    {
        if(poslist[i].lock==false){poslist[i].lock=true;a=i;break;}
    }
    int ml[3];int nl[3];for(int a=0;a<3;a++){ml[a]=a;nl[a]=a;}
    for(int k=0;k<100;k++)
    {
        srand((mn++)+time(NULL));
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
                data2[poslist[a].x*3+ml[m]][poslist[a].y*3+nl[n]].num=i+1;
            }
        }

    }
    px=new SudokuPuzzle;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            px->setBoardValue(i,j,data2[i][j].num);
        }
    }
    if(px->solve()==false){return false;}
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data2[i][j].num=px->data[i][j]->num;
        }
    }
    delete px;
    return true;
}

