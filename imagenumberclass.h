#ifndef IMAGENUMBERCLASS_H
#define IMAGENUMBERCLASS_H
#include<QImage>
#include<QFileDialog>
#include"mainwindow.h"
class imagenumberclass
{
public:
    imagenumberclass();
    QImage paper;
    QImage numim[9];
    int numarr[81];
    int arrcnt;
    MainWindow *mainwin;
    void numimageload();
    void paperimageload();
    void matchnumber();
    void filesave();
    void MainWindowSet(MainWindow *mmain);
};

#endif // IMAGENUMBERCLASS_H
