#include<stdio.h>
struct DATAX
{
    int num;
    int list[9];
};
bool isinput(DATAX data[][9],int x,int y,int num);
void setdata(DATAX data[][9],int questiondata[][9],int questionlist[][9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=questiondata[i][j];
            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=questionlist[i][j][k];
            }
        }
    }
}
void setdataans(DATAX data[][9],int answerdata[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=answerdata[i][j];
            for(int k=0;k<9;k++)
            {
                data[i][j].list[k]=1;
            }
        }
    }
}
bool yokohekezuru1(DATAX data[][9],int y)
{
return false;
}
bool tatehekezuru1(DATAX data[][9],int x)
{
    return false;
}
bool backisbetter(DATAX data[][9],DATAX ori[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int m=0;m<9;m++)
            {
                if(data[i][j].num!=0 && data[i][j].num==data[i][m].num && j!=m){return true;}
                if(data[i][j].num!=0 && data[i][j].num==data[m][j].num && i!=m){return true;}
                if(data[i][j].num==0 && ori[i][j].num!=data[i][m].num && j!=m){return true;}
                if(data[i][j].num==0 && ori[i][j].num!=data[m][j].num && i!=m){return true;}
                //if(data[(i/3)*3+i%3][(j/3)*3+j%3].num==data[(i/3)*3+m/3][(j/3)*3+m%3].num && (i/3)*3+i%3!=(i/3)*3+m/3 && (j/3)*3+j%3!=(j/3)*3+m%3){return true;}
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int m=0;m<3;m++)
            {
                for(int n=0;n<3;n++)
                {
                    for(int k=0;k<3;k++)
                    {
                        for(int h=0;h<3;h++)
                        {
                            if(m!=k && n!=h && data[i*3+m][j*3+n].num==data[i*3+k][j*3+h].num && data[i*3+k][j*3+h].num!=0){return true;}
                        }
                    }
                    //if(i!=m && j!=n && (i/3)*3+i%3!=(m/3)*3+m%3 && (j/3)*3+j%3!=(n/3)*3+n%3 && data[(i/3)*3+i%3][(j/3)*3+j%3].num==data[(m/3)*3+m%3][(n/3)*3+n%3].num){return true;}
                }
            }

        }

    }
    return false;
}
bool boxhekezuru1(DATAX data[][9],int x,int y)
{
return false;
}

void hintcheck1(DATAX data[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int k=0;k<9;k++)
            {
                if(data[i][j].list[k]==1){
                for(int m=0;m<9;m++)
                {
                    for(int n=0;n<9;n++)
                    {
                        if(k+1==data[m][n].num && m!=i && n!=i)
                        {
                            data[i][j].list[k]=0;
                        }
                    }
                }
                }
            }

        }
    }

}
void hintkakutei(DATAX data[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            for(int m=0;m<9;m++)
            {
                int cnt=0;
                int k1=0;
                for(int k=0;k<9;k++)
                {
                    if(data[i][j].list[k]==1){cnt++;k1=k;}
                }
                if(cnt==1 && isinput(data,i,j,k1+1)){
                    data[i][j].num=k1+1;
                    for(int m=0;m<9;m++)
                    {
                        data[i][j].list[m]=0;
                    }
                    for(int m=0;m<9;m++)
                    {
                        data[i][m].list[k1]=0;
                        data[m][j].list[k1]=0;
                        data[(i/3)*3+m/3][(j/3)*3+m%3].list[k1]=0;
                    }
                }
            }
        }
    }
}

void copydata(DATAX data1[][9],DATAX data2[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data1[i][j].num=data2[i][j].num;
            for(int k=0;k<9;k++)
            {
                data1[i][j].list[k]=data2[i][j].list[k];
            }
        }
    }
}
bool samedata(DATAX data1[][9],DATAX data2[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(data1[i][j].num!=data2[i][j].num){return false;}
            for(int k=0;k<9;k++)
            {
                if(data1[i][j].list[k]!=data2[i][j].list[k]){return false;}
            }
        }
    }
    return true;
}
void makereturndata(DATAX data1[][9],int returnd[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            returnd[i][j]=data1[i][j].num;
        }
    }
}
bool isinput(DATAX data[][9],int x,int y,int num)
{
    int kc=0;
    if(data[x][y].num!=0){return false;}
    for(int k=0;k<9;k++)
    {
        kc+=data[x][y].list[k];
    }
    if(kc!=1){return false;}
    for(int i=0;i<9;i++)
    {
        if(data[x][i].num==num){return false;}
        if(data[i][y].num==num){return false;}
        if(data[(x/3)*3+i/3][(y/3)*3+i%3].num==num){return false;}
        int kc=0;

    }
    return true;
}
bool mainsolve(int questiondata[][9],int questionlist[][9][9],int answerdata[][9],int returndata[][9],int p,int q)
{
    DATAX data[9][9];
    DATAX data2[9][9];
    DATAX data3[9][9];
    DATAX dataans[9][9];
    setdata(data,questiondata,questionlist);
    setdataans(data2,answerdata);
    copydata(data3,data);
    hintkakutei(data3);
        //boxhekezuru1(data3,p,q);
        //hintkakutei(data3);
        //yokohekezuru1(data3,p);
        //hintkakutei(data3);
        //tatehekezuru1(data3,p);
        //hintkakutei(data3);
        hintcheck1(data3);
    makereturndata(data3,returndata);
    return true;
}
