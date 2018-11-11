#include "aiclass.h"

aiclass::aiclass()
{
    bdcnt=0;
    linkmakecount=10000;
    aicnt=0;
    rootcntx=0;
    rootcntcontrol=0;
    paramr=0;
    paramr2=0;
    v1=1;
    v2=0;
    aipasscnt=0;
    manualconnect=0;
}
aiclass::~aiclass()
{
    for(int i=0;i<kesu.size();i++)
    {
        delete kesu[i];
    }
    kesu.clear();
}
void aiclass::initial(MainWindow *mmainwin)
{
    mainwin=mmainwin;
    mainwin->console=new consolemanageclass;
    mainwin->board=new boardhistorycclass;
    mainwin->console->BoardManageSet(mainwin->board,mainwin->board);
    mainwin->console->MainWindowSet(mainwin);
    mainwin->board->clear();
    mainwin->board->boardhistoryadd();
    mainwin->solvclass=new solverfuncclass;
    mainwin->solvclass->mainwinclassset(mainwin);
    mainwin->solvclass->boardhistorycclassset(mainwin->board);
    mainwin->console->solverfuncclassset(mainwin->solvclass);
    mainwin->progressBarvalue=0;
    mainwin->progressBarvalue2=0;
    mainwin->enable.mousepress=true;
    mainwin->root=new rootsearchclass;
    mainwin->root->boardhistorycclassset(mainwin->board);
    mainwin->console->rootsearchclassset(mainwin->root);
    mainwin->root->brd=mainwin->board;
    mainwin->console->brdhist=mainwin->board;
    mainwin->solvclass->brd=mainwin->board;
    fileName="";
    manualconnect=0;
    fmanulock=false;
    mainwin->input=new inputquestclass;
    mainwin->input->setParent(mainwin);
    mainwin->input->hide();
    mainwin->input->mainwinclassset(mainwin);
}
void aiclass::replayinitial()
{
    //mainwin->board->clear();
    //mainwin->board->clear();
    //delete mainwin->board;
    //boardhistorycclass *t=mainwin->board;
    kesu.push_back(mainwin->board);
    mainwin->board=new boardhistorycclass;
    mainwin->board->boardhistoryadd();
    mainwin->solvclass->init();
    mainwin->root->brd=mainwin->board;
    mainwin->console->brdhist=mainwin->board;
    mainwin->solvclass->brd=mainwin->board;
    mainwin->console->BoardManageSet(mainwin->board,mainwin->board);
    mainwin->console->MainWindowSet(mainwin);
    mainwin->solvclass->mainwinclassset(mainwin);
    mainwin->solvclass->boardhistorycclassset(mainwin->board);
    mainwin->console->solverfuncclassset(mainwin->solvclass);
    mainwin->progressBarvalue=0;
    mainwin->progressBarvalue2=0;
    mainwin->enable.mousepress=true;
    mainwin->root=new rootsearchclass;
    mainwin->root->boardhistorycclassset(mainwin->board);
    mainwin->console->rootsearchclassset(mainwin->root);
    //delete t;
    manualconnect=0;
    fmanulock=false;
    mainwin->wedit->setFocus();
    return;
}
void aiclass::play()
{
    static int fm=0;

    if(manualconnect==1)
    {
        pairlstmanual.clear();
        pairlstmanualonly.clear();
        if(fmanulock==false)
        {
            for(int i=0;i<mainwin->board->pairlst.size();i++)
            {
                pairlstmanual.push_back(mainwin->board->pairlst[i]);
                pairlstmanual2.push_back(mainwin->board->pairlst[i]);
            }
            for(int i=0;i<mainwin->board->paironlylst.size();i++)
            {
                pairlstmanualonly.push_back(mainwin->board->paironlylst[i]);
                pairlstmanualonly2.push_back(mainwin->board->paironlylst[i]);
            }
            fmanulock=true;
        }
        else
        {
            for(int i=0;i<mainwin->board->pairlst.size();i++)
            {
                pairlstmanual.push_back(mainwin->board->pairlst[i]);
                pairlstmanual[i]->manulck=pairlstmanual2[i]->manulck;
                mainwin->board->pairlst[i]->manulck=pairlstmanual2[i]->manulck;
            }
            for(int i=0;i<mainwin->board->paironlylst.size();i++)
            {
                pairlstmanualonly.push_back(mainwin->board->paironlylst[i]);
                pairlstmanualonly[i]->manulck=pairlstmanualonly2[i]->manulck;
                mainwin->board->paironlylst[i]->manulck=pairlstmanualonly2[i]->manulck;
            }
        }
        fm++;
    }
    mainwin->solvclass->badend=false;
    th=new std::thread(&aiclass::loopmoniter,this,0 );
    loopplay(0);
}
void aiclass::loopmoniter(int param)
{
    while(1)
    {
        usleep(2000000);
        if(mainwin->solvclass->badend)
        {
            replayinitial();
            //usleep(2000000);
            loopplay(0);
            //usleep(2000000);
            mainwin->solvclass->badend=false;
            //mainwin->enable.drawis=true;
            aipasscnt++;
            mainwin->view.process6="aiclasspasscnt="+QString::number(aipasscnt);
        }
        if(mainwin->solvclass->goodend)
        {
            return;
        }
    }
}
void aiclass::loopplay(int param)
{
    if(mainwin->solvclass->badend){return;}
    mainwin->enable.mousepress=false;
    //mainwin->enable.drawis=false;
    int back=manualconnect;
    if(fileName==""){mainwin->console->fileload();}
    else{mainwin->console->DataLoad((char *)fileName.toStdString().c_str());}
    if(fileName==""){fileName=mainwin->console->fileName;}
    manualconnect=back;
    //mainwin->aiclassplay();
line1:
    paramr=0;
    mainwin->root->sizeset();
    mainwin->root->mapset();
    mainwin->root->sort();
    //root->linkmake(cnt);
    static int fm=0;
    if(manualconnect==0)
    {
        mainwin->root->linkmake2(paramr2);paramr2++;
        if(paramr2==mainwin->board->pairlst.size()){paramr2=0;}
        mainwin->root->linkmake22(paramr);
        fm++;
    }
    if(manualconnect==1)
    {
        mainwin->board->pairlst.clear();
        mainwin->board->paironlylst.clear();
        for(int i=0;i<pairlstmanual.size();i++)
        {
            mainwin->board->pairlst.push_back(pairlstmanual[i]);
        }
        for(int i=0;i<pairlstmanualonly.size();i++)
        {
            mainwin->board->paironlylst.push_back(pairlstmanualonly[i]);
        }
    }
    rootcntchange();
    mainwin->root->rootcntx=rootcntx;
    mainwin->root->rootcnty=rootcnty;
    mainwin->root->rootcntx2=rootcntx2;
    mainwin->root->rootcnty2=rootcnty2;
    //mainwin->root->dowbleerase();
    mainwin->root->linkmake3();
    //check();
    mainwin->console->solver(4);
    //mainwin->enable.drawis=true;
    mainwin->console->vecshow();
    if(paramr>=mainwin->board->pairlst.size()){paramr=0;}

    //mainwin->root->treecreate(0,1);//////////////
}
void aiclass::rootcntchange()
{
    if(rootcntcontrol==mainwin->board->pairlst.size()-1)
    {
        //paramr++;
        v1++;
        rootcntcontrol=0;
    }
    rootcntx=rootcntcontrol+v1;
    rootcnty=rootcntcontrol;
    rootcntcontrol++;
    if(rootcntx==mainwin->board->pairlst.size()-1)
    {
        //paramr++;
        v1=1;
    }
}
bool aiclass::check()
{

    for(int i=0;i<mainwin->board->pairlst.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(mainwin->board->pairlst[i]->id2==mainwin->board->pairlst[j]->id1 || mainwin->board->pairlst[i]->id1==mainwin->board->pairlst[j]->id2)
            {
                if(i<j)
                {
                    mainwin->board->linkrepair(j);
                }
                else
                {
                    mainwin->board->linkrepair(i);
                }
            }
        }
        for(int j=0;j<i;j++)
        {
            if(mainwin->board->pairlst[i]->id1==mainwin->board->pairlst[j]->id1 || mainwin->board->pairlst[i]->id2==mainwin->board->pairlst[j]->id2)
            {
                if(i<j)
                {
                    mainwin->board->linkrepair(j);
                }
                else
                {
                    mainwin->board->linkrepair(i);
                }

            }
        }
    }
    return true;
}
