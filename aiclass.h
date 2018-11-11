#ifndef AICLASS_H
#define AICLASS_H
#include "mainwindow.h"
#include <QMainWindow>
#include <thread>
#include"weditclass.h"
#include"boardhistorycclass.h"
#include"consolemanageclass.h"
#include"solverfuncclass.h"
#include "rootsearchclass.h"
#include "imagenumberclass.h"
#include "inputquestclass.h"
class WEdit;
class consolemanageclass;
class aiclass
{
public:
    int aicnt;
    MainWindow *mainwin;
    std::thread *th;
    std::thread *thplay;
    QString fileName;
    bool playflag;
    int cnt;
    WEdit *twedt;
    bool badend;
    int bdcnt;
    int aipasscnt;
    int v1;
    int v2;
    int linkmakecount;
    int rootcntx;
    int rootcnty;
    int rootcntx2;
    int rootcnty2;
    int rootcntcontrol;
    int rootcntcontrol3;
    bool rootcntcontrolf;
    int paramr;
    int paramr2;
    int manualconnect;
    void rootcntchange();
    boardhistorycclass *tboard;
    consolemanageclass *tconsole;
    solverfuncclass *tsolvclass;
    rootsearchclass *troot;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstmanual;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstmanualonly;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstmanual2;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstmanualonly2;
    std::vector<boardhistorycclass *> kesu;
    std::vector<int> locklist;
    aiclass();
    ~aiclass();
    bool fmanulock;
    void initial(MainWindow *mmainwin);
    void replayinitial();
    void play();
    void loopmoniter(int param);
    void loopplay(int param);
    bool check();
};

#endif // AICLASS_H
