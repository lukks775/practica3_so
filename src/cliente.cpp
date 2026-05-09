#include<iostream>
#include<vector>
#include<cstring>
#include<arpa/inet.h>
#include<unistd.h>
#include<fstream>

using namespace std;

//crear el socket TCP/IP
int crearSocket(){
int sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1){ //comprobar si el socket se creo bien
cerr<<"error al crear el socket "<<endl;
return -1;
}
return sockfd;
}


//para configurar la ip y el puerto del servidor
void configurarServidor(sockaddr_in &servaddr){ //&para modificar la variable original
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(12345);//puerto del servidor
if(inet_pton(AF_INET,"127.0.0.1",&servaddr.sin_addr)<=0){
cerr<<"direccion invalida o no soportada"<<endl;
}
}

//para conectar el cliente con el servidor
int conectarServidor(int sockfd,sockaddr_in &servaddr){
if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){//si no conecta
cerr<<"Error al conectar"<<endl;
return -1;
}//si se conecta bien
return 0;
}

//esta funcion recive los datos enviados por el servidor
void recibirDatos(int sockfd,vector<unsigned char> &datos){
unsigned char buffer; //variable temporal para recibir cada dato
while(recv(sockfd,&buffer,sizeof(buffer),0)>0){
datos.push_back(buffer);
}
}

//esta funcion guarda los datos recibidos en un archivo .txt
void guardarDatos(vector<unsigned char> &datos){
ofstream f("temperaturas.txt"); //crea el archivo temperaturas.txt
for(unsigned char x:datos){//recorre los datos del vector
f<<(int)x<<endl;
}
f.close();
}


//muestra por la pantalla los datos recibidos
void imprimirDatos(vector<unsigned char> &datos){
cout<<"Datos recibidos:"<<endl;
for(unsigned char f:datos){
cout<<(int)f<<endl;
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

vector<unsigned char> datos;

recibirDatos(sockfd,datos);

guardarDatos(datos);

imprimirDatos(datos);

close(sockfd);

return 0;
}
