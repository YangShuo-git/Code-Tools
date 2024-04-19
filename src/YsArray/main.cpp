#include "YsArray.h"

int main() {
    printf("YsArray\n");

    YsArray* arr = creatYsArray(10);

    for (size_t i = 0; i < 12; i++)
    {
        ysArrayPushback(arr, i);
    }

    ysArrayPrint(arr);

    ysArrayPop(arr);
    ysArrayPop(arr);
    ysArrayPrint(arr);

    printf("end\n");
}