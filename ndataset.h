#ifndef ndataset_H
#define ndataset_H
#include<time.h>
#include<stdlib.h>
#include "SudokuPuzzle.h"
#include"boardclass.h"
class SudokuPuzzle;
class ndataset
{
public:

    struct POS
    {
        int x;
        int y;
        bool lock;
    };
    struct DATA
    {
        int num;
        int list[9];
        bool lock;
    };
    void dataset(DATA data[][9],int x,int y,int num);
    POS poslist[9];
    DATA data2[9][9];
    ndataset();
    int startpos;
    SudokuPuzzle *px;
    boardclass *bd;
    void poslistset();
    void posdataset(int ix,int iy,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9);
    bool isput(int x,int y,int num);
    bool datacreate();
    void datacreatea(int index);
    void datacreateb(int index);
    void datacreated(int index);
    void datacreated(int xx,int yy);
    void datacreatee(int xx,int yy);
    bool datacreatec();
};

#endif // ndataset_H
