#include "gtest/gtest.h"
extern "C" {
#include "char_buff.h"
}

TEST(char_buff, bootstrap) {
    struct char_buff *buffer = cb_create(2000);
    cb_print(buffer);
    EXPECT_TRUE(strcmp(buffer->buffer, "") == 0);
    cb_append(buffer, "Foo");
    cb_print(buffer);
    EXPECT_TRUE(strcmp(buffer->buffer, "Foo") == 0);
    cb_append(buffer, "Foo");
    cb_print(buffer);
    EXPECT_TRUE(strcmp(buffer->buffer, "FooFoo") == 0);
    cb_free(buffer);
}

TEST(char_buff, noOverFlow) {
    struct char_buff *buffer = cb_create(3);
    EXPECT_TRUE(strcmp(buffer->buffer, "") == 0);
    cb_print(buffer);
    cb_append(buffer, "Foo");
    cb_print(buffer);
    EXPECT_TRUE(strcmp(buffer->buffer, "Foo") == 0);
    cb_append(buffer, "Foo");
    cb_print(buffer);
    EXPECT_TRUE(strcmp(buffer->buffer, "Foo") == 0);
    cb_free(buffer);
}

TEST(char_buff, tokenize) {
    struct char_buff *buffer = cb_create(200);
    cb_append(buffer, "Foo Bar Baz");
    EXPECT_TRUE(strcmp(cb_tokenize(buffer, " "), "Foo") == 0);
    EXPECT_TRUE(strcmp(cb_next_token(buffer), "Bar") == 0);
    EXPECT_TRUE(strcmp(cb_next_token(buffer), "Baz") == 0);
    cb_free(buffer);
}


