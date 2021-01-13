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

TEST(game_fire,empty_game){
    game_init();
    struct game * gameon = game_get_current();
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(game_fire(gameon,1,0,0),0);
}

TEST(game_fire,hit_fire){
    game_init();
    struct game * gameon = game_get_current();
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(game_fire(gameon,1,0,0),1);
    ASSERT_EQ(game_fire(gameon,1,1,0),1);
    ASSERT_EQ(game_fire(gameon,1,2,0),1);
    ASSERT_EQ(game_fire(gameon,1,3,0),1);
    ASSERT_EQ(game_fire(gameon,1,4,0),1);
    ASSERT_EQ(game_fire(gameon,1,7,1),1);
    ASSERT_EQ(game_fire(gameon,1,0,2),1);
    ASSERT_EQ(game_fire(gameon,1,7,2),1);
    ASSERT_EQ(game_fire(gameon,1,0,3),1);
    ASSERT_EQ(game_fire(gameon,1,2,3),1);
    ASSERT_EQ(game_fire(gameon,1,3,3),1);
    ASSERT_EQ(game_fire(gameon,1,4,3),1);
    ASSERT_EQ(game_fire(gameon,1,0,4),1);
    ASSERT_EQ(game_fire(gameon,1,0,5),1);
    ASSERT_EQ(game_fire(gameon,1,5,7),1);
    ASSERT_EQ(game_fire(gameon,1,6,7),1);
    ASSERT_EQ(game_fire(gameon,1,4,7),1);
}

TEST(game_fire,hit_fire2){
    game_init();
    struct game * gameon = game_get_current();
    char *     spec = "c00B07d23s75P61";
    game_load_board(gameon, 1, spec);
    ASSERT_EQ(game_fire(gameon,0,0,0),1);
    ASSERT_EQ(game_fire(gameon,0,0,1),1);
    ASSERT_EQ(game_fire(gameon,0,0,2),1);
    ASSERT_EQ(game_fire(gameon,0,0,3),1);
    ASSERT_EQ(game_fire(gameon,0,0,4),1);
    ASSERT_EQ(game_fire(gameon,0,0,7),1);
    ASSERT_EQ(game_fire(gameon,0,1,7),1);
    ASSERT_EQ(game_fire(gameon,0,2,7),1);
    ASSERT_EQ(game_fire(gameon,0,3,7),1);
    ASSERT_EQ(game_fire(gameon,0,2,3),1);
    ASSERT_EQ(game_fire(gameon,0,2,4),1);
    ASSERT_EQ(game_fire(gameon,0,2,5),1);
    ASSERT_EQ(game_fire(gameon,0,7,5),1);
    ASSERT_EQ(game_fire(gameon,0,7,6),1);
    ASSERT_EQ(game_fire(gameon,0,7,7),1);
    ASSERT_EQ(game_fire(gameon,0,6,1),1);
    ASSERT_EQ(game_fire(gameon,0,7,1),1);
}

