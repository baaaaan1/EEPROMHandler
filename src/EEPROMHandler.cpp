#include "EEPROMHandler.h"

EEPROMHandler::EEPROMHandler(uint8_t deviceAddress, int baseAddr)
    : deviceAddress(deviceAddress), baseAddress(baseAddr) {}

void EEPROMHandler::saveInt(int address, int value) {
    Wire.beginTransmission(deviceAddress);
    Wire.write((baseAddress + address) >> 8); // High byte
    Wire.write((baseAddress + address) & 0xFF); // Low byte
    Wire.write(value >> 8); // High byte of value
    Wire.write(value & 0xFF); // Low byte of value
    Wire.endTransmission();
    delay(5); // Write cycle time
}

int EEPROMHandler::readInt(int address) {
    Wire.beginTransmission(deviceAddress);
    Wire.write((baseAddress + address) >> 8);
    Wire.write((baseAddress + address) & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(deviceAddress, (uint8_t)2);
    int value = (Wire.read() << 8) | Wire.read();
    return value;
}

void EEPROMHandler::saveBool(int address, bool value) {
    Wire.beginTransmission(deviceAddress);
    Wire.write((baseAddress + address) >> 8);
    Wire.write((baseAddress + address) & 0xFF);
    Wire.write(value);
    Wire.endTransmission();
    delay(5);
}

bool EEPROMHandler::readBool(int address) {
    Wire.beginTransmission(deviceAddress);
    Wire.write((baseAddress + address) >> 8);
    Wire.write((baseAddress + address) & 0xFF);
    Wire.endTransmission();

    Wire.requestFrom(deviceAddress, (uint8_t)1);
    return Wire.read();
}

void EEPROMHandler::saveIntArray(int startAddress, int values[], int size) {
    for (int i = 0; i < size; i++) {
        saveInt(startAddress + i * sizeof(int), values[i]);
    }
}

void EEPROMHandler::readIntArray(int startAddress, int values[], int size) {
    for (int i = 0; i < size; i++) {
        values[i] = readInt(startAddress + i * sizeof(int));
    }
}
