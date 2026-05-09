# Practica 3 – Comunicacion Cliente-Servidor usando Sockets TCP/IP en C++

## Asignatura
Sistemas Operativos

# Enlace al repositorio Git
https://github.com/lukks775/practica3_so.git

---

# Descripcion

Este proyecto consiste en aprender a desarrollar un cliente que pueda conectarse al servidor, recibir datos en tiempo real y almacenarlos en un archivo local.

El servidor en Python simula el comportamiento de una camara termica industrial que envia datos de temperatura al cliente a traves de una comunicacion TCP/IP.

El cliente en C++ recibe los datos usando sockets, los almacena en memoria usando vectores dinamicos y despues los guarda en un archivo local.

---

# Objetivos de la practica:

- Comprender el modelo cliente-servidor
- Establecer comunicación TCP/IP mediante sockets
- Utilizar programas de comunicaion en C++
- Recibir datos desde un sensor remoto
- Almacenar información en archivos
- Implementar control basico de errores en comunicaiones
- Utilizar GitHub para organizar el proyecto

---

# Tecnologias usadas

- C++
- Python
- Sockets TCP/IP
- Bash
- GitHub
- WSL Ubuntu

---

# Estructura del proyecto
(esquema generado con IA)

```text
practica3-sockets-cpp/
│
├── src/
│   └── cliente.cpp
│
├── server/
│   └── ServidorCamara.py
│
├── output/
│   └── datos_recibidos.txt
│
├── screenshots/
│
├── docs/
│   └── informe.pdf
│
├── run.sh
│
├── README.md
│
└── .gitignore
```

---

# Funcionamiento del sistema

El flujo de funcionamiento es el siguiente:

```text
Servidor Python → Socket TCP/IP → Cliente C++ → Archivo local
```

1. El servidor Python genera datos simulados.
2. El servidor espera conexiones TCP/IP.
3. El cliente C++ se conecta al servidor.
4. El cliente recibe los datos usando `recv()`.
5. Los datos se almacenan en un vector dinámico.
6. Los datos se guardan en un archivo `.txt`.
7. Los resultados se muestran por pantalla.

---

# Funcionalidades implementadas

## Cliente C++

- Creacion de socket TCP/IP
- Configuracion de IP y puerto
- Conexion con servidor
- Recibir de datos mediante `recv()`
- Uso de vectores dinamicos
- Escritura de archivos mediante `ofstream`
- Impresion de resultados
- Control basico de errores

---

## Servidor Python

- Creacion de socket servidor
- Espera de conexiones
- Envio de datos simulados
- Comunicaion TCP/IP

---

# Funciones implementadas en el cliente

| Funcion | Descripcion |
|---|---|
| `crearSocket()` | Crea el socket TCP/IP |
| `configurarServidor()` | Configura IP y puerto |
| `conectarServidor()` | Realiza la conexion |
| `recibirDatos()` | Recibe datos mediante recv() |
| `guardarDatos()` | Guarda datos en archivo |
| `imprimirDatos()` | Muestra resultados |

---

# Compilacion y ejecución

## 1. Ejecutar servidor

Abrir una terminal y ejecutar:

```bash
cd server
python3 ServidorCamara.py
```

---

## 2. Ejecutar cliente

Abrir otra terminal y ejecutar:

```bash
chmod +x run.sh
./run.sh
```

---

# Archivo generado

El cliente genera automáticamente:

```text
output/datos_recibidos.txt
```

Este archivo contiene todos los datos recibidos desde el servidor.

---

# Script Bash

El archivo `run.sh` automatiza:
- compilacion del cliente
- ejecucion del programa
- control basico de errores

---

# Capturas de ejecucion

Las capturas del funcionamiento del proyecto se encuentran en:

```text
screenshots/
```

---

# Resultados obtenidos

El cliente logro conectarse correctamente al servidor mediante sockets TCP/IP.

Los datos enviados por el servidor fueron:
- recibidos correctamente
- almacenados en memoria
- escritos en archivo
- mostrados por pantalla

La comunicacion cliente-servidor funciono correctamente.

---

# Conclusiones

Con esta practica comprendimos el funcionamiento basico de la comunicacion cliente-servidor utilizando sockets TCP/IP.

Tambien se aplicaron conceptos importantes relacionados con:
- programacion en C++
- comunicacion en red
- gestion de archivos
- automatizacion con Bash

Conseguimos simular un entorno similar a sistemas industriales reales basados en monitorizacion remota y transmision de datos.

---

# Autores

- Lucia Castellanos Paz
- Ander Zuazquita Pastor
