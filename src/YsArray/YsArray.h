#ifndef _YSARRAY_H_
#define _YSARRAY_H_

#include <stdio.h>

typedef struct YsArray
{
    size_t arrayLength;  // 数组的长度
    int* data;           // 数据的地址

    size_t dataNum;      // 数据的实际数量
}YsArray;

YsArray* creatYsArray();
YsArray creatYsArrayTest();


#endif // _YSARRAY_H_