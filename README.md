# Práctica 3 – Parte A

## Servidor Web con ESP32-S3

### Descripción

En esta práctica se implementa un **servidor web utilizando una ESP32-S3**.
La placa se conecta a una red **WiFi en modo estación (STA)** y crea un **servidor HTTP en el puerto 80**.
Cuando un usuario accede a la dirección IP de la ESP32 desde un navegador, la placa envía una **página web con HTML y JavaScript**.

La página contiene una imagen de una bombilla y dos botones que permiten **encenderla o apagarla** mediante JavaScript, cambiando la imagen mostrada.

---

### Funcionamiento

1. La ESP32 se conecta a la red WiFi utilizando el **SSID y contraseña configurados en el código**.
2. Una vez conectada, la placa muestra su **dirección IP en el monitor serie**.
3. Se inicia un **servidor web** en el puerto 80.
4. Cuando un navegador accede a la dirección `/`, la ESP32 envía la página HTML.
5. El usuario puede interactuar con la página mediante botones que cambian la imagen de la bombilla.

---

### Salida por el monitor serie

Al ejecutar el programa se puede observar algo similar a lo siguiente:

```
Conectando a WiFi...
.....
WiFi conectado
IP: 192.168.1.45
Servidor HTTP iniciado
```

---

### Cómo ejecutar el proyecto

1. Conectar la **ESP32-S3** al ordenador mediante USB.
2. Abrir el proyecto en **PlatformIO**.
3. Configurar en el código el **SSID y la contraseña de la red WiFi**.
4. Compilar y subir el programa a la placa.
5. Abrir el **Monitor Serie** a 115200 baudios.
6. Copiar la **dirección IP que aparece**.
7. Abrir esa dirección en un **navegador web**.

Ejemplo:

```
http://192.168.1.45
```

---

### Tecnologías utilizadas

* ESP32-S3
* Arduino Framework
* WiFi
* WebServer (HTTP)
* HTML
* JavaScript
* PlatformIO

---

### Resultado

Al acceder a la página web generada por la ESP32 se muestra una interfaz sencilla con una bombilla y dos botones.
Los botones permiten cambiar la imagen entre **bombilla encendida y apagada**, demostrando la interacción entre HTML, JavaScript y el servidor web de la ESP32.
