#ifndef BOARDGROUPCLASS_H
#define BOARDGROUPCLASS_H
#include<vector>
#include"boardclass.h"
class boardgroupclass
{
public:
    std::vector<boardclass *> brdgroup;
    int curentbrdnum;
    boardgroupclass();
    void boardclassadd();
    boardclass *curentboardget();
    boardclass *boardget(int index);
    void paintEvent(QPaintEvent *eve,QPainter *painter);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void curentboardindexset(int index);
    QPoint areanumberget(QPoint click,int *index,int *x,int *y,int cnt);
    void clear();
};
#endif // BOARDGROUPCLASS_H
