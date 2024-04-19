#ifndef _YSARRAY_H_
#define _YSARRAY_H_

/** 
 * 实现自动扩容的数组
 * 
**/

#include <stdio.h>

typedef struct YsArray YsArray;

// 创建动态数组
YsArray* creatYsArray(int arrLength);

// 尾部添加数据
bool ysArrayPushback(YsArray* arr, int data);

// 尾部删除数据
bool ysArrayPop(YsArray* arr);

// 打印数据
void ysArrayPrint(YsArray* arr);

#endif // _YSARRAY_H_