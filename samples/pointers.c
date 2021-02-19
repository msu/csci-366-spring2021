#include <stdio.h>

int my_int_function(int *pointer_to_int);

void pass_by_value_demo();

void pointer_fun_1() {
    int i = 10;
    int *pointer_to_i = &i;

    printf("i is %u\n", i);
    printf("pointer_to_i is %u\n",
            pointer_to_i);
    printf(" value at pointer_to_i is %d\n",
            my_int_function(pointer_to_i));
    return 0;
}

void pointer_fun_2() {
    int i = 10;
    int j = 10;
    char *str = "Hello Pointers...";

    printf("i addr is %u\n", &i);
    printf("j addr is %u\n", &j);
    printf("str addr is %u\n", str);
}

int* get_addr_of_10(){
    int i = 10;
    return &i;
}

int my_int_function(int *pointer_to_int){
    return *pointer_to_int;
}

void show_array_1() {
    int int_arr[] = {1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        printf("Value: %d\n", int_arr[i]);
    }
}

void show_array_2() {
    int int_arr[4] = {0};
    for (int i = 0; i < 4; ++i) {
        printf("Value: %d\n", int_arr[i]);
    }
}

void show_array_3() {
    int int_arr[4] = {0};
    for (int i = 0; i < 4; ++i) {
        printf("Value: %d\n", int_arr[i]);
    }
}

void pointers_and_arrays() {
    int int_arr[] = {1, 2, 3};
    int *int_ptr = int_arr;
    for (int i = 0; i < 3; ++i) {
        printf("Value from arr: %d\n", int_arr[i]);
        printf("Value from ptr: %d\n", *int_ptr);
        int_ptr++;
    }
}

int update_it1(int i) {
    i = 42;
}

int update_it2(int *i) {
    *i = 42;
}

struct demo {
    int value;
};

int update_it3(struct demo s) {
    s.value = 42;
}

int update_it4(struct demo *s) {
    (*s).value = 42;
}

#include <string.h>
void strtok_example() {
    char str[] = "C is pretty crazy...";
    char *token;
    char *str_ptr = str;
    char **rest_of_str_ptr = &str;

    while ((token = strtok_r(str_ptr, " ", rest_of_str_ptr)))
        printf("%s\n", token);


}

#include <unistd.h>
#include "stdio.h"
void read_file(){
    FILE *fileDescriptor = fopen("/etc/hosts", "r");
    char buffer[100] = {0};
    while (read(fileDescriptor->_fileno, buffer, 99) > 0) {
        printf("%s", buffer);
        memset(buffer, 0, 100);
    }
    fclose(fileDescriptor);
}

int main() {
    pass_by_value_demo();

}

void pass_by_value_demo() {
    struct demo s;
    s.value = 10;
    update_it4(&s);
    printf("Value: %d\n", s.value);
}

