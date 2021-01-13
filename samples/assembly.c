#include <stdio.h>
#include <string.h>

extern int add(int i, int j);
extern void hello_world();
extern void print_it(char * stl, int len);
extern char nth_char(char * stl, int n);

int main() {
    int result = add(1, 2);
    printf("Result was %d\n", result);
    hello_world();
    char *str = "Assembly is great\n";
    print_it(str, strlen(str));
    char i = nth_char("Yay", 2);
    printf("Char is %c", i);
    return 0;
}
