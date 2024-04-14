#include "YsArray.h"

int main() {
    printf("YsArray\n");

    YsArray arr = creatYsArrayTest();
    arr.arrayLength = 6; 

    printf("arrayLength = %d\n", arr.arrayLength);

}