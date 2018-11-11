#ifndef BOARDCLASS_H
#define BOARDCLASS_H
#include<QPoint>
#include<QSize>
#include<QPaintEvent>
#include<QPainter>
#include<vector>
#include<stdlib.h>
#include<time.h>
class boardclass
{
public:
    QPoint clickPos;
    QSize clickLen;
    QPoint drawpos;
    QPoint drawadjust;
    QSize chipsize;
    int index;
    int leaf;
public:
    struct CHIPDATA
    {
        int num;
        int xx;
        int yy;
        int index;
        bool lock;
    };
    struct ENABLE
    {
        bool mousepress;
        bool draw;
        bool circledraw;
    };
public:
    QPoint erasedpos;
    int erasednum;
    int erasecount;
    CHIPDATA ***data;
    CHIPDATA ***dataclone;
    ENABLE enable;
    std::vector<QPoint> clicklist;
    std::vector<QSize> sharelen;
    boardclass();
    ~boardclass();
    int curentsekinum;
    void indexset(int mid);
    void dataset(int x,int y,int num);
    int dataget(int x,int y);
    void dataseterase(int x,int y);
    void dataseteraserandom();
    void dataseteraserestore();
    void datacloneset(int x,int y,int num);
    int datacloneget(int x,int y);
    void datacloneing();
    void dataclonebacking();
    CHIPDATA *datagetelse(int x,int y);
    void clear();
public:
    void paintEvent(QPaintEvent *eve,QPainter *painter);
    void LinePaint(QPaintEvent *eve,QPainter *painter);
    void indexPaint(QPaintEvent *eve,QPainter *painter);
    void NumberPaint(QPaintEvent *eve,QPainter *painter);
    void CirclePaint(QPaintEvent *eve,QPainter *painter);
    bool mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool circlemousePressEvent(QMouseEvent *event);
    void circlemouseMoveEvent(QMouseEvent *event);
    void circlemouseReleaseEvent(QMouseEvent *event);
    bool mouseRangeIs(QPoint p);
    bool isput(int x,int y,int num);
    bool isput2(int x,int y,int num);
    bool isput3(int x,int y,int num);
    QPoint areanumberget(QPoint click);
    void makerandom();
};
#endif // BOARDCLASS_H
