# Demo Script

Below is the script and expected behavior of battleBit.  You are expected to record a video and upload it to Youtube or
another alternative.  If you do not have any screen recording experience, [OBS](https://obsproject.com/) is a cross
platform screen recording software package that can be used.

## Steps

1. ### Server Startup
    1. Open three terminals in the following configuration: 
    ```
    |------------------|----------------|
    |                  |   TERMINAL 2   |
    |   TERMINAL 1     |----------------|
    |                  |   TERMINAL 3   |
    |------------------|----------------|
    ```
    1. Terminal 1 will be used to launch battleBit, which can be found in `/battlbit/cmake-build-debug/battleBit`
       and which should present you with the following command line options:
       ```shell script
        /home/carson/CLionProjects/battleship/cmake-build-debug/battleBit
        Welcome to BattleBit
        
        battleBit (? for help) >
       ```
    1. From the command prompt, run the `server` command, which should start the server listening on port
       9876
    1. Terminal 2 will be used to connect as Player 0, using the following command:
       ```
       telnet localhost 9876
       ```
       When a player connects through this manner, the server should show the following prompt:
       ```shell script
        Trying 0.0.0.0...
        Connected to 0.0.0.0.
        Escape character is '^]'.
        Welcome to the battleBit server Player 0
        battleBit (? for help) > 
       ```
    1. Run the `?` command, which should show the following output
        ```shell script
        battleBit (? for help) > ?
        ? - show help
        load <string> - load a ship layout
        show - shows the board 
        fire [0-7] [0-7] - fires at the given position
        say <string> - Send the string to all players as part of a chat
        exit
        battleBit (? for help) > 
        ```
1. ### Game Play Demo
    1. ##### Player 0 Out Of Order Fire
        Player 0 should try to fire before Player 1 has connected, and see the following output
        ```shell script
        battleBit (? for help) > fire 1 1
        Game Has Not Begun!
        battleBit (? for help) > 
        ```
    1. ##### Player 0 Board Load
        Player 0 should then load the following configuration:
        ```shell script
        battleBit (? for help) > load C00b02D23S47p71
        Waiting On Player 1
        battleBit (? for help) > 
        ```
    1. ##### Player 1 Connect
       In Terminal 3, Player 1 should connect:
       ```shell script
        $ telnet localhost 9876
        Trying 0.0.0.0...
        Connected to 0.0.0.0.
        Escape character is '^]'.
        Welcome to the battleBit server Player 1
        battleBit (? for help) > 
       ```
    1. ##### Player 1 Board Load
       Player 1 should then load the following configuration:
       ```shell script
        battleBit (? for help) > load C07B00d23s61p72
        All Player Boards Loaded
        Player 0 Turn
        battleBit (? for help) > 
        ```
    1. ##### Player 1 Out Of Order Fire
        Player 0 should try to fire, and see the following output
        ```shell script
        battleBit (? for help) > fire 1 1
        Player 0 Turn
        battleBit (? for help) > 
        ```
    1. ##### Player 1 Talk Functionality
        Player 1 should use the `say` command to encourage Player 0 to fire
        ```shell script
        battleBit (? for help) > say Please fire
        battleBit (? for help) > 
        ```    
       Player 0 and the server (Terminal 1) should see the following:
        ```shell script
        battleBit (? for help) >
        Player 1 says: Please fire
        battleBit (? for help) > 
        ```    
    1. ##### Firing In Sequence
        Player 0 and Player 1 should make the following shots in squence:
        1. Player 0: `fire 0 0` - Should show `Player 0 fires at 0 0 - HIT` on all terminals
        1. Player 1: `fire 1 1` - Should show `Player 1 fires at 1 1 - MISS` on all terminals
        1. Player 0: `fire 7 7` - Should show `Player 0 fires at 1 1 - MISS` on all terminals
        1. Player 1: `fire 0 3` - Should show `Player 1 fires at 0 3 - HIT` on all terminals
    1. ##### Player 0 board state
        In terminal 2, run the show command to show the Player 0's board, which should show the following
        output
        ```shell script
                battleBit (? for help) > show
                battleBit.........
                -----[ ENEMY ]----
                  0 1 2 3 4 5 6 7 
                0 H               
                1                 
                2                 
                3                 
                4                 
                5                 
                6                 
                7               M 
                ==================
                -----[ SHIPS ]----
                  0 1 2 3 4 5 6 7 
                0 * * * * *       
                1               * 
                2 *             * 
                3     * * *       
                4 *               
                5 *               
                6                 
                7         * * *   
                .........battleBit
        ```
    1. ##### Player 1 board state
        In terminal 3, run the show command to show the Player 1's board, which should show the following
        output
        ```shell script
                battleBit (? for help) > show
                battleBit.........
                -----[ ENEMY ]----
                  0 1 2 3 4 5 6 7 
                0                 
                1   M             
                2                 
                3 H               
                4                 
                5                 
                6                 
                7                 
                ==================
                -----[ SHIPS ]----
                  0 1 2 3 4 5 6 7 
                0   * * *         
                1             *   
                2             * * 
                3     *       * * 
                4     *           
                5     *           
                6                 
                7 * * * * *       
                .........battleBit
        ```    
    1. ##### Shortcut
        From terminal 1 (the server terminal) run the following command:
        ```shell script
        battleBit (? for help) > shortcut
        ```
        This will set up player 1 to have a single ship bit in position (0, 0)
    1. ##### Player 0 Wins
        In terminal 2, fire a single shot from Player 0's at position 0, 0, which should show the following
        output in all terminals
        ```shell script
        battleBit (? for help) > fire 0 0
        Player 0 fires at 0 0 - HIT - PLAYER 0 WINS!
       ```