#ifndef RELOADCLASS_H
#define RELOADCLASS_H
#include "mainwindow.h"
#include <QMainWindow>
#include <thread>
#include"weditclass.h"
#include"boardhistorycclass.h"
#include"consolemanageclass.h"
#include"solverfuncclass.h"
#include "rootsearchclass.h"
#include "imagenumberclass.h"
#include "dataeraseclass.h"
class WEdit;
class consolemanageclass;
class dataeraseclass;
class reloadclass
{
public:
    int aicnt;
    MainWindow *mainwin;
    std::thread *th;
    std::thread *thplay;
    QString fileName;
    int cnt;
    WEdit *twedt;
    bool badend;
    int bdcnt;
    int aipasscnt;
    int v1;
    int v2;
    int linkmakecount;
    bool rootcntcontrolf;
    int paramr;
    int paramr2;
    int manualconnect;
    solverfuncclass *tsolvclass;
    rootsearchclass *troot;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstm;
    std::vector<boardhistorycclass::PAIRDATA *>pairlstmonly;
    reloadclass();
    ~reloadclass();
    void initial(MainWindow *mmainwin);
    void replayinitial();
    void setpairlist();
    void pushpairlist();
    void loopplay(int param);
};

#endif // AICLASS_H
