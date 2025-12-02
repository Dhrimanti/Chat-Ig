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
    char* ip="74.125.24.100";
    struct sockaddr_in address;
    address.sin_family=AF_INET;
    address.sin_port=htons(443);
    inet_pton(AF_INET,ip,&address.sin_addr);
    int res=connect(sockfd,&address,sizeof(address));
    if(res==0){
        printf("Connection was successful");
    }
    char* buffer;
    buffer="GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    send(sockfd,buffer,strlen(buffer),0);
    return 0;
}