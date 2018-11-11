#ifndef WEDITCLASS_H
#define WEDITCLASS_H
#include "mainwindow.h"
#include<vector>
#include<string>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QMouseEvent>
#include<QPlainTextEdit>
#include<QFileDialog>
#include<QColor>
#include <thread>
class MainWindow;
class WEdit : public QPlainTextEdit
{
    Q_OBJECT
public:
    MainWindow *pw;
    WEdit(MainWindow *mw);
    void keyPressEvent(QKeyEvent *event);
    QString mbuf;
};
#endif // WEDITCLASS_H
