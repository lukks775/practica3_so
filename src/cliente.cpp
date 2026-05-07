#include <iostream>
#include <vector>
#include <cstring>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
using namespace std;
int crearSocket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        cerr << "Error al crear el socket" << endl;
        exit(1);
    }
    return sockfd;
}
sockaddr_in configurarServidor(const char* ip, int puerto) {
    sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(puerto);
    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0) {
        cerr << "Direccion IP invalida" << endl;
        exit(1);
    }
    return servaddr;
}
void conectarServidor(int sockfd, sockaddr_in servaddr) {
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) { 
        cerr << "Error al conectar con el servidor" << endl;
        exit(1);
    }
    cout << "Conexion establecida correctamente" << endl;
}
vector<unsigned char> recibirDatos(int sockfd) {
    vector<unsigned char> datos;
    unsigned char buffer;
    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        datos.push_back(buffer);
    }
    return datos;
}
void guardarDatos(vector<unsigned char> datos) {
    ofstream archivo("output/datos_recibidos.txt");
    if (!archivo) {
        cerr << "Error al crear archivo" << endl;
        return;
    }
    for (unsigned char dato : datos) {
        archivo << (int)dato << endl;
    }

    archivo.close();

    cout << "Datos guardados correctamente" << endl;
}
void imprimirDatos(vector<unsigned char> datos) {
    cout << "\nDatos recibidos:\n" << endl;
    for (unsigned char dato : datos) {
        cout << (int)dato << endl;
    }
}

int main() {
    int sockfd = crearSocket();
    sockaddr_in servidor = configurarServidor("127.0.0.1", 12345);
    conectarServidor(sockfd, servidor);
    vector<unsigned char> datos = recibirDatos(sockfd);
    guardarDatos(datos);
    imprimirDatos(datos);
    close(sockfd);
    return 0;
}
