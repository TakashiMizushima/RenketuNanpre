#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdio.h>

#define True -1
#define False 0

#define N 9
#define N3 3
struct DATA
{
  int num;
};
int PrintBan(int Ban[N][N],DATA data[][9])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){data[i][j].num=Ban[i][j];}
    }
    return 0;
}

/* 空いた枡を見つける */
int findBlank(int *x,int *y,int Ban[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if (Ban[i][j] == 0)
            {
                *x=i; *y=j;
                return True;
            }
    return False;
}

/* kを枡(x,y)に置けるか ? */
int isOkeru(int x,int y,int k,int Ban[N][N])
{
    int i,j;

    for(i=0;i<N;i++) if (Ban[i][y] == k) return False; /* 横に同じ数はないか */
    for(j=0;j<N;j++) if (Ban[x][j] == k) return False; /* 縦に同じ数はないか */
    for(i=0;i<N3;i++)                                  /* blockに同じ数はないか */
        for(j=0;j<N3;j++)
            if (Ban[N3*(x/N3)+i][N3*(y/N3)+j] == k) return False;
    return True;
}

/* これが問題のバックトラック */
int Try(int Ban[N][N],DATA data[][9])
{
    int x,y,k;
    if (findBlank(&x,&y,Ban)) /* 盤に空いた枡(x,y)があるか */
    for(k=1;k<=N;k++)
    {
        if(isOkeru(x,y,k,Ban)) /* 枡(x,y)にkを置けるか */
        {
            Ban[x][y] = k; /* 置けるなら置く */
            Try(Ban,data);      /* 次を確かめる */
            Ban[x][y] = 0; /* 枡(x,y)にkを置けないとして別の置き方はないか */
        }
    }
    else
    {
        PrintBan(Ban,data);
    }
    return 0;
}


int mainx(DATA data[][9])
{
    int i,j,Ban[N][N];
    

    for(int i=0;i<9;i++)
    {
      for(int j=0;j<9;j++)
      {
	  Ban[i][j]=data[i][j].num;
      }
    }
    

    //PrintBan(Ban);
    Try(Ban,data);
    return 0;
}


struct VECTOR
{
  int cx;
  int cy;
};
int rn=0;
VECTOR randomvectorget()
{
    srand((rn++)+time(NULL));
    VECTOR v;
    v.cx=rand()%2;
    v.cy=rand()%2;
    if(v.cx==0){v.cx--;}
    if(v.cy==0){v.cy--;}
    return v;
}
void dataset(DATA data[][9],int x,int y,int num)
{
  data[x][y].num=num;
}
void initdataset(DATA data[][9],int n1,int n2,int n3,int n4,int n5,int n6,int n7,int n8,int n9)
{
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      data[i][j].num=0;
    }
  }
  dataset(data,0,0,n1);
  dataset(data,0,1,n2);
  dataset(data,0,2,n3);
  dataset(data,1,0,n4);
  dataset(data,1,1,n5);
  dataset(data,1,2,n6);
  dataset(data,2,0,n7);
  dataset(data,2,1,n8);
  dataset(data,2,2,n9);
}
int hy=0;
void seconddataset(DATA data[][9],int vec)
{
  int rx[3];
  int ry[3];
  rx[0]=2;rx[1]=1;rx[2]=0;
  ry[0]=1;ry[1]=0;ry[2]=2;
  srand((hy++)+time(NULL));
  int a1=rand()%2;
int b1;int b2;int b3;
if(vec==1){b1=0;b2=1;b3=2;}
else{b1=1;b2=2;b3=0;}
if(vec==1)
{
 dataset(data,4,b2,data[0][b1].num);
 dataset(data,3,b2,data[1][b1].num);
 dataset(data,5,b3,data[2][b1].num);

 dataset(data,3,b3,data[0][b2].num);
 dataset(data,4,b3,data[1][b2].num);
 dataset(data,5,b1,data[2][b2].num);

 dataset(data,5,b2,data[0][b3].num);
 dataset(data,4,b1,data[1][b3].num);
 dataset(data,3,b1,data[2][b3].num);
}
else
{
 dataset(data,3,b3,data[0][b1].num);
 dataset(data,4,b3,data[1][b1].num);
 dataset(data,5,b2,data[2][b1].num);

 dataset(data,3,b1,data[0][b2].num);
 dataset(data,4,b1,data[1][b2].num);
 dataset(data,5,b3,data[2][b2].num);

 dataset(data,4,b2,data[0][b3].num);
 dataset(data,3,b2,data[1][b3].num);
 dataset(data,5,b1,data[2][b3].num);
}
}

