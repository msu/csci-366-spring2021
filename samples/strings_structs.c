#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void string_ptr_fun_1() {
    char *str = "Hello, Strings!";
    for (int i = 0; i < 15; ++i) {
        printf("Char at %d is %c\n", i, *str);
        str++;
    }
}

void string_ptr_fun_2() {
    char *str = "Hello, Strings!";
    for (int i = 0; i < 16; ++i) {
        printf("Char at %d is %d\n", i, *(str + i));
    }
}

void string_ptr_fun_3() {
    char *str = "Hello, Strings!";
    *(str + 15) = 'a';
    printf(str);
}

void string_functions() {
    char buff[100];

    strcpy(buff, "Hello strcpy");
    printf("String is '%s'\n", buff);

    strcat(buff, " & strcat");
    printf("String is '%s'\n", buff);

    printf("String length is '%lu'\n", strlen(buff));

    printf("strcmp '%d'\n", strcmp(buff, "Hello strcpy & strcat"));

    printf("strcmp '%d'\n", strcmp(buff, "Hello strncpy & strncat"));

    char * str = strchr(buff, '&');
    printf("str is '%s'\n", str);

    str = strstr(buff, "strcpy");
    printf("str is '%s'\n", str);


}

void string_ptr_fun_4() {
    char *str = "Hello, Strings!";
    char *str_on_heap = malloc(16 * sizeof(char));
    strcpy(str_on_heap, str);
    printf(str_on_heap);
}

void buffer_overflow(){
    char buff[15];
    int pass = 0;

    printf("\n Enter the password : \n");
    gets(buff);

    if(strcmp(buff, "thegeekstuff"))
    {
        printf ("\n Wrong Password \n");
    }
    else
    {
        printf ("\n Correct Password \n");
        pass = 1;
    }

    if(pass)
    {
        /* Now Give root or admin rights to user*/
        printf ("\n Root privileges given to the user \n");
    }
}

typedef struct Book {
    char  title[10];
    char  author[50];
    char  subject[100];
    int   book_id;
} Book;

void fun_with_structs() {

    Book bk;
    strcpy(bk.title, "Fun with C");
    printf("Title: %s\n", bk.title);

    printf("Author: %s\n", bk.author);
    strcpy(bk.title, "Fun with C, SRS FUN");
    printf("Title: %s\n", bk.title);
    printf("Author: %s\n", bk.author);
}

void bk_print_title(Book *book){
    printf("Title: %s\n", book->title);
}

void fun_with_structs2() {
    Book bk;
    strcpy(bk.title, "Fun with C");
    bk_print_title(&bk);
}


int main() {
    fun_with_structs();
}
