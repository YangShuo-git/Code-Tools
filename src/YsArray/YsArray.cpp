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

    // 扩容操作
    if (arr->dataNum >= arr->arrayLength)
    {
        // 1、分配新的内存
        size_t newArrayLength = arr->arrayLength * 1.5;
        int* newData = (int*)malloc(newArrayLength * sizeof(int));
        if (newData == NULL)
        {
            return false;
        }

        // 2、将数组指向的旧数据拷贝到新的内存里面去，并释放旧的内存
        memcpy(newData, arr->data, arr->dataNum * sizeof(int));
        free(arr->data);

        // 3、数组指针指向新的地址，并更新数组长度
        arr->data = newData;
        arr->arrayLength = newArrayLength;
    }
    
    // 将数据存放YsArray中
    arr->data[arr->dataNum] = data;
    arr->dataNum++;
}

// 数组元素的删除只需数据量减1即可，内存还在；
// 链表元素的删除需要把内存释放；
bool ysArrayPop(YsArray* arr)
{
    if (arr == NULL)
    {
        return false;
    }
    if (arr->dataNum != 0)
    {
        arr->dataNum--;
    }
}

void ysArrayPrint(YsArray* arr)
{
    if (arr == NULL)
    {
        return;
    }

    for (int i = 0; i < arr->dataNum; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");    
}
