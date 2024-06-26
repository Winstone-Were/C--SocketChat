#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>

int main()
{
    // Socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8000);
    // htons converts from MACHINE byte order NETWORK byte order
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    listen(serverSocket, 5);

    int clientSocket = accept(serverSocket, nullptr, nullptr);
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << std::endl;

    close(serverSocket);

    return 0;
}
