# ESCÁNER I2C DUAL PARA RP2040 ZERO (Wire + Wire1) 🔹
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
