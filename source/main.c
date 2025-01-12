#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2025
#define BUFFER_SIZE 1024


void show_flag(int client_socket) {
    char file_buffer[BUFFER_SIZE];
    // Password is correct, send file content
    FILE *file = fopen("flag.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        close(client_socket);
        exit(EXIT_FAILURE);
    }

    while (fgets(file_buffer, sizeof(file_buffer), file) != NULL) {
        send(client_socket, file_buffer, strlen(file_buffer), 0);
    }
    fclose(file);
}

void handle_client(int client_socket) {
    char b[BUFFER_SIZE];


    send(client_socket, "Type in the password.\n", 22, 0);


    // Receive password from client
    ssize_t bytes_received = recv(client_socket, b, sizeof(b), 0);
    b[bytes_received] = '\0';

    // Check password
    if (b[0] + b[1] + b[2] + b[3] + b[4] + b[5] + b[6] == 546) {
        if (b[0] + b[1] + b[2] + b[3] + b[4] + b[5] - b[6] == 480) {
            if (b[0] + b[1] + b[2] + b[3] + b[4] - b[5] + b[6] == 412) {
                if (b[0] + b[1] + b[2] + b[3] - b[4] + b[5] + b[6] == 440) {
                    if (b[0] + b[1] + b[2] - b[3] + b[4] + b[5] + b[6] == 312) {
                        if (b[0] + b[1] - b[2] + b[3] + b[4] + b[5] + b[6] == 356) {
                            if (b[0] - b[1] + b[2] + b[3] + b[4] + b[5] + b[6] == 314) {
                                show_flag(client_socket);
                            }
                        }
                    }
                }
            }
        }        
    } else {
        // Incorrect password
        send(client_socket, "Access denied.\n", 15, 0);
    }

    // Close the connection
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error binding socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Error listening for connections");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept a connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Error accepting connection");
            close(server_socket);
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        // Handle the client
        handle_client(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}
