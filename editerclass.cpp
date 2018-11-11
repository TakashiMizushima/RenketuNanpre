#include "editerclass.h"
extern int maincreate(int answer[][9]);
extern bool solvedata(int data[][9]);
#include<string>
#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>
#include <stdio.h>
#include "SudokuPuzzle.h"
#include <iostream>
#include <fstream>
#include <wchar.h>
#define HINTNUM 18
char *itoa( int val, char *a, int radix )
{
    char *p = a;
    unsigned int v = val;/* 作業用(変換対象の値) */
    int n = 1;/* 変換文字列の桁数記憶用 */
    while(v >= (unsigned int)radix){/* 桁数を求める */
        v /= radix;
        n++;
    }
    p = a + n; /* 最下位の位置から設定する */
    v = val;
    *p = '\0';/* 文字列終端の設定 */
    do {
        --p;
        *p = v % radix + '0';/* 1桁の数値を文字に変換 */
        if(*p > '9') {/* 変換した文字が10進で表現できない場合 */
            *p = v % radix - 10 + 'A'; /* アルファベットを使う */
        }
        v /= radix;
    } while ( p != a);
    return a;
}

editerclass::editerclass()
{
    load=false;
    cleardata();
    sx=90;sy=90;
    cx=90;cy=90;
    answermode=0;
    solv=false;
    solveclear=false;
    autook=false;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=0;
            data2[i][j].num=0;
            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=1;
                data2[i][j].list[k]=1;
            }
        }

    }
    erasechip.setGeometry(500,500,700,700);
    erasechip.init();
    erasechipmode=false;
    //erasechip.show();
}

editerclass::~editerclass()
{
}
void  editerclass::loadautocnt()
{
    FILE *f=fopen("NanpreGui-conf.txt","r");
    fscanf(f,"%d",&autonumcnt);
    //autonumcnt--;
    fclose(f);
}
void editerclass::paintEvent(QPaintEvent *)//描画イベント
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);//アンチエイリアスセット
    painter.setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
    painter.setBrush(QBrush(Qt::white, Qt::SolidPattern));
    int lx=clickPos.x()/cx;
    int ly=clickPos.y()/cy;
    if(clickPos.x()!=0 && clickPos.y()!=0 && 1<= lx && lx<=9 && 1<= ly && ly<=9)
    {
        painter.drawRect((clickPos.x()/cx)*cx, (clickPos.y()/cy)*cy, cx,cy);
    }
    painter.drawRect(cx*11, cy*9, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*8.3, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*7.6, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*6.9, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*6.2, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*5.5, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*4.8, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*4.1, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*3.4, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*2.7, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*2.0, cx*2,cy*0.7);
    painter.drawRect(cx*11, cy*1.3, cx*2,cy*0.7);
    painter.drawText(cx*11+30, cy*9+10, cx*3,cy,true,QString("Load"));
    painter.drawText(cx*11+30, cy*8.3+10, cx*3,cy,true,QString("Save"));
    painter.drawText(cx*11+30, cy*7.6+10, cx*3,cy,true,QString("AnserSwitch"));
    painter.drawText(cx*11+30, cy*6.9+10, cx*3,cy,true,QString("Reset"));
    painter.drawText(cx*11+30, cy*6.2+10, cx*3,cy,true,QString("Random"));
    painter.drawText(cx*11+30, cy*5.5+10, cx*3,cy,true,QString("Undo"));
    painter.drawText(cx*11+30, cy*4.8+10, cx*3,cy,true,QString("Solve"));
    painter.drawText(cx*11+30, cy*4.1+10, cx*3,cy,true,QString("Auto"));
    painter.drawText(cx*11+30, cy*3.4+10, cx*3,cy,true,QString("Print"));
    painter.drawText(cx*11+30, cy*2.7+10, cx*3,cy,true,QString("Close"));
    painter.drawText(cx*11+30, cy*2.0+10, cx*3,cy,true,QString("Cancel"));
    painter.drawText(cx*11+30, cy*1.3+10, cx*3,cy,true,QString("EraseChip"));
    if(solveclear==true){painter.drawText(cx*11+30, cy*2.7+10, cx*3,cy,true,QString("Clear"));}
    if(autook==true){painter.drawText(cx*11+30, cy*2.7+10+20, cx*3,cy,true,QString("Autoclear"));}
    for(int i=0;i<10;i++)
    {
        painter.drawLine(sx+i*cx,sy,sx+i*cx,sy+cy*9);
        painter.drawLine(sx,sy+i*cy,sx+cx*9,sy+i*cy);
        if(i%3==0)
        {
            painter.drawLine(sx+i*cx+2,sy,sx+i*cx+2,sy+cy*9);
            painter.drawLine(sx,sy+i*cy+2,sx+cx*9,sy+i*cy+2);
        }
    }
