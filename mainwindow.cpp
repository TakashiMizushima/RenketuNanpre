#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wedit=new WEdit(this);
    wedit->setParent(this);
    wedit->setGeometry(1170,820,200,50);
    wedit->setFocus();
    enable.drawis=true;
    reload=new reloadclass;
    reload->initial(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::consolestringset(QString commandstr)
{
    consolestring=commandstr;
    console->CommandStringSet(consolestring);
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    board->mousePressEvent(event);
    update();
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    if(board->brdhist.size()==0){return;}
    board->mouseMoveEvent(event);
    update();
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if(enable.mousepress==false){return;}
    board->mouseReleaseEvent(event);
    update();
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    if(enable.drawis==false){return;}
    m.lock();
    QPainter painter(this);
    board->paintEvent(event,&painter);
    viewpaintEvent(event,&painter);
    progressBarDraw(event,&painter);
    m.unlock();
}
void MainWindow::viewpaintEvent(QPaintEvent *event,QPainter *painter)
{//w.setGeometry(50,50,1200,800);
    event=event;
    painter->setFont(QFont("メイリオ",8));
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
    painter->drawText(920,800,400,30,true,view.process1);
    painter->drawText(920,760,400,30,true,view.process2);
    painter->drawText(1020,320,400,600,true,view.process3);
    painter->drawText(220,760,400,1000,true,view.process4);
    painter->drawText(920,780,400,30,true,view.process6);
}
void MainWindow::progressBarSet()
{
    progressBarvalue++;
    if(progressBarvalue==90000){progressBarvalue=0;progressBarvalue2++;}
}
void MainWindow::proceessstatusSet()
{
    static int cnt=0;
    if(cnt<=2000){view.process1="processing...";}
    else if(cnt<=4000){view.process1="processing......";}
    else if(cnt<=6000){view.process1="processing.........";}
    else if(cnt<=8000){view.process1="processing............";}
    else if(cnt<=10000){view.process1="processing...............";}
    if(cnt>=12000){cnt=0;}
    cnt++;
}
void MainWindow::progressBarDraw(QPaintEvent *event,QPainter *painter)
{
    event=event;
    QBrush blueBrush(QColor(183,186,162));
    painter->setBrush(blueBrush);
    painter->drawRect(920,877,progressBarvalue/200,15);
    painter->setFont(QFont("メイリオ",8));
    painter->setPen(QPen(Qt::blue, 1, Qt::SolidLine , Qt::RoundCap));
    painter->drawText(900,875,20,15,true, QString::number(progressBarvalue2));
}
void MainWindow::aiclassplay()
{
    ai->play();
}
