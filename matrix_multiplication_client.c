#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>

int main()
{
 struct sockaddr_in client,server;
 int a[10][10],b[10][10],c[10][10],mt[4];
 int s,sock,r,i,j;
 client.sin_family=AF_INET;
 client.sin_port=3000;
 client.sin_addr.s_addr=inet_addr("127.0.0.1");
 s=socket(AF_INET,SOCK_STREAM,0);
 connect(s,(struct sockaddr *)&client,sizeof(client));
 
 printf("Enter order of matrix 1:");
  scanf("%d %d",&mt[0],&mt[1]);
 printf("Enter order of matrix 2:");
  scanf("%d %d",&mt[2],&mt[3]);
 if(mt[1]!=mt[2])
  printf("Matrices cannot be multiplied");
 else
 {
  send(s,&mt,sizeof(mt),0);
  printf("Enter Elements for matrix 1:\n");
  for(i=0;i<mt[0];i++)
  {
   for(j=0;j<mt[1];j++)
   {
    scanf("%d",&a[i][j]);
   }
  }
  send(s,&a,sizeof(a),0);
  printf("Enter Elements for matrix 2:\n");
  for(i=0;i<mt[2];i++)
  {
   for(j=0;j<mt[3];j++)
   {
    scanf("%d",&b[i][j]);
   }
  } 
  send(s,&b,sizeof(b),0);
  
  recv(s,&c,sizeof(c),0);
  printf("\nResult:\n"); 
  for(i=0;i<mt[0];i++)
  {
   printf("\n");  
   for(j=0;j<mt[3];j++)
   {
    printf(" %d ",c[i][j]);
   }
  } 
 }
 printf("\n"); 
 //pclose(s);
}