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
        .sin_port=htons(9999),
        .sin_addr.s_addr=inet_addr("127.0.0.1")
    };

    char* ip="127.0.0.1";



    inet_pton(AF_INET,ip,&server_addr.sin_addr);
    int res=connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(res==1){
        printf("There is an error");
    }else{
        printf("There is no error and connected");
    }


    return 0;
}