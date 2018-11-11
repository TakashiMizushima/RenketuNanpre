#ifndef BOARDHISTORYCCLASS_H
#define BOARDHISTORYCCLASS_H
#include<vector>
#include"boardgroupclass.h"
#include"memoryclass.h"
#include<math.h>
class boardhistorycclass
{
public:
    int curenthistrycnt;
    struct PAIRDATA
    {
        int groupid;
        int x1;
        int y1;
        int id1;
        boardclass *brd1;
        int x2;
        int y2;
        int id2;
        boardclass *brd2;
        int x3;
        int y3;
        int id3;
        boardclass *brd3;
        int x4;
        int y4;
        int id4;
        boardclass *brd4;
        int numlist[9];
        bool twice;
        bool manulck;
    };
    struct areanumberis
    {
        int index;
        int x;
        int y;
    };
    std::vector<int> locklist;
    bool clearstate;
    areanumberis arean[2];
    memoryclass memo;
    int brdcntdefault;
    int brdcntdefaultonly;
    std::vector<PAIRDATA *>pairlst;
    std::vector<PAIRDATA *>paironlylst;
    std::vector<PAIRDATA *>pairlstmanual;
    std::vector<PAIRDATA *>pairlstmanualonly;
    std::vector<boardgroupclass *> brdhist;
    int circledraw;
    bool pvec;
    boardhistorycclass();
    void clear();
    void boardhistoryadd();
    void boardhistorysnapshot();
    void boardhistorylastdel();
    void paintEvent(QPaintEvent *eve,QPainter *painter);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    boardgroupclass *curentbrdgroupget();
    void curentindexset(int id);
    void curentindexadd(int id);
    void circledrawset(int enable);
    void linkmake(int histcount,int id1,int x1,int y1,int id2,int x2,int y2);
    void linktwicemake(int histid,int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4);
    void linkmakeprev(int histcount,int id1,int x1,int y1,int id2,int x2,int y2);
    void linkerase(int histid,int id1,int x1,int y1,int id2,int x2,int y2);
    void dumpfile(char *filename);
    void copytocurent();
    void copytocurentzero();
    bool isput(int index,int x,int y,int num);
    QPoint areanumberget(QPoint click,areanumberis *aream);
    void searchareanumberset(bool serachis,int pririty);
    bool searchareanumber;
    int searchareanumberpriority;
    void paintvec(QPaintEvent *eve,QPainter *painter);
    void linkrepair(int id1);
    void linkchange(int id1,int id2);


};
#endif // BOARDHISTORYCCLASS_H
