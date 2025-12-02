#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


int createsocket(){
    return socket(AF_INET,SOCK_STREAM,0);
}
int main(){
    int sockfd=createsocket();
    char* ip="74.125.24.100";
    struct sockaddr_in address;
    address.sin_family=AF_INET;
    address.sin_port=htons(80);
    inet_pton(AF_INET,ip,&address.sin_addr);
    int res=connect(sockfd,&address,sizeof(address));
    if(res==0){
        printf("Connection was successful");
    }
    char* message;
    message="GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    send(sockfd,message,strlen(message),0);
    char buffer[4096];
    recv(sockfd,buffer,4096,0);
    printf("%s",buffer);

    return 0;
}