#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "utils/socketutils.h"
int main(){
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in server_addr={
        .sin_family=AF_INET,
        .sin_port=htons(5000),
        .sin_addr.s_addr=inet_addr("127.0.0.1")
    };

    char* ip="127.0.0.1";



    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton failed");
        close(sockfd);
        return -1;
    }

    
    
    if(connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr))==0){
        printf("Connection to spring boot");
        char *request = "GET /hello HTTP/1.1\r\n"
                        "Host: localhost\r\n"
                        "Connection: close\r\n"
                        "\r\n";
        send(sockfd,request,strlen(request),0);
        char buffer[4096];
        recv(sockfd,buffer,sizeof(buffer),0);
        printf("Response is %s",buffer);
    }


    return 0;
}