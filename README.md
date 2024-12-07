EEPROMHandler Library
=====================

EEPROMHandler adalah library sederhana untuk mempermudah penyimpanan dan pembacaan data dari modul EEPROM AT24C256 menggunakan Arduino dan perangkat berbasis I2C lainnya. Library ini mendukung penyimpanan tipe data integer, boolean, dan array, serta dapat diperluas sesuai kebutuhan proyek Anda.

Fitur
--------

*   Menyimpan dan membaca nilai integer dan boolean ke/dari EEPROM.
*   Mendukung penyimpanan dan pembacaan array integer.
*   Mudah digunakan dengan antarmuka yang intuitif.
*   Kompatibel dengan modul EEPROM berbasis I2C seperti AT24C256.

Instalasi
------------

### Download atau Clone Repository

Anda dapat mengunduh file ZIP dari repository ini atau menggunakan perintah git:

```bash
git clone https://github.com/baaaaan1/EEPROMHandler.git
```

### Pindahkan ke Folder Library Arduino

Ekstrak folder dan tempatkan di direktori library Arduino Anda:

```bash
Documents/Arduino/libraries/EEPROMHandler
```

### Restart Arduino IDE

Setelah instalasi, restart Arduino IDE agar library dikenali.

Cara Penggunaan
----------------

### 1. Inisialisasi

Tambahkan library di bagian awal program Anda:

```cpp
#include <Wire.h>
#include "EEPROMHandler.h"
```

Inisialisasi library dengan alamat EEPROM:

```cpp
EEPROMHandler eeprom(0x50); // 0x50 adalah alamat I2C default
```

### 2. Menyimpan Data

Gunakan fungsi `saveInt()`, `saveBool()`, atau `saveIntArray()` untuk menyimpan data:

```cpp
eeprom.saveInt(0, 1234); // Simpan integer 1234 di alamat 0
eeprom.saveBool(10, true); // Simpan nilai boolean true di alamat 10

int numbers[] = {10, 20, 30, 40, 50};
eeprom.saveIntArray(20, numbers, 5); // Simpan array integer di alamat 20
```

### 3. Membaca Data

Gunakan fungsi `readInt()`, `readBool()`, atau `readIntArray()` untuk membaca data:

```cpp
int value = eeprom.readInt(0); // Baca integer dari alamat 0
bool flag = eeprom.readBool(10); // Baca boolean dari alamat 10

int readNumbers[5];
eeprom.readIntArray(20, readNumbers, 5); // Baca array dari alamat 20
```

### 4. Contoh Program Lengkap

Berikut adalah program lengkap yang dapat dicoba:

```cpp
#include <Wire.h>
#include "EEPROMHandler.h"

EEPROMHandler eeprom(0x50);

void setup() {
    Serial.begin(9600);
    Wire.begin();

    // Menyimpan data
    eeprom.saveInt(0, 1234);
    eeprom.saveBool(10, true);

    int numbers[] = {10, 20, 30, 40, 50};
    eeprom.saveIntArray(20, numbers, 5);

    Serial.println("Data saved!");

    // Membaca data
    int value = eeprom.readInt(0);
    bool flag = eeprom.readBool(10);

    int readNumbers[5];
    eeprom.readIntArray(20, readNumbers, 5);

    // Menampilkan data yang dibaca
    Serial.println("Data read:");
    Serial.print("value: "); Serial.println(value);
    Serial.print("flag: "); Serial.println(flag);

    Serial.print("numbers: ");
    for (int i = 0; i < 5; i++) {
        Serial.print(readNumbers[i]); Serial.print(" ");
    }
    Serial.println();
}

void loop() {
    // Kosong
}
```

Struktur File
--------------

```css
EEPROMHandler/
├── examples/
│   └── EEPROMHandlerExample/
│       └── EEPROMHandlerExample.ino
├── src/
│   ├── EEPROMHandler.cpp
│   └── EEPROMHandler.h
├── library.properties
```

Kontribusi
------------

Kontribusi dalam bentuk peningkatan fitur, optimasi, atau pelaporan bug sangat diterima! Anda dapat melakukan pull request atau membuat issue di repository ini untuk membantu meningkatkan kualitas library ini.

Lisensi
--------

Proyek ini dilisensikan di bawah GPL-3.0 License. Anda bebas menggunakan, memodifikasi, dan mendistribusikan library ini sesuai dengan ketentuan lisensi. Perlu diingat bahwa setiap penggunaan, modifikasi, atau pendistribusian harus mematuhi ketentuan lisensi dan menyertakan keterangan tentang sumber asli library ini.

Kontak
--------

Jika Anda memiliki pertanyaan, saran, atau ingin berkontribusi, jangan ragu untuk menghubungi kami melalui email atau issue di GitHub. Kami senang membantu dan menerima umpan balik dari Anda!