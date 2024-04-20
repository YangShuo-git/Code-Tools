#ifndef _YSARRAY_H_
#define _YSARRAY_H_

/** 
 * 实现动态数组
 * 1、支持扩容
 * 2、支持尾部数据的增删
 * 3、支持中间数据的插入与删除
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

// 插入数据
bool ysArrayInsert(YsArray* arr, int data, int pos);

// 删除数据
bool ysArrayErase(YsArray* arr, int pos);

#endif // _YSARRAY_H_