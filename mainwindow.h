#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <thread>
#include"weditclass.h"
#include"dataeraseclass.h"
#include"boardhistorycclass.h"
#include"consolemanageclass.h"
#include"solverfuncclass.h"
#include "rootsearchclass.h"
#include "imagenumberclass.h"
#include "aiclass.h"
#include "reloadclassa.h"
#include "inputquestclass.h"
namespace Ui {
class MainWindow;
class WEdit;
class consolemanageclass;
class aiclass;
class reloadclass;
}
class aiclass;
class WEdit;
class reloadclass;
class consolemanageclass;
class inputquestclass;
class dataeraseclass;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    struct ENABLE
    {
        bool mousepress;
        bool drawis;
    };
    struct VIEW
    {
        QString process1;
        QString process2;
        QString process3;
        QString process4;
        QString process5;
        QString process6;
    };
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    Ui::MainWindow *ui;
    WEdit *wedit;
    inputquestclass *input;
public:
    aiclass *ai;
    imagenumberclass *image;
    ENABLE enable;
    VIEW view;
    WEdit *info;
    QString consolestring;
    dataeraseclass *erase;
    boardhistorycclass *board;
    boardhistorycclass *board2;
    consolemanageclass *console;
    solverfuncclass *solvclass;
    rootsearchclass *root;
    std::mutex m;
    int progressBarvalue;
    int progressBarvalue2;
    reloadclass *reload;
    void consolestringset(QString commandstr);
    void progressBarSet();
    void proceessstatusSet();
    void progressBarDraw(QPaintEvent *event,QPainter *painter);
    void aiclassplay();
protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void viewpaintEvent(QPaintEvent *event,QPainter *painter);
};

#endif // MAINWINDOW_H
