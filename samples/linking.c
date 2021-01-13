#include <stdio.h>
#include "linking.h"

int global_int = 10;
int extern_from_linking = 1;
static int static_from_linking = 10;

int main() {
    global_int = 10;
    printf("global_int: %d\n", global_int);
    printf("static_from_linking: %d\n", static_from_linking);
    printf("extern_from_linking: %d\n", extern_from_linking);

    print_linking2_data();
}

int foo() {
    return 10;
}