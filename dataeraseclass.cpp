#include "dataeraseclass.h"

dataeraseclass::dataeraseclass()
{
    brdnum=0;
    erasecoount=40;
}
void dataeraseclass::boardhistorycclassset(boardhistorycclass *mbrd)
{
    brdhist=mbrd;
}
void dataeraseclass::mainwindwclassset(MainWindow *m)
{
    mainwin=m;
}
void dataeraseclass::eraseexecute()
{
    int brdnum=mainwin->board->brdhist[0]->brdgroup.size();
    for(int i=0;i<brdnum;i++)
    {
        while(mainwin->erase->brdhist->brdhist[0]->brdgroup[i]->erasecount!=erasecoount)
        {
            brdhist->brdhist[0]->brdgroup[i]->dataseteraserandom();
            mainwin->update();
        }
    }
}
void dataeraseclass::eraserestore()
{
    brdhist->brdhist[0]->brdgroup[brdnum]->dataseteraserandom();
    mainwin->update();
}
