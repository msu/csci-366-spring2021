//
// Created by carson on 7/7/20.
//

#include "char_buff.h"
#include "stdlib.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>    //write

struct char_buff * cb_create(int size) {
    struct char_buff * char_buff = malloc(sizeof(struct char_buff));
    char_buff->buffer = malloc(sizeof(char) * (size + 1));
    char_buff->size = size;
    char_buff->buffer[char_buff->size] = '\0'; // null terminate end as well
    char_buff->buffer[0] = '\0'; // null terminate
    char_buff->append_offset = 0;
    return char_buff;
}

int cb_append(struct char_buff * buffer, const char * str) {
    long content_len = (long) strlen(str);
    char *append_point = buffer->buffer + buffer->append_offset;
    long limit = buffer->size - buffer->append_offset;
    strncpy(append_point, str, limit);
    buffer->append_offset += (content_len > limit ? limit : content_len);
}

int cb_append_int(struct char_buff * buffer, int arg) {
    char *append_point = buffer->buffer + buffer->append_offset;
    long limit = buffer->size - buffer->append_offset;
    int len = snprintf(append_point, limit, "%i", arg);
    buffer->append_offset += (len > limit ? limit : len);
}

void cb_print(struct char_buff * buffer) {
    printf("size: %li, append_offset: %li\n", buffer->size, buffer->append_offset);
    printf("string: %s\n", buffer->buffer);
}

char * cb_tokenize(struct char_buff * buffer, const char * split_on){
    buffer->tokienzed_on = split_on;
    return strtok_r(buffer->buffer, split_on, &buffer->tokenization_save_pointer);
}

char * cb_next_token(struct char_buff * buffer){
    return strtok_r(NULL, buffer->tokienzed_on, &buffer->tokenization_save_pointer);
}

void cb_free(struct char_buff * buffer) {
    free(buffer->buffer);
    free(buffer);
}

void cb_reset(struct char_buff * buffer) {
    buffer->buffer[0] = '\0'; // null terminate
    buffer->append_offset = 0;
    buffer->tokienzed_on = NULL;
    buffer->tokenization_save_pointer = NULL;
}


void cb_write(int fd, struct char_buff * buffer) {
    write(fd, buffer->buffer, strlen(buffer->buffer));
}
