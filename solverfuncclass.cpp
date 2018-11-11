#include"solverfuncclass.h"
//--------------------------------------------------------------------
//--------------------------------------------------------------------
//numberlopp de increment 1kodutu ni tyui
//--------------------------------------------------------------------
//--------------------------------------------------------------------
solverfuncclass::solverfuncclass()
{
    cnt=0;
    k=0;
    brdcnt=0;
    v=0;
    stopflag=0;
    bn=0;
    selectloop=0;
    goodend=false;
    badend=false;
    th=NULL;
    th2=NULL;
}
void solverfuncclass::init()
{
    cnt=0;
    k=0;
    brdcnt=0;
    v=0;
    stopflag=0;
    bn=0;
    selectloop=0;
    goodend=false;
    badend=false;
    mobject.clear();
    mobject2.clear();
    /*th->detach();
    th2->detach();
    delete th;
    delete th2;*/
}
void solverfuncclass::soundfile(int index)
{
    FILE *fp=fopen("./snd.txt","w");
    fprintf(fp,"%d",index);
    fclose(fp);
    system("./soundapp &");
}
void solverfuncclass::mainloop(int param)
{
    int tc=0;
    solvecount=0;
    param2=param;
    loopdoneis1=false;
    loopdoneis2=false;
    soundfile(1);
    int *mnumlist;
    int *mnumlist2;
    //soundfile(2);
    badend=false;
    stopthread=false;
    int mnumlist3[]={0,0,0,0,0,0,0,0,0};
    for(int i=0;i<brd->pairlst.size();i++)
    {
        boardclassadd(brd->pairlst[i]->brd1,123456789,0,brd->pairlst[i]->x1,brd->pairlst[i]->y1);
        boardclassadd(brd->pairlst[i]->brd2,123456789,0,brd->pairlst[i]->x2,brd->pairlst[i]->y2);
        if(brd->pairlst[i]->twice==true)
        {
            if(brd->pairlst[i]->id3>=0 && brd->pairlst[i]->id4>=0 && brd->pairlst[i]->x3>=0 && brd->pairlst[i]->x4>=0 && brd->pairlst[i]->y3>=0 && brd->pairlst[i]->y4>=0)
            {
                //FILE *fp=fopen("boardclassadd.log","a");
                //fprintf(fp,"brd->pairlst[i]->groupid=%d ,brd->pairlst[i]->id1=%d ,brd->pairlst[i]->id2=%d ,brd->pairlst[i]->id3=%d ,brd->pairlst[i]->id4=%d ,brd->pairlst[i]->x1=%d ,brd->pairlst[i]->x2=%d ,brd->pairlst[i]->x3=%d ,brd->pairlst[i]->x4=%d ,brd->pairlst[i]->y1=%d ,brd->pairlst[i]->y2=%d ,brd->pairlst[i]->y3=%d ,brd->pairlst[i]->y4=%d ,brd->pairlst[i]->twice=%d \n",brd->pairlst[i]->groupid,brd->pairlst[i]->id1,brd->pairlst[i]->id2,brd->pairlst[i]->id3,brd->pairlst[i]->id4,brd->pairlst[i]->x1,brd->pairlst[i]->x2,brd->pairlst[i]->x3,brd->pairlst[i]->x4,brd->pairlst[i]->y1,brd->pairlst[i]->y2,brd->pairlst[i]->y3,brd->pairlst[i]->y4,brd->pairlst[i]->twice);
                //fclose(fp);
                boardclassadd(brd->pairlst[i]->brd3,123456789,1,brd->pairlst[i]->x3,brd->pairlst[i]->y3);
                boardclassadd(brd->pairlst[i]->brd4,123456789,1,brd->pairlst[i]->x4,brd->pairlst[i]->y4);
            }
            else
            {
                brd->pairlst[i]->twice=false;
            }
        }
    }
    //soundfile(1);
    brdcnt=brd->pairlst.size();
    int fn=brdcnt-2;
    bool rets=false;
    int maxnum=brd->pairlst.size()*brd->pairlst.size()-1;
    brd1=brd->pairlst[v]->brd1;
    brd2=brd->pairlst[v]->brd2;
    brd3=brd->pairlst[v]->brd3;
    brd4=brd->pairlst[v]->brd4;
    locknumber();
    int nnum2;
    if(brd->pairlst[v]->twice==true)
    {
        nnum2=nextnum(brd3,1,brd->pairlst[v]->x3,brd->pairlst[v]->y3);
    }
    if(brd->pairlst[v]->twice==false)
    {
        goto line3;
    }
    int nnum;
line1:
    {
        if(badend==true){return;}
        if(stopthread==true){return;}
    if(brd->pairlst[v]->twice==false)
    {
        goto line3;
    }
    //mainwin->setWindowTitle("loop 1 pass");
    if(stopflag==1){stopflag=0;return;}
    /*
    listclear(brd1,0);
    listclear(brd3,1);
    listclear(brd2,0);
    listclear(brd4,1);
    */
    nnum=nextnum(brd3,1,brd->pairlst[v]->x3,brd->pairlst[v]->y3);//<<<<<<----------------debugger
    if(nnum==-1)
    {
        if(loopdoneis2==true)
        {
            loopdoneis2=false;
            goto line3;
        }
        nnum=nextnum(brd3,1,brd->pairlst[v]->x3,brd->pairlst[v]->y3);
    }
    mnumlist2=numlist(brd3,nnum,1,brd->pairlst[v]->x3,brd->pairlst[v]->y3);
    numset(mnumlist3,mnumlist2,v);
    brd1->datacloneing();
    brd2->datacloneing();
    rets=solvertest3(brd1,brd2,false);
    brd1->dataclonebacking();
    brd2->dataclonebacking();
    if(rets)
    {
        soundfile(2);
        numset(mnumlist3,mnumlist2,v);
        //mainwin->update();
        //selectloop=0;//<<<<<<<<--------------------------?????????????????????????????
        goto line3;
    }
    }
    mainwin->m.lock();
    mainwin->view.process1="processing...";
    mainwin->view.process2=QString::number(nnum);
    /*mainwin->view.process3="";
    for(int i=0;i<brd->pairlst.size();i++)
    {
        mainwin->view.process3+="i=["+QString::number(i)+"] groupid="+QString::number(brd->pairlst[i]->groupid)+" id1="+QString::number(brd->pairlst[i]->id1)+" id2="+QString::number(brd->pairlst[i]->id2)+" curenthistrycnt="+QString::number(brd->curenthistrycnt)+"\n";
    }*/
    mainwin->progressBarSet();
    mainwin->proceessstatusSet();
    mainwin->m.unlock();
    if(brd->pairlst[v]->twice==true/* && loopdoneis2*/)
    {
        //loopdoneis2=false;
        //goto line3;
    }
    goto line1;
line3:
    {
        if(badend==true){return;}
        if(stopthread==true){return;}
        //if(cnta==1){cnta++;goto line1;}
        //mainwin->setWindowTitle("loop 2 pass");
        /*listclear(brd1,0);
        listclear(brd3,1);
        listclear(brd2,0);
        listclear(brd4,1);*/
        int nnum=nextnum(brd1,0,brd->pairlst[v]->x1,brd->pairlst[v]->y1);
        if(nnum==-1)
        {
            nnum=nextnum(brd1,0,brd->pairlst[v]->x1,brd->pairlst[v]->y1);
        }
        /*
        if(loopdoneis==true && brd->pairlst[v]->twice==true)
        {
            loopdoneis=false;
            goto line1;
        }*/
        mnumlist=numlist(brd1,nnum,0,brd->pairlst[v]->x1,brd->pairlst[v]->y1);
        if(brd->pairlst[v]->twice==true)
        {
            numset(mnumlist,mnumlist2,v);
        }
        else
        {
            numset(mnumlist,v);
        }
        brd1->datacloneing();
        brd2->datacloneing();
        rets=solvertest2(brd1,brd2,false);
        bool isok=allok(brd->pairlst[v]->groupid);
        brd1->dataclonebacking();
        brd2->dataclonebacking();
        if((rets && v!=brd->pairlst.size()-1) || (rets && isok && v==brd->pairlst.size()-1))
        {
            soundfile(3);
            if(v==brd->pairlst.size()-1)
            {

                brd1->datacloneing();
                brd2->datacloneing();
                solver(brd1,brd2,true);
                //mainwin->setWindowTitle("Solve Done brd->pairlst.size");
                //return;
                if(allok(brd->pairlst[v]->groupid))
                {
                    if(solvecount==1 && param==1 && anscheckis()==false)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai";
                        mainwin->setWindowTitle(mstr);
                        return;
                    }
                    if(solvecount==1 && param==1 && anscheckis()==true)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai Not";
                        mainwin->setWindowTitle(mstr);
                        brd1->dataclonebacking();
                        brd2->dataclonebacking();
                        goto line3;
                    }
                    if(solvecount==0 && param==1)
                    {
                        solvecount++;
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai Pre : ";
                        mainwin->setWindowTitle(mstr);
                        QString fstr="tmp"+QString::number(tc);tc++;
                        mainwin->console->DataSave2((char *)fstr.toStdString().c_str());
                        anscheckset();
                        brd1->dataclonebacking();
                        brd2->dataclonebacking();
                        goto line3;
                    }
                    if(param==0)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Solve Done";
                        mainwin->setWindowTitle(mstr);
                        return;
                    }

                }
                else
                {
                    brd1->dataclonebacking();
                    brd2->dataclonebacking();
                }
            }
            if(brd->pairlst[v]->twice==true)
            {
                numset(mnumlist3,mnumlist3,v);
            }
            else
            {
                numset(mnumlist3,v);
            }
            brd->boardhistorysnapshot();
            int id1=brd->pairlst[v]->id1;
            int id2=brd->pairlst[v]->id2;
            brd->curenthistrycnt++;
            brd->copytocurentzero();
            for(int i=v;i<brd->pairlst.size();i++)
            {
                if(id1==brd->pairlst[i]->id1 && id2==brd->pairlst[i]->id2 && brd->curenthistrycnt==brd->pairlst[i]->groupid)
                {
                    v=i;break;
                }
            }
            brd1=brd->pairlst[v]->brd1;
            brd2=brd->pairlst[v]->brd2;
            brd3=brd->pairlst[v]->brd3;
            brd4=brd->pairlst[v]->brd4;
            if(brd->pairlst[v]->twice==true)
            {
                numset(mnumlist,mnumlist2,v);
            }
            else
            {
                numset(mnumlist,v);
            }
            for(int i=0;i<brd->pairlst.size();i++)
            {
                boardclassadd(brd->pairlst[i]->brd1,123456789,0,brd->pairlst[i]->x1,brd->pairlst[i]->y1);
                boardclassadd(brd->pairlst[i]->brd2,123456789,0,brd->pairlst[i]->x2,brd->pairlst[i]->y2);
                if(brd->pairlst[i]->twice==true)
                {
                    if(brd->pairlst[i]->id3>=0 && brd->pairlst[i]->id4>=0 && brd->pairlst[i]->x3>=0 && brd->pairlst[i]->x4>=0 && brd->pairlst[i]->y3>=0 && brd->pairlst[i]->y4>=0)
                    {
                        //FILE *fp=fopen("boardclassadd.log","a");
                        //fprintf(fp,"brd->pairlst[i]->groupid=%d ,brd->pairlst[i]->id1=%d ,brd->pairlst[i]->id2=%d ,brd->pairlst[i]->id3=%d ,brd->pairlst[i]->id4=%d ,brd->pairlst[i]->x1=%d ,brd->pairlst[i]->x2=%d ,brd->pairlst[i]->x3=%d ,brd->pairlst[i]->x4=%d ,brd->pairlst[i]->y1=%d ,brd->pairlst[i]->y2=%d ,brd->pairlst[i]->y3=%d ,brd->pairlst[i]->y4=%d ,brd->pairlst[i]->twice=%d \n",brd->pairlst[i]->groupid,brd->pairlst[i]->id1,brd->pairlst[i]->id2,brd->pairlst[i]->id3,brd->pairlst[i]->id4,brd->pairlst[i]->x1,brd->pairlst[i]->x2,brd->pairlst[i]->x3,brd->pairlst[i]->x4,brd->pairlst[i]->y1,brd->pairlst[i]->y2,brd->pairlst[i]->y3,brd->pairlst[i]->y4,brd->pairlst[i]->twice);
                        //fclose(fp);
                        boardclassadd(brd->pairlst[i]->brd3,123456789,1,brd->pairlst[i]->x3,brd->pairlst[i]->y3);
                        boardclassadd(brd->pairlst[i]->brd4,123456789,1,brd->pairlst[i]->x4,brd->pairlst[i]->y4);
                    }
                    else
                    {
                        brd->pairlst[i]->twice=false;
                    }
                }
            }
            if(v==brd->pairlst.size()-1)
            {

                brd1->datacloneing();
                brd2->datacloneing();
                solver(brd1,brd2,true);
                //mainwin->setWindowTitle("Solve Done brd->pairlst.size");
                //return;
                if(allok(brd->pairlst[v]->groupid))
                {
                    if(solvecount==1 && param==1 && anscheckis()==false)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai";
                        mainwin->setWindowTitle(mstr);
                        return;
                    }
                    if(solvecount==1 && param==1 && anscheckis()==true)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai Not";
                        mainwin->setWindowTitle(mstr);
                        brd1->dataclonebacking();
                        brd2->dataclonebacking();
                        goto line3;
                    }
                    if(solvecount==0 && param==1)
                    {
                        solvecount++;
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Tajyu Kai Pre : ";
                        mainwin->setWindowTitle(mstr);
                        QString fstr="tmp"+QString::number(tc);tc++;
                        mainwin->console->DataSave2((char *)fstr.toStdString().c_str());
                        anscheckset();
                        brd1->dataclonebacking();
                        brd2->dataclonebacking();
                        goto line3;
                    }
                    if(param==0)
                    {
                        soundfile(5);
                        QString mstr=mainwin->windowTitle()+" : Solve Done";
                        mainwin->setWindowTitle(mstr);
                        return;
                    }
                }
                else
                {
                    brd1->dataclonebacking();
                    brd2->dataclonebacking();
                }
            }
            if(v!=brd->pairlst.size()-1)
            {
                solver(brd1,brd2,false);
            }
            if(allok(brd->pairlst[v]->groupid))
            {
                if(solvecount==1 && param==1 && anscheckis()==false)
                {
                    soundfile(5);
                    QString mstr=mainwin->windowTitle()+" : Tajyu Kai";
                    mainwin->setWindowTitle(mstr);
                    return;
                }
                if(solvecount==1 && param==1 && anscheckis()==true)
                {
                    soundfile(5);
                    QString mstr=mainwin->windowTitle()+" : Tajyu Kai Not";
                    mainwin->setWindowTitle(mstr);
                    brd1->dataclonebacking();
                    brd2->dataclonebacking();
                    goto line3;
                }
                if(solvecount==0 && param==1)
                {
                    solvecount++;
                    soundfile(5);
                    QString mstr=mainwin->windowTitle()+" : Tajyu Kai Pre : ";
                    mainwin->setWindowTitle(mstr);
                    QString fstr="tmp"+QString::number(tc);tc++;
                    mainwin->console->DataSave2((char *)fstr.toStdString().c_str());
                    anscheckset();
                    brd1->dataclonebacking();
                    brd2->dataclonebacking();
                    goto line3;
                }
                if(param==0)
                {
                    soundfile(5);
                    QString mstr=mainwin->windowTitle()+" : Solve Done";
                    mainwin->setWindowTitle(mstr);
                    return;
                }
                goodend=true;
                return;
            }
            v++;
            fcnt1=0;
            brd1=brd->pairlst[v]->brd1;
            brd2=brd->pairlst[v]->brd2;
            brd3=brd->pairlst[v]->brd3;
            brd4=brd->pairlst[v]->brd4;
            if(brd->pairlst[v]->twice==true)
            {
                goto line1;
            }
            //mainwin->view.process4+="*v="+QString::number(v)+" ";
            //mainwin->view.process4+="brdcnt="+QString::number(brdcnt)+" bn="+QString::number(bn)+" v="+QString::number(v)+" brd->curenthistrycnt="+QString::number(brd->curenthistrycnt)+"\n";
        }
        mainwin->m.lock();
        mainwin->view.process1="processing...";
        mainwin->view.process2=QString::number(nnum);
        /*mainwin->view.process3="";
        for(int i=0;i<brd->pairlst.size();i++)
        {
            mainwin->view.process3+="i=["+QString::number(i)+"] groupid="+QString::number(brd->pairlst[i]->groupid)+" id1="+QString::number(brd->pairlst[i]->id1)+" id2="+QString::number(brd->pairlst[i]->id2)+" curenthistrycnt="+QString::number(brd->curenthistrycnt)+"\n";
        }*/
        mainwin->progressBarSet();
        mainwin->proceessstatusSet();
        mainwin->m.unlock();

        if(brd->pairlst[v]->twice==true && loopdoneis1)
        {
            loopdoneis1=false;
            goto line1;
        }
    }
    goto line3;
}
void solverfuncclass::loopdone(boardclass *mbrd,int tow,int xx,int yy)
{
    soundfile(4);
    if(brd->pairlst[v]->twice==true && brd->pairlst[v]->brd1==mbrd && brd->pairlst[v]->x1==xx && brd->pairlst[v]->y1==yy)
    {
        //selectloop++;
        //mainwin->setWindowTitle("LOOP DONE");
        loopdoneis1=true;
        fcnt1=1;
        return;
    }
    if(brd->pairlst[v]->twice==true && brd->pairlst[v]->brd3==mbrd && brd->pairlst[v]->x3==xx && brd->pairlst[v]->y3==yy)
    {
        //selectloop++;
        //mainwin->setWindowTitle("LOOP DONE");
        loopdoneis2=true;
        if(fcnt1!=1){return;}
        fcnt1=0;
    }
    if(v==0)
    {
        soundfile(5);
        stopthread=true;
        if(param2==0)
        {
            QString mstr=mainwin->windowTitle()+" : ERROR STOP";
            mainwin->setWindowTitle(mstr);
        }
        else
        {
            QString mstr=mainwin->windowTitle()+" : Not Tajyu Kai";
            mainwin->setWindowTitle(mstr);
        }

        //delete th;
        //th=NULL;
        badend=true;
        return;
    }
    int id1=brd->pairlst[v-1]->id1;
    int id2=brd->pairlst[v-1]->id2;
    int id3=brd->pairlst[v-1]->id3;
    int id4=brd->pairlst[v-1]->id4;
    brd->curenthistrycnt--;
    for(int i=v-1;i>=0;i--)
    {
        if(id1==brd->pairlst[i]->id1 && id2==brd->pairlst[i]->id2 && brd->curenthistrycnt==brd->pairlst[i]->groupid)
        {
            v=i;break;
        }
    }
    brd1=brd->pairlst[v]->brd1;
    brd2=brd->pairlst[v]->brd2;
    brd3=brd->pairlst[v]->brd3;
    brd4=brd->pairlst[v]->brd4;
    if(param2==1 && solvecount==1)
    {
        QString mstr=mainwin->windowTitle()+" : Solve Done Tajyu Kai";
    }
    return;
}
void solverfuncclass::loopupdate(int param)
{
    while(1)
    {
        usleep(200000);
        if(badend==true){usleep(2000000);}
        mainwin->update();
    }
}
void solverfuncclass::mainloopth(int param)
{
    if(th==NULL)
    {
    th=new std::thread( &solverfuncclass::mainloop,this, param );
    }
    else
    {
        th->detach();
        delete th;
        th=new std::thread( &solverfuncclass::mainloop,this, param );
        //firstline=true;
    }
    if(th2==NULL)
    {
    th2=new std::thread( &solverfuncclass::loopupdate,this,0 );
    }
}
void solverfuncclass::mainloopthrestart()
{
    th2->detach();
    th2->~thread();
    delete th2;
    th2=new std::thread( &solverfuncclass::loopupdate,this,0 );
}
void solverfuncclass::boardhistoryclassset(boardhistorycclass *mbrd)
{
    brd=mbrd;
    numberloopclass::boardhistorycclassset(mbrd);
}
void solverfuncclass::mainwinclassset(MainWindow *mmainwin)
{
    mainwin=mmainwin;
}
void solverfuncclass::numset(int *num,int *num2,int r)
{
    bool twice=brd->pairlst[r]->twice;
    int x1=brd->pairlst[r]->x1;
    int y1=brd->pairlst[r]->y1;
    int x2=brd->pairlst[r]->x2;
    int y2=brd->pairlst[r]->y2;
    int x3=brd->pairlst[r]->x3;
    int y3=brd->pairlst[r]->y3;
    int x4=brd->pairlst[r]->x4;
    int y4=brd->pairlst[r]->y4;


    boardclass *brd1=brd->pairlst[r]->brd1;
    boardclass *brd3=brd->pairlst[r]->brd3;
    //boardclass *brd2=brd->pairlst[r]->brd2;
    mainwin->m.lock();
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            brd->pairlst[r]->numlist[x*3+y]=num[x*3+y];
            if(brd1->data[x1*3+x][y1*3+y]->lock==false)
            {
                brd1->dataset(x1*3+x,y1*3+y,num[x*3+y]);
            }
            if(twice)
            {
                if(brd1->data[x3*3+x][y3*3+y]->lock==false)
                {
                    brd1->dataset(x3*3+x,y3*3+y,num2[x*3+y]);
                }
            }
        }
    }
    mainwin->m.unlock();

}
void solverfuncclass::numset(int *num,int r)
{
    int x1=brd->pairlst[r]->x1;
    int y1=brd->pairlst[r]->y1;
    int x2=brd->pairlst[r]->x2;
    int y2=brd->pairlst[r]->y2;
    int x3=brd->pairlst[r]->x3;
    int y3=brd->pairlst[r]->y3;
    int x4=brd->pairlst[r]->x4;
    int y4=brd->pairlst[r]->y4;
    bool twice=brd->pairlst[r]->twice;

    boardclass *brd1=brd->pairlst[r]->brd1;
    boardclass *brd3=brd->pairlst[r]->brd3;
    //boardclass *brd2=brd->pairlst[r]->brd2;
    mainwin->m.lock();
    for(int x=0;x<3;x++)
    {
        for(int y=0;y<3;y++)
        {
            brd->pairlst[r]->numlist[x*3+y]=num[x*3+y];
            if(brd1->data[x1*3+x][y1*3+y]->lock==false)
            {
                brd1->dataset(x1*3+x,y1*3+y,num[x*3+y]);
            }
        }
    }
    mainwin->m.unlock();

}

