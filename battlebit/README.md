## battleBit: A bit-wise implementation of BattleShip

The project for CS366 is a bit-based version of [Battleship](https://en.wikipedia.org/wiki/Battleship_(game)). Rather than a 10x10 board as in the original game, battleBit will use an 8x8 board, allowing board state to be stored in a set of 64-bit integers.

### Ships & Board Specifications

A battleBit board consists of five ships:

* Carrier - 5 spaces
* Battleship - 4 spaces
* Destroyer - 3 spaces
* Submarine - 3 spaces
* PatrolBoat - 2 spaces

A battleBit board is specified as follows:

* Five triples of a letter L taken from the set [c, C, b, B, d, D, s, S, p, P] followed by two numbers between 0 and 7.  * Each letter corresponds to a ship with the same starting letter.  
* The numbers indicate the X and Y position of the start of the ship 
* A capital letter indicates that the ship is oriented horizontially, starting at the X, Y postion
* A lower case letter indicates that the ship is oriented vertically, starting at the X, Y position
* By convention, 0, 0 is the upper left position in the board, and 7,7 is the lower right
  * So the top row would consist of the positions (0, 0), (1, 0), (2, 0), ..., (7,0)

An example of a board specifications is:

  * `C00b02D23S47p71`
```
      CCCCC...
      .......P
      b......P
      b.DDD...
      b.......
      b.......
      ........
      ....SSS.
```

### Project Goals

#### Board Display

The initial goal of the project will be to display a board to a player.  The struct used to capture a players state in a game looks like this:

```c
typedef struct game_state {
    enum Status status;
    long long shots;
    long long hits;
    long long ships;
} game_state;

```

Using this information, students will need to print out an ASCII board representation that looks like this:

```
battleBit........
----[ ENEMY ]----
  0 1 2 3 4 5 6 7
0
1   H H
2
3         M
4       
5
6
7
=================
----[ SHIPS ]----
  0 1 2 3 4 5 6 7
0 * * * * *
1               *
2 *             *
3 *   * * *
4 *
5 *
6
7         * * *  
........battleBit
```

Note that as a bit is hit on a board, it flips from 1 to 0, and thus a losing board is empty.

#### Board Load & Verification

The next step in the project is loading board given the specification above into the `ships` field.  Board specifications must be verified to ensure that:

* All ship positions lie within the board boundaries
* No ships overlap

It is sufficient to report one error.

If a specification is erroneous, it should not update the `ships` board.

#### Local Gameplay Implementation

The next step in the project involves implementing local gameplay mechanics.  You are provided with a basic Read-Evaluate-Print-Loop (REPL) in `main.c` and `repl.c`.  You will need to implement the following commands:

```
? - show help
load [0-1] <string> - load a ship layout specification for the given player
show [0-1] - shows the board for the given player
say <string> - Send the string to all players as part of a chat
fire [0-1] [0-7] [0-7] - the given player fires at the given position
reset - reset the game
server - start the server
exit - quit
```

You have been provided with a helper library `char_buff.h/char_buff.c` that makes it easier to deal with strings in the project.

You can play a full, if fake, game with just a server by loading two player boards and then alternating fires between them.

#### Network Gameplay Implementation

The final step in the project is adding network functionality that allows two players to connect via `telnet` to the server and begin a game.  The server waits until two players have connected and then begins the game, coordinating responses and managing turns between the two players.

The server also supports a `say` command that allows the players to talk with one another during the game, even if it is not a given players turn.  It also allows the server command line to observe the chat as well as participate in it.  Note that this functionality requires synchronization to avoid corruption of the chat order.

The client commands are:

```
? - show help
load <string> - load a ship layout specification for the current player
show - shows the board for the current player
say <string> - Send the string to all players as part of a chat
fire [0-7] [0-7] - fire at the given position of the opponent
exit - quit the server
```

#### Grading Rubric

The grading will be mainly based on automated tests.  However, a major component of the project is network programming, which is difficult to test in an automated manner, and will require us to run and test your application manually.  Additionally, you will be required to record a demo of the application running in network mode, with a specfic set of commands.

The grading will break down like so:

* 70% automated tests
* 20% recorded demo
* 10% code quality and proper synchronization
