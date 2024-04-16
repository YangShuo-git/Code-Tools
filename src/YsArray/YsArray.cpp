#include "YsArray.h"
#include <stdlib.h>
#include <string.h>

struct YsArray{
    size_t arrayLength;  // 数组的长度

    size_t dataNum;      // 数据的实际数量
    int* data;           // 数据的地址（指向数组的内存）
};

YsArray* creatYsArray(int arrLength) 
{
    YsArray* newArray = (YsArray*)malloc(sizeof(YsArray));
    if (newArray == NULL)
    {
        return NULL;
    }
    
    newArray->arrayLength = arrLength;
    newArray->dataNum = 0;
    // 给数组分配内存，arrLength个int大小
    newArray->data = (int*)malloc(sizeof(int)*arrLength); 
    if (newArray->data == NULL)
    {
        free(newArray);
        return NULL;
    }
    memset(newArray->data, 0, sizeof(int)*arrLength);

    return newArray;
}

bool ysArrayPushback(YsArray* arr, int data)
{
    if (arr == NULL)
    {
        return false;
    }

    // 扩容判断
    if (arr->dataNum >= arr->arrayLength)
    {
        
    }
    
    // 将数据存放YsArray中
    arr->data[arr->dataNum] = data;
    arr->dataNum++;
}