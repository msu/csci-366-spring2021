#include "stdio.h"
#include "linking.h"

//int extern_from_linking = 10;
static int static_from_linking = 20;
extern int extern_from_linking;

void print_linking2_data() {
    printf("global_int: %d\n", global_int);
    printf("static_from_linking: %d\n", static_from_linking);
    printf("extern_from_linking: %d\n", extern_from_linking);
}
