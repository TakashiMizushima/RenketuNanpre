#ifndef stonecreateclass_H
#define stonecreateclass_H
#include<time.h>
#include<stdlib.h>
#include "SudokuPuzzle.h"
#include"boardclass.h"
class SudokuPuzzle;
class stonecreateclass
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
    DATA data[9][9];
    stonecreateclass();
    ~stonecreateclass();
    int startpos;
    SudokuPuzzle *px;
    void posdataset(int ix,int iy,int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9);
    bool isput(int x,int y,int num);
    bool datacreate();
    void datacreated(int index);
    void datacreated(int xx,int yy);
    void datacreatee(int xx,int yy);
    bool datacreatec();
    void boardclassset(boardclass *bd);
    void boardclassget(boardclass *bd);
};

#endif // stonecreateclass_H
