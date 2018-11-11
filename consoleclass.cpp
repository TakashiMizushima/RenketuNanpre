#include"consoleclass.h"

void consoleclass::CommandStringSet(QString command)
{
    QStringList strList = command.split(QRegExp(" "), QString::SkipEmptyParts) ;
    int leng=strList.size();
    if(leng==1 && strList[0]=="up"){mapup();}
    if(leng==1 && strList[0]=="dn"){mapdn();}
    if(leng==1 && strList[0]=="lf"){maplf();}
    if(leng==1 && strList[0]=="rt"){maprt();}
    if(leng==1 && strList[0]=="sav"){filesave();}
    if(leng==1 && strList[0]=="sav2"){filesave2();}
    if(leng==1 && strList[0]=="lod"){fileload();}
    if(leng==1 && strList[0]=="loda"){fileloadapend();}
    if(leng==1 && strList[0]=="adar"){mapaddr(1);return;}
    if(leng==1 && strList[0]=="ada"){mapadd(1);return;}
    if(leng==2 && strList[0]=="adar"){mapaddr(strList[1].toInt());return;}
    if(leng==2 && strList[0]=="ada"){mapadd(strList[1].toInt());return;}
    if(leng==2 && strList[0]=="dela"){mapdel(strList[1].toInt());}
    if(leng==1 && strList[0]=="delh"){mapdelh();}
    if(leng>=4 && strList[0]=="gor"){numlist.clear();for(int i=2;i<leng;i++){numlist.push_back(strList[i].toInt());}mapfall(strList[1].toInt(),&numlist);}
    if(leng==2 && strList[0]=="adss"){linkrepair(strList[1].toInt());}
    if(leng==3 && strList[0]=="adsc"){linkchange(strList[1].toInt(),strList[2].toInt());}
    if(leng==1 && strList[0]=="adse"){linkerase();return;}
    if(leng==2 && strList[0]=="adse"){linkerase(strList[1].toInt());return;}
    if(leng==7 && strList[0]=="adsd"){linkdowblemake(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt(),strList[5].toInt(),strList[6].toInt());}
    if(leng==13 && strList[0]=="adst"){linktwicemake(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt(),strList[5].toInt(),strList[6].toInt(),strList[7].toInt(),strList[8].toInt(),strList[9].toInt(),strList[10].toInt(),strList[11].toInt(),strList[12].toInt());}
    if(leng==1 && strList[0]=="adsai"){ailinkmake(0);}
    if(leng==7 && strList[0]=="ads"){linkmake(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt(),strList[5].toInt(),strList[6].toInt());}
    if(leng==7 && strList[0]=="adso"){linkonlymake(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt(),strList[5].toInt(),strList[6].toInt());}
    if(leng==3 && strList[0]=="adsr"){reallinkmake(strList[1].toInt(),strList[2].toInt());}
    if(leng==3 && strList[0]=="adsrp"){realpartslinkmake(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt(),strList[5].toInt(),strList[6].toInt());}
    if(leng==13 && strList[0]=="set"){numlist.clear();int id=strList[1].toInt();int xx=strList[2].toInt();int yy=strList[3].toInt();for(int i=4;i<leng;i++){numlist.push_back(strList[i].toInt());}dataset(id,xx,yy,&numlist);}
    if(leng==1 && strList[0]=="sol"){solver(4);}
    if(leng==1 && strList[0]=="solc"){solvercomplex(4);}
    if(leng==2 && strList[0]=="edt"){mapedit(strList[1].toInt());}
    if(leng==1 && strList[0]=="ers"){dataerase();}
    if(leng==2 && strList[0]=="pri"){dataprint(strList[1].toInt());}
    if(leng==2 && strList[0]=="prm"){dataprintmap(strList[1].toInt());}
    if(leng==1 && strList[0]=="cir"){circleput();}
    if(leng==1 && strList[0]=="memo"){memoeditshow();}
    if(leng==1 && strList[0]=="rot"){maprotate();}
    if(leng==3 && strList[0]=="ide"){indexedit(strList[1].toInt(),strList[2].toInt());}
    if(leng==1 && strList[0]=="qmak"){makequestion();}
    if(leng==1 && strList[0]=="adah"){mapaddh(1);}
    if(leng==1 && strList[0]=="chis"){curenthistorychange(1);}
    if(leng==1 && strList[0]=="chis++"){curenthistorychangeadd(1);}
    if(leng==1 && strList[0]=="chis--"){curenthistorychangeadd(-1);}
    if(leng==1 && strList[0]=="chistop"){stopthread();}
    if(leng==5 && strList[0]=="cheat"){cheatnumber(strList[1].toInt(),strList[2].toInt(),strList[3].toInt(),strList[4].toInt());}
    if(leng==1 && strList[0]=="update"){updatethread();}
    if(leng==3 && strList[0]=="sla"){serchset1(strList[1].toInt());}
    if(leng==1 && strList[0]=="slb"){serchset2();}
    if(leng==2 && strList[0]=="eda"){leafset(strList[1].toInt(),1);}
    if(leng==1 && strList[0]=="vec"){vecshow();}
    if(leng==1 && strList[0]=="play"){aiplay();}
    if(leng==2 && strList[0]=="manul"){manuallock(strList[1].toInt());return;}
    if(leng==1 && strList[0]=="manu"){manualconnect();}
    if(leng==1 &&  strList[0]=="reload"){reloadset();}
    if(leng==1 &&  strList[0]=="is"){inputboxshow();}
    if(leng==1 &&  strList[0]=="ih"){inputboxhide();}
    if(leng==2 &&  strList[0]=="it"){inputboxtrans(strList[1].toInt());}
    if(leng==1 &&  strList[0]=="m-"){mapminus();}
    if(leng==1 &&  strList[0]=="m+"){mapplus();}
    if(leng==1 &&  strList[0]=="rnd"){randommake(strList[1].toInt());}
    if(leng==2 &&  strList[0]=="erd"){eraseset(strList[1].toInt());}

}