TEST(game_fire,miss_fire){
    game_init();
    struct game * gameon = game_get_current();
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(game_fire(gameon,1,5,0),0);
    ASSERT_EQ(game_fire(gameon,1,6,0),0);
    ASSERT_EQ(game_fire(gameon,1,7,0),0);
    ASSERT_EQ(game_fire(gameon,1,0,1),0);
    ASSERT_EQ(game_fire(gameon,1,1,1),0);
    ASSERT_EQ(game_fire(gameon,1,2,1),0);
    ASSERT_EQ(game_fire(gameon,1,3,1),0);
    ASSERT_EQ(game_fire(gameon,1,4,1),0);
    ASSERT_EQ(game_fire(gameon,1,5,1),0);
    ASSERT_EQ(game_fire(gameon,1,6,1),0);
    ASSERT_EQ(game_fire(gameon,1,1,2),0);
    ASSERT_EQ(game_fire(gameon,1,2,2),0);
    ASSERT_EQ(game_fire(gameon,1,3,2),0);
    ASSERT_EQ(game_fire(gameon,1,4,2),0);
    ASSERT_EQ(game_fire(gameon,1,5,2),0);
    ASSERT_EQ(game_fire(gameon,1,6,2),0);
    ASSERT_EQ(game_fire(gameon,1,1,3),0);
    ASSERT_EQ(game_fire(gameon,1,5,3),0);
    ASSERT_EQ(game_fire(gameon,1,6,3),0);
    ASSERT_EQ(game_fire(gameon,1,7,3),0);
    ASSERT_EQ(game_fire(gameon,1,1,4),0);
    ASSERT_EQ(game_fire(gameon,1,2,4),0);
    ASSERT_EQ(game_fire(gameon,1,3,4),0);
    ASSERT_EQ(game_fire(gameon,1,4,4),0);
    ASSERT_EQ(game_fire(gameon,1,5,4),0);
    ASSERT_EQ(game_fire(gameon,1,6,4),0);
    ASSERT_EQ(game_fire(gameon,1,7,4),0);
    ASSERT_EQ(game_fire(gameon,1,1,5),0);
    ASSERT_EQ(game_fire(gameon,1,2,5),0);
    ASSERT_EQ(game_fire(gameon,1,3,5),0);
    ASSERT_EQ(game_fire(gameon,1,4,5),0);
    ASSERT_EQ(game_fire(gameon,1,5,5),0);
    ASSERT_EQ(game_fire(gameon,1,6,5),0);
    ASSERT_EQ(game_fire(gameon,1,7,5),0);
    ASSERT_EQ(game_fire(gameon,1,0,6),0);
    ASSERT_EQ(game_fire(gameon,1,1,6),0);
    ASSERT_EQ(game_fire(gameon,1,2,6),0);
    ASSERT_EQ(game_fire(gameon,1,3,6),0);
    ASSERT_EQ(game_fire(gameon,1,4,6),0);
    ASSERT_EQ(game_fire(gameon,1,5,6),0);
    ASSERT_EQ(game_fire(gameon,1,6,6),0);
    ASSERT_EQ(game_fire(gameon,1,7,6),0);
    ASSERT_EQ(game_fire(gameon,1,0,7),0);
    ASSERT_EQ(game_fire(gameon,1,1,7),0);
    ASSERT_EQ(game_fire(gameon,1,2,7),0);
    ASSERT_EQ(game_fire(gameon,1,3,7),0);
    ASSERT_EQ(game_fire(gameon,1,7,7),0);
}

