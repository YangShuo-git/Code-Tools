#include "YsArray.h"
#include <stdlib.h>

YsArray creatYsArrayTest() 
{
    YsArray newArray;
    newArray.arrayLength = 10;
    newArray.dataNum = 3;
    newArray.data = NULL;

    return newArray;
}

YsArray* creatYsArray() 
{
    YsArray* newArray = (YsArray*)malloc(sizeof(YsArray));
    newArray->arrayLength = 10;
    newArray->dataNum = 3;
    newArray->data = (int*)malloc(sizeof(int)*10);

    return newArray;
}