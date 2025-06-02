#ifndef EEPROMHANDLER_H
#define EEPROMHANDLER_H

#include <Wire.h>

class EEPROMHandler {
private:
    uint8_t deviceAddress;
    int baseAddress;

public:
    EEPROMHandler(uint8_t deviceAddress, int baseAddr = 0x0000);

    // Fungsi dasar untuk menyimpan dan membaca data
    void saveInt(int address, int value);
    int readInt(int address);

    void saveBool(int address, bool value);
    bool readBool(int address);

    // Fungsi utilitas untuk membaca atau menyimpan array
    void saveIntArray(int startAddress, int values[], int size);
    void readIntArray(int startAddress, int values[], int size);
};

#endif
