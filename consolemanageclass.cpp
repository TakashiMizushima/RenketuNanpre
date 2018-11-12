#include"consolemanageclass.h"
consolemanageclass::consolemanageclass()
{
    areaediter=NULL;
}
consolemanageclass::~consolemanageclass()
{
    //th->join();
    //delete th;
    if(areaediter!=NULL){delete areaediter;}
}
void consolemanageclass::MainWindowSet(MainWindow *main)
{
    mainwin=main;
}
void consolemanageclass::BoardManageSet(boardhistorycclass *mbrdhist,boardhistorycclass *mbrdhistr)
{
    brdhist=mbrdhist;
    brdhistr=mbrdhistr;
    //solc->handleboardmane(brdhist,brdhistr);
}
void consolemanageclass::imagenumberclassset(imagenumberclass *im)
{
    image=im;
}
void consolemanageclass::manualconnect()
{
    mainwin->ai->manualconnect=1;
    mainwin->aiclassplay();
}
void consolemanageclass::mapup()
{
    QPoint ps;
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        ps.setX(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*3*0);
        ps.setY(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*3*1);
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setX(ps.x());
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setY(ps.y());
    }
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        for(unsigned int j=0;j<brdhist->curentbrdgroupget()->brdgroup[i]->clicklist.size();j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setX(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*0);
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setY(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*3);
        }
    }
    mainwin->update();
    return;
}
void consolemanageclass::mapdn()
{
    QPoint ps;
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        ps.setX(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*3*0);
        ps.setY(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*3*(-1));
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setX(ps.x());
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setY(ps.y());
    }
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        for(unsigned int j=0;j<brdhist->curentbrdgroupget()->brdgroup[i]->clicklist.size();j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setX(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*0);
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setY(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*(-3));
        }
    }
    mainwin->update();
    return;
}
void consolemanageclass::maplf()
{
    QPoint ps;
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        ps.setX(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*3*1);
        ps.setY(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*3*0);
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setX(ps.x());
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setY(ps.y());
    }
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        for(unsigned int j=0;j<brdhist->curentbrdgroupget()->brdgroup[i]->clicklist.size();j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setX(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*3);
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setY(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*0);
        }
    }
    mainwin->update();
    return;
}
void consolemanageclass::maprt()
{
    QPoint ps;
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        ps.setX(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*3*(-1));
        ps.setY(brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*3*0);
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setX(ps.x());
        brdhist->curentbrdgroupget()->brdgroup[i]->drawpos.setY(ps.y());
    }
    for(unsigned int i=0;i<brdhist->curentbrdgroupget()->brdgroup.size();i++)
    {
        for(unsigned int j=0;j<brdhist->curentbrdgroupget()->brdgroup[i]->clicklist.size();j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setX(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].x()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.width()*(-3));
            brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].setY(brdhist->curentbrdgroupget()->brdgroup[i]->clicklist[j].y()+brdhist->curentbrdgroupget()->brdgroup[i]->chipsize.height()*0);
        }
    }
    mainwin->update();
    return;
}
void consolemanageclass::filesave()
{
    QString fileName = QFileDialog::getSaveFileName(mainwin,QObject::tr("Save Data"), QObject::tr(""),QObject::tr("text (*.txt);;All Files (*)"));
    if(fileName==""){return;}
    DataSave((char *)fileName.toStdString().c_str());
    mainwin->setWindowTitle(fileName);
}

void consolemanageclass::filesave2()
{
    QString fileName = QFileDialog::getSaveFileName(mainwin,QObject::tr("Save Data"), QObject::tr(""),QObject::tr("text (*.txt);;All Files (*)"));
    if(fileName==""){return;}
    DataSave2((char *)fileName.toStdString().c_str());
    mainwin->setWindowTitle(fileName);
}
void consolemanageclass::fileload()
{
    //mainwin->ai->replayinitial();
    //mainwin->ai->manualconnect=1;
    QString fileNamex = QFileDialog::getOpenFileName(mainwin,QObject::tr("Open Data"), QObject::tr(""),QObject::tr("text (*.txt);;All Files (*)"));
    if(fileNamex==""){return;}
    DataLoad((char *)fileNamex.toStdString().c_str());
    fileName=fileNamex;
    mainwin->enable.mousepress=true;
}
void consolemanageclass::fileloadapend()
{
    //mainwin->ai->replayinitial();
    //mainwin->ai->manualconnect=1;
    QString fileNamex = QFileDialog::getOpenFileName(mainwin,QObject::tr("Open Data"), QObject::tr(""),QObject::tr("text (*.txt);;All Files (*)"));
    if(fileNamex==""){return;}
    DataLoadApend((char *)fileNamex.toStdString().c_str());
    fileName=fileNamex;
    mainwin->enable.mousepress=true;
}
void consolemanageclass::mapadd(int count)
{
    count=count;
    mainwin->board->curentbrdgroupget()->boardclassadd();
    mainwin->enable.mousepress=true;
    return;
}
void consolemanageclass::mapaddr(int count)
{
    count=count;
    mainwin->board2->curentbrdgroupget()->boardclassadd();
    return;
}

void consolemanageclass::mapdel(int index)
{
    if(index>=mainwin->board->curentbrdgroupget()->brdgroup.size()){return;}
    if(index<0){return;}
    mainwin->board->brdhist[0]->brdgroup.erase(mainwin->board->brdhist[0]->brdgroup.begin()+index);
    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        mainwin->board->brdhist[0]->brdgroup[i]->index=i;
    }
    return;
}

void consolemanageclass::mapdelh()
{
    brdhist->boardhistorylastdel();
    mainwin->update();
}

void consolemanageclass::setboarddata(boardclass *brdl,int xx,int yy,stonecreateclass *nds)
{
    int n1=brdl->dataget(xx*3+0,yy*3+0);
    int n2=brdl->dataget(xx*3+0,yy*3+1);
    int n3=brdl->dataget(xx*3+0,yy*3+2);
    int n4=brdl->dataget(xx*3+1,yy*3+0);
    int n5=brdl->dataget(xx*3+1,yy*3+1);
    int n6=brdl->dataget(xx*3+1,yy*3+2);
    int n7=brdl->dataget(xx*3+2,yy*3+0);
    int n8=brdl->dataget(xx*3+2,yy*3+1);
    int n9=brdl->dataget(xx*3+2,yy*3+2);
    nds->posdataset(xx,yy,n1,n2,n3,n4,n5,n6,n7,n8,n9);
}


void consolemanageclass::mapfall(int index,std::vector<int> *mlist)
{
    boardclass *ie=brdhist->curentbrdgroupget()->brdgroup[index];
    stonecreateclass *nds;
    nds=new stonecreateclass;
    nds->boardclassset(ie);
    for(unsigned int i=0;i<mlist->size();i+=2)
    {
        setboarddata(ie,(*mlist)[i],(*mlist)[i+1],nds);
    }
    nds->datacreate();
    nds->boardclassget(ie);
    mainwin->update();
    delete nds;
    return;
}

void consolemanageclass::dataset(int id,int xx,int yy,std::vector<int> *list)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[id]->dataset(xx*3+i,yy*3+j,(*list)[i+j*3]);
        }
    }
}

