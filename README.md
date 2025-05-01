# Bellum Ferrum

## Taller Estructura de Datos

Este proyecto incorpora la librería [SFML](https://www.sfml-dev.org/) para la visualización gráfica. Está preparado para compilar directamente desde **Visual Studio Code** usando **g++** y **MinGW** sin necesidad de instalar SFML por separado.

## Requisitos

- Visual Studio Code
- Extensión C/C++ de Microsoft
- MinGW con `g++` y `gdb` en el PATH

## Compilar

1. Abre el proyecto en VS Code.
2. Abre una terminal del proyecto.
3. Escribe el siguiente comando: g++ Logica/main.cpp Dominio/Tanques/Tanque.cpp Dominio/Tanques/TanquePesado.cpp Dominio/Nodos/NodoSistema.cpp -o prueba
   <!-- Asegúrate de que g++ y gdb están en el PATH -->
   <!--- Pulsa `Ctrl+Shift+B` y selecciona `Compilar con SFML`. -->

## Ejecutar

- Escribe el siguiente comando en la terminal: ./prueba
  <!--Pulsa `F5` o el botón de "Run" en la parte superior derecha.-->
  <!--Si ves errores de DLL al ejecutar, asegúrate de que `main.exe` esté junto a las DLLs en `SFML/bin`.-->

## Autores

- Daniel Durán
- Martín Castillo

> [!IMPORTANT]
> Este proyecto está en desarrollo, por lo que puede tener bugs...