bool solverfuncclass::solver(boardclass *mbr1,boardclass *mbr2,bool lastis)
{
    mainwin->m.lock();
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz1.setBoardValue(j,k,mbr1->dataget(j,k));
            pz2.setBoardValue(j,k,mbr2->dataget(j,k));
        }
    }
    mainwin->m.unlock();
    if(pz2.solve()==false)
    {
        return false;
    }
    if(pz1.solve()==false)
    {
        return false;
    }
    mainwin->m.lock();
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            mbr1->dataset(j,k,pz1.dataget(j,k));
            if(lastis){mbr2->dataset(j,k,pz2.dataget(j,k));}
        }
    }
    mainwin->m.unlock();
    return true;
}
bool solverfuncclass::solvertest3(boardclass *mbr1,boardclass *mbr2,bool lastis)
{
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz1.setBoardValue(j,k,mbr1->dataget(j,k));
        }
    }
    if(pz1.solve()==false)
    {
        return false;
    }
    return true;
}
bool solverfuncclass::solvertest2(boardclass *mbr1,boardclass *mbr2,bool lastis)
{

    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            if(mbr1->isput2(j,k,mbr1->dataget(j,k))==false)
            {
                return false;
            }
            if(mbr2->isput2(j,k,mbr2->dataget(j,k))==false)
            {
                return false;
            }
        }
    }
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz1.setBoardValue(j,k,mbr1->dataget(j,k));
        }
    }
    if(pz1.solve()==false)
    {
        return false;
    }
    mainwin->m.lock();
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            //mbr1->data[j][k]->lock=true;<<<-------------------<<<*----------------????? kokokana?
            mbr1->dataset(j,k,pz1.dataget(j,k));
            //mbr1->data[j][k]->lockchild=true;
        }
    }
    mainwin->m.unlock();
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            if(mbr2->isput2(j,k,mbr2->dataget(j,k))==false)
            {
                return false;
            }
        }
    }
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz2.setBoardValue(j,k,mbr2->dataget(j,k));
        }
    }
   if(pz2.solve()==false)
    {
        return false;
    }
   mainwin->m.lock();
   for(int j=0;j<9;j++)
   {
       for(int k=0;k<9;k++)
       {
           //if
           mbr2->dataset(j,k,pz2.dataget(j,k));
       }
   }
   mainwin->m.unlock();
    return true;
}
bool solverfuncclass::solvertest1(boardclass *mbr1,boardclass *mbr2,bool lastis)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                int n1=mbr1->dataget(j,k);
                int n2=mbr1->dataget(i,k);
                if(i!=j && n1==n2 && n1!=0){return false;}
                n1=mbr1->dataget(k,i);
                n2=mbr1->dataget(k,j);
                if(i!=j && n1==n2 && n1!=0){return false;}
                n1=mbr2->dataget(j,k);
                n2=mbr2->dataget(i,k);
                if(i!=j && n1==n2 && n1!=0){return false;}
                n1=mbr2->dataget(k,i);
                n2=mbr2->dataget(k,j);
                if(i!=j && n1==n2 && n1!=0){return false;}
            }
        }
    }
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz1.setBoardValue(j,k,mbr1->dataget(j,k));
        }
    }
    if(pz1.solve()==false)
    {
        return false;
    }
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            mbr1->dataset(j,k,pz1.dataget(j,k));
        }
    }
    for(int j=0;j<9;j++)
    {
        for(int k=0;k<9;k++)
        {
            pz2.setBoardValue(j,k,mbr2->dataget(j,k));
        }
    }
   if(pz2.solve()==false)
    {
        return false;
    }
    return true;
}
bool solverfuncclass::allok(int histid)
{
    for(int i=0;i<brd->brdhist[histid]->brdgroup.size();i++)
    {

        for(int m=0;m<9;m++)
        {
            int sum1=0;
            int sum2=0;
            for(int n=0;n<9;n++)
            {
                sum1+=brd->brdhist[histid]->brdgroup[i]->dataget(m,n);
                sum2+=brd->brdhist[histid]->brdgroup[i]->dataget(n,m);
            }
            if(sum1!=45){return false;}
            if(sum2!=45){return false;}
        }
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                int sum3=0;
                for(int a=0;a<3;a++)
                {
                    for(int b=0;b<3;b++)
                    {
                        sum3+=brd->brdhist[histid]->brdgroup[i]->dataget(m*3+a,n*3+b);
                    }
                }
                if(sum3!=45){return false;}
            }
        }

    }
    return true;
}

