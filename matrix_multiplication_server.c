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
 int s,sock;
 int r,i,j,sz,k;
 server.sin_family=AF_INET;
 server.sin_port=3000;
 server.sin_addr.s_addr=inet_addr("127.0.0.1");
 s=socket(AF_INET,SOCK_STREAM,0);
 bind(s,(struct sockaddr *)&server,sizeof(server));
 listen(s,1);
 sz=sizeof(server);
 sock=accept(s,(struct sockaddr *)&server,&sz);
 recv(sock,&mt,sizeof(mt),0);
 recv(sock,&a,sizeof(a),0);
 printf("\nReceived Matrix 1\n");
 for(i=0;i<mt[0];i++)
 {
  printf("\n");  
  for(j=0;j<mt[1];j++)
  {
   printf(" %d ",a[i][j]);
  }
 } 
  
 recv(sock,&b,sizeof(b),0);
 printf("\nReceived Matrix 2\n"); 
 for(i=0;i<mt[2];i++)
 {
  printf("\n");  
  for(j=0;j<mt[3];j++)
  {
   printf(" %d ",b[i][j]);
  }
 } 
  
 printf("\nMultiplying........\n"); 
 for(i=0;i<mt[0];i++)
 for(j=0;j<mt[3];j++)
 {
  c[i][j]=0;
  for(k=0;k<mt[1];k++)
   c[i][j]+=a[i][k]*b[k][j];
 }
 printf("\nResult:\n") ; 
 for(i=0;i<mt[0];i++)
 {
  printf("\n");  
  for(j=0;j<mt[3];j++)
  {
   printf(" %d ",c[i][j]);
  }
 }
 printf("\n"); 
 send(sock,&c,sizeof(c),0);
 //pclose(sock);
 //pclose(s); 
}