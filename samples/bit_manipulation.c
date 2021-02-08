#include <stdio.h>
void print_binary_short(unsigned short num);
void print_binary_int(unsigned int num);

void syntax_demo() {

    // variable declaration
    unsigned long long my_unsigned_int_64 = 0;

    // literal
    my_unsigned_int_64 = 1ull;
}

void not_demo() {
    print_binary_short(1);
    print_binary_short(~1);
    printf("%d\n", ~1);

    print_binary_short(42);
    print_binary_short(~42);
}

void and_demo() {
    print_binary_short(12);
    print_binary_short(6);
    print_binary_short(12 & 6);
    printf("%d\n", 12 & 6);
}

void or_demo() {
    print_binary_short(12);
    print_binary_short(6);
    print_binary_short(12 | 6);
    printf("%d\n", 12 | 6);
}

void xor_demo() {
    print_binary_short(12);
    print_binary_short(6);
    print_binary_short(12 ^ 6);
    printf("%d\n", 12 ^ 6);
}

void bitshift_demo() {
    unsigned int mask = 1;
    for (int i = 0; i < 32; ++i) {
        printf("%d - ", i);
        print_binary_int(mask);
        mask = mask << 1u;
    }
}

void demo_bitshift_plus_and() {
    unsigned int value = 1023;
    unsigned int n = 10;
    unsigned int mask = 1u << n;
    print_binary_int(value);
    print_binary_int(mask);
    print_binary_int(mask & value);
    if (mask & value) {
        printf("Yep! That bit was 1\n");
    }
}

void demo_bitshift_plus_or() {
    unsigned int value = 1023;
    unsigned int n = 10;
    unsigned int mask = 1u << n;
    print_binary_int(value);
    print_binary_int(mask);
    value = value | mask;
    print_binary_int(value);
}

void demo_bitshift_plus_not() {
    unsigned int value = 1025;
    unsigned int n = 10;
    unsigned int mask = ~(1u << n);
    print_binary_int(value);
    print_binary_int(mask);
    value = value & mask;
    print_binary_int(value);
}

int main() {
    demo_bitshift_plus_not();

    //bitshift_demo();
    return 0;
}


































































