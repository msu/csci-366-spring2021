#include <stdio.h>
void cast_demo() {
    int i;
    double x = 1.9;
    i = x;
    printf("i is %d", i);
}

void arr_demo() {
    int arr[] = {1, 2, 3};
    printf("Yay %i", arr[3]);
}

void arr_factorial() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int factorial = 1;
    for (int i = 0; i < 10; ++i) {
        factorial *= array[i];
    }
    printf("10! is %d.\n", factorial);
}

void if_demo() {
    int x = 0;
    if(x) {
        puts("True");
    } else {
        puts("Not true");
    }
    printf("x < 10 is %d.\n", x > 10);
}

int main() {
    if_demo();
    return 0;
}

