#include"numberloopclass.h"

numberloopclass::numberloopclass()
{

}
numberloopclass::~numberloopclass()
{

}
void numberloopclass::boardclassadd(boardclass *mbrd,int startnumber,int two,int xx,int yy)
{
    DATA data;
    data.brd=mbrd;
    data.startnumber=startnumber;
    data.curentnumber=startnumber;
    data.index=mbrd->index;
    data.loopdoneis=false;
    data.passcount=0;
    data.totalnumber=0;
    data.two=two;
    data.xx=xx;
    data.yy=yy;
    for(int i=0;i<9;i++)
    {
        data.list[i]=0;
    }
    for(int i=mobject.size()-1;i>=0;i--)
   {
       if(mobject[i].brd==mbrd && mobject[i].two==two && mobject[i].xx==xx && mobject[i].yy==yy){return;}
   }
    mobject.push_back(data);
}
int numberloopclass::numprevset(boardclass *mbrd,int num)
{
    int i;
    for(i=mobject.size()-1;i>=0;i--)
   {
       if(mobject[i].brd==mbrd){return 0;}
   }
    mobject[i].curentnumber=num;
    return 0;
}
int numberloopclass::nextnum(boardclass *mbr,int two,int xx,int yy)
{
    int sum;
    int n=mobject.size()-1;
    while(1)
    {

        if(mobject[n].brd==mbr && mobject[n].two==two && mobject[n].xx==xx && mobject[n].yy==yy)
        {
            break;
        }
        n--;
    }
    mobject[n].curentnumber++;

line2:
    if(mobject[n].curentnumber>987654321){mobject[n].curentnumber=123456789;}
    int n2=mobject[n].curentnumber;
    bool swi=false;
    for(int i=0;i<9;i++)
    {
        mobject[n].list[i]=n2%10;n2=n2/10;
    }
    /*
    boardclass *tui;
    int tuix=0;int tuiy=0;
    for(int m=0;m<brd->pairlst.size();m++)
    {
        if(brd->pairlst[m]->brd1==mobject[n].brd)
        {
            tui=brd->pairlst[m]->brd2;
            tuix=brd->pairlst[m]->x2;
            tuiy=brd->pairlst[m]->y2;
            break;
        }
        if(brd->pairlst[m]->brd2==mobject[n].brd)
        {
            tui=brd->pairlst[m]->brd1;
            tuix=brd->pairlst[m]->x1;
            tuiy=brd->pairlst[m]->y1;
            break;
        }
    }*/
    sum=0;
    for(int i=0;i<9;i++)
    {
        sum+=mobject[n].list[i];
        if(mobject[n].list[i]==0)
        {
            mobject[n].curentnumber++;
            goto line2;
        }
    }
    if(sum!=45){mobject[n].curentnumber++;goto line2;}

    for(int i=0;i<8;i++)
    {    for(int j=i+1;j<9;j++)
        {
            if(mobject[n].list[i]==mobject[n].list[j])
            {
                mobject[n].curentnumber++;
                goto line2;
            }
        }
    }
    /*
    if(tui->isput2(tuix,tuiy,mobject[n].curentnumber)==false)
    {
        mobject[n].curentnumber++;
        goto line2;
    }*/
    if(mobject[n].passcount==2 && mobject[n].curentnumber>mobject[n].startnumber)
    {
        loopdone(mobject[n].brd,mobject[n].two,mobject[n].xx,mobject[n].yy);
        mobject[n].startnumber=mobject[n].curentnumber;
        mobject[n].passcount=0;
        return -1;
    }
    else if(mobject[n].passcount==1 && (mobject[n].curentnumber<mobject[n].startnumber || (mobject[n].curentnumber==mobject[n].startnumber && mobject[n].startnumber==123456789)))
    {
        mobject[n].passcount++;
    }
    else if(mobject[n].passcount==0 && mobject[n].curentnumber>mobject[n].startnumber)
    {
        mobject[n].passcount++;
    }
    return mobject[n].curentnumber;
}
int *numberloopclass::numlist(boardclass *mbrd,int num,int two,int xx,int yy)
{
    int n=0;
line1:
    if(!(mobject[n].brd==mbrd && mobject[n].two==two && mobject[n].xx==xx && mobject[n].yy==yy))
    {
        n++;
        goto line1;
    }
line2:
    int n2=mobject[n].curentnumber;
    for(int i=0;i<9;i++)
    {
        //mobject[n].list[i]=n2%10;n2=n2/10;
    }
    return mobject[n].list;
}

void numberloopclass::listclear(boardclass *brd1,int two)
{
    int n=0;
line1:
    if(!(mobject[n].brd==brd1 && mobject[n].two==two))
    {
        n++;
        goto line1;
    }
    for(int i=0;i<9;i++)
    {
        mobject[n].list[i]=0;
    }

}
void numberloopclass::boardhistorycclassset(boardhistorycclass *mbrd)
{
    brd=mbrd;
}
