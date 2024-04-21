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
    if (arr == NULL) return false;

    // 实际的数据量大于等于数组长度，就需要扩容
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
    if (arr == NULL) return false;

    if (arr->dataNum != 0)
    {
        arr->dataNum--;
    }
}

void ysArrayPrint(YsArray* arr)
{
    if (arr == NULL) return;

    for (int i = 0; i < arr->dataNum; i++)
    {
        printf("%d ", arr->data[i]);
    }
    printf("\n");    
}

bool ysArrayInsert(YsArray* arr, int data, int pos)
{
    if (arr == NULL) return false;
    if (pos < 0 || pos > arr->arrayLength-1) return false;

    if (pos == arr->arrayLength)
    {
        return ysArrayPushback(arr, data);
    }

    // 是否需要扩容
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

    // 开始移位 从尾部一个一个移位，所以数组插入元素效率低
    for (int i = arr->arrayLength-1; i >= pos; i--)
    {
        arr->data[i+1] = arr->data[i];
    }
    arr->data[pos] = data;
    arr->dataNum++;

    return true;    
}


bool ysArrayErase(YsArray* arr, int pos)
{
    if (arr == NULL) return false;
    if (pos < 0 || pos > arr->arrayLength-1) return false;

    for (int i = pos; i < arr->dataNum-1; i++)
    {
        arr->data[i] = arr->data[i+1];   
    }
    
    arr->dataNum--;

    return true;
}

// 不采取以下写法的原因：如果存放的数据就是-1呢？
int ysArrayAt(YsArray* arr, int pos)
{
    if (arr == NULL) return -1;
    if (pos < 0 || pos > arr->arrayLength-1) return -1;

    return arr->data[pos];
}

// 遇到返回值是数值型的情况，可以用形参接收
// 比如这里的int* data
bool ysArrayAt(YsArray* arr, int pos, int& data)
{
    if (arr == NULL) return false;
    if (pos < 0 || pos > arr->arrayLength-1) return false;
    
    data = arr->data[pos];

    return true;
}

