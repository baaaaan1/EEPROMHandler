EEPROMHandler Library
=====================

EEPROMHandler is a lightweight library designed to simplify storing and retrieving data from AT24C256 EEPROM using STM32 HAL. The library supports storing integers, booleans, and arrays, and can be extended as needed for your project.

Features
--------

*   Save and read integer and boolean values to/from EEPROM.
*   Support for saving and reading arrays of integers.
*   Easy-to-use interface with intuitive methods.
*   Compatible with I2C-based EEPROM modules like AT24C256.
*   Optimized for STM32 HAL.

Installation
------------

### Clone Repository

You can clone the repository using the following command:

```bash
git clone https://github.com/baaaaan1/EEPROMHandler.git
```

Add to Your STM32 Project
Place the library files (EEPROMHandler.h and EEPROMHandler.cpp) in your STM32 project directory and include them in your project.

Usage
1. Initialization
Include the library in your STM32 project:

```bash
#include "EEPROMHandler.h"
```
Initialize the EEPROMHandler object with the I2C peripheral handle, device address, and base address:

```bash
I2C_HandleTypeDef hi2c1; // Example I2C handle
EEPROMHandler eeprom(&hi2c1, 0x50, 0x0000); // Device address 0x50, base address 0x0000
```
2. Save and Read Data
Save an integer to EEPROM:

```bash
eeprom.saveInt(0x10, 12345); // Save 12345 at address 0x10
```

Read an integer from EEPROM:

```bash
int value = eeprom.readInt(0x10); // Read value from address 0x10
```

Save a boolean to EEPROM:

```bash
eeprom.saveBool(0x20, true); // Save true at address 0x20
```

Read a boolean from EEPROM:

```bash
bool flag = eeprom.readBool(0x20); // Read boolean from address 0x20
```

Save an array of integers to EEPROM:

```bash
int values[] = {10, 20, 30};
eeprom.saveIntArray(0x30, values, 3); // Save array starting at address 0x30
```

Read an array of integers from EEPROM:

```bash
int readValues[3];
eeprom.readIntArray(0x30, readValues, 3); // Read array starting at address 0x30
```

Notes
Ensure the I2C peripheral is properly initialized in your STM32 project before using the library.
Adjust the device address and base address as needed for your EEPROM module.
License
This library is licensed under the GNU General Public License v3.0. See the LICENSE file for details.


### Key Changes:
1. **Removed Arduino-Specific Instructions**:
   - Removed references to Arduino IDE and `Wire.h`.

2. **Added STM32 HAL Instructions**:
   - Updated initialization and usage examples to reflect STM32 HAL compatibility.

3. **Updated Installation Instructions**:
   - Provided instructions for adding the library to an STM32 project.

4. **Retained License Information**:
   - Included a note about the GNU GPL license.

This updated [README.md](http://_vscodecontentref_/2) ensures the library documentation is aligned with STM32 development practices.