#ifndef EEPROMHANDLER_H
#define EEPROMHANDLER_H

#include "stm32f1xx_hal.h" // Include STM32 HAL header

class EEPROMHandler {
private:
    I2C_HandleTypeDef *hi2c; // Pointer to the I2C peripheral handle
    uint8_t deviceAddress;   // I2C device address
    int baseAddress;         // Base address for EEPROM operations

public:
    // Constructor
    EEPROMHandler(I2C_HandleTypeDef *hi2c, uint8_t deviceAddress, int baseAddr = 0x0000);

    // Basic functions for saving and reading data
    void saveInt(int address, int value);
    int readInt(int address);

    void saveBool(int address, bool value);
    bool readBool(int address);

    // Utility functions for saving and reading arrays
    void saveIntArray(int startAddress, int values[], int size);
    void readIntArray(int startAddress, int values[], int size);
};

#endif
