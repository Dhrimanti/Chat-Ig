#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
int main(){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr={
        .sin_family=AF_INET,
        .sin_port=htons(443),
        .sin_addr.s_addr=inet_addr("74.125.24.100")
    };

    char* ip="74.125.24.100";



    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        close(sockfd);
        return -1;
    }

    int res = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (res == -1) {  
        perror("connect failed");
        close(sockfd);
        return -1;
    } else {
        printf("Connecting to server");
    }


    return 0;
}