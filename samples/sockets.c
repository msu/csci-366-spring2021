#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void client_demo(){
    int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (socket_fd == -1)
    {
        printf("Could not create socket\n");
    }

    struct sockaddr_in connecting_to;

    // google.com
    connecting_to.sin_addr.s_addr = inet_addr("216.58.193.78");
    connecting_to.sin_family = AF_INET;
    // we have to deal with endian-ness
    connecting_to.sin_port = htons(80);

    //Connect to remote server
    if (connect(socket_fd ,
            // we cast here because sockaddr_in
            // is structurally compatible
            // with sockaddr so it works out.
            // Insane, but this is the
            // recommended approach o_O
            (const struct sockaddr *) &connecting_to,
            sizeof(connecting_to)) < 0)
    {
        puts("Could not connect!\n");
    } else {
        puts("Connected!\n");
    }

    //Send some data
    char * message = "GET / HTTP/1.1\r\n\r\n";
    if( send(socket_fd , message ,
            strlen(message) , 0) < 0)
    {
        puts("Send failed");
    } else {
        puts("Data Sent!\n");

        //Receive some data
        char buffer[2000];
        if( recv(socket_fd, buffer , 2000 , 0) < 0)
        {
            puts("Recieve failed");
        } else {
            puts("Reply received\n");
            puts(buffer);
        }
    }
}

void server_demo() {

    int server_socket_fd = socket(AF_INET,
                                  SOCK_STREAM,
                                  IPPROTO_TCP);
    if (server_socket_fd == -1) {
        printf("Could not create socket\n");
    }

    int yes = 1;
    setsockopt(server_socket_fd,
               SOL_SOCKET,
               SO_REUSEADDR, &yes, sizeof(yes));

    struct sockaddr_in server;

    // fill out the socket information
    server.sin_family = AF_INET;
    // bind the socket on all available interfaces
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(9876);

    int request = 0;
    if (bind(server_socket_fd,
            // Again with the cast
             (struct sockaddr *) &server,
             sizeof(server)) < 0) {
        puts("Bind failed");
    } else {
        puts("Bind worked!");
        listen(server_socket_fd, 3);

        //Accept an incoming connection
        puts("Waiting for incoming connections...");


        struct sockaddr_in client;
        socklen_t size_from_connect;
        int client_socket_fd;
        int request_count = 0;
        while ((client_socket_fd = accept(server_socket_fd,
                                          (struct sockaddr *) &client,
                                          &size_from_connect)) > 0) {
            char message[100] = {0};
            sprintf(message,
                    "Thank you for coming, come again - req %d\n\n",
                    request_count++);
            send(client_socket_fd, message,
                 strlen(message), 0);
            close(client_socket_fd);
        }
    }

}

int main(){
    server_demo();
}