#include"memoryclass.h"
boardclass::CHIPDATA *memoryclass::add()
{
    boardclass::CHIPDATA *m=new boardclass::CHIPDATA;
    lastindex++;
    m->num=0;
    memo.push_back(m);
    return memo[memo.size()-1];
}
memoryclass::memoryclass()
{
    lastindex=-1;
}
memoryclass::~memoryclass()
{
    for(int i=0;i<memo.size();i++)
    {
        delete memo[i];
    }
    memo.clear();
}