void consolemanageclass::mapedit(int index)
{
    areaediter=new editerclass;
    int das[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            das[i][j]=brdhist->curentbrdgroupget()->boardget(index)->dataget(i,j);
        }
    }
    areaediter->setGeometry(0,0,1400,1000);
    areaediter->pushdata(this->mainwin,index,das);
    areaediter->setWindowTitle(areaediter->windowTitle()+"  :  "+ QString::number(index));
    areaediter->show();
    return;
}
void consolemanageclass::dataerase()//????
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            brdhist->curentbrdgroupget()->brdgroup[brdhist->curentbrdgroupget()->curentbrdnum]->dataset(i,j,0);
        }
    }
}
void consolemanageclass::dataprint(int index)
{
    int k=index;
    std::string str;
    str+="%!\n";
    str+="gsave\n";
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38+2,120+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38+2,120+(j+1)*38);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38,120+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38,120+(j+1)*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+j*38,120+i*38+2);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,120+i*38+2);
                str+=tstr;
            }
            if(j!=9)
            {
                char tstr[250];
                sprintf(tstr,"%d %d moveto\n",140+j*38,120+i*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,120+i*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[380];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38+2,470+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38+2,470+(j+1)*38);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38,470+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38,470+(j+1)*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {/**/
                sprintf(tstr,"%d %d moveto\n",140+j*38,470+i*38+2);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,470+i*38+2);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+j*38,470+i*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,470+i*38);
                str+=tstr;
            }
        }
    }

    str+="gsave\n";
    char tstr[250];
    //sprintf(tstr,"Ryumin-Light-UniJIS-UTF8-H findfont 12 scalefont setfont");
    sprintf(tstr,"/Courier     findfont [ 20 0 0 20 0 0 ] makefont setfont\n");
    str+=tstr;
    ///////////////
    for(int j=0;j<9;j++)
    {
    for(int i=0;i<9;i++)
    {
        /*
            sprintf(tstr,"%d %d moveto\n",140+10+j*38,120+10+i*38);
            str+=tstr;
            sprintf(tstr,"(%d) show\n",brdhist->curentbrdgroupget()->brdgroup[k]->stoneoriginget(j,8-i));
            str+=tstr;
        */
            if(brdhist->curentbrdgroupget()->brdgroup[k]->dataget(j,8-i)!=0)
            {
                sprintf(tstr,"%d %d moveto\n",140+10+j*38,470+10+i*38);
                str+=tstr;
                sprintf(tstr,"(%d) show\n",brdhist->curentbrdgroupget()->brdgroup[k]->dataget(j,8-i));
                str+=tstr;
            }

        }
    }

    //sprintf(tstr,"Ryumin-Light-UniJIS-UTF8-H findfont 12 scalefont setfont");
    //str+=tstr;
    sprintf(tstr,"%d %d moveto\n",0,0);
    str+=tstr;
    str+="stroke\n";
    //////////////
    int tc=0;
    FILE *f2=fopen("NanpreGui-conf.txt","r");
    fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);
    fclose(f2);
    sprintf(tstr,"%d %d moveto\n",0,0);
    str+=tstr;
    str+="showpage\n";
    str+="grestore\n";
    FILE *f=fopen("print.ps","w");
    fprintf(f,str.c_str());
    fclose(f);
    char filenameps1[2560];
    char filenameps2[2560];
    sprintf(filenameps1,"cat address.ps >print%d.ps",k);
    sprintf(filenameps2,"cat print.ps >> print%d.ps",k);
    if(tc==1)
    {
        system("cat address.ps >print2.ps");
        system("cat print.ps >> print2.ps");
        system("cat print2.ps | lpr -P Epson-PX-M5041F");
    }
    else
    {
        system("cat print.ps | lpr -P Epson-PX-M5041F");
    }


}
void consolemanageclass::dataprintmap(int index)
{
    index=index;
    std::string str;
    str+="%!\n";
    str+="gsave\n";
    for(unsigned int t=0;t<brdhist->curentbrdgroupget()->brdgroup.size();t++)
    {
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                char tstr[250];
                if(i%3==0 && j!=9)
                {
                    sprintf(tstr,"%d %d moveto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+j*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                    sprintf(tstr,"%d %d lineto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+(j+1)*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                }
                if(j!=9)
                {
                    sprintf(tstr,"%d %d moveto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+j*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                    sprintf(tstr,"%d %d lineto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+(j+1)*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                }
            }
            for(int j=0;j<10;j++)
            {
                char tstr[250];
                if(i%3==0 && j!=9)
                {
                    sprintf(tstr,"%d %d moveto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+j*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                    sprintf(tstr,"%d %d lineto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+(j+1)*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                }
                if(j!=9)
                {
                    char tstr[250];
                    sprintf(tstr,"%d %d moveto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+j*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                    sprintf(tstr,"%d %d lineto\n",20+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.x()/2+(j+1)*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.width()/2,60+brdhist->curentbrdgroupget()->brdgroup[t]->drawpos.y()/2+i*brdhist->curentbrdgroupget()->brdgroup[t]->chipsize.height()/2);
                    str+=tstr;
                }
            }
        }
    }
        str+="gsave\n";
        char tstr[250];
        //sprintf(tstr,"Ryumin-Light-UniJIS-UTF8-H findfont 12 scalefont setfont");
        sprintf(tstr,"/Courier     findfont [ 20 0 0 20 0 0 ] makefont setfont\n");
        str+=tstr;
        str+="stroke\n";
    ///////////////
    //////////////
    int tc=0;
    FILE *f2=fopen("NanpreGui-conf.txt","r");
    fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);
    fclose(f2);
    sprintf(tstr,"%d %d moveto\n",0,0);
    str+=tstr;
    str+="showpage\n";
    str+="grestore\n";
    FILE *f=fopen("print.ps","w");
    fprintf(f,str.c_str());
    fclose(f);
    if(tc==1)
    {
        system("cat address.ps >print2.ps");
        system("cat print.ps >> print2.ps");
        system("cat print2.ps | lpr -P Epson-PX-M5041F");
    }
    else
    {
       system("cat print.ps | lpr -P Epson-PX-M5041F");
    }


}
void consolemanageclass::circleput()
{
    if(brdhist->circledraw==1){brdhist->circledrawset(0);}
    else{brdhist->circledrawset(1);}
    mainwin->update();
    return;
}
void consolemanageclass::maprotate()
{
    rotation();
    mainwin->update();
    return;
}
#define PI  3.141592
void consolemanageclass::rotation()
{


    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        boardclass *brd=mainwin->board->brdhist[0]->brdgroup[i];
        boardclass brdt;
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                int x1=y;
                int y1=8-x;
                brdt.dataset(x1,y1,brd->dataget(x,y));
            }
        }
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                brd->dataset(x,y,brdt.dataget(x,y));
            }
        }
    }
    /*
    for(int i=0;i<mainwin->board->pairlst.size();i++)
    {
        int a1=mainwin->board->pairlst[i]->x1;
        int b1=mainwin->board->pairlst[i]->y1;
        mainwin->board->pairlst[i]->x1=b1;
        mainwin->board->pairlst[i]->y1=2-a1;
        int a2=mainwin->board->pairlst[i]->x2;
        int b2=mainwin->board->pairlst[i]->y2;
        mainwin->board->pairlst[i]->x1=b2;
        mainwin->board->pairlst[i]->y1=2-a2;
        int a3=mainwin->board->pairlst[i]->x3;
        int b3=mainwin->board->pairlst[i]->y3;
        mainwin->board->pairlst[i]->x3=b3;
        mainwin->board->pairlst[i]->y3=2-a3;
        int a4=mainwin->board->pairlst[i]->x4;
        int b4=mainwin->board->pairlst[i]->y4;
        mainwin->board->pairlst[i]->x4=b4;
        mainwin->board->pairlst[i]->y4=2-a4;
    }
    for(int i=0;i<mainwin->board->paironlylst.size();i++)
    {
        int a1=mainwin->board->paironlylst[i]->x1;
        int b1=mainwin->board->paironlylst[i]->y1;
        mainwin->board->paironlylst[i]->x1=b1;
        mainwin->board->paironlylst[i]->y1=2-a1;
        int a2=mainwin->board->paironlylst[i]->x2;
        int b2=mainwin->board->paironlylst[i]->y2;
        mainwin->board->paironlylst[i]->x1=b2;
        mainwin->board->paironlylst[i]->y1=2-a2;
        int a3=mainwin->board->paironlylst[i]->x3;
        int b3=mainwin->board->paironlylst[i]->y3;
        mainwin->board->paironlylst[i]->x3=b3;
        mainwin->board->paironlylst[i]->y3=2-a3;
        int a4=mainwin->board->paironlylst[i]->x4;
        int b4=mainwin->board->paironlylst[i]->y4;
        mainwin->board->paironlylst[i]->x4=b4;
        mainwin->board->paironlylst[i]->y4=2-a4;
    }
    */

    QPoint min;
    QPoint max;
    min.setX(mainwin->board->brdhist[0]->brdgroup[0]->drawpos.x());
    min.setX(mainwin->board->brdhist[0]->brdgroup[0]->drawpos.y());
    max.setX(mainwin->board->brdhist[0]->brdgroup[0]->drawpos.x()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.width()*9);
    max.setX(mainwin->board->brdhist[0]->brdgroup[0]->drawpos.y()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.height()*9);
    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        if(min.x()>mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x())
        {
            min.setX(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x());
        }
        if(min.y()>mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y())
        {
            min.setY(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y());
        }
        if(max.x()<mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.width()*9)
        {
            max.setX(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.width()*9);
        }
        if(max.y()<mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.height()*9)
        {
            max.setY(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y()+mainwin->board->brdhist[0]->brdgroup[0]->chipsize.height()*9);
        }
    }
    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setX(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x()-(max.x()-min.x())/2);
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setY(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y()-(max.y()-min.y())/2);
    }

    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        int x1=mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x();
        int y1=mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y();
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setX(y1);
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setY((-1)*x1);
    }
    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setX(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.x()+(max.x()-min.x())/2);
        mainwin->board->brdhist[0]->brdgroup[i]->drawpos.setY(mainwin->board->brdhist[0]->brdgroup[i]->drawpos.y()+(max.y()-min.y())/2);
    }
    /*
    for(int i=0;i<mainwin->board->brdhist[0]->brdgroup.size();i++)
    {
        boardclass *brd=mainwin->board->brdhist[0]->brdgroup[i];
        boardclass brdt;
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                brdt.dataset(8-y,x,brd->dataget(x,y));
                brd->dataset(x,y,0);
            }
        }
        for(int x=0;x<9;x++)
        {
            for(int y=0;y<9;y++)
            {
                brd->dataset(x,y,brdt.dataget(x,y));
            }
        }

    }
*/
}
void consolemanageclass::DataSave(char *filename)
{
    mainwin->reload->fileName=filename;
   FILE *f=fopen(filename,"w");
    fprintf(f,"%d %d %d\n",(int)brdhist->brdhist.size(),(int)brdhist->pairlst.size(),(int)brdhist->paironlylst.size());
    for(int i=0;i<(signed int)brdhist->pairlst.size();i++)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %d\n",0,0,brdhist->pairlst[i]->id1,brdhist->pairlst[i]->id2,brdhist->pairlst[i]->x1,brdhist->pairlst[i]->x2,brdhist->pairlst[i]->y1,brdhist->pairlst[i]->y2,brdhist->pairlst[i]->groupid);
    }
    for(int i=0;i<(signed int)brdhist->paironlylst.size();i++)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %d\n",0,0,brdhist->paironlylst[i]->id1,brdhist->paironlylst[i]->id2,brdhist->paironlylst[i]->x1,brdhist->paironlylst[i]->x2,brdhist->paironlylst[i]->y1,brdhist->paironlylst[i]->y2,brdhist->paironlylst[i]->groupid);
    }
    for(int i=0;i<(signed int)brdhist->brdhist.size();i++)
    {
        fprintf(f,"%d\n",(int)brdhist->brdhist[i]->brdgroup.size());
        for(int j=0;j<(signed int)brdhist->brdhist[i]->brdgroup.size();j++)
        {;
            fprintf(f,"%d %d %d %d %d %d %d\n",brdhist->brdhist[i]->brdgroup[j]->index,brdhist->brdhist[i]->brdgroup[j]->enable.circledraw,brdhist->brdhist[i]->brdgroup[j]->enable.draw,brdhist->brdhist[i]->brdgroup[j]->enable.mousepress,(signed int)brdhist->brdhist[i]->brdgroup[j]->clicklist.size(),brdhist->brdhist[i]->brdgroup[j]->drawpos.x(),brdhist->brdhist[i]->brdgroup[j]->drawpos.y());
            for(int t=0;t<(signed int)brdhist->brdhist[i]->brdgroup[j]->clicklist.size();t++)
            {
                fprintf(f,"%d %d\n",brdhist->brdhist[i]->brdgroup[j]->clicklist[t].x(),brdhist->brdhist[i]->brdgroup[j]->clicklist[t].y());
            }
            for(int m=0;m<9;m++)
            {
                for(int n=0;n<9;n++)
                {
                    fprintf(f,"%d %d %d %d\n",brdhist->brdhist[i]->brdgroup[j]->data[m][n]->index,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->num,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->xx,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->yy);
                }
            }
        }
    }
    fclose(f);
}
void consolemanageclass::DataSave2(char *filename)
{
    mainwin->reload->fileName=filename;
   FILE *f=fopen(filename,"w");
    fprintf(f,"%d %d %d\n",(int)1,(int)0,(int)0);
    for(int i=0;i<(signed int)0;i++)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %d\n",0,0,brdhist->pairlst[i]->id1,brdhist->pairlst[i]->id2,brdhist->pairlst[i]->x1,brdhist->pairlst[i]->x2,brdhist->pairlst[i]->y1,brdhist->pairlst[i]->y2,brdhist->pairlst[i]->groupid);
    }
    for(int i=0;i<(signed int)0;i++)
    {
        fprintf(f,"%d %d %d %d %d %d %d %d %d\n",0,0,brdhist->paironlylst[i]->id1,brdhist->paironlylst[i]->id2,brdhist->paironlylst[i]->x1,brdhist->paironlylst[i]->x2,brdhist->paironlylst[i]->y1,brdhist->paironlylst[i]->y2,brdhist->paironlylst[i]->groupid);
    }
    for(int i=brdhist->brdhist.size()-1;i<(signed int)brdhist->brdhist.size();i++)
    {
        fprintf(f,"%d\n",(int)brdhist->brdhist[i]->brdgroup.size());
        for(int j=0;j<(signed int)brdhist->brdhist[i]->brdgroup.size();j++)
        {
            fprintf(f,"%d %d %d %d %d %d %d\n",brdhist->brdhist[i]->brdgroup[j]->index,brdhist->brdhist[i]->brdgroup[j]->enable.circledraw,brdhist->brdhist[i]->brdgroup[j]->enable.draw,brdhist->brdhist[i]->brdgroup[j]->enable.mousepress,(signed int)brdhist->brdhist[i]->brdgroup[j]->clicklist.size(),brdhist->brdhist[i]->brdgroup[j]->drawpos.x(),brdhist->brdhist[i]->brdgroup[j]->drawpos.y());
            for(int t=0;t<(signed int)brdhist->brdhist[i]->brdgroup[j]->clicklist.size();t++)
            {
                fprintf(f,"%d %d\n",brdhist->brdhist[i]->brdgroup[j]->clicklist[t].x(),brdhist->brdhist[i]->brdgroup[j]->clicklist[t].y());
            }
            for(int m=0;m<9;m++)
            {
                for(int n=0;n<9;n++)
                {
                    fprintf(f,"%d %d %d %d\n",brdhist->brdhist[i]->brdgroup[j]->data[m][n]->index,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->num,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->xx,brdhist->brdhist[i]->brdgroup[j]->data[m][n]->yy);
                }
            }
        }
    }
    fclose(f);
}
void consolemanageclass::DataLoad(char *filename)
{
    //mainwin->ai->manualconnect=1;
    mainwin->reload->fileName=filename;
    mainwin->setWindowTitle(QString(filename));
    for(int i=0;i<(int)brdhist->brdhist.size();i++)
    {
        for(int j=0;j<(int)brdhist->brdhist[i]->brdgroup.size();j++)
        {
            delete brdhist->brdhist[i]->brdgroup[j];
        }
        brdhist->brdhist[i]->brdgroup.clear();
        delete brdhist->brdhist[i];
    }
    //delete brdhist;
    brdhist->brdhist.clear();

    //brdhist=new boardhistorycclass;
    FILE *f=fopen(filename,"r");
    int histcnt=0;
    int parecnt=0;
    int pareonlycnt=0;
    fscanf(f,"%d %d %d\n",&histcnt,&parecnt,&pareonlycnt);
    for(int i=0;i<parecnt;i++)
    {
        int g1,g2,g3,g4,g5,g6,g7,g8,g9;
        fscanf(f,"%d %d %d %d %d %d %d %d %d\n",&g1,&g2,&g3,&g4,&g5,&g6,&g7,&g8,&g9);
        boardhistorycclass::PAIRDATA *pa=new boardhistorycclass::PAIRDATA;
        //brdhist->pairlst[i]->brd1;
        //brdhist->pairlst[i]->brd2;
        pa->id1=g3;
        pa->id2=g4;
        pa->x1=g5;
        pa->x2=g6;
        pa->y1=g7;
        pa->y2=g8;
        pa->groupid=g9;
        brdhist->pairlst.push_back(pa);
    }
    for(int i=0;i<pareonlycnt;i++)
    {
        int g1,g2,g3,g4,g5,g6,g7,g8,g9;
        fscanf(f,"%d %d %d %d %d %d %d %d %d\n",&g1,&g2,&g3,&g4,&g5,&g6,&g7,&g8,&g9);
        boardhistorycclass::PAIRDATA *paonly=new boardhistorycclass::PAIRDATA;
        //brdhist->pairlst[i]->brd1;
        //brdhist->pairlst[i]->brd2;
        paonly->id1=g3;
        paonly->id2=g4;
        paonly->x1=g5;
        paonly->x2=g6;
        paonly->y1=g7;
        paonly->y2=g8;
        paonly->groupid=g9;
        brdhist->paironlylst.push_back(paonly);
    }
    for(int i=0;i<histcnt;i++)
    {
        boardgroupclass *bg1=new boardgroupclass;
        int brdgrpcnt=0;
        fscanf(f,"%d\n",&brdgrpcnt);
        for(int j=0;j<brdgrpcnt;j++)
        {
            boardclass *bc1=new boardclass;
            int h0,h1,h2,h3,h4,h5,h6,g9,g10;
            fscanf(f,"%d %d %d %d %d %d %d\n",&h0,&h1,&h2,&h3,&h4,&g9,&g10);
            bc1->index=h0;
            bc1->enable.circledraw=(h1==1?true:false);
            bc1->enable.draw=(h2==1?true:false);
            bc1->enable.mousepress=(h3==1?true:false);
            h4=h4;//brdhist->brdhist[i]->brdgroup[j]->clicklist.size();
            bc1->drawpos.setX(g9);
            bc1->drawpos.setY(g10);
            for(int t=0;t<h4;t++)
            {
                fscanf(f,"%d %d\n",&h5,&h6);
                QPoint qp;
                qp.setX(h5);
                qp.setY(h6);
                bc1->clicklist.push_back(qp);
            }
            for(int m=0;m<9;m++)
            {
                for(int n=0;n<9;n++)
                {
                    int g1,g2,g3,g4;
                    fscanf(f,"%d %d %d %d\n",&g1,&g2,&g3,&g4);
                    bc1->data[m][n]->index=g1;
                    bc1->data[m][n]->num=g2;
                    bc1->data[m][n]->xx=g3;
                    bc1->data[m][n]->yy=g4;
                }
            }
            bg1->brdgroup.push_back(bc1);
        }
        brdhist->brdhist.push_back(bg1);
    }
    fclose(f);
    for(int i=0;i<(signed int)brdhist->pairlst.size();i++)
    {
        int id1=brdhist->pairlst[i]->id1;
        int id2=brdhist->pairlst[i]->id2;
        int index=brdhist->pairlst[i]->groupid;
        brdhist->pairlst[i]->brd1=brdhist->brdhist[index]->boardget(id1);
        brdhist->pairlst[i]->brd2=brdhist->brdhist[index]->boardget(id2);
        boardclass::CHIPDATA *dm;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int histid=brdhist->pairlst[i]->groupid;
                int id1=brdhist->pairlst[i]->id1;
                int x1=brdhist->pairlst[i]->x1;
                int y1=brdhist->pairlst[i]->y1;
                int id2=brdhist->pairlst[i]->id2;
                int x2=brdhist->pairlst[i]->x2;
                int y2=brdhist->pairlst[i]->y2;
                dm=memo.add();
                boardclass::CHIPDATA ch=*brdhist->brdhist[histid]->boardget(id1)->data[x1*3+x][y1*3+y];
                brdhist->brdhist[histid]->boardget(id1)->data[x1*3+x][y1*3+y]=dm;
                brdhist->brdhist[histid]->boardget(id2)->data[x2*3+x][y2*3+y]=dm;
                *dm=ch;
            }
        }
    }
    for(int i=0;i<pareonlycnt;i++)
    {
        int num=brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->num;
        bool lock=brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->lock;
        linkonlymake(brdhist->curenthistrycnt,brdhist->paironlylst[i]->id1,brdhist->paironlylst[i]->x1,brdhist->paironlylst[i]->y1,brdhist->paironlylst[i]->id2,brdhist->paironlylst[i]->x2,brdhist->paironlylst[i]->y2);
        brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->num=num;
        brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->lock=lock;
    }
}
void consolemanageclass::DataLoadApend(char *filename)
{
    //brdhist=new boardhistorycclass;
    FILE *f=fopen(filename,"r");
    int histcnt=0;
    int parecnt=0;
    int pareonlycnt=0;
    fscanf(f,"%d %d %d\n",&histcnt,&parecnt,&pareonlycnt);
    for(int i=0;i<parecnt;i++)
    {
        int g1,g2,g3,g4,g5,g6,g7,g8,g9;
        fscanf(f,"%d %d %d %d %d %d %d %d %d\n",&g1,&g2,&g3,&g4,&g5,&g6,&g7,&g8,&g9);
        boardhistorycclass::PAIRDATA *pa=new boardhistorycclass::PAIRDATA;
        //brdhist->pairlst[i]->brd1;
        //brdhist->pairlst[i]->brd2;
        pa->id1=g3;
        pa->id2=g4;
        pa->x1=g5;
        pa->x2=g6;
        pa->y1=g7;
        pa->y2=g8;
        pa->groupid=g9;
        brdhist->pairlst.push_back(pa);
    }
    for(int i=0;i<pareonlycnt;i++)
    {
        int g1,g2,g3,g4,g5,g6,g7,g8,g9;
        fscanf(f,"%d %d %d %d %d %d %d %d %d\n",&g1,&g2,&g3,&g4,&g5,&g6,&g7,&g8,&g9);
        boardhistorycclass::PAIRDATA *paonly=new boardhistorycclass::PAIRDATA;
        //brdhist->pairlst[i]->brd1;
        //brdhist->pairlst[i]->brd2;
        paonly->id1=g3;
        paonly->id2=g4;
        paonly->x1=g5;
        paonly->x2=g6;
        paonly->y1=g7;
        paonly->y2=g8;
        paonly->groupid=g9;
        brdhist->paironlylst.push_back(paonly);
    }
    for(int i=0;i<histcnt;i++)
    {
        boardgroupclass *bg1=new boardgroupclass;
        int brdgrpcnt=0;
        fscanf(f,"%d\n",&brdgrpcnt);
        for(int j=0;j<brdgrpcnt;j++)
        {
            boardclass *bc1=new boardclass;
            int h0,h1,h2,h3,h4,h5,h6,g9,g10;
            fscanf(f,"%d %d %d %d %d %d %d\n",&h0,&h1,&h2,&h3,&h4,&g9,&g10);
            bc1->index=h0;
            bc1->enable.circledraw=(h1==1?true:false);
            bc1->enable.draw=(h2==1?true:false);
            bc1->enable.mousepress=(h3==1?true:false);
            h4=h4;//brdhist->brdhist[i]->brdgroup[j]->clicklist.size();
            bc1->drawpos.setX(g9);
            bc1->drawpos.setY(g10);
            for(int t=0;t<h4;t++)
            {
                fscanf(f,"%d %d\n",&h5,&h6);
                QPoint qp;
                qp.setX(h5);
                qp.setY(h6);
                bc1->clicklist.push_back(qp);
            }
            for(int m=0;m<9;m++)
            {
                for(int n=0;n<9;n++)
                {
                    int g1,g2,g3,g4;
                    fscanf(f,"%d %d %d %d\n",&g1,&g2,&g3,&g4);
                    bc1->data[m][n]->index=g1;
                    bc1->data[m][n]->num=g2;
                    bc1->data[m][n]->xx=g3;
                    bc1->data[m][n]->yy=g4;
                }
            }
            bg1->brdgroup.push_back(bc1);
        }
        brdhist->brdhist.push_back(bg1);
    }
    fclose(f);
    for(int i=0;i<(signed int)brdhist->pairlst.size();i++)
    {
        int id1=brdhist->pairlst[i]->id1;
        int id2=brdhist->pairlst[i]->id2;
        int index=brdhist->pairlst[i]->groupid;
        brdhist->pairlst[i]->brd1=brdhist->brdhist[index]->boardget(id1);
        brdhist->pairlst[i]->brd2=brdhist->brdhist[index]->boardget(id2);
        boardclass::CHIPDATA *dm;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int histid=brdhist->pairlst[i]->groupid;
                int id1=brdhist->pairlst[i]->id1;
                int x1=brdhist->pairlst[i]->x1;
                int y1=brdhist->pairlst[i]->y1;
                int id2=brdhist->pairlst[i]->id2;
                int x2=brdhist->pairlst[i]->x2;
                int y2=brdhist->pairlst[i]->y2;
                dm=memo.add();
                boardclass::CHIPDATA ch=*brdhist->brdhist[histid]->boardget(id1)->data[x1*3+x][y1*3+y];
                brdhist->brdhist[histid]->boardget(id1)->data[x1*3+x][y1*3+y]=dm;
                brdhist->brdhist[histid]->boardget(id2)->data[x2*3+x][y2*3+y]=dm;
                *dm=ch;
            }
        }
    }
    for(int i=0;i<pareonlycnt;i++)
    {
        int num=brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->num;
        bool lock=brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->lock;
        linkonlymake(brdhist->curenthistrycnt,brdhist->paironlylst[i]->id1,brdhist->paironlylst[i]->x1,brdhist->paironlylst[i]->y1,brdhist->paironlylst[i]->id2,brdhist->paironlylst[i]->x2,brdhist->paironlylst[i]->y2);
        brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->num=num;
        brdhist->brdhist[brdhist->paironlylst[i]->groupid]->boardget(brdhist->paironlylst[i]->id1)->data[brdhist->paironlylst[i]->x1][brdhist->paironlylst[i]->y1]->lock=lock;
    }
}
void consolemanageclass::solver(int count)
{
    count=count;
    solc->mainloopth(0);
}
void consolemanageclass::solvercomplex(int count)
{
    count=count;
    solc->mainloopth(1);
}
void consolemanageclass::copyboard(std::vector<boardclass *> *data1,std::vector<boardclass *> *data2)
{
    data1=data1;data2=data2;
}
void consolemanageclass::indexedit(int fromindex,int toindex)
{
   boardclass *x1=brdhist->curentbrdgroupget()->brdgroup[fromindex];
   boardclass *x2=brdhist->curentbrdgroupget()->brdgroup[toindex];
   brdhist->curentbrdgroupget()->brdgroup[fromindex]=x2;
   brdhist->curentbrdgroupget()->brdgroup[toindex]=x1;
   brdhist->curentbrdgroupget()->brdgroup[fromindex]->index=fromindex;
   brdhist->curentbrdgroupget()->brdgroup[toindex]->index=toindex;
}
void consolemanageclass::makequestion()
{
}
void consolemanageclass::linkerase()
{
    brdhist->pairlst.clear();
    brdhist->paironlylst.clear();
    for(int i=0;i<(signed int)brdhist->brdhist.size();i++)
    {
        for(int j=0;j<(signed int)brdhist->brdhist[i]->brdgroup.size();j++)
        {
            brdhist->brdhist[i]->brdgroup[j]->clicklist.clear();
        }
    }
}
void consolemanageclass::linkerase(int index)
{
    brdhist->pairlst.erase(brdhist->pairlst.begin()+index);
}
void consolemanageclass::linkmake(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            (*dm).num=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->num;
            (*dm).lock=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->lock;
            (*dm).index=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->index;
            (*dm).xx=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->xx;
            (*dm).yy=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->yy;
            brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist->brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
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
    pr->twice=false;
    brdhist->pairlst.push_back(pr);

    pr->brd1=brdhist->brdhist[histid]->boardget(id1);
    pr->brd2=brdhist->brdhist[histid]->boardget(id2);

    QPoint cl1;QPoint cl2;
    cl1.setX(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);
    //mainwin->info->selectAll();
    //QString mhis=mainwin->info->textCursor().selectedText();
    //mainwin->info->clear();
    //QString mstr="'ads'("+QString::number(id1)+")["+QString::number(x1)+"]["+QString::number(y1)+"]\n";
      //     mstr+="'ads'("+QString::number(id2)+")["+QString::number(x2)+"]["+QString::number(y2)+"]\n";
    //mainwin->info->insertPlainText(QString(mstr));
    //mainwin->info->insertPlainText("-------------\n");
    //mainwin->info->insertPlainText(mhis);
    //mainwin->info->scroll(0,3);
    mainwin->update();
}
void consolemanageclass::linktwicemake(int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4)
{
    linktwicemake(brdhist->curenthistrycnt,id1,x1,y1,id2,x2,y2,id3,x3,y3,id4,x4,y4);
}
void consolemanageclass::linktwicemake(int histid,int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4)
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
            (*dm).num=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->num;
            (*dm).lock=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->lock;
            (*dm).index=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->index;
            (*dm).xx=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->xx;
            (*dm).yy=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->yy;
            (*dm2).num=brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->num;
            (*dm2).lock=brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->lock;
            (*dm2).index=brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->index;
            (*dm2).xx=brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->xx;
            (*dm2).yy=brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]->yy;
            brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist->brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
            brdhist->brdhist[histid]->boardget(id3)->data[x3*3+i][y3*3+j]=dm2;
            brdhist->brdhist[histid]->boardget(id4)->data[x4*3+i][y4*3+j]=dm2;
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
    pr->groupid=histid;
    pr->twice=true;
    pr->brd1=brdhist->brdhist[histid]->boardget(id1);
    pr->brd2=brdhist->brdhist[histid]->boardget(id2);
    pr->brd3=brdhist->brdhist[histid]->boardget(id3);
    pr->brd4=brdhist->brdhist[histid]->boardget(id4);
    brdhist->pairlst.push_back(pr);


    QPoint cl1;QPoint cl2;QPoint cl3;QPoint cl4;
    cl1.setX(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);
    cl3.setX(brdhist->curentbrdgroupget()->boardget(id3)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id3)->chipsize.width()*(x3+1)*3-20);
    cl3.setY(brdhist->curentbrdgroupget()->boardget(id3)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id3)->chipsize.height()*(y3+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id3)->clicklist.push_back(cl3);
    cl4.setX(brdhist->curentbrdgroupget()->boardget(id4)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id4)->chipsize.width()*(x4+1)*3-20);
    cl4.setY(brdhist->curentbrdgroupget()->boardget(id4)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id4)->chipsize.height()*(y4+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id4)->clicklist.push_back(cl4);
    /*mainwin->info->selectAll();
    QString mhis=mainwin->info->textCursor().selectedText();
    mainwin->info->clear();
    QString mstr="'adst'("+QString::number(id1)+")["+QString::number(x1)+"]["+QString::number(y1)+"]\n";
           mstr+="'adst'("+QString::number(id2)+")["+QString::number(x2)+"]["+QString::number(y2)+"]\n";
           mstr+="'adst'("+QString::number(id3)+")["+QString::number(x3)+"]["+QString::number(y3)+"]\n";
           mstr+="'adst'("+QString::number(id4)+")["+QString::number(x4)+"]["+QString::number(y4)+"]\n";
    mainwin->info->insertPlainText(QString(mstr));
    mainwin->info->insertPlainText("-------------\n");
    mainwin->info->insertPlainText(mhis);
    mainwin->info->scroll(0,3);*/
    mainwin->update();
}
void consolemanageclass::linkdowblemake(int id1,int x1,int y1,int id2,int x2,int y2)
{
    linkdowblemake(brdhist->curenthistrycnt,id1,x1,y1,id2,x2,y2);
}
void consolemanageclass::linkdowblemake(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist->brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
            dm->index=0;
            dm->num=0;
            dm->xx=0;
            dm->yy=0;
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
    brdhist->pairlst.push_back(pr);

    pr->brd1=brdhist->brdhist[histid]->boardget(id1);
    pr->brd2=brdhist->brdhist[histid]->boardget(id2);

    QPoint cl1;QPoint cl2;
    cl1.setX(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);
    /*mainwin->info->selectAll();
    QString mhis=mainwin->info->textCursor().selectedText();
    mainwin->info->clear();
    QString mstr="'ads'("+QString::number(id1)+")["+QString::number(x1)+"]["+QString::number(y1)+"]\n";
           mstr+="'ads'("+QString::number(id2)+")["+QString::number(x2)+"]["+QString::number(y2)+"]\n";
    mainwin->info->insertPlainText(QString(mstr));
    mainwin->info->insertPlainText("-------------\n");
    mainwin->info->insertPlainText(mhis);
    mainwin->info->scroll(0,3);*/
    mainwin->update();
}
void consolemanageclass::linkonlymake(int histid,int id1,int x1,int y1,int id2,int x2,int y2)
{
    if(id1<0){return;}
    if(id2<0){return;}
    boardclass::CHIPDATA *dm;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            dm=memo.add();
            (*dm).num=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->num;
            (*dm).lock=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->lock;
            (*dm).index=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->index;
            (*dm).xx=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->xx;
            (*dm).yy=brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]->yy;
            brdhist->brdhist[histid]->boardget(id1)->data[x1*3+i][y1*3+j]=dm;
            brdhist->brdhist[histid]->boardget(id2)->data[x2*3+i][y2*3+j]=dm;
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
    brdhist->paironlylst.push_back(pr);

    pr->brd1=brdhist->brdhist[histid]->boardget(id1);
    pr->brd2=brdhist->brdhist[histid]->boardget(id2);

    QPoint cl1;QPoint cl2;
    cl1.setX(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.width()*(x1+1)*3-20);
    cl1.setY(brdhist->curentbrdgroupget()->boardget(id1)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id1)->chipsize.height()*(y1+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id1)->clicklist.push_back(cl1);
    cl2.setX(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.x()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.width()*(x2+1)*3-20);
    cl2.setY(brdhist->curentbrdgroupget()->boardget(id2)->drawpos.y()+brdhist->curentbrdgroupget()->boardget(id2)->chipsize.height()*(y2+1)*3-20);
    brdhist->curentbrdgroupget()->boardget(id2)->clicklist.push_back(cl2);
    /*mainwin->info->selectAll();
    QString mhis=mainwin->info->textCursor().selectedText();
    mainwin->info->clear();
    QString mstr="'adso'("+QString::number(id1)+")["+QString::number(x1)+"]["+QString::number(y1)+"]\n";
           mstr+="'adso'("+QString::number(id2)+")["+QString::number(x2)+"]["+QString::number(y2)+"]\n";
    mainwin->info->insertPlainText(QString(mstr));
    mainwin->info->insertPlainText("-------------\n");
    mainwin->info->insertPlainText(mhis);
    mainwin->info->scroll(0,3);*/
    mainwin->update();
}

