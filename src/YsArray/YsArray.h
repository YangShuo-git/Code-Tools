#ifndef _YSARRAY_H_
#define _YSARRAY_H_

/** 
 * 实现自动扩容的数组
 * 
**/

#include <stdio.h>

typedef struct YsArray YsArray;

YsArray* creatYsArray(int arrLength);

bool ysArrayPushback(YsArray* arr, int data);

#endif // _YSARRAY_H_