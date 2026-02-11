// ========================================================================
//                      🔸 I 2 C  -  S C A N 🔸
// ========================================================================
//  Archivo    : I2C--Scan.ino
//  Autor      : Klaus Michalsky
//  Fecha      : Feb-2026
//
//  ESTADO
//  -----------------------------------------------------------------------
//  ✅ Funcional
// ========================================================================

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
