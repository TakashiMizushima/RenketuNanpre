#ifndef NUMBERLOOPCLASS_H
#define NUMBERLOOPCLASS_H
#include <math.h>
#include"boardhistorycclass.h"
class numberloopclass
{
public:
    struct DATA
    {
        boardclass *brd;
        int index;
        int posx;
        int posy;
        int startnumber;
        int curentnumber;
        long long totalnumber;
        bool loopdoneis;
        int passcount;
        int list[9];
        int list2[9];
        int two;
        int xx;
        int yy;
        bool replay;
        std::vector<int> nummemry;
    };
    int sortn;
    std::vector<DATA> mobject;
    std::vector<DATA> mobject2;
    boardhistorycclass *brd;
    numberloopclass();
    ~numberloopclass();
    void boardhistorycclassset(boardhistorycclass *mbrd);
    void boardclassadd(boardclass *mbrd,int startnumber,int two,int xx,int yy);
    void boardclassset(boardclass *mbrd,int startnumber,int two,int xx,int yy);
    virtual void loopdone(boardclass *mbrd,int two,int xx,int yy)=0;
    virtual void loopstart(boardclass *mbrd)=0;
    virtual void looping(boardclass *mbrd)=0;
    virtual void loopout()=0;
    int nextnum(boardclass *mbrd,int two,int xx,int yy);
    int numprevset(boardclass *mbrd,int num);
    int prevnum(boardclass *mbrd);
    int *numlist(boardclass *mbrd,int num,int two,int xx,int yy);
    void listclear(boardclass *brd1,int two);
};
#endif // NUMBERLOOPCLASS_H
