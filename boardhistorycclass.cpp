#include"boardhistorycclass.h"
boardhistorycclass::boardhistorycclass()
{
    brdcntdefault=0;
    curenthistrycnt=0;
    searchareanumber=false;
    searchareanumberpriority=1;
    pvec=false;
    clearstate=false;
}
void boardhistorycclass::clear()
{
    clearstate=true;
    for(int i=0;i<brdhist.size();i++)
    {
        brdhist[i]->clear();
    }
    pairlst.clear();
    paironlylst.clear();
    brdhist.clear();
    brdcntdefault=0;
    curenthistrycnt=0;
    searchareanumber=false;
    searchareanumberpriority=1;
    pvec=false;
    clearstate=false;
}
void boardhistorycclass::boardhistoryadd()
{
    boardgroupclass *bdg=new boardgroupclass;
    brdhist.push_back(bdg);
    clearstate=false;
}
void boardhistorycclass::paintEvent(QPaintEvent *eve,QPainter *painter)
{
    if(clearstate==true){return;}
    brdhist[curenthistrycnt]->paintEvent(eve,painter);
    if(pvec==true)
    {
        paintvec(eve,painter);
    }
}
void boardhistorycclass::mousePressEvent(QMouseEvent *event)
{
    if(brdhist.size()==0){return;}
    if(brdhist[curenthistrycnt]->brdgroup.size()==0){return;}
    if(searchareanumber==true)
    {
       int  mindex=-1;
       areanumberget(event->pos(),arean);
       return;
    }
    for(unsigned int i=0;i<brdhist[curenthistrycnt]->brdgroup.size();i++)
    {
        if(brdhist[curenthistrycnt]->brdgroup[i]->mouseRangeIs(event->pos())==false){brdhist[curenthistrycnt]->curentbrdnum=-1;}
        else{brdhist[curenthistrycnt]->curentbrdnum=i;break;}
    }
    if(brdhist[curenthistrycnt]->curentbrdnum==-1){return;}
    brdhist[curenthistrycnt]->mousePressEvent(event);
}
void boardhistorycclass::mouseMoveEvent(QMouseEvent *event)
{
    if(searchareanumber==true)
    {
       return;
    }
    if(brdhist[curenthistrycnt]->curentbrdnum==-1){return;}
    brdhist[curenthistrycnt]->mouseMoveEvent(event);
}
void boardhistorycclass::mouseReleaseEvent(QMouseEvent *event)
{
    if(searchareanumber==true)
    {
       return;
    }
    if(brdhist[curenthistrycnt]->curentbrdnum==-1){return;}
    brdhist[curenthistrycnt]->mouseReleaseEvent(event);
}
boardgroupclass *boardhistorycclass::curentbrdgroupget()
{
    return brdhist[curenthistrycnt];
}
void boardhistorycclass::curentindexset(int id)
{
    if(id<0){return;}
    if(id>=(signed int)brdhist.size()){return;}
    curenthistrycnt=id;
}
void boardhistorycclass::curentindexadd(int id)
{
    if(curenthistrycnt+id<0){return;}
    if(id+curenthistrycnt>=(signed int)brdhist.size()){return;}
    curenthistrycnt+=id;
}
void boardhistorycclass::circledrawset(int enable)
{
    circledraw=enable;
    for(unsigned int i=0;i<curentbrdgroupget()->brdgroup.size();i++)
    {
        curentbrdgroupget()->brdgroup[i]->enable.circledraw=enable;
    }
}
void boardhistorycclass::boardhistorylastdel()
{
    for(int j=0;j<(int)brdhist[brdhist.size()-1]->brdgroup.size();j++)
    {
        delete brdhist[brdhist.size()-1]->brdgroup[j];
    }
    brdhist[brdhist.size()-1]->brdgroup.clear();
    //delete brdhist[brdhist.size()-1];
    brdhist.erase(brdhist.end()-1);
}
void boardhistorycclass::boardhistorysnapshot()
{
    int pos1=curenthistrycnt;
    boardgroupclass *bdg=new boardgroupclass;
    for(int i=0;i<brdhist[pos1]->brdgroup.size();i++)
    {
        bdg->boardclassadd();
        //brdhist[pos1]->
    }
    for(int i=0;i<brdhist[pos1]->brdgroup.size();i++)
    {
        //brdhist[pos1]->brdgroup[i]=brdhist[pos2]->brdgroup[i];

        bdg->brdgroup[i]->drawpos=brdhist[pos1]->brdgroup[i]->drawpos;
        bdg->brdgroup[i]->index=brdhist[pos1]->brdgroup[i]->index;
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                bdg->brdgroup[i]->data[x][y]->index=brdhist[pos1]->brdgroup[i]->data[x][y]->index;
                bdg->brdgroup[i]->data[x][y]->num=brdhist[pos1]->brdgroup[i]->data[x][y]->num;
                bdg->brdgroup[i]->data[x][y]->xx=brdhist[pos1]->brdgroup[i]->data[x][y]->xx;
                bdg->brdgroup[i]->data[x][y]->yy=brdhist[pos1]->brdgroup[i]->data[x][y]->yy;
                bdg->brdgroup[i]->data[x][y]->lock=brdhist[pos1]->brdgroup[i]->data[x][y]->lock;
            }
        }
    }
    brdhist.push_back(bdg);
    if(brdcntdefault==0){brdcntdefault=pairlst.size();}
    std::vector<boardhistorycclass::PAIRDATA *> palist;
    for(int i=0;i<brdcntdefault;i++)
    {
        boardhistorycclass::PAIRDATA *pa=new boardhistorycclass::PAIRDATA;
        (*pa).groupid=pos1+1;
        (*pa).id1=pairlst[i]->id1;
        (*pa).id2=pairlst[i]->id2;
        (*pa).id3=pairlst[i]->id3;
        (*pa).id4=pairlst[i]->id4;
        (*pa).x1=pairlst[i]->x1;
        (*pa).x2=pairlst[i]->x2;
        (*pa).x3=pairlst[i]->x3;
        (*pa).x4=pairlst[i]->x4;
        (*pa).y1=pairlst[i]->y1;
        (*pa).y2=pairlst[i]->y2;
        (*pa).y3=pairlst[i]->y3;
        (*pa).y4=pairlst[i]->y4;
        (*pa).manulck=pairlst[i]->manulck;
        if(pairlst[i]->id3<0 || pairlst[i]->id3>=brdhist[0]->brdgroup.size() || pairlst[i]->id4<0 || pairlst[i]->id4>=brdhist[0]->brdgroup.size())
        {
            pairlst[i]->twice=false;
        }
        (*pa).twice=pairlst[i]->twice;
        (*pa).brd1=brdhist[pos1+1]->boardget(pa->id1);
        (*pa).brd2=brdhist[pos1+1]->boardget(pa->id2);
        if(pairlst[i]->twice)
        {
            (*pa).brd3=brdhist[pos1+1]->boardget(pa->id3);
            (*pa).brd4=brdhist[pos1+1]->boardget(pa->id4);
        }

        palist.push_back(pa);
    }
    int gidmax=pairlst[pairlst.size()-1]->groupid;
    for(int i=0;i<palist.size();i++)
    {
        bool f1=false;
        for(int j=0;j<pairlst.size();j++)
        {
            if(palist[i]->id1==pairlst[j]->id1 && palist[i]->id2==pairlst[j]->id2 && palist[i]->groupid==pairlst[j]->groupid && palist[i]->x1==pairlst[j]->x1 && palist[i]->y1==pairlst[j]->y1 && palist[i]->x2==pairlst[j]->x2 && palist[i]->y2==pairlst[j]->y2)
            {
                f1=true;
            }
        }
        if(f1==false)
        {
            palist[i]->brd1=brdhist[palist[i]->groupid]->boardget(palist[i]->id1);
            palist[i]->brd2=brdhist[palist[i]->groupid]->boardget(palist[i]->id2);
            if(palist[i]->twice)
            {
                palist[i]->brd3=brdhist[palist[i]->groupid]->boardget(palist[i]->id3);
                palist[i]->brd4=brdhist[palist[i]->groupid]->boardget(palist[i]->id4);
            }
            pairlst.push_back(palist[i]);
        }
    }
        //linkmake(palist[i]->groupid,palist[i]->id1,palist[i]->x1,palist[i]->y1,palist[i]->id2,palist[i]->x2,palist[i]->y2);
    for(int i=0;i<pairlst.size();i++)
    {
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int gid=pairlst[i]->groupid;
                int id1=pairlst[i]->id1;
                int x1=pairlst[i]->x1;
                int y1=pairlst[i]->y1;
                int id2=pairlst[i]->id2;
                int x2=pairlst[i]->x2;
                int y2=pairlst[i]->y2;
                int id3=pairlst[i]->id3;
                int x3=pairlst[i]->x3;
                int y3=pairlst[i]->y3;
                int id4=pairlst[i]->id4;
                int x4=pairlst[i]->x4;
                int y4=pairlst[i]->y4;
                boardclass::CHIPDATA *mm=memo.add();
                boardclass::CHIPDATA *mm2=memo.add();
                *mm=*brdhist[gid]->brdgroup[id1]->data[x1*3+x][y1*3+y];
                brdhist[gid]->brdgroup[id1]->data[x1*3+x][y1*3+y]=mm;
                brdhist[gid]->brdgroup[id2]->data[x2*3+x][y2*3+y]=mm;
                if(pairlst[i]->twice)
                {
                    *mm2=*brdhist[gid]->brdgroup[id3]->data[x3*3+x][y3*3+y];
                    brdhist[gid]->brdgroup[id3]->data[x3*3+x][y3*3+y]=mm2;
                    brdhist[gid]->brdgroup[id4]->data[x4*3+x][y4*3+y]=mm2;
                }
            }
        }
    }
    //**********************************************************************************
    //if(brdcntdefaultonly==0){brdcntdefaultonly=paironlylst.size();}
    std::vector<boardhistorycclass::PAIRDATA *> paonlylist;
    for(int i=0;i<paironlylst.size();i++)
    {
        boardhistorycclass::PAIRDATA *pa2=new boardhistorycclass::PAIRDATA;
        (*pa2).groupid=pos1+1;
        (*pa2).id1=paironlylst[i]->id1;
        (*pa2).id2=paironlylst[i]->id2;
        (*pa2).x1=paironlylst[i]->x1;
        (*pa2).x2=paironlylst[i]->x2;
        (*pa2).y1=paironlylst[i]->y1;
        (*pa2).y2=paironlylst[i]->y2;
        (*pa2).x3=paironlylst[i]->x3;
        (*pa2).x4=paironlylst[i]->x4;
        (*pa2).y3=paironlylst[i]->y3;
        (*pa2).y4=paironlylst[i]->y4;
        (*pa2).twice=paironlylst[i]->twice;
        (*pa2).brd1=brdhist[pos1+1]->boardget(pa2->id1);
        (*pa2).brd2=brdhist[pos1+1]->boardget(pa2->id2);
        paonlylist.push_back(pa2);
    }
    //gidmax=paironlylst[paironlylst.size()-1]->groupid;
    for(int i=0;i<paonlylist.size();i++)
    {
        bool f1=false;
        for(int j=0;j<paironlylst.size();j++)
        {
            if(paonlylist[i]->id1==paironlylst[j]->id1 && paonlylist[i]->id2==paironlylst[j]->id2 && paonlylist[i]->groupid==paironlylst[j]->groupid && paonlylist[i]->x1==paironlylst[j]->x1 && paonlylist[i]->y1==paironlylst[j]->y1 && paonlylist[i]->x2==paironlylst[j]->x2 && paonlylist[i]->y2==paironlylst[j]->y2)
            {
                f1=true;
            }
        }
        if(f1==false)
        {
            paonlylist[i]->brd1=brdhist[paonlylist[i]->groupid]->boardget(paonlylist[i]->id1);
            paonlylist[i]->brd2=brdhist[paonlylist[i]->groupid]->boardget(paonlylist[i]->id2);
            paironlylst.push_back(paonlylist[i]);
        }
    }
        //linkmake(palist[i]->groupid,palist[i]->id1,palist[i]->x1,palist[i]->y1,palist[i]->id2,palist[i]->x2,palist[i]->y2);
    for(int i=0;i<paironlylst.size();i++)
    {
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int gid=paironlylst[i]->groupid;
                int id1=paironlylst[i]->id1;
                int x1=paironlylst[i]->x1;
                int y1=paironlylst[i]->y1;
                int id2=paironlylst[i]->id2;
                int x2=paironlylst[i]->x2;
                int y2=paironlylst[i]->y2;
                boardclass::CHIPDATA *mm=memo.add();
                *mm=*brdhist[gid]->brdgroup[id1]->data[x1*3+x][y1*3+y];
                brdhist[gid]->brdgroup[id1]->data[x1*3+x][y1*3+y]=mm;
                brdhist[gid]->brdgroup[id2]->data[x2*3+x][y2*3+y]=mm;
            }
        }
    }
    clearstate=false;
}
void boardhistorycclass::linktwicemake(int histid,int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    boardclass::CHIPDATA *dm2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            dm2=memo.add();
            (*dm).num=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->num;
            (*dm).lock=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->lock;
            (*dm).index=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->index;
            (*dm).xx=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->xx;
            (*dm).yy=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->yy;
            (*dm2).num=brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->num;
            (*dm2).lock=brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->lock;
            (*dm2).index=brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->index;
            (*dm2).xx=brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->xx;
            (*dm2).yy=brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->yy;
            brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
            brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]=dm2;
            brdhist[histid]->boardget(id4)->data[x4*3+i][y4*3+j]=dm2;
        }
    }
    boardhistorycclass::PAIRDATA *pr=new boardhistorycclass::PAIRDATA;
    pr->id1=id1;
    pr->x1=x1;
    pr->y1=y1;
    pr->id2=id2;
    pr->x2=x2;
    pr->y2=y2;
    pr->id3=id3;
    pr->x3=x3;
    pr->y3=y3;
    pr->id4=id4;
    pr->x4=x4;
    pr->y4=y4;
    pr->manulck=false;
    pr->groupid=histid;
    pr->twice=true;
    pr->brd1=brdhist[histid]->boardget(id1);
    pr->brd2=brdhist[histid]->boardget(id2);
    pr->brd3=brdhist[histid]->boardget(id3);
    pr->brd4=brdhist[histid]->boardget(id4);
    pairlst.push_back(pr);
    QPoint cl1;QPoint cl2;QPoint cl3;QPoint cl4;
    cl1.setX(curentbrdgroupget()->boardget(id1)->drawpos.x()+curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(curentbrdgroupget()->boardget(id1)->drawpos.y()+curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(curentbrdgroupget()->boardget(id2)->drawpos.x()+curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(curentbrdgroupget()->boardget(id2)->drawpos.y()+curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);
    cl3.setX(curentbrdgroupget()->boardget(id3)->drawpos.x()+curentbrdgroupget()->boardget(id3)->chipsize.width()*(x3+1)*3-20);
    cl3.setY(curentbrdgroupget()->boardget(id3)->drawpos.y()+curentbrdgroupget()->boardget(id3)->chipsize.height()*(y3+1)*3-20);
    curentbrdgroupget()->boardget(id3)->clicklist.push_back(cl3);
    cl4.setX(curentbrdgroupget()->boardget(id4)->drawpos.x()+curentbrdgroupget()->boardget(id4)->chipsize.width()*(x4+1)*3-20);
    cl4.setY(curentbrdgroupget()->boardget(id4)->drawpos.y()+curentbrdgroupget()->boardget(id4)->chipsize.height()*(y4+1)*3-20);
    curentbrdgroupget()->boardget(id4)->clicklist.push_back(cl4);
}
void boardhistorycclass::linkmake(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    boardclass::CHIPDATA *dm2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            dm2=memo.add();
            (*dm).num=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->num;
            (*dm).lock=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->lock;
            (*dm).index=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->index;
            (*dm).xx=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->xx;
            (*dm).yy=brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->yy;
            brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
        }
    }
    boardhistorycclass::PAIRDATA *pr=new boardhistorycclass::PAIRDATA;
    pr->id1=id1;
    pr->x1=x1;
    pr->y1=y1;
    pr->id2=id2;
    pr->x2=x2;
    pr->y2=y2;
    pr->groupid=histid;
    pr->manulck=false;
    //pr->twice=true;
    pr->brd1=brdhist[histid]->boardget(id1);
    pr->brd2=brdhist[histid]->boardget(id2);
    bool f=true;
    for(int i=0;i<pairlst.size();i++)
    {
        if(pairlst[i]->brd1==pr->brd1)
        {
            f=false;
        }
    }
    if(f){pairlst.push_back(pr);}
    else{paironlylst.push_back(pr);}
    QPoint cl1;QPoint cl2;
    cl1.setX(curentbrdgroupget()->boardget(id1)->drawpos.x()+curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(curentbrdgroupget()->boardget(id1)->drawpos.y()+curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(curentbrdgroupget()->boardget(id2)->drawpos.x()+curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(curentbrdgroupget()->boardget(id2)->drawpos.y()+curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);



}
void boardhistorycclass::linkmakeprev(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            boardclass::CHIPDATA n1=*brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j];
            delete brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j];
            brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
            *dm=n1;
        }
    }
}
void boardhistorycclass::linkerase(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    boardclass::CHIPDATA *dm2;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            dm2=memo.add();
            boardclass::CHIPDATA n1=*brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j];
            delete brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j];
            brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm2;
            *dm=n1;
            *dm2=n1;
        }
    }
}
void boardhistorycclass::dumpfile(char *filename)
{
    FILE *f=fopen(filename,"a");
    fprintf(f,"brdhist.size()=%d\n",brdhist.size());
    for(int i=0;i<brdhist.size();i++)
    {
        fprintf(f,"brdhist[i]->brdgroup.size()=%d\n",brdhist[i]->brdgroup.size());
        for(int j=0;j<brdhist[i]->brdgroup.size();j++)
        {
            for(int x=0;x<9;x++)
            {
                for(int y=0;y<9;y++)
                {
                    fprintf(f,"brdhist[i]->brdgroup[j]->data[x][y]->num=%d\n",brdhist[i]->brdgroup[j]->data[x][y]->num);
                }
            }

        }
    }
    fprintf(f,"-------------------------------------------------\n");
    fprintf(f,"pairlst.size()=%d\n",pairlst.size());
    for(int i=0;i<pairlst.size();i++)
    {
        fprintf(f,"pairlst[i]->groupid=%d,pairlst[i]->id1=%d,pairlst[i]->x1=%d,pairlst[i]->y1=%d,pairlst[i]->id2=%d,pairlst[i]->x2=%d,pairlst[i]->y2=%d\n",pairlst[i]->groupid,pairlst[i]->id1,pairlst[i]->x1,pairlst[i]->y1,pairlst[i]->id2,pairlst[i]->x2,pairlst[i]->y2);
    }
    fprintf(f,"-------------------------------------------------\n");
    fprintf(f,"-------------------------------------------------\n");
    fclose(f);
}
void boardhistorycclass::copytocurent()
{
    for(int j=0;j<brdhist[curenthistrycnt]->brdgroup.size();j++)
    {
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                if(brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->num==0 && brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->num!=0)
                {
                    brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->num=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->num;
                    brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->index=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->index;
                    brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->xx=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->xx;
                    brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->yy=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->yy;
                }
            }
        }
    }

}
void boardhistorycclass::copytocurentzero()
{
    for(int j=0;j<brdhist[curenthistrycnt]->brdgroup.size();j++)
    {
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->num=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->num;
                brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->index=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->index;
                brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->xx=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->xx;
                brdhist[curenthistrycnt]->brdgroup[j]->data[x][y]->yy=brdhist[curenthistrycnt-1]->brdgroup[j]->data[x][y]->yy;
            }
        }
    }

}
bool boardhistorycclass::isput(int index,int x,int y,int num)
{
    return brdhist[curenthistrycnt]->brdgroup[index]->isput(x,y,num);
}
QPoint boardhistorycclass::areanumberget(QPoint click,areanumberis *aream)
{
    int areai1=-1;
    int areax1=-1;
    int areay1=-1;
    int areai2=-1;
    int areax2=-1;
    int areay2=-1;
    brdhist[curenthistrycnt]->areanumberget(click,&areai1,&areax1,&areay1,0);
    brdhist[curenthistrycnt]->areanumberget(click,&areai2,&areax2,&areay2,1);
    if(searchareanumberpriority==0)
    {
        if(areai1<areai2)
        {
            arean[0].index=areai1;
            arean[0].x=areax1;
            arean[0].y=areay1;
            arean[1].index=areai2;
            arean[1].x=areax2;
            arean[1].y=areay2;
        }
        else
        {
            arean[1].index=areai1;
            arean[1].x=areax1;
            arean[1].y=areay1;
            arean[0].index=areai2;
            arean[0].x=areax2;
            arean[0].y=areay2;
        }
    }
    if(searchareanumberpriority!=0)
    {
        if(areai1<areai2)
        {
            arean[1].index=areai1;
            arean[1].x=areax1;
            arean[1].y=areay1;
            arean[0].index=areai2;
            arean[0].x=areax2;
            arean[0].y=areay2;
        }
        else
        {
            arean[0].index=areai1;
            arean[0].x=areax1;
            arean[0].y=areay1;
            arean[1].index=areai2;
            arean[1].x=areax2;
            arean[1].y=areay2;
        }
    }
}
void boardhistorycclass::searchareanumberset(bool serachis,int pririty)
{
    searchareanumber=serachis;
    searchareanumberpriority=pririty;
}
void boardhistorycclass::paintvec(QPaintEvent *eve,QPainter *painter)
{
    for(int i=0;i<pairlst.size();i++)
    {
        if(pairlst[i]->groupid!=0){return;}
        int x1=pairlst[i]->brd1->drawpos.x()+pairlst[i]->brd1->drawadjust.x()+pairlst[i]->brd1->chipsize.width()*4.5;
        int y1=pairlst[i]->brd1->drawpos.y()+pairlst[i]->brd1->drawadjust.y()+pairlst[i]->brd1->chipsize.height()*4.5;
        int x2=pairlst[i]->brd2->drawpos.x()+pairlst[i]->brd2->drawadjust.x()+pairlst[i]->brd2->chipsize.width()*4.5;
        int y2=pairlst[i]->brd2->drawpos.y()+pairlst[i]->brd2->drawadjust.y()+pairlst[i]->brd2->chipsize.height()*4.5;
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(QPen(Qt::darkGreen, 1, Qt::SolidLine , Qt::RoundCap));
        painter->drawLine(x1,y1,x2,y2);
        painter->drawEllipse(x1-5,y1-5,10,10);
        painter->drawText(x1-8,y1-8,QString::number(i));
        painter->setPen(QPen(Qt::red, 1, Qt::SolidLine , Qt::RoundCap));
        painter->drawEllipse(x2-7,y2-7,14,14);
    }
    for(int i=0;i<paironlylst.size();i++)
    {
        if(paironlylst[i]->groupid!=0){return;}
        int x1=paironlylst[i]->brd1->drawpos.x()+paironlylst[i]->brd1->drawadjust.x()+paironlylst[i]->brd1->chipsize.width()*paironlylst[i]->x1*3;
        int y1=paironlylst[i]->brd1->drawpos.y()+paironlylst[i]->brd1->drawadjust.y()+paironlylst[i]->brd1->chipsize.height()*paironlylst[i]->y1*3;
        int x2=paironlylst[i]->brd2->drawpos.x()+paironlylst[i]->brd2->drawadjust.x()+paironlylst[i]->brd2->chipsize.width()*paironlylst[i]->x2*3;
        int y2=paironlylst[i]->brd2->drawpos.y()+paironlylst[i]->brd2->drawadjust.y()+paironlylst[i]->brd2->chipsize.height()*paironlylst[i]->y2*3;
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine , Qt::RoundCap));
        painter->drawEllipse(x1-3,y1-3,6,6);
    }
}
void boardhistorycclass::linkrepair(int id1)
{
    int groupid=pairlst[id1]->groupid;
    bool twice=pairlst[id1]->twice;
    boardclass *brd1=pairlst[id1]->brd1;
    boardclass *brd2=pairlst[id1]->brd2;
    boardclass *brd3=pairlst[id1]->brd3;
    boardclass *brd4=pairlst[id1]->brd4;
    int x1=pairlst[id1]->x1;
    int x2=pairlst[id1]->x2;
    int x3=pairlst[id1]->x3;
    int x4=pairlst[id1]->x4;
    int y1=pairlst[id1]->y1;
    int y2=pairlst[id1]->y2;
    int y3=pairlst[id1]->y3;
    int y4=pairlst[id1]->y4;
    int id01=pairlst[id1]->id1;
    int id2=pairlst[id1]->id2;
    int id3=pairlst[id1]->id3;
    int id4=pairlst[id1]->id4;
    pairlst[id1]->brd1=brd2;
    pairlst[id1]->brd2=brd1;
    pairlst[id1]->brd3=brd4;
    pairlst[id1]->brd4=brd3;
    pairlst[id1]->x1=x2;
    pairlst[id1]->x2=x1;
    pairlst[id1]->x3=x4;
    pairlst[id1]->x4=x3;
    pairlst[id1]->y1=y2;
    pairlst[id1]->y2=y1;
    pairlst[id1]->y3=y4;
    pairlst[id1]->y4=y3;
    pairlst[id1]->id1=id2;
    pairlst[id1]->id2=id01;
    pairlst[id1]->id3=id4;
    pairlst[id1]->id4=id3;
}

