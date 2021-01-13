//
// Created by carson on 5/20/20.
//

#ifndef BATTLESHIP_SERVER_H
#define BATTLESHIP_SERVER_H

#include "char_buff.h"

#define BATTLEBIT_PORT 9876

typedef  struct game_server {
    pthread_t server_thread; // main server thread that listens for connections
    pthread_t player_threads[2]; // threads managing I/O from the two sockets
    int player_sockets[2]; // the client sockets that are inputing and outputting from the network
} game_server;

int server_start();

void server_broadcast(char_buff *msg);

#endif //BATTLESHIP_SERVER_H
