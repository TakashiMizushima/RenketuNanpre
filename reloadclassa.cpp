#include "reloadclassa.h"

reloadclass::reloadclass()
{
    bdcnt=0;
    linkmakecount=10000;
    aicnt=0;
    paramr=0;
    paramr2=0;
    v1=1;
    v2=0;
    aipasscnt=0;
    manualconnect=0;
}
reloadclass::~reloadclass()
{
}
void reloadclass::initial(MainWindow *mmainwin)
{
    mainwin=mmainwin;
    mainwin->wedit=new WEdit(mainwin);
    mainwin->wedit->setGeometry(1170,820,200,50);
    mainwin->wedit->setFocus();
    mainwin->console=new consolemanageclass;
    mainwin->board=new boardhistorycclass;
    mainwin->console->BoardManageSet(mainwin->board,mainwin->board);
    mainwin->console->MainWindowSet(mainwin);
    mainwin->board->clear();
    mainwin->board->boardhistoryadd();
    mainwin->solvclass=new solverfuncclass;
    mainwin->solvclass->mainwinclassset(mainwin);
    mainwin->solvclass->boardhistoryclassset(mainwin->board);
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
    mainwin->enable.mousepress=false;
    mainwin->erase=new dataeraseclass;
    mainwin->erase->boardhistorycclassset(mainwin->board);
    mainwin->erase->mainwindwclassset(mainwin);
}
void reloadclass::replayinitial()
{
    mainwin->board=new boardhistorycclass;
    mainwin->board->boardhistoryadd();
    mainwin->solvclass->init();
    mainwin->root->brd=mainwin->board;
    mainwin->console->brdhist=mainwin->board;
    mainwin->solvclass->brd=mainwin->board;
    mainwin->console->BoardManageSet(mainwin->board,mainwin->board);
    mainwin->console->MainWindowSet(mainwin);
    mainwin->solvclass->mainwinclassset(mainwin);
    mainwin->solvclass->boardhistoryclassset(mainwin->board);
    mainwin->console->solverfuncclassset(mainwin->solvclass);
    mainwin->progressBarvalue=0;
    mainwin->progressBarvalue2=0;
    mainwin->enable.mousepress=true;
    mainwin->root=new rootsearchclass;
    mainwin->root->boardhistorycclassset(mainwin->board);
    mainwin->console->rootsearchclassset(mainwin->root);
    mainwin->enable.mousepress=false;
    mainwin->erase->boardhistorycclassset(mainwin->board);
    mainwin->erase->mainwindwclassset(mainwin);
    //delete t;
    return;
}
void reloadclass::setpairlist()
{

    for(int i=0;i<mainwin->board->pairlst.size();i++)
    {
        boardhistorycclass::PAIRDATA *m=new boardhistorycclass::PAIRDATA;
        *m=*mainwin->board->pairlst[i];
        pairlstm.push_back(m);
    }
    for(int i=0;i<mainwin->board->paironlylst.size();i++)
    {
        boardhistorycclass::PAIRDATA *m=new boardhistorycclass::PAIRDATA;
        *m=*mainwin->board->paironlylst[i];
        pairlstmonly.push_back(m);
    }
}
void reloadclass::pushpairlist()
{
    mainwin->board->pairlst.clear();
    mainwin->board->paironlylst.clear();
    for(int i=0;i<pairlstm.size();i++)
    {
        boardhistorycclass::PAIRDATA *m=new boardhistorycclass::PAIRDATA;
        *m=*pairlstm[i];
        mainwin->board->pairlst.push_back(m);
    }
    for(int i=0;i<pairlstmonly.size();i++)
    {
        boardhistorycclass::PAIRDATA *m=new boardhistorycclass::PAIRDATA;
        *m=*pairlstmonly[i];
        mainwin->board->paironlylst.push_back(m);
    }
}
void reloadclass::loopplay(int param)
{
    if(fileName==""){mainwin->console->fileload();}
    else{mainwin->console->DataLoad((char *)fileName.toStdString().c_str());}
    if(fileName==""){fileName=mainwin->console->fileName;}
}
