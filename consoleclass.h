#ifndef CONSOLECLASS_H
#define CONSOLECLASS_H
#include<string>
#include<vector>
#include<QString>
#include<QStringList>
class consoleclass
{
public:
    void CommandStringSet(QString command);
    std::vector<int> numlist;
    virtual void mapup()=0;
    virtual void mapdn()=0;
    virtual void maplf()=0;
    virtual void maprt()=0;
    virtual void filesave()=0;
    virtual void filesave2()=0;
    virtual void fileload()=0;
    virtual void fileloadapend()=0;
    virtual void mapadd(int count)=0;
    virtual void mapaddr(int count)=0;
    virtual void mapaddh(int count)=0;
    virtual void mapdel(int index)=0;
    virtual void mapdelh()=0;
    virtual void mapfall(int index,std::vector<int> *mlist)=0;
    virtual void ailinkmake(int cnt)=0;
    virtual void linkerase()=0;
    virtual void linkerase(int index)=0;
    virtual void linkmake(int id1,int x1,int y1,int id2,int x2,int y2)=0;
    virtual void linkrepair(int id1)=0;
    virtual void linkchange(int id1,int id2)=0;
    virtual void linkonlymake(int id1,int x1,int y1,int id2,int x2,int y2)=0;
    virtual void linktwicemake(int id1,int x1,int y1,int id2,int x2,int y2,int id3,int x3,int y3,int id4,int x4,int y4)=0;
    virtual void linkdowblemake(int id1,int x1,int y1,int id2,int x2,int y2)=0;
    virtual void reallinkmake(int id1,int id2)=0;
    virtual void realpartslinkmake(int id1,int x1,int y1,int id2,int x2,int y2)=0;
    virtual void dataset(int id,int xx,int yy,std::vector<int> *list)=0;
    virtual void solver(int count)=0;
    virtual void solvercomplex(int count)=0;
    virtual void mapedit(int index)=0;
    virtual void dataerase()=0;
    virtual void dataprint(int index)=0;
    virtual void dataprintmap(int index)=0;
    virtual void circleput()=0;
    virtual void memoeditshow()=0;
    virtual void maprotate()=0;
    virtual void indexedit(int fromindex,int toindex)=0;
    virtual void makequestion()=0;
    virtual void curenthistorychange(int index)=0;
    virtual void curenthistorychangeadd(int index)=0;
    virtual void stopthread()=0;
    virtual void cheatnumber(int index,int x,int y,int num)=0;
    virtual void updatethread()=0;
    virtual void serchset1(int b)=0;
    virtual void serchset2()=0;
    virtual void leafset(int index,int swi)=0;
    virtual void vecshow()=0;
    virtual void aiplay()=0;
    virtual void manualconnect()=0;
    virtual void manuallock(int index)=0;
    virtual void reloadset()=0;
    virtual void inputboxshow()=0;
    virtual void inputboxhide()=0;
    virtual void inputboxtrans(int index)=0;
    virtual void mapminus()=0;
    virtual void mapplus()=0;
    virtual void randommake(int index)=0;
    virtual void eraseset(int param)=0;
    virtual void swapnum(int num1,int num2)=0;


};
#endif // CONSOLECLASS_H
