#include "EEPROMHandler.h"

// Initialize the I2C peripheral handle (example: hi2c1)
extern I2C_HandleTypeDef hi2c1; // Ensure this is defined and initialized in your STM32 project

// Initialize the EEPROMHandler object with the I2C handle, device address, and base address
EEPROMHandler eeprom(&hi2c1, 0x50, 0x0000); // Device address 0x50, base address 0x0000

void setup() {
    // Example setup code for STM32 (if needed)
    // Ensure the I2C peripheral is initialized before using the EEPROMHandler library

    // Data to be saved
    int value1 = 1234;
    bool flag = true;
    int numbers[5] = {10, 20, 30, 40, 50};

    // Save data to EEPROM
    eeprom.saveInt(0, value1);
    eeprom.saveBool(10, flag);
    eeprom.saveIntArray(20, numbers, 5);

    // Reset values for testing read operations
    value1 = 0;
    flag = false;
    for (int i = 0; i < 5; i++) numbers[i] = 0;

    // Read data back from EEPROM
    value1 = eeprom.readInt(0);
    flag = eeprom.readBool(10);
    eeprom.readIntArray(20, numbers, 5);

    // Display results (replace with your STM32 debugging method, e.g., UART or LEDs)
    // Example: Print results via UART
    printf("Data read:\n");
    printf("value1: %d\n", value1);
    printf("flag: %d\n", flag);
    printf("numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

void loop() {
    // Empty loop (if needed for STM32 project structure)
}