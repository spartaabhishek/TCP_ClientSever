#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netinet/ip.h>
#include<unistd.h>

int main(){ 
    int n, sock, count=0; 
    char word[20], terminate; 
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server,client;
    server.sin_family = AF_INET; 
    server.sin_port = htons(6000); 
    server.sin_addr.s_addr = INADDR_ANY; 
    int b = bind(s, (struct sockaddr*)&server, sizeof server); 
    int l = listen(s, 5);
    n = sizeof client; 
    sock = accept(s, (struct sockaddr*)&client, &n);
    if(sock==-1)
    {
    perror("failed \n");
    }
    printf("%s\n", word);
    int k = recv(sock, word, sizeof(word), 0);
    word[k] = '\0'; 
    printf("\nThe string received is:%s\n", word);
    for(int i=0;word[i]!='\0';i++){
    	if (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u')  
    	{
        	send(sock, &word[i], sizeof(char), 0);
        	count++;
        }
    } 
    terminate='>';
    send(sock, &terminate, sizeof(char), 0);
    send(sock, &count, sizeof(int), 0);
}
