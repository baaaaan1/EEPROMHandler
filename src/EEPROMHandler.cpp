#include "EEPROMHandler.h"
#include "stm32f1xx_hal.h"

// Constructor
EEPROMHandler::EEPROMHandler(I2C_HandleTypeDef *hi2c, uint8_t deviceAddress, int baseAddr)
    : hi2c(hi2c), deviceAddress(deviceAddress), baseAddress(baseAddr) {}

// Save an integer to EEPROM
void EEPROMHandler::saveInt(int address, int value) {
    uint8_t data[4];
    data[0] = (baseAddress + address) >> 8; // High byte of address
    data[1] = (baseAddress + address) & 0xFF; // Low byte of address
    data[2] = value >> 8; // High byte of value
    data[3] = value & 0xFF; // Low byte of value

    HAL_I2C_Master_Transmit(hi2c, deviceAddress << 1, data, 4, HAL_MAX_DELAY);
    HAL_Delay(5); // Write cycle time
}

// Read an integer from EEPROM
int EEPROMHandler::readInt(int address) {
    uint8_t addr[2];
    addr[0] = (baseAddress + address) >> 8; // High byte of address
    addr[1] = (baseAddress + address) & 0xFF; // Low byte of address

    HAL_I2C_Master_Transmit(hi2c, deviceAddress << 1, addr, 2, HAL_MAX_DELAY);

    uint8_t data[2];
    HAL_I2C_Master_Receive(hi2c, deviceAddress << 1, data, 2, HAL_MAX_DELAY);

    return (data[0] << 8) | data[1];
}

// Save a boolean to EEPROM
void EEPROMHandler::saveBool(int address, bool value) {
    uint8_t data[3];
    data[0] = (baseAddress + address) >> 8; // High byte of address
    data[1] = (baseAddress + address) & 0xFF; // Low byte of address
    data[2] = value ? 1 : 0; // Boolean value as byte

    HAL_I2C_Master_Transmit(hi2c, deviceAddress << 1, data, 3, HAL_MAX_DELAY);
    HAL_Delay(5); // Write cycle time
}

// Read a boolean from EEPROM
bool EEPROMHandler::readBool(int address) {
    uint8_t addr[2];
    addr[0] = (baseAddress + address) >> 8; // High byte of address
    addr[1] = (baseAddress + address) & 0xFF; // Low byte of address

    HAL_I2C_Master_Transmit(hi2c, deviceAddress << 1, addr, 2, HAL_MAX_DELAY);

    uint8_t data;
    HAL_I2C_Master_Receive(hi2c, deviceAddress << 1, &data, 1, HAL_MAX_DELAY);

    return data != 0;
}

// Save an array of integers to EEPROM
void EEPROMHandler::saveIntArray(int startAddress, int values[], int size) {
    for (int i = 0; i < size; i++) {
        saveInt(startAddress + i * sizeof(int), values[i]);
    }
}