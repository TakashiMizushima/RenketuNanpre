#ifndef MEMORYCLASS_H
#define MEMORYCLASS_H
#include"boardclass.h"
#include<vector>
class memoryclass
{
public:
    memoryclass();
    ~memoryclass();
    std::vector<boardclass::CHIPDATA *> memo;
    boardclass::CHIPDATA *add();
    int lastindex;
};
#endif // MEMORYCLASS_H