TEST(game_fire,miss_fire2){
    game_init();
    struct game * gameon = game_get_current();
    char * spec = "c00B07d23s75P61";
    game_load_board(gameon, 1, spec);
    helper_print_ull(gameon->players[1].ships);
    ASSERT_EQ(game_fire(gameon,0,1,0),0);
    ASSERT_EQ(game_fire(gameon,0,2,0),0);
    ASSERT_EQ(game_fire(gameon,0,3,0),0);
    ASSERT_EQ(game_fire(gameon,0,4,0),0);
    ASSERT_EQ(game_fire(gameon,0,5,0),0);
    ASSERT_EQ(game_fire(gameon,0,6,0),0);
    ASSERT_EQ(game_fire(gameon,0,7,0),0);
    ASSERT_EQ(game_fire(gameon,0,1,1),0);
    ASSERT_EQ(game_fire(gameon,0,2,1),0);
    ASSERT_EQ(game_fire(gameon,0,3,1),0);
    ASSERT_EQ(game_fire(gameon,0,4,1),0);
    ASSERT_EQ(game_fire(gameon,0,5,1),0);
    ASSERT_EQ(game_fire(gameon,0,1,2),0);
    ASSERT_EQ(game_fire(gameon,0,2,2),0);
    ASSERT_EQ(game_fire(gameon,0,3,2),0);
    ASSERT_EQ(game_fire(gameon,0,4,2),0);
    ASSERT_EQ(game_fire(gameon,0,5,2),0);
    ASSERT_EQ(game_fire(gameon,0,6,2),0);
    ASSERT_EQ(game_fire(gameon,0,7,2),0);
    ASSERT_EQ(game_fire(gameon,0,1,3),0);
    ASSERT_EQ(game_fire(gameon,0,3,3),0);
    ASSERT_EQ(game_fire(gameon,0,4,3),0);
    ASSERT_EQ(game_fire(gameon,0,5,3),0);
    ASSERT_EQ(game_fire(gameon,0,6,3),0);
    ASSERT_EQ(game_fire(gameon,0,7,3),0);
    ASSERT_EQ(game_fire(gameon,0,1,4),0);
    ASSERT_EQ(game_fire(gameon,0,3,4),0);
    ASSERT_EQ(game_fire(gameon,0,4,4),0);
    ASSERT_EQ(game_fire(gameon,0,5,4),0);
    ASSERT_EQ(game_fire(gameon,0,6,4),0);
    ASSERT_EQ(game_fire(gameon,0,7,4),0);
    ASSERT_EQ(game_fire(gameon,0,0,5),0);
    ASSERT_EQ(game_fire(gameon,0,1,5),0);
    ASSERT_EQ(game_fire(gameon,0,3,5),0);
    ASSERT_EQ(game_fire(gameon,0,4,5),0);
    ASSERT_EQ(game_fire(gameon,0,5,5),0);
    ASSERT_EQ(game_fire(gameon,0,6,5),0);
    ASSERT_EQ(game_fire(gameon,0,0,6),0);
    ASSERT_EQ(game_fire(gameon,0,1,6),0);
    ASSERT_EQ(game_fire(gameon,0,2,6),0);
    ASSERT_EQ(game_fire(gameon,0,3,6),0);
    ASSERT_EQ(game_fire(gameon,0,4,6),0);
    ASSERT_EQ(game_fire(gameon,0,5,6),0);
    ASSERT_EQ(game_fire(gameon,0,6,6),0);
    ASSERT_EQ(game_fire(gameon,0,4,7),0);
    ASSERT_EQ(game_fire(gameon,0,5,7),0);
    ASSERT_EQ(game_fire(gameon,0,6,7),0);
}

TEST(game_fire,invalid_fire){
    game_init();
    struct game * gameon = game_get_current();
    char * spec = "C00b02D23S47p71";
    game_load_board(gameon, 0, spec);
    //EXPECT_TRUE(strcmp("Baz", "Baz") == 0);
    ASSERT_EQ(game_fire(gameon,1,8,0),0);
    ASSERT_EQ(game_fire(gameon,1,0,8),0);
    ASSERT_EQ(game_fire(gameon,1,0,-1),0);
    ASSERT_EQ(game_fire(gameon,1,-1,0),0);
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
TEST(game_status, is_correct) {
    game_init();
    game *pGame = game_get_current();
    ASSERT_EQ(CREATED, pGame->status);
    char *spec = "C00b02D23S47p71";

    // player 0 set, still in CREATED STATE
    ASSERT_EQ(game_load_board(pGame, 0, spec), 1);
    ASSERT_EQ(CREATED, pGame->status);

    // player 1 set, now in PLAYER_0_TURN
    ASSERT_EQ(game_load_board(pGame, 1, spec), 1);
    ASSERT_EQ(PLAYER_0_TURN, pGame->status);

    // player 0 fires, now PLAYER_1_TURN
    ASSERT_EQ(game_fire(pGame,0,0,0),1);
    ASSERT_EQ(PLAYER_1_TURN, pGame->status);

    player_info *player0 = &pGame->players[0];
    player0->ships = 1ull; // set ships to only in (1, 1)

    // player 1 shoots at (1, 1)
    ASSERT_EQ(game_fire(pGame,1,0,0),1);

    // no ships left for player 0, player 1 wins
    ASSERT_EQ(PLAYER_1_WINS, pGame->status);
}
