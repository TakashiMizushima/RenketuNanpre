#ifndef MAINWINDOW_H23
#define MAINWINDOW_H23
#include "mainwindow.h"
#include <qmainwindow.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qstring.h>
#include <string>
#include <qpen.h>
#include <qpainter.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QMouseEvent>
#include <sstream>
#include<stdlib.h>
#include<time.h>
#include <QtGui>
#include <QtWidgets/QApplication>
#include<vector>
#include "selecterasechipclass.h"
class MainWindow;
class editerclass : public QMainWindow
{
public:
    editerclass();
    ~editerclass();
    struct DATA
    {
        int num;
        int list[9];
    };
    struct POS
    {
        int x;
        int y;
        int num;
        bool erase;
    };
private:
    std::vector<POS> undolist;
    int answermode;
    DATA data[9][9];
    DATA data2[9][9];
    DATA data3[9][9];
    DATA data4[9][9];
    QPoint clickPos;
    bool load;
    bool solv;
    bool solveclear;
    bool autook;
    int sx;
    int sy;
    int cx;
    int cy;
    int autonumcnt;
    int indexnum;
    MainWindow *parentp;
    selecterasechipclass erasechip;
    bool erasechipmode;
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void fileRead(char* filename);
    void cleardata();
    void listcheck(int x,int y,int num);
    void listcheck2(int x,int y,int num);
    bool isput(int x,int y,int num);
    QString to_qstring(const int value);
    void savedata();
    void updatedata();
    void resetdata();
    void randomdata();
    void undodata();
    void autodata();
    void showkuni();
    void loadautocnt();
    void printdata();
public:
    void pushdata(MainWindow *pp,int index,int list[][9]);
    void popdata();
};

#endif // MAINWINDOW_H