//    if(load==false){return;}
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(data[i][j].num!=0 && (answermode==0 || answermode==2))
            {
                painter.setFont(QFont("メイリオ",45));
                if(solv==true  && data3[i][j].num!=data[i][j].num){painter.setPen(QPen(Qt::blue, 1, Qt::SolidLine , Qt::RoundCap));}
                painter.drawText(sx+i*cx+10+3+15,sy+j*cy+5,cx,cy,true,QString(to_qstring(data[i][j].num)));
                painter.setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
            }
            else if(answermode==1)
            {
                painter.setFont(QFont("メイリオ",45));
                painter.drawText(sx+i*cx+10+3+15,sy+j*cy+5,cx,cy,true,QString(to_qstring(data2[i][j].num)));
            }
            else
            {
                painter.setFont(QFont("メイリオ",19));
                for(int k=0;k<9;k++)
                {
                    if(data[i][j].list[k]==1 && isput(i,j,k+1)==true  && (answermode==0 || answermode==2) && k+1!= data2[i][j].num)
                    {
                        painter.drawText(sx+i*cx+5+(k%3)*28,sy+j*cy+5+(k/3)*27,28,28,true,QString(to_qstring(k+1)));
                    }
                    if(data[i][j].list[k]==1 && isput(i,j,k+1)==true  && (answermode==0 || answermode==2) && k+1== data2[i][j].num)
                    {
                        if(answermode==0){painter.setPen(QPen(Qt::red, 1, Qt::SolidLine , Qt::RoundCap));}
                        if(answermode==2){painter.setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));}
                        painter.drawText(sx+i*cx+5+(k%3)*28,sy+j*cy+5+(k/3)*27,28,28,true,QString(to_qstring(k+1)));
                        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine , Qt::RoundCap));
                    }
                }
            }

        }
    }
}
QString editerclass::to_qstring(const int value)
{
  std::stringstream ss;
  ss << value;

  return QString::fromStdString(ss.str());
}
void editerclass::cleardata()
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=0;
            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=1;
            }
        }
    }
}
void editerclass::listcheck(int x,int y,int num)
{
        bool f1=false;
         if(num!=0){f1=true;}
         for(int k=0;k<9;k++)
         {
             if(data[x][y].list[k]==num ){f1=true;}
         }
         if(f1==false){return;}
    data[x][y].list[num-1]=0;
    for(int i=0;i<9;i++)
    {
            data[i][y].list[num-1]=0;
            data[x][i].list[num-1]=0;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            data[(x/3)*3+i][(y/3)*3+j].list[num-1]=0;
        }
    }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(x!=i && y!= j && data[i][j].num!=0)
            {
                //listcheck2(i,j,data[i][j].num);
            }
        }
    }
    //updatedata();
}
bool editerclass::isput(int x,int y,int num)
{
    num=num;
    for(int i=0;i<9;i++)
    {
        if(data[x][y].num==data[i][y].num && x!=i && data[i][y].num!=0)
        {
            return false;
        }
        if(data[x][y].num==data[x][i].num && y!=i && data[x][i].num!=0)
        {
            return false;
        }

    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(data[x][y].num==data[(x/3)*3+i][(y/3)*3+j].num && x!=(x/3)*3+i && y!=(y/3)*3+j && data[(x/3)*3+i][(y/3)*3+j].num!=0)
            {
                return false;
            }

        }
    }
    return true;
}
void editerclass::listcheck2(int x,int y,int num)
{    bool f1=false;
     if(num!=0){f1=true;}
     for(int k=0;k<9;k++)
     {
         if(data[x][y].list[k]==num ){f1=true;}
     }
     if(f1==false){return;}
    data[x][y].list[data[x][y].num-1]=1;
    for(int i=0;i<9;i++)
    {
        bool flag=true;
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                if(data[(i/3)*3+m][(y/3)*3+n].num==num){flag=false;}
            }
        }
            if(flag==true){data[i][y].list[data[x][y].num-1]=1;}
     }
    for(int i=0;i<9;i++)
    {
        bool flag=true;
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                if(data[(x/3)*3+m][(i/3)*3+n].num==num){flag=false;}
            }
        }
            if(flag==true){data[x][i].list[data[x][y].num-1]=1;}

    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            data[(x/3)*3+i][(y/3)*3+j].list[data[x][y].num-1]=1;
        }
    }
    data[x][y].num=0;
    //updatedata();
}
void editerclass::mousePressEvent(QMouseEvent *e)
{
    clickPos=e->pos();

    int lx=clickPos.x()/cx;
    int ly=clickPos.y()/cy;
    int tx=(clickPos.x()-sx)/cx;
    int ty=(clickPos.y()-sy)/cy;

    int cx2=cx/3;int cy2=cy/3;
    int tx2=(clickPos.x()-sx)/cx2;
    int ty2=(clickPos.y()-sy)/cy2;
    solveclear=false;
    update();
    if(erasechipmode==true)
    {
        return;
    }
    if(clickPos.x()!=0 && clickPos.y()!=0 && 1<= lx && lx<=9 && 1<= ly && ly<=9)
    {
        if(answermode==0 || answermode==2)
        {

        //sx+i*cx+10+3,sy+j*cy+5,cx,cy
        if(data[tx][ty].num==0){
            data[tx][ty].num=(tx2%3)+(ty2%3)*3+1;
            POS x;
            x.x=tx;x.y=ty;x.num=(tx2%3)+(ty2%3)*3+1;
            x.erase=false;
            undolist.push_back(x);
            listcheck(tx,ty,(tx2%3)+(ty2%3)*3+1);}//+(ty2%9);}
        else
        {
            POS x;
            x.x=tx;x.y=ty;x.num=(tx2%3)+(ty2%3)*3+1;
            x.erase=true;
            undolist.push_back(x);
            listcheck2(tx,ty,(tx2%3)+(ty2%3)*3+1);
        }//+(ty2%9);}
        updatedata();
        }

    }
    if(cx*11+30<clickPos.x() && cy*9+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*9+10+cy*0.7)
    {
        solv=false;
        this->fileRead((char *)"data.txt");
    }
    if(cx*11+30<clickPos.x() && cy*8.3+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*8.3+10+cy*0.7)
    {
        solv=false;
        this->savedata();
    }
    if(cx*11+30<clickPos.x() && cy*7.6+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*7.6+10+cy*0.7)
    {
        answermode++;
        if(answermode==3){answermode=0;}
    }
    if(cx*11+30<clickPos.x() && cy*6.9+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*6.9+10+cy*0.7)
    {
        solv=false;
        this->resetdata();
    }
    if(cx*11+30<clickPos.x() && cy*6.2+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*6.2+10+cy*0.7)
    {
        solv=false;
        this->randomdata();
    }
    if(cx*11+30<clickPos.x() && cy*5.5+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*5.5+10+cy*0.7)
    {
        solv=false;
        this->undodata();
    }
    if(cx*11+30<clickPos.x() && cy*4.8+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*4.8+10+cy*0.7)
    {
        if(solv==true){solv=false;update();return;}
        /////////////////////////////////////////////////////////////////////////
        ///
        int datax[9][9];
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
              datax[i][j]=data[i][j].num;
            }
        }
        solvedata(datax);
        /////////////////////////////////////////////////////////////////////////
        solv=false;
    }
    if(cx*11+30<clickPos.x() && cy*4.1+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*4.1+10+cy*0.7)
    {
        solv=false;
        this->autodata();
    }
    if(cx*11+30<clickPos.x() && cy*3.4+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*3.4+10+cy*0.7)
    {
        solv=false;
        this->printdata();
    }
    if(cx*11+30<clickPos.x() && cy*2.7+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*2.7+10+cy*0.7)
    {
        solv=false;
        popdata();
        parentp->update();
        this->close();
    }
    if(cx*11+30<clickPos.x() && cy*2.0+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*2.1+10+cy*0.7)
    {
        return;
        solv=false;
        this->close();
    }
    if(cx*11+30<clickPos.x() && cy*1.3+10<clickPos.y() && clickPos.x()<cx*11+30+cx*3 &&clickPos.y()< cy*2.1+10+cy*0.7)
    {
        erasechipmode=true;
        erasechip.show();
        return;
    }

    update();
}
void editerclass::printdata()
{
    std::string str;
    str+="%!\n";
    str+="gsave\n";
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38+2,120+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38+2,120+(j+1)*38);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38,120+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38,120+(j+1)*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+j*38,120+i*38+2);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,120+i*38+2);
                str+=tstr;
            }
            if(j!=9)
            {
                char tstr[250];
                sprintf(tstr,"%d %d moveto\n",140+j*38,120+i*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,120+i*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[380];
            if(i%3==0 && j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38+2,470+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38+2,470+(j+1)*38);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+i*38,470+j*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+i*38,470+(j+1)*38);
                str+=tstr;
            }
        }
        for(int j=0;j<10;j++)
        {
            char tstr[250];
            if(i%3==0 && j!=9)
            {/**/
                sprintf(tstr,"%d %d moveto\n",140+j*38,470+i*38+2);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,470+i*38+2);
                str+=tstr;
            }
            if(j!=9)
            {
                sprintf(tstr,"%d %d moveto\n",140+j*38,470+i*38);
                str+=tstr;
                sprintf(tstr,"%d %d lineto\n",140+(j+1)*38,470+i*38);
                str+=tstr;
            }
        }
    }

    str+="gsave\n";
    char tstr[250];
    //sprintf(tstr,"Ryumin-Light-UniJIS-UTF8-H findfont 12 scalefont setfont");
    sprintf(tstr,"/Courier     findfont [ 20 0 0 20 0 0 ] makefont setfont\n");
    str+=tstr;
    ///////////////
    for(int j=0;j<9;j++)
    {
    for(int i=0;i<9;i++)
    {
            sprintf(tstr,"%d %d moveto\n",140+10+j*38,120+10+i*38);
            str+=tstr;
            sprintf(tstr,"(%d) show\n",data2[j][8-i].num);
            str+=tstr;

            if(data[j][8-i].num!=0)
            {
                sprintf(tstr,"%d %d moveto\n",140+10+j*38,470+10+i*38);
                str+=tstr;
                sprintf(tstr,"(%d) show\n",data[j][8-i].num);
                str+=tstr;
            }

        }
    }

    //sprintf(tstr,"Ryumin-Light-UniJIS-UTF8-H findfont 12 scalefont setfont");
    //str+=tstr;
    sprintf(tstr,"%d %d moveto\n",0,0);
    str+=tstr;
    str+="stroke\n";
    //////////////
    int tc=0;
    FILE *f2=fopen("NanpreGui-conf.txt","r");
    fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);fscanf(f2,"%d",&tc);
    fclose(f2);
    sprintf(tstr,"%d %d moveto\n",0,0);
    str+=tstr;
    str+="showpage\n";
    str+="grestore\n";
    FILE *f=fopen("print.ps","w");
    fprintf(f,str.c_str());
    fclose(f);
    if(tc==1)
    {
        system("cat address.ps >print2.ps");
        system("cat print.ps >> print2.ps");
        system("cat print2.ps | lpr -P Epson-PX-M5041F");
    }
    else
    {
        system("cat print.ps | lpr -P Epson-PX-M5041F");
    }

}
int gf=0;
void editerclass::autodata()
{
    loadautocnt();
    int index1[9];
    int index2[9];
    char exclude[9][9];
    char exclude2[9][9];

    FILE *f=fopen("exclude.txt","r");
    for(int i=0;i<9;i++)
    {
        fscanf(f,"%c%c%c%c%c%c%c%c%c\n",&exclude[0][i],&exclude[1][i],&exclude[2][i],&exclude[3][i],&exclude[4][i],&exclude[5][i],&exclude[6][i],&exclude[7][i],&exclude[8][i]);
        for(int j=0;j<9;j++)
        {exclude[j][i]-='0';exclude2[j][i]-='0';}
    }
    fclose(f);

    bool excludeflag=false;
    f=fopen("NanpreGui-conf.txt","r");
    int tc=0;
    fscanf(f,"%d",&tc);
    fscanf(f,"%d",&tc);
    if(tc==1){excludeflag=true;}
    fclose(f);

    for(int i=0;i<9;i++)
    {
        index1[i]=i;
        index2[i]=i;
    }
    for(int m=0;m<200;m++)
    {
        srand((gf++)+time(NULL));
        int x1=rand()%9;
        int x2=rand()%9;
        int y1=rand()%9;
        int y2=rand()%9;
        int t1=index1[x1];
        int t2=index2[x2];
        index1[x1]=index1[y1];
        index2[x2]=index2[y2];
        index1[y1]=t1;
        index2[y2]=t2;
    }
    cleardata();
    line2:
    randomdata();
    int limits=0;
    autook=false;

    update();
    int cnt2=0;
    line3:
    while(cnt2<81-autonumcnt && limits<3000)
    {
    for(int m=0;m<9;m++)
    {
        int cnt1=0;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(i!=10 && excludeflag==true && exclude[index1[i]][index2[j]]==1)
                {

                }
                if(i!=10 && excludeflag==true && (exclude[index1[i]][index2[j]]==0 || exclude[index1[i]][index2[j]]==2))
                {
                    //solveclear==false;
                    if(i!=10 && exclude[index1[i]][index2[j]]==0){
                        if(data[index1[i]][index2[j]].num==m+1)
                        {
                            data[index1[i]][index2[j]].num=0;

                        cnt1++;
                        cnt2++;

                        if(solveclear==false)
                        {
                            data[index1[i]][index2[j]].num=m+1;
                            cnt1--;
                            cnt2--;
                        }
                        else if(solveclear==true)
                        {
                            for(int k=0;k<9;k++){data[index1[i]][index2[j]].list[k]=1;}
                        }
                        if(cnt2==81-autonumcnt){goto line3;}
                        if(cnt1==7){i=10;j=10;}
                        }
                    }
                    if(i!=10 && exclude[index1[i]][index2[j]]==2){
                        if(data[index1[i]][index2[j]].num==m+1)
                        {
                            data[index1[i]][index2[j]].num=0;

                        cnt1++;
                        cnt2++;

                        for(int k=0;k<9;k++){data[index1[i]][index2[j]].list[k]=1;}

                        if(cnt2==81-autonumcnt){goto line3;}
                        if(cnt1==7){i=10;j=10;}
                        //exclude[index1[i]][index2[j]]=1;
                        }
                    }


                }
                if(excludeflag==false)
                {
                    if(data[index1[i]][index2[j]].num==m+1)
                    {
                        data[index1[i]][index2[j]].num=0;

                    cnt1++;
                    cnt2++;

                    if(solveclear==false)
                    {
                        data[index1[i]][index2[j]].num=m+1;
                        cnt1--;
                        cnt2--;
                    }
                    else
                    {
                        for(int k=0;k<9;k++){data[index1[i]][index2[j]].list[k]=1;}
                    }
                    if(cnt2==81-autonumcnt){goto line3;}
                    if(cnt1==7){i=10;j=10;}
                }
                }
                limits++;

                //update();

            }
        }
    }
    //update();
    }
    if(limits>=3000){goto line2;}
    autook=true;
}


