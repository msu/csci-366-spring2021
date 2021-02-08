#include "gtest/gtest.h"

extern "C" {
#include "game.h"
#include "helper.h"
}

TEST(xy_to_bitval, good_values) {
    // row 1
    EXPECT_EQ(xy_to_bitval(0, 0), 1ull);
    EXPECT_EQ(xy_to_bitval(1, 0), 2ull);
    EXPECT_EQ(xy_to_bitval(2, 0), 4ull);
    EXPECT_EQ(xy_to_bitval(3, 0), 8ull);
    EXPECT_EQ(xy_to_bitval(4, 0), 16ull);
    EXPECT_EQ(xy_to_bitval(5, 0), 32ull);
    EXPECT_EQ(xy_to_bitval(6, 0), 64ull);
    EXPECT_EQ(xy_to_bitval(7, 0), 128ull);

    // row 2
    EXPECT_EQ(xy_to_bitval(0, 1), 256ull);
    EXPECT_EQ(xy_to_bitval(1, 1), 512ull);
    EXPECT_EQ(xy_to_bitval(2, 1), 1024ull);
    EXPECT_EQ(xy_to_bitval(3, 1), 2048ull);
    EXPECT_EQ(xy_to_bitval(4, 1), 4096ull);
    EXPECT_EQ(xy_to_bitval(5, 1), 8192ull);
    EXPECT_EQ(xy_to_bitval(6, 1), 16384ull);
    EXPECT_EQ(xy_to_bitval(7, 1), 32768ull);

    // start of row 7
    EXPECT_EQ(xy_to_bitval(0, 7), 1ull << 56ull);

    // end of row 7
    EXPECT_EQ(xy_to_bitval(7, 7), 1ull << 63ull);
}

TEST(xy_to_bitval, bad_values) {
    EXPECT_EQ(xy_to_bitval(0, 8), 0);
    EXPECT_EQ(xy_to_bitval(8, 0), 0);
    EXPECT_EQ(xy_to_bitval(-1, 0), 0);
    EXPECT_EQ(xy_to_bitval(0, -1), 0);
}

TEST(add_ship_horizontal,empty_ship){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    game_init_player_info(player_info);
    //char * spec = "C00b02D23S47p71";
    //game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(add_ship_horizontal(player_info,1,8,0),1);
}
TEST(add_ship_horizontal,load_ship){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    game_init_player_info(player_info);
    //char * spec = "C00b02D23S47p71";
    //game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(add_ship_horizontal(player_info,0,0,5),1); // C-> length = 5
    ASSERT_EQ(add_ship_horizontal(player_info,4,0,4),-1); //overlapping ship B-> length = 4
}
TEST(add_ship_vertical,empty_ship){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    game_init_player_info(player_info);
    //char * spec = "C00b02D23S47p71";
    //game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(add_ship_vertical(player_info,1,8,0),1);
}
TEST(add_ship_vertical,load_ship){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    game_init_player_info(player_info);
    //char * spec = "C00b02D23S47p71";
    //game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(add_ship_vertical(player_info,0,0,5),1); // C-> length = 5
    ASSERT_EQ(add_ship_vertical(player_info,0,4,4),-1); //overlapping ship B-> length = 4
}
TEST(game_load_board,empty_spec){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    //game_init_player_info(player_info);
    //char * spec = "C00b02D23S47p71";
    //game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(game_load_board(gameon,0,NULL),-1);
}
TEST(game_load_board,incomplete_spec){
    game_init();
    struct game * gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    //game_init_player_info(player_info);
    char * spec = "C00b02D23S47";//incomplete spec
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C-1-1b02D23S47p71";//invalid spec
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "A00b02D23S47p71";//invalid spec
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00c02D23S47p71";//invalid spec- Multiple carriers
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "B00b02D23S47p71";//invalid spec- Multiple batleships
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00b02D23S47d71";//invalid spec- Multiple destroyers
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00b02D23S47s71";//invalid spec- Multiple ships
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00P02D23S47p71";//invalid spec- Multiple patrol boats
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C60P02D23S47p71";//invalid spec- horizontal out of bound
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00b02D23S47p77";//invalid spec- vertical out of bound
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00b02D30S47p71";//invalid spec- horizontal Overlaps
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
    spec = "C00b02D23S47p01";//invalid spec- vertical Overlaps
    ASSERT_EQ(game_load_board(gameon,0,spec),-1);
}
TEST(game_load_board,valid_spec) {
    game_init();
    struct game *gameon = game_get_current();
    struct player_info *player_info = &gameon->players[0];
    //game_init_player_info(player_info);
    char *spec = "C00b02D23S47p71";
    ASSERT_EQ(game_load_board(gameon, 0, spec), 1);
}