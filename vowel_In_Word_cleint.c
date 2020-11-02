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
    char word[20],msg, terminate; 
    int c = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET; 
    server.sin_port = htons(6000); 
    server.sin_addr.s_addr = INADDR_ANY; 
    int b = connect(c, (struct sockaddr*)&server, sizeof server); 
    printf("\nEnter a word to check the number of vowel: "); 
    scanf("%s", word); 
    send(c, word, strlen(word), 0);
    printf("\nVowels are: ");
    int k = recv(c, &msg, sizeof(char), 0); 
    while(k>0)
    {
  	if(msg=='>')
  	{
  	break;
  	}
   	printf("%c ", msg);
  	k = recv(c, &msg, sizeof(char), 0); 
    }
    printf("\n");
    recv(c, &count, sizeof(int), 0);
    printf("Total no. of vowels are %d\n", count);
}