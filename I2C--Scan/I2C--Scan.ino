/************************************************************************************************************
 🔹 ESCÁNER I2C DUAL PARA RP2040 ZERO (Wire + Wire1) 🔹
  - Escanea los dos buses I2C del RP2040:
        • Wire  → SDA = GP4,  SCL = GP5
        • Wire1 → SDA = GP26, SCL = GP27
  - Recorre todas las direcciones I2C (0x01 a 0x7E) y detecta
    cualquier dispositivo conectado en cada bus.
  - Muestra en el Serial Monitor las direcciones donde un
    dispositivo responde correctamente.
  - Útil para diagnosticar sensores como AS5600, OLED I2C,
    IMU, ADC externos, expansores, etc.
  - Pensado para tu Zero usando dos buses en paralelo.

  K. Michalsky – 11.2025
*************************************************************************************************************/

#include <Wire.h>

void setup()
{
    Serial.begin(115200);

    // Configura pines I2C del Zero
    Wire.setSDA(4);   // SDA del bus I2C principal
    Wire.setSCL(5);   // SCL del bus I2C principal
    Wire1.setSDA(26); // SDA del bus I2C secundario
    Wire1.setSCL(27); // SCL del bus I2C secundario

    Wire.begin();  // Inicializa bus I2C principal
    Wire1.begin(); // Inicializa bus I2C secundario

    Serial.println("Escaneando I2C en Wire...");
    Serial.println("Escaneando I2C en Wire1...");
}

void loop()
{
    byte error, address;
    int found = 0;

    // -----------------------------
    // Escaneo del bus Wire (4,5)
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
    // Escaneo del bus Wire1 (26,27)
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
