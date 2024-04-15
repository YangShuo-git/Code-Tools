#include "YsArray.h"
#include <stdlib.h>

struct YsArray{
    size_t arrayLength;  // 数组的长度
    int* data;           // 数据的地址

    size_t dataNum;      // 数据的实际数量
};

YsArray* creatYsArray() 
{
    YsArray* newArray = (YsArray*)malloc(sizeof(YsArray));
    newArray->arrayLength = 10;
    newArray->dataNum = 3;
    newArray->data = (int*)malloc(sizeof(int)*10);

    return newArray;
}