void thirddataset(DATA data[][9],int vec)
{
  int rx[3];
  int ry[3];
  rx[0]=2;rx[1]=1;rx[2]=0;
  ry[0]=1;ry[1]=0;ry[2]=2;
  srand((hy++)+time(NULL));
  int a1=rand()%2;

int b1;int b2;int b3;
if(vec==1){b1=1;b2=2;b3=0;}
else{b1=2;b2=1;b3=0;}
  
 dataset(data,6,2,data[0][0].num);
 dataset(data,7,2,data[1][0].num);
 dataset(data,8,1,data[2][0].num);
 
 dataset(data,6,1,data[0][1].num);
 dataset(data,7,1,data[1][1].num);
 dataset(data,8,0,data[2][1].num);
 
 dataset(data,6,0,data[0][2].num);
 dataset(data,7,0,data[1][2].num);
 dataset(data,8,2,data[2][2].num);
}
void fourdataset(DATA data[][9],int vec)
{
   int rx[3];
  int ry[3];
  rx[0]=2;rx[1]=1;rx[2]=0;
  ry[0]=1;ry[1]=0;ry[2]=2;
  int b1=0;int b2=1;int b3=2;
if(vec==1)
{
 dataset(data,b2,3,data[b1][0].num);
 dataset(data,b2,4,data[b1][1].num);
 dataset(data,b3,5,data[b1][2].num);
 
 dataset(data,b3,3,data[b2][0].num);
 dataset(data,b3,4,data[b2][1].num);
 dataset(data,b1,5,data[b2][2].num);
 
 dataset(data,b1,3,data[b3][0].num);
 dataset(data,b1,4,data[b3][1].num);
 dataset(data,b2,5,data[b3][2].num);
}
else if(vec==-1)
{
    dataset(data,b2,3,data[b1][0].num);
    dataset(data,b3,5,data[b1][1].num);
    dataset(data,b2,4,data[b1][2].num);

    dataset(data,b3,3,data[b2][0].num);
    dataset(data,b1,5,data[b2][1].num);
    dataset(data,b3,4,data[b2][2].num);

    dataset(data,b1,3,data[b3][0].num);
    dataset(data,b2,5,data[b3][1].num);
    dataset(data,b1,4,data[b3][2].num);
}
else
{
    dataset(data,b3,3,data[b1][0].num);
    dataset(data,b2,5,data[b1][1].num);
    dataset(data,b2,4,data[b1][2].num);

    dataset(data,b1,3,data[b2][0].num);
    dataset(data,b3,5,data[b2][1].num);
    dataset(data,b3,4,data[b2][2].num);

    dataset(data,b2,3,data[b3][0].num);
    dataset(data,b1,5,data[b3][1].num);
    dataset(data,b1,4,data[b3][2].num);


}
}
void fivedataset(DATA data[][9],int vec)
{
  int rx[3];
  int ry[3];
  rx[0]=2;rx[1]=1;rx[2]=0;
  ry[0]=1;ry[1]=0;ry[2]=2;
  int b1=0;int b2=1;int b3=2;
  if(vec==1)
  {
 dataset(data,b3,6,data[0][0].num);
 dataset(data,b3,7,data[0][1].num);
 dataset(data,b2,8,data[0][2].num);
 
 dataset(data,b1,6,data[1][0].num);
 dataset(data,b1,7,data[1][1].num);
 dataset(data,b3,8,data[1][2].num);
 
 dataset(data,b2,6,data[2][0].num);
 dataset(data,b2,7,data[2][1].num);
 dataset(data,b1,8,data[2][2].num);
  }
  else if(vec==-1)
  {
      dataset(data,b3,6,data[b1][0].num);
      dataset(data,b2,7,data[b1][1].num);
      dataset(data,b3,8,data[b1][2].num);

      dataset(data,b1,6,data[b2][0].num);
      dataset(data,b3,7,data[b2][1].num);
      dataset(data,b1,8,data[b2][2].num);

      dataset(data,b2,6,data[b3][0].num);
      dataset(data,b1,7,data[b3][1].num);
      dataset(data,b2,8,data[b3][2].num);
  }
  else
{
      dataset(data,b2,6,data[b1][0].num);
      dataset(data,b3,7,data[b1][1].num);
      dataset(data,b3,8,data[b1][2].num);

      dataset(data,b3,6,data[b2][0].num);
      dataset(data,b1,7,data[b2][1].num);
      dataset(data,b1,8,data[b2][2].num);

      dataset(data,b1,6,data[b3][0].num);
      dataset(data,b2,7,data[b3][1].num);
      dataset(data,b2,8,data[b3][2].num);

  }
}
bool isput(DATA data[][9],int x,int y,int num)
{
  //if(x==5 && y==3){printf("pass1\n");}
  if(data[x][y].num!=0){return false;}
    for(int i=0;i<9;i++)
    {
      //if(x==5 && y==3){printf("pass2\n");}
	if(num==data[i][y].num){return false;}
	if(num==data[x][i].num){return false;}
    }
    for(int i=0;i<3;i++)
    {
	for(int j=0;j<3;j++)
	{
	  //if(x==5 && y==3){printf("pass3\n");}
	  int h=x*9+y;
	  if(num==data[(x/3)*3+i][(y/3)*3+j].num){return false;}
	  //if(x==5 && y==3){printf("m=%d n=%d\n",(x/3)*3+i,(y%3)*3+j);}
	}
    }
    //if(x==5 && y==3){printf("pass4\n");}
    return true;
}
void sixdataset(DATA data[][9])//2,2
{
  int rx[3];int ry[3];rx[0]=2;rx[1]=1;rx[2]=0;ry[0]=1;ry[1]=0;ry[2]=2;
  if(isput(data,3,4,data[0][3].num)==true){dataset(data,3,4,data[0][3].num);}
 else{dataset(data,4,4,data[0][3].num);}
 if(isput(data,4,4,data[1][3].num)==true){dataset(data,4,4,data[1][3].num);}
 else{if(isput(data,5,4,data[1][3].num)==true){dataset(data,5,4,data[1][3].num);}
   else{dataset(data,3,4,data[1][3].num);}}
 if(isput(data,5,5,data[2][3].num)==true){dataset(data,5,5,data[2][3].num);}
 else{
   if(isput(data,3,5,data[2][3].num)==true){dataset(data,3,5,data[2][3].num);}
   else{dataset(data,4,5,data[2][3].num);}
 }
 if(isput(data,3,5,data[0][4].num)==true){dataset(data,3,5,data[0][4].num);}
 else{dataset(data,4,5,data[0][4].num);}
 if(isput(data,4,5,data[1][4].num)==true){dataset(data,4,5,data[1][4].num);}
 else{
    if(isput(data,5,5,data[1][4].num)==true){dataset(data,5,5,data[1][4].num);}
    else{
      if(isput(data,3,5,data[1][4].num)==true){dataset(data,3,5,data[1][4].num);}
      else{dataset(data,4,5,data[1][4].num);}
    }
      //printf("data[%d][%d].num=%d\n",2,4,data[2][4].num);
 }
 //printf("data[%d][%d].num=%d\n",5,3,data[5][3].num);
 if(isput(data,5,3,data[2][4].num)==true){dataset(data,5,3,data[2][4].num);}
 else
 {
    if(isput(data,3,3,data[2][4].num)==true){dataset(data,3,3,data[2][4].num);}
    else{dataset(data,4,3,data[2][4].num);}
 }
 if(isput(data,3,3,data[0][5].num)==true){dataset(data,3,3,data[0][5].num);}
 else{dataset(data,4,3,data[0][5].num);}
 if(isput(data,4,3,data[1][5].num)==true){dataset(data,4,3,data[1][5].num);}
 else
 {
    if(isput(data,5,3,data[1][5].num)==true){dataset(data,5,3,data[1][5].num);}
    else{dataset(data,3,3,data[1][5].num);}
 }
 if(isput(data,5,4,data[2][5].num)==true){dataset(data,5,4,data[2][5].num);}
 else
 {
    if(isput(data,3,4,data[2][5].num)==true){dataset(data,3,4,data[2][5].num);}
    else{dataset(data,4,4,data[2][5].num);}
 }
}
bool  sevendatacheck(DATA data[][9])
{
 for(int i=0;i<3;i++)
 {
  for(int j=0;j<3;j++)
  {
      if(data[3+i][6+j].num==0){return false;}
  }
 }
 return true;
}
 void sevendata2set(DATA data[][9])
 {
  int rx[3];int ry[3];rx[0]=2;rx[1]=1;rx[2]=0;ry[0]=1;ry[1]=0;ry[2]=2;
  if(isput(data,3,7,data[0][6].num)==true){dataset(data,3,7,data[0][6].num);}
 else{dataset(data,4,7,data[0][6].num);}
 if(isput(data,4,7,data[1][6].num)==true){dataset(data,4,4,data[1][6].num);}
 else{if(isput(data,5,7,data[1][6].num)==true){dataset(data,5,7,data[1][6].num);}
   else{dataset(data,3,7,data[1][6].num);}}
 if(isput(data,5,8,data[2][6].num)==true){dataset(data,5,8,data[2][3].num);}
 else{
   if(isput(data,3,8,data[2][6].num)==true){dataset(data,3,8,data[2][6].num);}
   else{dataset(data,4,8,data[2][6].num);}
 }
 if(isput(data,3,8,data[0][7].num)==true){dataset(data,3,8,data[0][7].num);}
 else{dataset(data,4,8,data[0][7].num);}
 if(isput(data,4,8,data[1][7].num)==true){dataset(data,4,8,data[1][7].num);}
 else{
    if(isput(data,5,8,data[1][7].num)==true){dataset(data,5,8,data[1][7].num);}
    else{
      if(isput(data,3,8,data[1][7].num)==true){dataset(data,3,8,data[1][7].num);}
      else{dataset(data,4,8,data[1][7].num);}
    }
      //printf("data[%d][%d].num=%d\n",2,4,data[2][4].num);
 }
 //printf("data[%d][%d].num=%d\n",5,3,data[5][3].num);
 if(isput(data,5,6,data[2][7].num)==true){dataset(data,5,6,data[2][7].num);}
 else
 {
    if(isput(data,3,6,data[2][7].num)==true){dataset(data,3,6,data[2][7].num);}
    else{dataset(data,4,6,data[2][7].num);}
 }
 if(isput(data,3,6,data[0][8].num)==true){dataset(data,3,6,data[0][8].num);}
 else{dataset(data,4,6,data[0][8].num);}
 if(isput(data,4,6,data[1][8].num)==true){dataset(data,4,6,data[1][8].num);}
 else
 {
    if(isput(data,5,3,data[1][8].num)==true){dataset(data,5,6,data[1][8].num);}
    else{dataset(data,3,6,data[1][8].num);}
 }
 if(isput(data,5,7,data[2][8].num)==true){dataset(data,5,7,data[2][8].num);}
 else
 {
    if(isput(data,3,7,data[2][8].num)==true){dataset(data,3,7,data[2][8].num);}
    else{dataset(data,4,7,data[2][8].num);}
 } 
 }
 
  void sevendataset(DATA data[][9])
 {
  int rx[3];int ry[3];rx[0]=2;rx[1]=1;rx[2]=0;ry[0]=1;ry[1]=0;ry[2]=2;
  if(isput(data,3,7,data[0][6].num)==true){dataset(data,3,7,data[0][6].num);}
 else{dataset(data,4,7,data[0][6].num);}
 if(isput(data,4,7,data[1][6].num)==true){dataset(data,4,4,data[1][6].num);}
 else{if(isput(data,5,7,data[1][6].num)==true){dataset(data,5,7,data[1][6].num);}
   else{dataset(data,3,7,data[1][6].num);}}
 if(isput(data,5,8,data[2][6].num)==true){dataset(data,5,8,data[2][3].num);}
 else{
   if(isput(data,3,8,data[2][6].num)==true){dataset(data,3,8,data[2][6].num);}
   else{dataset(data,4,8,data[2][6].num);}
 }
 if(isput(data,3,8,data[0][7].num)==true){dataset(data,3,8,data[0][7].num);}
 else{dataset(data,4,8,data[0][7].num);}
 if(isput(data,4,8,data[1][7].num)==true){dataset(data,4,8,data[1][7].num);}
 else{
    if(isput(data,5,8,data[1][7].num)==true){dataset(data,5,8,data[1][7].num);}
    else{
      if(isput(data,3,8,data[1][7].num)==true){dataset(data,3,8,data[1][7].num);}
      else{dataset(data,4,8,data[1][7].num);}
    }
      //printf("data[%d][%d].num=%d\n",2,4,data[2][4].num);
 }
 //printf("data[%d][%d].num=%d\n",5,3,data[5][3].num);
 if(isput(data,5,6,data[2][7].num)==true){dataset(data,5,6,data[2][7].num);}
 else
 {
    if(isput(data,3,6,data[2][7].num)==true){dataset(data,3,6,data[2][7].num);}
    else{dataset(data,4,6,data[2][7].num);}
 }
 if(isput(data,3,6,data[0][8].num)==true){dataset(data,3,6,data[0][8].num);}
 else{dataset(data,4,6,data[0][8].num);}
 if(isput(data,4,6,data[1][8].num)==true){dataset(data,4,6,data[1][8].num);}
 else
 {
    if(isput(data,5,3,data[1][8].num)==true){dataset(data,5,6,data[1][8].num);}
    else{dataset(data,3,6,data[1][8].num);}
 }
 if(isput(data,5,7,data[2][8].num)==true){dataset(data,5,7,data[2][8].num);}
 else
 {
    if(isput(data,3,7,data[2][8].num)==true){dataset(data,3,7,data[2][8].num);}
    else{dataset(data,4,7,data[2][8].num);}
 } 
 if(sevendatacheck(data)==false)
 {
    //sevendata2set(data);
 }
 }
 void copydata(DATA data1[][9],DATA data2[][9])
 {
  for(int i=0;i<9;i++)
  {
      for(int j=0;j<9;j++)
      {
	  data1[i][j].num=data2[i][j].num;
      }
  }
 }
 bool allok(DATA data[][9])
 {
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	{
	    if(data[i][j].num==0){return false;}
	}
    }
    return true;
 }
 void printdata(DATA data[][9])
 {
    for(int i=0;i<9;i++)
  {
      for(int j=0;j<9;j++)
      {
	  printf("%d",data[i][j].num);
      }
      printf("\n");
  } 
  printf("\n");
 }
 int hn=0;
 bool solvedata(int data[][9])
 {
     DATA data2[9][9];
     for(int i=0;i<9;i++)
     {
         for(int j=0;j<9;j++)
         {
             data2[i][j].num=data[i][j];
         }
     }
 }
 bool solvedata(DATA data[][9])
 {
   DATA cd[9][9];
   copydata(cd,data);
   int limit=0;
   while(allok(data)==false && limit<200)
   {
  for(int i=0;i<81;i++)
  {
    if(data[i/9][i%9].num==0)
    {
      srand((hn++)+time(NULL));
      int num=rand()%9+1;
      if(isput(data,i/9,i%9,num)==true)
      {
	  dataset(data,i/9,i%9,num);
      }
    }
  }
  printdata(data);
  limit++;
   }
   if(limit<200){return true;}
   return false;
  
 }
 
 void sevendatasetx(DATA data[][9])
 {
    int list[3][3];
    int li2[9];int m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[3][i].num-1]=0;}
    //for(int i=0;i<9;i++){printf("li2[%d]=%d ",i,li2[i]);}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[0][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[4][i].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[1][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[5][i].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[2][m]=li2[n];m++;}}
    //for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d",list[i][j]);}printf("\n");}
    
    for(int i=0;i<3;i++)
    {
      /////////////////////////
      if(isput(data,3+i,6,list[i][0])==true){dataset(data,3+i,6,list[i][0]);}
      else
      {
	if(isput(data,3+i,7,list[i][0])==true){dataset(data,3+i,7,list[i][0]);}
	else{dataset(data,3+i,8,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,3+i,6,list[i][1])==true){dataset(data,3+i,6,list[i][1]);}
      else
      {
	if(isput(data,3+i,7,list[i][1])==true){dataset(data,3+i,7,list[i][1]);}
	else{dataset(data,3+i,8,list[i][1]);}
      }
      /////////////////////////
      if(isput(data,3+i,6,list[i][2])==true){dataset(data,3+i,6,list[i][2]);}
      else
      {
	if(isput(data,3+i,7,list[i][2])==true){dataset(data,3+i,7,list[i][2]);}
	else
	{
	  dataset(data,3+i,8,list[i][2]);
	  int t=data[3+i][8].num;
	  int s=data[3+i][6].num;
	  int u=data[3+i][7].num;
	  data[3+i][8].num=0;
	  data[3+i][6].num=0;
	  data[3+i][7].num=0;
	  
      if(isput(data,3+i,8,list[i][0])==true){dataset(data,3+i,8,list[i][0]);}
      else
      {
	if(isput(data,3+i,6,list[i][0])==true){dataset(data,3+i,6,list[i][0]);}
	else{dataset(data,3+i,7,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,3+i,7,list[i][1])==true){dataset(data,3+i,7,list[i][1]);}
      else
      {
	if(isput(data,3+i,8,list[i][1])==true){dataset(data,3+i,8,list[i][1]);}
	else{dataset(data,3+i,6,list[i][1]);}
      }
	  if(isput(data,3+i,6,list[i][2])==true){dataset(data,3+i,6,list[i][2]);}
	  else
	  {
	    if(isput(data,3+i,7,list[i][2])==true){dataset(data,3+i,7,list[i][2]);}
	    else
	    {
	      dataset(data,3+i,8,list[i][2]);
	    }
	  }
	  
	}
      }
    }
    
    
 }
 /////////////////////////////////////////////////////////////////////////
 
 
  void eightdatasetx(DATA data[][9])
 {
    int list[3][3];
    int li2[9];int m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][3].num-1]=0;}
    //for(int i=0;i<9;i++){printf("li2[%d]=%d ",i,li2[i]);}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[0][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][4].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[1][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][5].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[2][m]=li2[n];m++;}}
    //for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d",list[i][j]);}printf("\n");}
    
    for(int i=0;i<3;i++)
    {
      /////////////////////////
      if(isput(data,6,3+i,list[i][0])==true){dataset(data,6,3+i,list[i][0]);}
      else
      {
	if(isput(data,7,3+i,list[i][0])==true){dataset(data,7,3+i,list[i][0]);}
	else{dataset(data,8,3+i,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,6,3+i,list[i][1])==true){dataset(data,6,3+i,list[i][1]);}
      else
      {
	if(isput(data,7,3+i,list[i][1])==true){dataset(data,7,3+i,list[i][1]);}
	else{dataset(data,8,3+i,list[i][1]);}
      }
      /////////////////////////
      if(isput(data,6,3+i,list[i][2])==true){dataset(data,6,3+i,list[i][2]);}
      else
      {
	if(isput(data,7,3+i,list[i][2])==true){dataset(data,7,3+i,list[i][2]);}
	else
	{
	  dataset(data,8,3+i,list[i][2]);
	  int t=data[8][3+i].num;
	  int s=data[6][3+i].num;
	  int u=data[7][3+i].num;
	  data[8][3+i].num=0;
	  data[6][3+i].num=0;
	  data[7][3+i].num=0;
	  
      if(isput(data,8,3+i,list[i][0])==true){dataset(data,8,3+i,list[i][0]);}
      else
      {
	if(isput(data,6,3+i,list[i][0])==true){dataset(data,6,3+i,list[i][0]);}
	else{dataset(data,7,3+i,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,7,3+i,list[i][1])==true){dataset(data,7,3+i,list[i][1]);}
      else
      {
	if(isput(data,8,3+i,list[i][1])==true){dataset(data,8,3+i,list[i][1]);}
	else{dataset(data,6,3+i,list[i][1]);}
      }
	  if(isput(data,6,3+i,list[i][2])==true){dataset(data,6,3+i,list[i][2]);}
	  else
	  {
	    if(isput(data,7,3+i,list[i][2])==true){dataset(data,7,3+i,list[i][2]);}
	    else
	    {
	      dataset(data,8,3+i,list[i][2]);
	    }
	  }
	  
	}
      }
    }
    
    
 }
 
 ////////////////////////////////////////////////////////////////////////
 
   void ninedatasetx(DATA data[][9])
 {
    int list[3][3];
    int li2[9];int m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][3].num-1]=0;}
    //for(int i=0;i<9;i++){printf("li2[%d]=%d ",i,li2[i]);}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[0][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][4].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[1][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][5].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[2][m]=li2[n];m++;}}
    //for(int i=0;i<3;i++){for(int j=0;j<3;j++){printf("%d",list[i][j]);}printf("\n");}
    
    for(int i=0;i<3;i++)
    {
      /////////////////////////
      if(isput(data,6,6+i,list[i][0])==true){dataset(data,6,6+i,list[i][0]);}
      else
      {
	if(isput(data,7,6+i,list[i][0])==true){dataset(data,7,6+i,list[i][0]);}
	else{dataset(data,8,6+i,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,6,6+i,list[i][1])==true){dataset(data,6,6+i,list[i][1]);}
      else
      {
	if(isput(data,7,6+i,list[i][1])==true){dataset(data,7,6+i,list[i][1]);}
	else{dataset(data,8,6+i,list[i][1]);}
      }
      /////////////////////////
      if(isput(data,6,6+i,list[i][2])==true){dataset(data,6,6+i,list[i][2]);}
      else
      {
	if(isput(data,7,6+i,list[i][2])==true){dataset(data,7,6+i,list[i][2]);}
	else
	{
	  dataset(data,8,6+i,list[i][2]);
	  int t=data[8][6+i].num;
	  int s=data[6][6+i].num;
	  int u=data[7][6+i].num;
	  data[8][3+i].num=0;
	  data[6][3+i].num=0;
	  data[7][3+i].num=0;
	  
      if(isput(data,8,6+i,list[i][0])==true){dataset(data,8,6+i,list[i][0]);}
      else
      {
	if(isput(data,6,6+i,list[i][0])==true){dataset(data,6,6+i,list[i][0]);}
	else{dataset(data,7,6+i,list[i][0]);}
      }
      /////////////////////////
      if(isput(data,7,6+i,list[i][1])==true){dataset(data,7,6+i,list[i][1]);}
      else
      {
	if(isput(data,8,6+i,list[i][1])==true){dataset(data,8,6+i,list[i][1]);}
	else{dataset(data,6,6+i,list[i][1]);}
      }
	  if(isput(data,6,6+i,list[i][2])==true){dataset(data,6,6+i,list[i][2]);}
	  else
	  {
	    if(isput(data,7,6+i,list[i][2])==true){dataset(data,7,6+i,list[i][2]);}
	    else
	    {
	      dataset(data,8,6+i,list[i][2]);
	    }
	  }
	  
	}
      }
    }
    
    
 }
 
 void ninedatasetz(DATA data[][9])
 {
 for(int i=6;i<9;i++)
 {
  for(int j=6;j<9;j++)
  {
      for(int m=1;m<=9;m++)
      {
	if(isput(data,i,j,m)==true){dataset(data,i,j,m);}
      }
  }
 }
   
 }
 void linex(DATA data[][9])
 {
    int list[9][3];
    int li2[9];int m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][0].num-1]=0;}
    //for(int i=0;i<9;i++){printf("li2[%d]=%d ",i,li2[i]);}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[0][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][1].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[1][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][2].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[2][m]=li2[n];m++;}}
    
    m=0;
    
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][3].num-1]=0;}
    //for(int i=0;i<9;i++){printf("li2[%d]=%d ",i,li2[i]);}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[3][m]=li2[n];m++;}}
    m=0;
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    for(int i=0;i<6;i++){li2[data[i][4].num-1]=0;}
    for(int n=0;n<9;n++){if(li2[n]!=0){list[4][m]=li2[n];m++;}}
    m=0;
    //return;
    
    for(int i=0;i<9;i++){li2[i]=i+1;   }
    //return;
    for(int i=0;i<6;i++){li2[data[i][5].num-1]=0;}
    //return;
    for(int n=0;n<9;n++){if(li2[n]!=0){list[5][m]=li2[n];m++;}}
    //return;
    m=0;
     int kei=0;
    while(1)
    {
      
      for(int i=0;i<9;i++)
      {
	int num=list[i][0];
	int j=0;
	for(j=0;j<9;j++)
	{
	if(isput(data,6,j,num)==true){dataset(data,6,j,num);kei+=num;
	}
      printdata(data);}
      }
      if(kei==45){break;}
      else
      {
	 for(int i=0;i<9;i++)
	{
	  data[6][i].num=0;
	}
	
      }
      
    }
    
 }
 void autoseedset(DATA data[][9])
 {
   int list[9];
   for(int i=0;i<9;i++){list[i]=i+1;}
   for(int i=0;i<100;i++)
   {
     srand((hy++)+time(NULL));
      int x=rand()%9;
      int y=rand()%9;
      int t=list[x];
      list[x]=list[y];
      list[y]=t;
   }
   initdataset(data,list[0],list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8]);
 }
int maincreate(int answer[][9])
{
line1:
    DATA data[9][9];
    autoseedset(data);
  bool flag=false;
  int v1=rand()%2;
  int v2=rand()%3-1;
  
  seconddataset(data,v1);
  fourdataset(data,v2);
  fivedataset(data,v2);
  sixdataset(data);
  sevendatasetx(data);
  //linex(data);
  mainx(data);

  for(int i=0;i<9;i++)
  {
    int sum1=0;
    int sum2=0;
    for(int j=0;j<9;j++)
    {
        sum1+=data[i][j].num;
        sum2+=data[j][i].num;
    }
    if(sum1!=45 || sum2!=45){goto line1;}
  }

  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      answer[i][j]=data[i][j].num;
    }
  }

  return 0;
}
int mainsolvx(int question[][9],int answer[][9])
{

    DATA data[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            data[i][j].num=question[i][j];
        }
    }
  mainx(data);
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      answer[i][j]=data[i][j].num;
    }
  }

  return 0;
}
