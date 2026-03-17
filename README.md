# Práctica 3A – Servidor Web WiFi (Modo Station) en ESP32

**Asignatura**: Microprocesadores y Sistemas Digitales  
**Universitat Politècnica de Catalunya (UPC)**  
**Curso académico**: 2025-2026

Repositorio oficial de la **Parte A** de la Práctica 3: **Generación de un servidor web con ESP32 en modo STA**.

## Objetivo de la Parte A

Crear un servidor web accesible desde cualquier navegador utilizando la ESP32 conectada a una red WiFi existente (modo Station).  
Se demuestra el uso de las librerías `WiFi.h` y `WebServer.h` para servir contenido HTML dinámico, mostrando la IP asignada por el router y permitiendo el acceso remoto sin necesidad de montaje hardware adicional.

Esta parte es la base para extender el proyecto al modo Access Point (AP) y a la comunicación Bluetooth Classic (Parte B).

## Características implementadas

- Conexión WiFi en **modo STA** (Station)
- Servidor HTTP en puerto 80
- Página web con HTML + CSS (mejorada y separada en fichero externo)
- Visualización de la IP en Monitor Serie
- Acceso desde cualquier dispositivo en la misma red WiFi
- Código limpio y comentado con separación de HTML (según requisito de la práctica)

## Requisitos

### Hardware
- Placa ESP32 (cualquier variante)
- Cable USB  
*(No se requiere ningún componente externo)*

### Software
- **Arduino IDE** 2.x
- ESP32 board package instalado
- Monitor Serie a **115200 baudios**
- Navegador web (Chrome, Firefox, Safari…)
- Editor Markdown (para generar el fichero HTML mejorado)

## Código fuente (`src/practica3A_webserver.ino`)

```cpp
#include <WiFi.h>
#include <WebServer.h>

// ================== CONFIGURACIÓN WIFI ==================
const char* ssid = "TU_SSID";          // ← CAMBIA ESTO
const char* password = "TU_PASSWORD";  // ← CAMBIA ESTO

WebServer server(80);

---

### Resultado

Al acceder a la página web generada por la ESP32 se muestra una interfaz sencilla con una bombilla y dos botones.
Los botones permiten cambiar la imagen entre **bombilla encendida y apagada**, demostrando la interacción entre HTML, JavaScript y el servidor web de la ESP32.
