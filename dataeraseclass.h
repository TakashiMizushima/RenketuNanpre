#ifndef DATAERASECLASS_H
#define DATAERASECLASS_H
#include"boardhistorycclass.h"
#include"mainwindow.h"
class MainWindow;
class dataeraseclass
{
public:
    boardhistorycclass *brdhist;
    int brdnum;
    int erasecoount;
    MainWindow *mainwin;
    void boardhistorycclassset(boardhistorycclass *mbrd);
    void mainwindwclassset(MainWindow *m);
    dataeraseclass();
    void eraseexecute();
    void eraserestore();
    void eraseboardchange(int index);
};

#endif // DATAERASECLASS_H