void consolemanageclass::linkmake(int id1,int x1,int y1,int id2,int x2,int y2)
{
    linkmake(brdhist->curenthistrycnt,id1,x1,y1,id2,x2,y2);
}
void consolemanageclass::linkonlymake(int id1,int x1,int y1,int id2,int x2,int y2)
{
    linkonlymake(brdhist->curenthistrycnt,id1,x1,y1,id2,x2,y2);
}
void consolemanageclass::reallinkmake(int id1,int id2)
{
    /**/
    id1=id1;id2=id2;
}
void consolemanageclass::realpartslinkmake(int id1,int x1,int y1,int id2,int x2,int y2)
{
    id1=id1;x1=x1;y1=y1;id2=id2;x2=x2;y2=y2;
}
void consolemanageclass::memoeditshow()
{

}
void consolemanageclass::mapaddh(int count)
{
    count=count;
    brdhist->boardhistoryadd();
    brdhist->curenthistrycnt++;

}
void consolemanageclass::curenthistorychange(int count)
{
    brdhist->curentindexset(count);
}
void consolemanageclass::curenthistorychangeadd(int count)
{
    brdhist->curentindexadd(count);
}
void consolemanageclass::solverfuncclassset(solverfuncclass *sol)
{
    solc=sol;
}
void consolemanageclass::stopthread()
{
    solc->mainloopthstop();
}
void consolemanageclass::cheatnumber(int index,int x,int y,int num)
{
    index=index;
    x=x;
    y=y;
    num=num;
}
void consolemanageclass::rootsearchclassset(rootsearchclass *mroot)
{
    root=mroot;
}
void consolemanageclass::updatethread()
{
    solc->mainloopthrestart();
}
void consolemanageclass::serchset1(int b)
{
    static bool flaga=true;
    brdhist->searchareanumberset(flaga,b);
    flaga=!flaga;
}
void consolemanageclass::serchset2()
{
    if(brdhist->arean[0].index==-1){return;}
    linkmake(brdhist->curenthistrycnt,brdhist->arean[0].index,brdhist->arean[0].x,brdhist->arean[0].y,brdhist->arean[1].index,brdhist->arean[1].x,brdhist->arean[1].y);
}
void consolemanageclass::ailinkmake(int cnt)
{
    root->sizeset();
    root->mapset();
    root->sort();
    //root->linkmake(cnt);
    root->linkmake2(0);
    root->linkmake22(cnt);
}
void consolemanageclass::ailinkmake4(int param)
{
    root->sizeset();
    root->mapset();
    root->sort();
    root->linkmake2(param);
    //root->rootcntchange();
}
void consolemanageclass::ailinkmake3(int cnt)
{
    root->linkmake22(cnt);
}
int consolemanageclass::ailinkmakecount()
{
    return root->linkcount;
}
void consolemanageclass::leafset(int index,int swi)
{
    brdhist->brdhist[0]->boardget(index)->leaf=swi;
}
void consolemanageclass::vecshow()
{
    brdhist->pvec=!brdhist->pvec;
    mainwin->update();
}
void consolemanageclass::linkrepair(int id1)
{
    int groupid=brdhist->pairlst[id1]->groupid;
    bool twice=brdhist->pairlst[id1]->twice;
    boardclass *brd1=brdhist->pairlst[id1]->brd1;
    boardclass *brd2=brdhist->pairlst[id1]->brd2;
    boardclass *brd3=brdhist->pairlst[id1]->brd3;
    boardclass *brd4=brdhist->pairlst[id1]->brd4;
    int x1=brdhist->pairlst[id1]->x1;
    int x2=brdhist->pairlst[id1]->x2;
    int x3=brdhist->pairlst[id1]->x3;
    int x4=brdhist->pairlst[id1]->x4;
    int y1=brdhist->pairlst[id1]->y1;
    int y2=brdhist->pairlst[id1]->y2;
    int y3=brdhist->pairlst[id1]->y3;
    int y4=brdhist->pairlst[id1]->y4;
    int id01=brdhist->pairlst[id1]->id1;
    int id2=brdhist->pairlst[id1]->id2;
    int id3=brdhist->pairlst[id1]->id3;
    int id4=brdhist->pairlst[id1]->id4;
    brdhist->pairlst[id1]->brd1=brd2;
    brdhist->pairlst[id1]->brd2=brd1;
    brdhist->pairlst[id1]->brd3=brd4;
    brdhist->pairlst[id1]->brd4=brd3;
    brdhist->pairlst[id1]->x1=x2;
    brdhist->pairlst[id1]->x2=x1;
    brdhist->pairlst[id1]->x3=x4;
    brdhist->pairlst[id1]->x4=x3;
    brdhist->pairlst[id1]->y1=y2;
    brdhist->pairlst[id1]->y2=y1;
    brdhist->pairlst[id1]->y3=y4;
    brdhist->pairlst[id1]->y4=y3;
    brdhist->pairlst[id1]->id1=id2;
    brdhist->pairlst[id1]->id2=id01;
    brdhist->pairlst[id1]->id3=id4;
    brdhist->pairlst[id1]->id4=id3;

    mainwin->update();
}