void editerclass::undodata()
{
    if(undolist.size()==0){return;}
    //cleardata();
    for(int i=0;i<9;i++){for(int j=0;j<9;j++){data[i][j].num=data2[i][j].num;for(int k=0;k<9;k++){data[i][j].list[k]=data2[i][j].list[k];}}}
    for(int i=0;i<(signed int)undolist.size();i++)
    {
        if(undolist[i].erase==false)
        {
            data[undolist[i].x][undolist[i].y].num=undolist[i].num;
            for(int k=0;k<9;k++){data[undolist[i].x][undolist[i].y].list[k]=0;}
        }
        else
        {
            data[undolist[i].x][undolist[i].y].num=0;
            for(int k=0;k<9;k++){data[undolist[i].x][undolist[i].y].list[k]=1;}
        }

    }
    undolist.erase(undolist.end()-1);
    updatedata();
    update();
}
void editerclass::updatedata()
{
    //return;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            /*
            for(int m=0;m<9;m++)
            {
                for(int k=0;k<9;k++)
                {
                    if(data[i][j].num==k+1 && data[i][m].list[k]==1 && j/3!=m/3)
                    {
                        data[i][m].list[k]=0;
                    }
                    if(data[i][j].num==k+1 && data[m][j].list[k]==1 && i/3!=m/3)
                    {
                        data[m][j].list[k]=0;
                    }
                    if(data[i][j].num==k+1 && data[(i/3)*3+m/3][(j/3)*3+m%3].list[k]==1 && ((i/3)*3+m/3)/3!=i/3 && ((j/3)*3+m%3)/3!=j/3)
                    {
                        data[(i/3)*3+m/3][(j/3)*3+m%3].list[k]=0;
                    }
                }
            }*/
            if(data[i][j].num!=0){ listcheck(i,j,data[i][j].num);}
        }
    }
    update();
}
void  editerclass::fileRead(char* filename)
{
    filename=filename;
    QString selFilter = tr("テキスト(*.txt)");
    QString fileName2 = QFileDialog::getOpenFileName(this,tr("ファイルを開く"), "/home/tak/ドキュメント",tr("すべて(*.*);;テキスト(*.txt);;ソース(*.h *.cpp)"),&selFilter,QFileDialog::DontUseCustomDirectoryIcons);
    if (fileName2.isEmpty()) {
        // キャンセル
        return;
    }

    FILE *f=fopen(fileName2.toStdString().c_str(),"r");

    if( f == NULL ){
      return;
    }
    for(int i=0;i<9;i++){
    fscanf(f,"%c%c%c%c%c%c%c%c%c\n",(char *)&data[0][i].num,(char *)&data[1][i].num,(char *)&data[2][i].num,(char *)&data[3][i].num,(char *)&data[4][i].num,(char *)&data[5][i].num,(char *)&data[6][i].num,(char *)&data[7][i].num,(char *)&data[8][i].num);
    data[0][i].num-='0';data[1][i].num-='0';data[2][i].num-='0';data[3][i].num-='0';data[4][i].num-='0';data[5][i].num-='0';data[6][i].num-='0';data[7][i].num-='0';data[8][i].num-='0';
    }
    char line[256];
    fscanf(f,"%s\n",line);
////

    for(int i=0;i<9;i++){
        fscanf(f,"%c%c%c%c%c%c%c%c%c\n",(char *)&data2[0][i].num,(char *)&data2[1][i].num,(char *)&data2[2][i].num,(char *)&data2[3][i].num,(char *)&data2[4][i].num,(char *)&data2[5][i].num,(char *)&data2[6][i].num,(char *)&data2[7][i].num,(char *)&data2[8][i].num);
        data2[0][i].num-='0';data2[1][i].num-='0';data2[2][i].num-='0';data2[3][i].num-='0';data2[4][i].num-='0';data2[5][i].num-='0';data2[6][i].num-='0';data2[7][i].num-='0';data2[8][i].num-='0';
        }
    ///
    for(int i=0;i<9;i++){for(int j=0;j<9;j++){for(int k=0;k<9;k++){data2[i][j].list[k]=0;}}}
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                if(data[i][j].num==0 && isput(i,j,k+1)==true)
                {
                    data[i][j].list[k]=1;
                }
            }
        }
     }
    fclose(f);
    load=true;
    update();
}
void  editerclass::savedata()
{
    QString selFilter = tr("テキスト(*.txt)");
    QString fileName2 = QFileDialog::getSaveFileName(this,tr("ファイルを保存"), "/home/tak/ドキュメント",tr("すべて(*.*);;テキスト(*.txt)"),&selFilter,QFileDialog::DontUseCustomDirectoryIcons);
    if (fileName2.isEmpty()) {
        // キャンセル
        return;
    }
    FILE *f=fopen(fileName2.toStdString().c_str(),"w");
    for(int j=0;j<9;j++)
    {
    for(int i=0;i<9;i++)
    {
            fprintf(f,"%d",data[i][j].num);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"-----------------------------\n");

    for(int j=0;j<9;j++)
    {
    for(int i=0;i<9;i++)
    {
            fprintf(f,"%d",data2[i][j].num);
        }
        fprintf(f,"\n");
    }
    fprintf(f,"-----------------------------\n");
    fclose(f);
    f=fopen("data.htm","w");
    fprintf(f,"<html><body>");
    fprintf(f,"<table  border=1 style='font-size : 20px;'>");
    for(int j=0;j<9;j++)
    {
        fprintf(f,"<tr>");
        for(int i=0;i<9;i++)
        {
            if(data[i][j].num!=0)
            {
                fprintf(f,"<td style='border=3;border-style=dashed;padding-left:12px;padding-right:12px;padding-top:8px;padding-bottom:8px;'> %d </td>",data[i][j].num);
            }
            else
            {
                fprintf(f,"<td style='color:white;border-style=dashed;padding-left:12px;padding-right:12px;padding-top:8px;padding-bottom:8px;'> %s </td>","&nbsp;");
            }
        }
        fprintf(f,"</tr>");
    }
    fprintf(f,"</table><br><br>");
    fprintf(f,"<table  border=1 style='font-size : 20px;'>");
    for(int j=0;j<9;j++)
    {
        fprintf(f,"<tr>");
        for(int i=0;i<9;i++)
        {
            fprintf(f,"<td style='border-style=dashed;padding-left:12px;padding-right:12px;padding-top:8px;padding-bottom:8px;'> %d </td>",data2[i][j].num);
        }
        fprintf(f,"</tr>");
    }
    fprintf(f,"</table>");
    fprintf(f,"</body></html>");
    fclose(f);
}
void editerclass::resetdata()
{
    cleardata();
    update();
}
void editerclass::randomdata()
{
    static int tt=0;
    srand(time(NULL)+(tt++));
    cleardata();
    int answer[9][9];
    maincreate(answer);
    int rt=rand()%2;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(rt==0)
            {
                data[i][j].num=answer[i][j];
                data2[i][j].num=answer[i][j];
            }
            else
            {
                data[i][j].num=answer[j][i];
                data2[i][j].num=answer[j][i];
            }

            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=0;
                data2[i][j].list[k]=0;
            }
        }
    }
    update();
}
void editerclass::pushdata(MainWindow *pp,int index,int list[][9])
{
    indexnum=index;
    parentp=pp;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=list[i][j];
            data2[i][j].num=list[i][j];
            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=0;
                if(data[i][j].num==0){data[i][j].list[k]=1;}
                data2[i][j].list[k]=0;
            }
        }
    }
    update();

}
void editerclass::popdata()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            parentp->board->curentbrdgroupget()->boardget(indexnum)->dataset(i,j,data[i][j].num);
        }
    }
}
