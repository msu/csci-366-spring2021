#include <stdio.h>
#include <stdlib.h>
#include "repl.h"
#include "game.h"

int main() {
    printf("Welcome to BattleBit\n\n");
    /**
     * Step 0 - Debug this main function with a break point on the line after
     * the repl_read_command, and step through some input of the various
     * commands you are expected to implement.  Notice how we are reading
     * into a buffer and then freeing the buffer.
     */
    char_buff * command;

    game_init(); // NB: game init initializes the game state, all held in game.c

    do {
        // This is the classic Read, Evaluate, Print Loop, hence REPL
        command = repl_read_command("battleBit (? for help) > ");
        repl_execute_command(command);
        cb_free(command);
    } while (command);
    return 0;

}