void consolemanageclass::linkchange(int id1,int id2)
{
    int groupid=brdhist->pairlst[id1]->groupid;
    bool twice=brdhist->pairlst[id1]->twice;
    boardclass *brd1=brdhist->pairlst[id1]->brd1;
    boardclass *brd2=brdhist->pairlst[id1]->brd2;
    boardclass *brd3=brdhist->pairlst[id1]->brd3;
    boardclass *brd4=brdhist->pairlst[id1]->brd4;
    int x1=brdhist->pairlst[id1]->x1;
    int x2=brdhist->pairlst[id1]->x2;
    int x3=brdhist->pairlst[id1]->x3;
    int x4=brdhist->pairlst[id1]->x4;
    int y1=brdhist->pairlst[id1]->y1;
    int y2=brdhist->pairlst[id1]->y2;
    int y3=brdhist->pairlst[id1]->y3;
    int y4=brdhist->pairlst[id1]->y4;
    int id01=brdhist->pairlst[id1]->id1;
    int id02=brdhist->pairlst[id1]->id2;
    int id3=brdhist->pairlst[id1]->id3;
    int id4=brdhist->pairlst[id1]->id4;
    brdhist->pairlst[id1]->groupid=brdhist->pairlst[id2]->groupid;
    brdhist->pairlst[id1]->twice=brdhist->pairlst[id2]->twice;
    brdhist->pairlst[id1]->brd1=brdhist->pairlst[id2]->brd1;
    brdhist->pairlst[id1]->brd2=brdhist->pairlst[id2]->brd2;
    brdhist->pairlst[id1]->brd3=brdhist->pairlst[id2]->brd3;
    brdhist->pairlst[id1]->brd4=brdhist->pairlst[id2]->brd4;
    brdhist->pairlst[id1]->x1=brdhist->pairlst[id2]->x1;
    brdhist->pairlst[id1]->x2=brdhist->pairlst[id2]->x2;
    brdhist->pairlst[id1]->x3=brdhist->pairlst[id2]->x3;
    brdhist->pairlst[id1]->x4=brdhist->pairlst[id2]->x4;
    brdhist->pairlst[id1]->y1=brdhist->pairlst[id2]->y1;
    brdhist->pairlst[id1]->y2=brdhist->pairlst[id2]->y2;
    brdhist->pairlst[id1]->y3=brdhist->pairlst[id2]->y3;
    brdhist->pairlst[id1]->y4=brdhist->pairlst[id2]->y4;
    brdhist->pairlst[id1]->id1=brdhist->pairlst[id2]->id1;
    brdhist->pairlst[id1]->id2=brdhist->pairlst[id2]->id2;
    brdhist->pairlst[id1]->id3=brdhist->pairlst[id2]->id3;
    brdhist->pairlst[id1]->id4=brdhist->pairlst[id2]->id4;
    brdhist->pairlst[id2]->groupid=groupid;
    brdhist->pairlst[id2]->twice=twice;
    brdhist->pairlst[id2]->brd1=brd1;
    brdhist->pairlst[id2]->brd2=brd2;
    brdhist->pairlst[id2]->brd3=brd3;
    brdhist->pairlst[id2]->brd4=brd4;
    brdhist->pairlst[id2]->x1=x1;
    brdhist->pairlst[id2]->x2=x2;
    brdhist->pairlst[id2]->x3=x3;
    brdhist->pairlst[id2]->x4=x4;
    brdhist->pairlst[id2]->y1=y1;
    brdhist->pairlst[id2]->y2=y2;
    brdhist->pairlst[id2]->y3=y3;
    brdhist->pairlst[id2]->y4=y4;
    brdhist->pairlst[id2]->id1=id01;
    brdhist->pairlst[id2]->id2=id02;
    brdhist->pairlst[id2]->id3=id3;
    brdhist->pairlst[id2]->id4=id4;

        mainwin->update();
}
void consolemanageclass::aiplay()
{
    mainwin->aiclassplay();
}
void consolemanageclass::manuallock(int index)
{
    mainwin->board->pairlst[index]->manulck=true;
}
void consolemanageclass::reloadset()
{
    mainwin->reload->setpairlist();
    mainwin->reload->replayinitial();
    mainwin->reload->loopplay(5);
    mainwin->reload->pushpairlist();
}
void  consolemanageclass::inputboxshow()
{
    mainwin->input->showx(mainwin->board);
}
void  consolemanageclass::inputboxhide()
{
    mainwin->input->hide();
}
void  consolemanageclass::inputboxtrans(int index)
{
    mainwin->input->trans(index);
}
void  consolemanageclass::mapminus()
{
    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        brdhist->brdhist[0]->brdgroup[i]->chipsize.setWidth(20);
        brdhist->brdhist[0]->brdgroup[i]->chipsize.setHeight(20);
        brdhist->brdhist[0]->brdgroup[i]->drawpos.setX(brdhist->brdhist[0]->brdgroup[i]->drawpos.x()*2/3.0);
        brdhist->brdhist[0]->brdgroup[i]->drawpos.setY(brdhist->brdhist[0]->brdgroup[i]->drawpos.y()*2/3.0);
    }
}
void consolemanageclass::mapplus()
{
    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        brdhist->brdhist[0]->brdgroup[i]->chipsize.setWidth(30);
        brdhist->brdhist[0]->brdgroup[i]->chipsize.setHeight(30);
        brdhist->brdhist[0]->brdgroup[i]->drawpos.setX(brdhist->brdhist[0]->brdgroup[i]->drawpos.x()*3/2.0);
        brdhist->brdhist[0]->brdgroup[i]->drawpos.setY(brdhist->brdhist[0]->brdgroup[i]->drawpos.y()*3/2.0);
    }
}

