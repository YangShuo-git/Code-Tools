#include "YsArray.h"

int main() {
    printf("YsArray\n");

    YsArray* arr = creatYsArray(10);

    for (size_t i = 0; i < 10; i++)
    {
        ysArrayPushback(arr, i*10);
    }

    printf("end\n");
}