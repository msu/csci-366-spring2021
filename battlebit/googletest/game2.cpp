#include "gtest/gtest.h"

extern "C" {
#include "game.h"
#include "helper.h"
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
