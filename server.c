#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024



int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creates a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed!");
        exit(EXIT_FAILURE);
    }

    // Sets socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt,sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Sets the adress family to IPv4
    address.sin_family = AF_INET;

    // Accepting connections on any available interface / communicaton
    address.sin_addr.s_addr = INADDR_ANY;

    // Set the port number in network byte order / Port 8080
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed!");
        exit(EXIT_FAILURE);
    }

    // Starts listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listening failed!");
        exit(EXIT_FAILURE);
    }

    // Prints a message stating the server is listening on the specified port
    printf("Server listening on port %d\n", PORT);

    // Accept incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen)) < 0) {
        perror("accept failed!");
        exit(EXIT_FAILURE);
    }

    printf("Connection accepted\n");

    // Declares a signed size type variable for the number of bytes read
    ssize_t valread;
    while ((valread = read(new_socket, buffer, BUFFER_SIZE)) > 0) {
        printf("Client: %.*s\n", (int)valread, buffer);
        memset(buffer, 0, sizeof(buffer));
    }

    // closes the socket
    close(server_fd);
    return 0;
}