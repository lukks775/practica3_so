#include<iostream>
#include<vector>
#include<cstring>
#include<arpa/inet.h>
#include<unistd.h>
#include<fstream>

using namespace std;

int crearSocket(){
int sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1){
cerr<<"Error al crear socket"<<endl;
return -1;
}
return sockfd;
}


void configurarServidor(sockaddr_in &servaddr){
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(12345);
inet_pton(AF_INET,"192.168.0.148",&servaddr.sin_addr);
}


int conectarServidor(int sockfd,sockaddr_in &servaddr){
if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){
cerr<<"Error al conectar"<<endl;
return -1;
}
return 0;
}


void recibirDatos(int sockfd,vector<float> &floats){
float buffer;
while(recv(sockfd,&buffer,sizeof(buffer),0)>0){
floats.push_back(buffer);
}
}


void guardarDatos(vector<float> &floats){
ofstream f("datos.txt");
for(float x:floats){
f<<x<<endl;
}
f.close();
}


void imprimirDatos(vector<float> &floats){
cout<<"Numeros recibidos:"<<endl;
for(float f:floats){
cout<<f<<endl;
}
}
int main(){
int sockfd=crearSocket();
if(sockfd==-1){
return 1;
}
sockaddr_in servaddr;
configurarServidor(servaddr);
if(conectarServidor(sockfd,servaddr)==-1){
return 1;
}
vector<float> floats;
recibirDatos(sockfd,floats);
guardarDatos(floats);
imprimirDatos(floats);
close(sockfd);
return 0;
}
