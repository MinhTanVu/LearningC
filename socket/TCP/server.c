#include <stdio.h>
#include <arpa/inet.h>


#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    
    //create socket
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0) == 0)) {
        perror("Create socket failed");
        exit(EXIT_FAILURE);
    }

    //define the server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    //Bind the socket to the address and port
    if(bind(server_fd,(struct sockaddr_in*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    //listen for incoming connections
    if(listen(server_fd, 3) < 0){
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Waiting for connections...\n");
    
    //accept an incoming connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Connection established with client\n");
    
    //receive data from the client
    int bytes_received = read(new_socket, buffer, BUFFER_SIZE);
    printf("Received: %s\n", buffer);

    //send response to the client
    send(new_socket, response, strlen(response), 0);
    printf("Response sent\n");

    //Close the socket
    close(new_socket);
    close(server_fd);

    return 0;
}