void boardhistorycclass::linkchange(int id1,int id2)
{
    int groupid=pairlst[id1]->groupid;
    bool twice=pairlst[id1]->twice;
    boardclass *brd1=pairlst[id1]->brd1;
    boardclass *brd2=pairlst[id1]->brd2;
    boardclass *brd3=pairlst[id1]->brd3;
    boardclass *brd4=pairlst[id1]->brd4;
    int x1=pairlst[id1]->x1;
    int x2=pairlst[id1]->x2;
    int x3=pairlst[id1]->x3;
    int x4=pairlst[id1]->x4;
    int y1=pairlst[id1]->y1;
    int y2=pairlst[id1]->y2;
    int y3=pairlst[id1]->y3;
    int y4=pairlst[id1]->y4;
    int id01=pairlst[id1]->id1;
    int id02=pairlst[id1]->id2;
    int id3=pairlst[id1]->id3;
    int id4=pairlst[id1]->id4;
    int ml=pairlst[id1]->manulck;
    pairlst[id1]->groupid=pairlst[id2]->groupid;
    pairlst[id1]->twice=pairlst[id2]->twice;
    pairlst[id1]->brd1=pairlst[id2]->brd1;
    pairlst[id1]->brd2=pairlst[id2]->brd2;
    pairlst[id1]->brd3=pairlst[id2]->brd3;
    pairlst[id1]->brd4=pairlst[id2]->brd4;
    pairlst[id1]->x1=pairlst[id2]->x1;
    pairlst[id1]->x2=pairlst[id2]->x2;
    pairlst[id1]->x3=pairlst[id2]->x3;
    pairlst[id1]->x4=pairlst[id2]->x4;
    pairlst[id1]->y1=pairlst[id2]->y1;
    pairlst[id1]->y2=pairlst[id2]->y2;
    pairlst[id1]->y3=pairlst[id2]->y3;
    pairlst[id1]->y4=pairlst[id2]->y4;
    pairlst[id1]->id1=pairlst[id2]->id1;
    pairlst[id1]->id2=pairlst[id2]->id2;
    pairlst[id1]->id3=pairlst[id2]->id3;
    pairlst[id1]->id4=pairlst[id2]->id4;
    pairlst[id1]->manulck=pairlst[id2]->manulck;
    pairlst[id2]->groupid=groupid;
    pairlst[id2]->twice=twice;
    pairlst[id2]->brd1=brd1;
    pairlst[id2]->brd2=brd2;
    pairlst[id2]->brd3=brd3;
    pairlst[id2]->brd4=brd4;
    pairlst[id2]->x1=x1;
    pairlst[id2]->x2=x2;
    pairlst[id2]->x3=x3;
    pairlst[id2]->x4=x4;
    pairlst[id2]->y1=y1;
    pairlst[id2]->y2=y2;
    pairlst[id2]->y3=y3;
    pairlst[id2]->y4=y4;
    pairlst[id2]->id1=id01;
    pairlst[id2]->id2=id02;
    pairlst[id2]->id3=id3;
    pairlst[id2]->id4=id4;
    pairlst[id2]->manulck=ml;
}
