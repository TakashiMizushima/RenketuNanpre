#ifndef CONSOLEMANAGECLASS_H
#define CONSOLEMANAGECLASS_H
#include<QString>
#include<QObject>
#include<thread>
#include <mutex>
#include"consoleclass.h"
#include"mainwindow.h"
#include "editerclass.h"
#include "SudokuPuzzle.h"
#include"stonecreateclass.h"
#include"memoryclass.h"
#include "rootsearchclass.h"
#include "imagenumberclass.h"
#include<unistd.h>
#include<thread>
#include <QMessageBox>
#include <math.h>
class editerclass;
class MainWindow;
class stonecreateclass;
class solverfuncclass;
class boardhistorycclass;
class imagenumberclass;
class consolemanageclass : public consoleclass
{
public:
    solverfuncclass *solc;
    std::thread *th;
    std::mutex m;
    MainWindow *mainwin;
    boardhistorycclass *brdhist;
    boardhistorycclass *brdhistr;
    QSize komasize;
    QPoint clicksize;
    editerclass *areaediter;
    consolemanageclass();
    ~consolemanageclass();
    stonecreateclass stc;
    SudokuPuzzle pz;
    QSize chipsize;
    memoryclass memo;
    rootsearchclass *root;
    imagenumberclass *image;
    QString fileName;
    int thend;
    int ailinkmakecount();
    void ailinkmake3();
    void ailinkmake4(int param);
    void ailinkmake3(int cnt);
    void imagenumberclassset(imagenumberclass *im);
    void solverfuncclassset(solverfuncclass *sol);
    void rootsearchclassset(rootsearchclass *mroot);
    void MainWindowSet(MainWindow *main);
    void BoardManageSet(boardhistorycclass *mbrdmane,boardhistorycclass *mbrdmaner);
    void setboarddata(boardclass *brdl,int xx,int yy,stonecreateclass *nds);
    void DataLoad(char *filename);
    void DataLoadApend(char *filename);
    void DataSave(char *filename);
    void DataSave2(char *filename);
    void manualconnect();
    void mapup();
    void mapdn();
    void maplf();
    void maprt();
    void linkerase(int index);
    void ailinkmake(int cnt);
    void mapadd(int count);
    void mapaddr(int count);
    void mapaddh(int count);
    void mapaddrp(int id1,int x1,int y1,int id2,int x2,int y2);
    void filesave();
    void filesave2();
    void fileload();
    void fileloadapend();
    void mapdel(int index);
    void mapdelh();
    void mapfall(int index,std::vector<int> *mlist);
    void linkerase();
    void linktwicemake(int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4);
    void linktwicemake(int histcount,int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4);
    void linkmake(int id1,int x1,int y1,int id2,int x2,int y2);
    void linkdowblemake(int histcount,int id1,int x1,int y1,int id2,int x2,int y2);
    void linkdowblemake(int id1,int x1,int y1,int id2,int x2,int y2);
    void linkmake(int histcount,int id1,int x1,int y1,int id2,int x2,int y2);
    void linkonlymake(int id1,int x1,int y1,int id2,int x2,int y2);
    void linkonlymake(int histcount,int id1,int x1,int y1,int id2,int x2,int y2);
    void reallinkmake(int id1,int id2);
    void realpartslinkmake(int id1,int x1,int y1,int id2,int x2,int y2);
    void dataset(int id,int xx,int yy,std::vector<int> *list);
    void solver(int count);
    void solvercomplex(int count);
    void mapedit(int index);
    void dataerase();
    void dataprint(int index);
    void dataprintmap(int index);
    void circleput();
    void memoeditshow();
    void maprotate();
    void indexedit(int fromindex,int toindex);
    void makequestion();
    void curenthistorychange(int index);
    void curenthistorychangeadd(int index);
    void stopthread();
    void cheatnumber(int index,int x,int y,int num);
    void solveth3();
    void solveth4();
    void solveth5();
    void solveth6();
    void autosolve3(int param);
    void autosolve4(int param);
    void autosolve5(int param);
    void autosolve6(int param);
    void copyboard(std::vector<boardclass *> *data1,std::vector<boardclass *> *data2);
    void updatethread();
    void serchset1(int b);
    void serchset2();
    void leafset(int index,int swi);
    void vecshow();
    void linkrepair(int id1);
    void linkchange(int id1,int id2);
    void aiplay();
    void manuallock(int index);
    void reloadset();
    void inputboxshow();
    void inputboxhide();
    void inputboxtrans(int index);
    void mapminus();
    void mapplus();
    void randommake(int index);
    void eraseset(int param);
    void rotation();
    virtual void swapnum(int num1,int num2);

};
#endif // CONSOLEMANAGECLASS_H
