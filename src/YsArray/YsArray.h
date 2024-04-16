#ifndef _YSARRAY_H_
#define _YSARRAY_H_

#include <stdio.h>

typedef struct YsArray YsArray;

YsArray* creatYsArray(int arrLength);

bool ysArrayPushback(YsArray* arr, int data);

#endif // _YSARRAY_H_