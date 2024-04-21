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

    ysArrayInsert(arr, 100, 4);
    ysArrayPrint(arr);

    ysArrayErase(arr, 5);
    ysArrayPrint(arr);

    int pos0;
    ysArrayAt(arr, 0, pos0);
    printf("pos[0]= %d\n", pos0);

    printf("end\n");
}