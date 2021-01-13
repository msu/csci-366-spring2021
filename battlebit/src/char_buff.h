//
// Created by carson on 7/7/20.
//

#ifndef BATTLESHIP_CHAR_BUFF_H
#define BATTLESHIP_CHAR_BUFF_H

typedef struct char_buff {
    char * buffer;
    long append_offset;
    long size;
    char * tokenization_save_pointer;
    const char *tokienzed_on;
} char_buff;

struct char_buff * cb_create(int size);

int cb_append(char_buff * buffer, const char * str);

int cb_append_int(char_buff * buffer, int arg);

void cb_print(char_buff * buffer);

char * cb_tokenize(char_buff * buffer, const char * split_on);

char * cb_next_token(char_buff * buffer);

void cb_free(char_buff * buffer);

void cb_reset(char_buff * buffer);

void cb_write(int fd, char_buff * buffer);

#endif //BATTLESHIP_CHAR_BUFF_H
