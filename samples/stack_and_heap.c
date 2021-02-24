#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void recursive_func(int i) {
    printf("i is %d\n", i);
    int *i_address = &i;
    printf("i address is %u\n", i_address);
    if (i > 0) {
        recursive_func(i - 1);
    } else {
        printf("i is %d\n", i);
        printf("i address is %u\n", i_address);
    }
}

void stack_overflow(int i) {
    printf("i is %d\n", i);
    int *i_address = &i;
    int buff[i];
    printf("i address is %u\n", i_address);
    if (i_address > 0) {
        stack_overflow(i + 1);
    } else {
        printf("i is %d\n", i);
        printf("i address is %u\n", i_address);
    }
}

char * malloc_free_example(int size) {
    char *static_string = "Hello, Malloc";
    printf("static_string address is %u\n", &static_string);
    char *str_buff = malloc(size * (sizeof(char)));
    printf("str_buff address is %u\n", &str_buff);
    strcpy(str_buff, static_string);
    printf("%s", str_buff);
    return str_buff;
}

void malloc_underallocate_free_example() {
    char *static_string = "Hello, Malloc";
    printf("static_string address is %u\n", &static_string);
    char *str_buff = malloc(3 * (sizeof(char)));
    printf("str_buff address is %u\n", &str_buff);
    strcpy(str_buff, static_string);
    printf("%s", str_buff);
    free(str_buff);
}

void double_free_example() {
    char *static_string = "Hello, Malloc";
    printf("static_string address is %u\n", &static_string);
    char *str_buff = malloc(15 * (sizeof(char)));
    printf("str_buff address is %u\n", &str_buff);
    strcpy(str_buff, static_string);
    printf("%s", str_buff);
    free(str_buff);
    free(str_buff);
}

void no_free_example() {
    char *static_string = "Hello, Malloc";
    printf("static_string address is %u\n", &static_string);
    char *str_buff = malloc(15 * (sizeof(char)));
    printf("str_buff address is %u\n", &str_buff);
    strcpy(str_buff, static_string);
    printf("%s", str_buff);
    no_free_example();
}

char * calloc_example() {
    char *static_string = "Hello, Calloc";
    printf("static_string address is %u\n", &static_string);
    char *str_buff = calloc(16, (sizeof(char)));
    printf("str_buff address is %u\n", &str_buff);
    strcpy(str_buff, static_string);
    printf("%s\n", str_buff);
    return str_buff;
}

void memset_example() {

    char *static_string = "Hello, Malloc";
    char *str_buff = malloc(16 * (sizeof(char)));
    memset(str_buff, 0, 16 * sizeof(char));
    strcpy(str_buff, static_string);
    printf("%s\n", str_buff);
    free(str_buff);

}

void brk_fun() {
    // get the current pointer of the break
    void *initial_location = sbrk(0);

    unsigned int *memoryLocation = (unsigned int *)initial_location;

    /* Allocate two more memory locations */
    brk(memoryLocation + 2 );

    /* Use the ints. */
    *memoryLocation = 1;
    printf("p address: %u\n", memoryLocation);
    printf("p points to %d\n", *memoryLocation);

    *(memoryLocation + 1) = 2;
    printf("p + 1 address: %u\n", (memoryLocation + 1));
    printf("p + 1 points to %d\n", *(memoryLocation + 1));

    /* Deallocate back. */
    brk(initial_location);
}


int main() {
    stack_overflow(1);
    return 0;
}