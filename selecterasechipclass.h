#ifndef SELECTERASECHIPCLASS_H
#define SELECTERASECHIPCLASS_H
#include<vector>
#include <QMainWindow>
#include<QPainter>
class selecterasechipclass : public QMainWindow
{
    Q_OBJECT
public:
    struct DATA
    {
        int chip[3][3];
    };
    explicit selecterasechipclass(QWidget *parent = nullptr);
    std::vector<DATA> list;
signals:

public slots:
    void init();
    void dataset(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9);

    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *e);
};

#endif // SELECTERASECHIPCLASS_H