void consolemanageclass::randommake(int index)
{
    //mainwin->board->
}
void consolemanageclass::eraseset(int param)
{
        mainwin->erase->erasecoount=param;
        mainwin->erase->eraseexecute();
        QString mstr=mainwin->reload->fileName+".02.txt";
        DataSave((char *)mstr.toStdString().c_str());
        //ailinkmake(0);
        solc->mainloopth(1);
    //if(param==1){mainwin->erase->eraserestore();}
}
void consolemanageclass::swapnum(int num1,int num2)
{
    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        for(int x1=0;x1<9;x1++)
        {
            for(int y1=0;y1<9;y1++)
            {
                if(num1==brdhist->brdhist[0]->brdgroup[i]->dataget(x1,y1))
                {
                    brdhist->brdhist[0]->brdgroup[i]->dataset(x1,y1,'w');
                }
            }
        }
    }
    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        for(int x1=0;x1<9;x1++)
        {
            for(int y1=0;y1<9;y1++)
            {
                if(num2==brdhist->brdhist[0]->brdgroup[i]->dataget(x1,y1))
                {
                    brdhist->brdhist[0]->brdgroup[i]->dataset(x1,y1,'r');
                }
            }
        }
    }
    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        for(int x1=0;x1<9;x1++)
        {
            for(int y1=0;y1<9;y1++)
            {
                if('w'==brdhist->brdhist[0]->brdgroup[i]->dataget(x1,y1))
                {
                    brdhist->brdhist[0]->brdgroup[i]->dataset(x1,y1,num2);
                }
            }
        }
    }

    for(int i=0;i<brdhist->brdhist[0]->brdgroup.size();i++)
    {
        for(int x1=0;x1<9;x1++)
        {
            for(int y1=0;y1<9;y1++)
            {
                if('r'==brdhist->brdhist[0]->brdgroup[i]->dataget(x1,y1))
                {
                    brdhist->brdhist[0]->brdgroup[i]->dataset(x1,y1,num1);
                }
            }
        }
    }
}
