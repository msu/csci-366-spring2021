//
// Created by carson on 5/20/20.
//

#ifndef BATTLESHIP_REPL_H
#define BATTLESHIP_REPL_H

#include "game.h"
#include "char_buff.h"

struct char_buff * repl_read_command(char *prompt);

void repl_execute_command(struct char_buff *buffer);

void repl_print_board(game *state, int player, char_buff *buffer);

void repl_print_ships( player_info *player_info, char_buff *buffer);

void repl_print_hits(player_info *player_info, char_buff *buffer);

#endif //BATTLESHIP_REPL_H
