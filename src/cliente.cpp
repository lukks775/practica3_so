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
if(inet_pton(AF_INET,"192.168.0.148",&servaddr.sin_addr)<=0){
cerr<<"direccion invalida o no soportada"<<endl;
}
}

//para conectar el cliente con el servidor
int conectarServidor(int sockfd,sockaddr_in &servaddr){
if(connect(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr))==-1){//si no se conecta da error
cerr<<"Error al conectar"<<endl;
return -1;
}//si se conecta bien
return 0;
}


//esta funcion recive  los datos enviados por el servidor
void recibirDatos(int sockfd,vector<float> &floats){
float buffer; //variable temporal para recibir cada float
while(recv(sockfd,&buffer,sizeof(buffer),0)>0){
floats.push_back(buffer);
}
}

//esta fuvncion guarda  los datos recibidos en un archivo .txt
void guardarDatos(vector<float> &floats){
ofstream f("temperaturas.txt"); //crea el archivo temperatuas.txt
for(float x:floats){//recorre los datos del vector
f<<x<<endl;
}
f.close();
}


//muestra r por la pantalla los datos recibidos
void imprimirDatos(vector<float> &floats){
cout<<"Numeros  recibidos:"<<endl;
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