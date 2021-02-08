#include "functions.h"
#include "stdio.h"

void func_1() {
    func_2();
}

void func_2() {
    func_1();
}

void funny(int i) {
    printf("I is %d\n", i);

}

void func_3() {
    static int x = 12;
    x++;
    printf("x is %d\n", x);
}

#include "string.h"
void func_4() {
    char *str ="A Sample String";
    char * token;
    token = strtok (str, " ");
    while (token != NULL)
    {
        printf ("%s\n", token);
        token = strtok (NULL, " ");
    }
}

void func_5() {
    register int foo = 10;
    //
    // int *foo_ptr = &foo;
}

#define square(x) x*x
void func_6() {
    printf("%d", square(2 + 2));
}

int main() {
    func_6();
}