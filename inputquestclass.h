#ifndef INPUTQUESTCLASS_H
#define INPUTQUESTCLASS_H
#include<QTextEdit>
#include"boardhistorycclass.h"
#include "mainwindow.h"
class inputquestclass : public QTextEdit
{
public:
    inputquestclass();
    int index;
    MainWindow *mainwin;
    boardhistorycclass *brd;

    void mainwinclassset(MainWindow *mmainwin);
    void showx(boardhistorycclass *mbrd);
    void trans(int mindex);
    void keyPressEvent(QKeyEvent *event);
};

#endif // INPUTQUESTCLASS_H
