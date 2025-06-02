#include <Wire.h>
#include "EEPROMHandler.h"

// Inisialisasi library dengan alamat EEPROM (0x50 default untuk AT24C256)
EEPROMHandler eeprom(0x50);

void setup() {
    Serial.begin(9600);
    Wire.begin();

    Serial.println("EEPROM Handler Example");

    // Data untuk disimpan
    int value1 = 1234;
    bool flag = true;
    int numbers[5] = {10, 20, 30, 40, 50};

    // Menyimpan data
    eeprom.saveInt(0, value1);
    eeprom.saveBool(10, flag);
    eeprom.saveIntArray(20, numbers, 5);

    Serial.println("Data saved!");

    // Reset nilai untuk pengujian baca
    value1 = 0;
    flag = false;
    for (int i = 0; i < 5; i++) numbers[i] = 0;

    // Membaca kembali data
    value1 = eeprom.readInt(0);
    flag = eeprom.readBool(10);
    eeprom.readIntArray(20, numbers, 5);

    // Menampilkan hasil baca
    Serial.println("Data read:");
    Serial.print("value1: "); Serial.println(value1);
    Serial.print("flag: "); Serial.println(flag);
    Serial.print("numbers: ");
    for (int i = 0; i < 5; i++) {
        Serial.print(numbers[i]); Serial.print(" ");
    }
    Serial.println();
}

void loop() {
    // Kosong
}
