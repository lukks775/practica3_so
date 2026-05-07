# Practica 3 – Comunicacion Cliente-Servidor usando Sockets TCP/IP en C++

## Asignatura
Sistemas Operativos

---

# Descripcion

Este proyecto consiste en el desarrollo de una aplicacion cliente-servidor utilizando sockets TCP/IP.

El servidor, implementado en Python, simula el comportamiento de una cámara térmica industrial que envía datos de temperatura al cliente mediante comunicación TCP/IP.

El cliente, desarrollado en C++, recibe dichos datos usando sockets, los almacena en memoria mediante vectores dinámicos y posteriormente los guarda en un archivo local.

---

# Objetivos de la práctica

- Comprender el funcionamiento del modelo cliente-servidor
- Implementar comunicación TCP/IP mediante sockets
- Utilizar sockets en C++
- Recibir datos desde un servidor remoto
- Almacenar información en estructuras dinámicas
- Guardar datos en archivos de texto
- Automatizar la ejecución mediante Bash
- Utilizar Git y GitHub para organización del proyecto

---

# Tecnologías utilizadas

- C++
- Python
- Sockets TCP/IP
- Bash
- Git
- GitHub
- Linux / WSL Ubuntu

---

# Estructura del proyecto

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

- Creación de socket TCP/IP
- Configuración de IP y puerto
- Conexión con servidor
- Recepción de datos mediante `recv()`
- Uso de vectores dinámicos
- Escritura de archivos mediante `ofstream`
- Impresión de resultados
- Modularización mediante funciones
- Control básico de errores

---

## Servidor Python

- Creación de socket servidor
- Espera de conexiones
- Envío de datos simulados
- Comunicación TCP/IP

---

# Funciones implementadas en el cliente

| Función | Descripción |
|---|---|
| `crearSocket()` | Crea el socket TCP/IP |
| `configurarServidor()` | Configura IP y puerto |
| `conectarServidor()` | Realiza la conexión |
| `recibirDatos()` | Recibe datos mediante recv() |
| `guardarDatos()` | Guarda datos en archivo |
| `imprimirDatos()` | Muestra resultados |

---

# Compilación y ejecución

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
- compilación del cliente
- ejecución del programa
- control básico de errores

---

# Capturas de ejecución

Las capturas del funcionamiento del proyecto se encuentran en:

```text
screenshots/
```

---

# Resultados obtenidos

El cliente logró conectarse correctamente al servidor mediante sockets TCP/IP.

Los datos enviados por el servidor fueron:
- recibidos correctamente
- almacenados en memoria
- escritos en archivo
- mostrados por pantalla

La comunicación cliente-servidor funcionó correctamente.

---

# Conclusiones

Mediante esta práctica se logró comprender el funcionamiento básico de la comunicación cliente-servidor utilizando sockets TCP/IP.

También se aplicaron conceptos importantes relacionados con:
- programación en C++
- comunicación en red
- gestión de archivos
- modularización
- automatización mediante Bash
- control de versiones con Git y GitHub

La práctica permitió simular un entorno similar a sistemas industriales reales basados en monitorización remota y transmisión de datos.

---

# Autores

- Nombre Apellido
- Nombre Apellido
