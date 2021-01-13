#include "gtest/gtest.h"

extern "C" {
#include "repl.h"
}

TEST(repl_print_ships, print_ships){
    game_init();
    struct game * gameon = game_get_current();
    struct char_buff *buffer = cb_create(2000);
    //cb_print(buffer);
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    struct player_info player_info = gameon->players[0];
    repl_print_ships(&player_info, buffer);
    //cb_print(buffer);
    char * expected = "  0 1 2 3 4 5 6 7 \n"
                      "0 * * * * *       \n"
                      "1               * \n"
                      "2 *             * \n"
                      "3 *   * * *       \n"
                      "4 *               \n"
                      "5 *               \n"
                      "6                 \n"
                      "7         * * *   \n";
    ASSERT_STREQ(buffer->buffer, expected);
    free(buffer);
}
TEST(repl_print_hits, print_hits){
    game_init();
    struct game * gameon = game_get_current();
    struct char_buff *buffer = cb_create(2000);
    //cb_print(buffer);
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    game_load_board(gameon, 1, spec);
    game_fire(gameon, 0, 0,0);
    struct player_info player_info = gameon->players[0];
    repl_print_hits(&player_info, buffer);
    char * expected = "  0 1 2 3 4 5 6 7 \n"
                      "0 H               \n"
                      "1                 \n"
                      "2                 \n"
                      "3                 \n"
                      "4                 \n"
                      "5                 \n"
                      "6                 \n"
                      "7                 \n";
    //cb_print(buffer);
    ASSERT_STREQ(buffer->buffer, expected);
    free(buffer);
}
TEST(repl_print_hits, print_miss){
    game_init();
    struct game * gameon = game_get_current();
    struct char_buff *buffer = cb_create(2000);
    //cb_print(buffer);
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    game_load_board(gameon, 1, spec);
    game_fire(gameon, 0, 0,7);
    struct player_info player_info = gameon->players[0];
    repl_print_hits(&player_info, buffer);
    char * expected = "  0 1 2 3 4 5 6 7 \n"
                      "0                 \n"
                      "1                 \n"
                      "2                 \n"
                      "3                 \n"
                      "4                 \n"
                      "5                 \n"
                      "6                 \n"
                      "7 M               \n";
    //cb_print(buffer);
    ASSERT_STREQ(buffer->buffer, expected);
    free(buffer);
}
TEST(repl_print_ships, print_ship_status){
    game_init();
    struct game * gameon = game_get_current();
    struct char_buff *buffer = cb_create(2000);
    //cb_print(buffer);
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    game_load_board(gameon, 1, spec);
    game_fire(gameon, 0, 6,7);
    struct player_info player_info = gameon->players[0];
    repl_print_hits(&player_info, buffer);
    player_info = gameon->players[1];
    repl_print_ships(&player_info, buffer);

    player_info.ships = 0ull<<32;
    ASSERT_EQ(0,player_info.ships);
    //cb_print(buffer);

    free(buffer);
}
