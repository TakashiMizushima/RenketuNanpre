#ifndef SOLVERFUNCCLASS_H
#define SOLVERFUNCCLASS_H
#include"boardhistorycclass.h"
#include"mainwindow.h"
#include"numberloopclass.h"
#include"SudokuPuzzle.h"
#include"memoryclass.h"
#include <QThread>
#include <sys/shm.h>
#include<unistd.h>
#include"numberloopclass.h"
#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include "QSound"
#include<omp.h>
class MainWindow;
class solverfuncclass : public numberloopclass
{
public:
    MainWindow *mainwin;
    //boardhistorycclass *brd;
    std::thread *th;
    std::thread *th2;
    std::thread *tht;
    std::thread *th2t;
    SudokuPuzzle pz1;
    SudokuPuzzle pz2;
    memoryclass memo;
    bool loopdoneis1;
    bool loopdoneis2;
    bool badend;
    bool goodend;
    bool onekai;
    int cnt;
    int k;
    int brdcnt;
    int v;
    int stopflag;
    int bn;
    boardclass *brd1;
    boardclass *brd2;
    boardclass *brd3;
    boardclass *brd4;
    int solvecount;
    int selectloop;
    bool stopthread=false;
    int fcnt1=0;
    int param2;
    bool multianswer;
    boardgroupclass anscheck;
    solverfuncclass();
    void soundfile(int index);
    void init();
    void boardhistoryclassset(boardhistorycclass *mbrd);
    void mainwinclassset(MainWindow *mmainwin);
    void mainloop(int param);
    void mainloopth(int param);
    void numset(boardclass *brd,int *num);
    void numsettest(boardclass *brd,int *num);
    bool solver(boardclass *mbr1,boardclass *mbr2,bool lastis);
    bool solver2(boardclass *mbr1,boardclass *mbr2,bool lastis);
    bool solvertest1(boardclass *mbr1,boardclass *mbr2,bool lastis);
    bool solvertest2(boardclass *mbr1,boardclass *mbr2,bool lastis);
    bool solvertest3(boardclass *mbr1,boardclass *mbr2,bool lastis);
    bool allok(int histid);
    //int nextnum(int num,int *retlist);
    void numset(int *num,int r);
    void numset(int *num,int *num2,int r);
    void loopupdate(int param);
    void loopdone(boardclass *mbrd,int tow,int xx,int yy);
    void loopstart(boardclass *mbrd);
    void looping(boardclass *mbrd);
    void loopout();
    void mainloopthstop();
    void locknumber();
    void emerge();
    void mainloopthrestart();
    void anscheckset();
    bool anscheckis();
};
#endif // SOLVERFUNCCLASS_H
