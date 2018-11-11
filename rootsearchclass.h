#ifndef ROOTSEARCHCLASS_H
#define ROOTSEARCHCLASS_H
#include <math.h>
#include"boardhistorycclass.h"
class boardhistorycclass;
class rootsearchclass
{
public:
    struct ROOTSTRUCT
    {
        int a[2];
        int x[2];
        int y[2];
        int pi;
        int pj;
        bool twice1;
        bool twice2;
        int f;
        int leaf;
        bool pass;
    };
    int left;
    int right;
    int top;
    int bottom;
    ROOTSTRUCT **board;
    int cx;
    int cy;
    boardhistorycclass *brd;
    int rootcntx;
    int rootcnty;
    int rootcntx2;
    int rootcnty2;
    void boardtouch();
    rootsearchclass();
    void boardhistorycclassset(boardhistorycclass *mbrd);
    void sizeset();
    void mapset();
    void linkmake(int cnt);
    void linkmake2(int param);
    void linkmake22(int cnt);
    void linkmake3();
    void treecreate(int leftindex,int rightindex);
    void sort();
    void dowbleerase();
    int linkcount;
};

#endif // ROOTSEARCHCLASS_H