void solverfuncclass::loopstart(boardclass *mbrd)
{

}
void solverfuncclass::looping(boardclass *mbrd)
{

}
void solverfuncclass::loopout()
{

}
void solverfuncclass::mainloopthstop()
{
    stopflag=1;
}
void solverfuncclass::locknumber()// tabunn sizega  goto line1 ikounisetti
{
    for(int i=0;i<brd->brdhist[brd->curenthistrycnt]->brdgroup.size();i++)
    {
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                if(brd->brdhist[brd->curenthistrycnt]->brdgroup[i]->data[x][y]->num!=0)
                {
                    brd->brdhist[brd->curenthistrycnt]->brdgroup[i]->data[x][y]->lock=true;
                }
                else
                {
                    brd->brdhist[brd->curenthistrycnt]->brdgroup[i]->data[x][y]->lock=false;
                }
            }
        }

    }
}
void solverfuncclass::emerge()
{
    //mainloop2();
}
void solverfuncclass::anscheckset()
{
    for(int i=0;i<brd->brdhist[brd->curenthistrycnt]->brdgroup.size();i++)
    {
        boardclass *brt=new boardclass;
        for(int m=0;m<9;m++)
        {
            for(int n=0;n<9;n++)

            {
                int num=brd->brdhist[brd->curenthistrycnt]->brdgroup[i]->dataget(m,n);
                brt->dataset(m,n,num);
            }
        }
        anscheck.brdgroup.push_back(brt);
    }
}
bool solverfuncclass::anscheckis()
{
    for(int i=0;i<anscheck.brdgroup.size();i++)
    {
        for(int m=0;m<9;m++)
        {
            for(int n=0;n<9;n++)
            {
                int num1=brd->brdhist[brd->curenthistrycnt]->brdgroup[i]->dataget(m,n);
                int num2=anscheck.brdgroup[i]->dataget(m,n);
                if(num1!=num2){return false;}
            }
        }
    }
    return  true;
}
