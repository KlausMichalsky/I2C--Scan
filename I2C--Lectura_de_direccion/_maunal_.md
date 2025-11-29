==============================
  ESCÁNER I2C DUAL PARA RP2040 ZERO
==============================

Este archivo contiene:
1. Descripción del programa
2. Código completo listo para compilar
3. Manual explicado línea por línea

--------------------------------------------------
1) DESCRIPCIÓN GENERAL
--------------------------------------------------
Este programa escanea los dos buses I2C del RP2040 Zero:

- Wire  → SDA = GP4, SCL = GP5
- Wire1 → SDA = GP26, SCL = GP27

Permite detectar sensores conectados en cualquiera de los dos buses,
incluyendo dispositivos como el AS5600.

--------------------------------------------------
2) CÓDIGO COMPLETO
--------------------------------------------------

/*
   Escáner I2C dual para RP2040 Zero
   - Wire  → I2C en pines GP4 (SDA) y GP5 (SCL)
   - Wire1 → I2C en pines GP26 (SDA) y GP27 (SCL)
   Este programa detecta cualquier dispositivo conectado en ambos buses.
*/

#include <Wire.h>

void setup()
{
  Serial.begin(115200);

  // Configuración de pines I2C del Zero
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire1.setSDA(26);
  Wire1.setSCL(27);

  Wire.begin();   // Inicializa I2C principal
  Wire1.begin();  // Inicializa I2C secundario

  Serial.println("Escaneando I2C en Wire...");
  Serial.println("Escaneando I2C en Wire1...");
}

void loop()
{
  byte error, address;
  int found = 0;

  // -----------------------------
  // Escaneo Wire (GP4 y GP5)
  // -----------------------------
  Serial.println("\n--- Escaneando bus Wire ---");
  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(address, HEX);
      found++;
    }
  }

  // -----------------------------
  // Escaneo Wire1 (GP26 y GP27)
  // -----------------------------
  Serial.println("\n--- Escaneando bus Wire1 ---");
  for (address = 1; address < 127; address++)
  {
    Wire1.beginTransmission(address);
    error = Wire1.endTransmission();

    if (error == 0)
    {
      Serial.print("Dispositivo encontrado en 0x");
      Serial.println(address, HEX);
      found++;
    }
  }

  if (found == 0)
    Serial.println("No se encontraron dispositivos I2C");

  Serial.println("\nEscaneo completo");
  delay(2000);
}

--------------------------------------------------
3) MANUAL EXPLICADO LÍNEA POR LÍNEA
--------------------------------------------------

#include <Wire.h>
--> Incluye la librería I2C estándar para usar Wire y Wire1.

void setup()
--> La función setup() se ejecuta una vez al iniciar el programa.

Serial.begin(115200);
--> Activa la comunicación serial a 115200 baudios.

Wire.setSDA(4);
Wire.setSCL(5);
--> Asigna los pines SDA y SCL para el bus I2C principal (Wire).

Wire1.setSDA(26);
Wire1.setSCL(27);
--> Asigna los pines SDA y SCL para el bus I2C secundario (Wire1).

Wire.begin();
--> Inicializa el bus I2C principal.

Wire1.begin();
--> Inicializa el bus I2C secundario.

Serial.println("Escaneando I2C en Wire...");
Serial.println("Escaneando I2C en Wire1...");
--> Mensajes iniciales en la terminal.

void loop()
--> La función loop() se ejecuta continuamente.

byte error, address;
int found = 0;
--> Variables auxiliares para manejar el escaneo.

Serial.println("\n--- Escaneando bus Wire ---");
--> Indica que inicia el escaneo del primer bus.

for (address = 1; address < 127; address++)
--> Recorre todas las direcciones I2C posibles (1–126).

Wire.beginTransmission(address);
--> Intenta comunicarse con un dispositivo en esa dirección.

error = Wire.endTransmission();
--> Devuelve 0 si un dispositivo respondió.

if (error == 0)
--> Si el dispositivo responde...

Serial.print("Dispositivo encontrado en 0x");
Serial.println(address, HEX);
--> Muestra la dirección del dispositivo en formato hexadecimal.

found++;
--> Aumenta el contador de dispositivos detectados.

Serial.println("\n--- Escaneando bus Wire1 ---");
--> Inicia el escaneo del segundo bus I2C.

Wire1.beginTransmission(address);
Wire1.endTransmission();
--> Igual que Wire, pero usando el segundo bus físico del RP2040.

if (found == 0)
    Serial.println("No se encontraron dispositivos I2C");
--> Mensaje si no se halló ningún dispositivo.

Serial.println("\nEscaneo completo");
--> Mensaje final después de los dos escaneos.

delay(2000);
--> Espera 2 segundos antes de repetir el proceso.

--------------------------------------------------
FIN DEL ARCHIVO
--------------------------------------------------
