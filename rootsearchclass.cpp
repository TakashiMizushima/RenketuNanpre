#include "rootsearchclass.h"

rootsearchclass::rootsearchclass()
{
    linkcount=0;

}
void rootsearchclass::boardhistorycclassset(boardhistorycclass *mbrd)
{
    brd=mbrd;
}
void rootsearchclass::sizeset()
{
    left=1000000;
    right=-100000;
    top=1000000;
    bottom=-1000000;

    for(int i=0;i<(signed int)brd->brdhist[0]->brdgroup.size();i++)
    {
        boardclass *bd=brd->brdhist[0]->brdgroup[i];
        bd->drawpos.setX(bd->drawpos.x()+30000);
        bd->drawpos.setY(bd->drawpos.y()+30000);
        if(bd->drawpos.x()/(bd->chipsize.width()*3)<left){left=bd->drawpos.x()/(bd->chipsize.width()*3);}
        if(bd->drawpos.x()/(bd->chipsize.width()*3)>right){right=bd->drawpos.x()/(bd->chipsize.width()*3);}
        if(bd->drawpos.y()/(bd->chipsize.height()*3)<top){top=bd->drawpos.y()/(bd->chipsize.height()*3);}
        if(bd->drawpos.y()/(bd->chipsize.height()*3)>bottom){bottom=bd->drawpos.y()/(bd->chipsize.height()*3);}
    }
    right+=3;
    bottom+=3;
    bottom=bottom;
    right=right;
    board=new ROOTSTRUCT *[right-left];
    for(int i=0;i<right-left;i++)
    {
        board[i]=new ROOTSTRUCT [bottom-top];
        for(int j=0;j<bottom-top;j++)
        {
            board[i][j].a[0]=-1;
            board[i][j].a[1]=-1;
            board[i][j].a[2]=-1;
            board[i][j].a[3]=-1;
            board[i][j].x[0]=-1;
            board[i][j].x[1]=-1;
            board[i][j].y[0]=-1;
            board[i][j].y[1]=-1;
            board[i][j].pi=-10;
            board[i][j].pj=-10;
            board[i][j].f=-1;
            board[i][j].twice1=false;
            board[i][j].twice2=false;
            board[i][j].leaf=1;
            board[i][j].pass=false;
        }
    }
    cx=right-left;
    cy=bottom-top;
}
void rootsearchclass::mapset()
{
    for(int i=0;i<(signed int)brd->brdhist[0]->brdgroup.size();i++)
    {
        boardclass *bd=brd->brdhist[0]->brdgroup[i];
        int left2=bd->drawpos.x()/(bd->chipsize.width()*3)-left;
        int top2=bd->drawpos.y()/(bd->chipsize.height()*3)-top;
        bd->drawpos.setX(bd->drawpos.x()-30000);
        bd->drawpos.setY(bd->drawpos.y()-30000);
        for(int m=0;m<3;m++)
        {
            for(int n=0;n<3;n++)
            {
                board[left2+m][top2+n].leaf=bd->leaf;
                if(board[left2+m][top2+n].a[0]==-1)
                {
                    board[left2+m][top2+n].a[0]=bd->index;
                    board[left2+m][top2+n].x[0]=m;
                    board[left2+m][top2+n].y[0]=n;
                }
                else
                {
                    board[left2+m][top2+n].a[1]=bd->index;
                    board[left2+m][top2+n].x[1]=m;
                    board[left2+m][top2+n].y[1]=n;
                }
            }
        }
    }
}
void rootsearchclass::sort()
{
    for(int i=0;i<cx-1;i++)
    {
        for(int j=0;j<cy;j++)
        {
            if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1 && board[i+1][j].a[0]!=-1 && board[i+1][j].a[1]!=-1)
            {
                int s1=board[i][j].a[0];
                int s2=board[i][j].a[1];
                int s3=board[i+1][j].a[0];
                int s4=board[i+1][j].a[1];
                int s5=i;
                int s6=j;
                s1=board[i][j].a[0];
                s2=board[i][j].a[1];
                s3=board[i+1][j].a[0];
                s4=board[i+1][j].a[1];
                s5=i;
                s6=j;
                board[i][j].twice1=true;
                board[i][j].pi=i+1;
                board[i][j].pj=j;
                board[i][j].f=1;
                board[i+1][j].f=1;

                //board[i+1][j].twice1=true;
            }
        }
    }
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<cy-1;j++)
        {
            if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1 && board[i][j+1].a[0]!=-1 && board[i][j+1].a[1]!=-1)
            {
                int s1=board[i][j].a[0];
                int s2=board[i][j].a[1];
                int s3=board[i][j+1].a[0];
                int s4=board[i][j+1].a[1];
                int s5=i;
                int s6=j;
                s1=board[i][j].a[0];
                s2=board[i][j].a[1];
                s3=board[i][j+1].a[0];
                s4=board[i][j+1].a[1];
                s5=i;
                s6=j;
                board[i][j].twice1=true;
                board[i][j].pi=i;
                board[i][j].pj=j+1;
                board[i][j].f=1;
                board[i][j+1].f=1;

                //board[i][j+1].twice1=true;
            }
        }
    }
    /*
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<cy;j++)
        {
            for(int m=0;m<cx;m++)
            {
                for(int n=0;n<cy;n++)
                {
                    if(m!=i && n!=j && board[i][j].twice1==false && (board[i][j].a[0]==board[m][n].a[0] || board[i][j].a[0]==board[m][n].a[1] || board[i][j].a[1]==board[m][n].a[0] || board[i][j].a[1]==board[m][n].a[1]))
                    {
                            board[i][j].leaf=0;
                    }
                    if(m!=i && n!=j && board[i][j].twice1==true && (board[i][j].a[0]==board[m][n].a[0] || board[i][j].a[0]==board[m][n].a[1] || board[i][j].a[1]==board[m][n].a[0] || board[i][j].a[1]==board[m][n].a[1]) && (board[i+1][j].a[0]==board[m+1][n].a[0] || board[i+1][j].a[0]==board[m+1][n].a[1] || board[i+1][j].a[1]==board[m+1][n].a[0] || board[i+1][j].a[1]==board[m+1][n].a[1]) && (board[i][j+1].a[0]==board[m][n+1].a[0] || board[i][j+1].a[0]==board[m][n+1].a[1] || board[i][j+1].a[1]==board[m][n+1].a[0] || board[i][j+1].a[1]==board[m][n+1].a[1]))
                    {
                            board[i][j].leaf=0;
                    }
                }
            }
        }
    }*/
}
void rootsearchclass::linkmake(int cnt)
{
    if(cnt==0)
    {
        for(int i=0;i<cx;i++)
        {
            for(int j=0;j<cy;j++)
            {
                if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1)
                {
                    int pi=board[i][j].pi;
                    int pj=board[i][j].pj;
                    int f=board[i][j].f;
                    if(board[i][j].twice1==false && f==-1)
                    {
                        if(board[i][j].leaf==1)
                        {
                            brd->linkmake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1]);
                        }
                        else
                        {
                            brd->linkmake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0]);
                        }

                    }
                    if(board[i][j].twice1==true)
                    {
                        int pi=board[i][j].pi;
                        int pj=board[i][j].pj;

                        if(board[i][j].leaf==1)
                        {
                            brd->linktwicemake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1]);
                        }
                        else
                        {
                            brd->linktwicemake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0]);
                        }
                    }
                }
            }
        }
    }
    if(cnt==1)
    {
        for(int i=cx-1;i>=0;i--)
        {
            for(int j=0;j<cy;j++)
            {
                if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1)
                {
                    int pi=board[i][j].pi;
                    int pj=board[i][j].pj;
                    int f=board[i][j].f;
                    if(board[i][j].twice1==false && f==-1)
                    {
                        if(board[i][j].leaf==1)
                        {
                            brd->linkmake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1]);
                        }
                        else
                        {
                            brd->linkmake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0]);
                        }

                    }
                    if(board[i][j].twice1==true)
                    {
                        int pi=board[i][j].pi;
                        int pj=board[i][j].pj;

                        if(board[i][j].leaf==1)
                        {
                            brd->linktwicemake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1]);
                        }
                        else
                        {
                            brd->linktwicemake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0]);
                        }
                    }
                }
            }
        }
    }
    if(cnt==2)
    {
        for(int i=0;i<cx;i++)
        {
            for(int j=cy-1;j>=0;j--)
            {
                if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1)
                {
                    int pi=board[i][j].pi;
                    int pj=board[i][j].pj;
                    int f=board[i][j].f;
                    if(board[i][j].twice1==false && f==-1)
                    {
                        if(board[i][j].leaf==1)
                        {
                            brd->linkmake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1]);
                        }
                        else
                        {
                            brd->linkmake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0]);
                        }

                    }
                    if(board[i][j].twice1==true)
                    {
                        int pi=board[i][j].pi;
                        int pj=board[i][j].pj;

                        if(board[i][j].leaf==1)
                        {
                            brd->linktwicemake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1]);
                        }
                        else
                        {
                            brd->linktwicemake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0]);
                        }
                    }
                }
            }
        }
    }
    if(cnt==3)
    {
        for(int i=cx-1;i>=0;i--)
        {
            for(int j=cy-1;j>=0;j--)
            {
                if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1)
                {
                    int pi=board[i][j].pi;
                    int pj=board[i][j].pj;
                    int f=board[i][j].f;
                    if(board[i][j].twice1==false && f==-1)
                    {
                        if(board[i][j].leaf==1)
                        {
                            brd->linkmake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1]);
                        }
                        else
                        {
                            brd->linkmake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0]);
                        }

                    }
                    if(board[i][j].twice1==true)
                    {
                        int pi=board[i][j].pi;
                        int pj=board[i][j].pj;

                        if(board[i][j].leaf==1)
                        {
                            brd->linktwicemake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1]);
                        }
                        else
                        {
                            brd->linktwicemake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0]);
                        }
                    }
                }
            }
        }
    }
}
void rootsearchclass::linkmake2(int param)
{
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<cy;j++)
        {
            if(board[i][j].a[0]!=-1 && board[i][j].a[1]!=-1)
            {
                int pi=board[i][j].pi;
                int pj=board[i][j].pj;
                int f=board[i][j].f;
                if(board[i][j].twice1==false && f==-1)
                {
                    linkcount++;
                    if(board[i][j].leaf==1)
                    {
                        brd->linkmake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1]);
                    }
                    else
                    {
                        brd->linkmake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0]);
                    }

                }
                if(board[i][j].twice1==true)
                {
                    linkcount++;
                    int pi=board[i][j].pi;
                    int pj=board[i][j].pj;

                    if(board[i][j].leaf==1)
                    {
                        brd->linktwicemake(0,board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1]);
                    }
                    else
                    {
                        brd->linktwicemake(0,board[i][j].a[1],board[i][j].x[1],board[i][j].y[1],board[i][j].a[0],board[i][j].x[0],board[i][j].y[0],board[pi][pj].a[1],board[pi][pj].x[1],board[pi][pj].y[1],board[pi][pj].a[0],board[pi][pj].x[0],board[pi][pj].y[0]);
                    }
                }
            }
        }
    }
}
void rootsearchclass::linkmake22(int cnt)
{
    if(brd->pairlst[cnt]->manulck==false)
    {
        brd->linkchange(cnt,brd->pairlst.size()-1);
    }
    for(int i=0;i<brd->pairlst.size()-1;i++)
    {
        for(int j=0;j<brd->pairlst.size();j++)
        {
            if(i!=j && brd->pairlst[i]->id1==brd->pairlst[j]->id2 && brd->pairlst[j]->manulck==false)
            {
                //brd->linkchange(i+1,j);
                brd->linkchange(i,j);
            }
        }

    }

}
void rootsearchclass::linkmake3()
{
    if(rootcntx>=brd->pairlst.size()){rootcntx=brd->pairlst.size()-1;}
    if(rootcnty>=brd->pairlst.size()){rootcnty=brd->pairlst.size()-1;}
    brd->linkchange(rootcnty,rootcntx);
}

void rootsearchclass::boardtouch()
{
    int max=0;
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<cy;j++)
        {
           // if(max<board[i][j]){max=board[i][j];}
        }
    }
    for(int i=0;i<cx;i++)
    {
        for(int j=0;j<cy;j++)
        {
            for(int h=0;h<brd->locklist.size();h++)
            {
                if(board[i][j].a[1]!=-1 && board[i][j].a[0]!=brd->locklist[h])
                {
                    int x=board[i][j].a[1];
                }
            }

        }

    }

}
