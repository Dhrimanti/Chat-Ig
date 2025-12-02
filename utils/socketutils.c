#include "socketutils.h"


int createsocket(){
    return socket(AF_INET,SOCK_STREAM,0);
}


struct sockaddr_in* createaddress(char *ip,int port){
    
    struct sockaddr_in *address=malloc(sizeof(struct sockaddr_in));
    address->sin_family=AF_INET;
    address->sin_port=htons(port);
    inet_pton(AF_INET,ip,&address->sin_addr);
    return address; 
}