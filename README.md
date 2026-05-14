# Anything You Want - Arduino Lyrical Display

*A transcription of Reality Club's masterpiece, "Anything You Want", breathing life into a mechanical display.*

##

https://github.com/user-attachments/assets/25444e44-6e7d-45b8-8ded-f16c454396e2

 The Feature

**A Synchronized Visual Serenade**
This project dedicates itself entirely to one singular, beautiful purpose: displaying the lyrics of "Anything You Want" in perfect harmony with the song's natural rhythm. 

Through carefully calibrated timings, the Arduino transforms lines of code into a rhythmic visual performance on a 16x2 LCD screen. It elegantly wraps longer phrases so words are never clumsily cut off, and gracefully center-aligns every line to draw the eye to the heart of the poetry. 

It is a quiet, glowing tribute to the song, played on repeat.

---

## 📖 Documentation of Uses

To bring this lyrical display to life on your own hardware, follow these instructions:

### Hardware Requirements
- **1x** Arduino Board (e.g., Arduino Uno, Nano)
- **1x** 16x2 LCD Display equipped with an I2C module
- Jumper wires

### Wiring Guide
Connect the I2C LCD module to your Arduino as follows:
- **GND** to **GND**
- **VCC** to **5V**
- **SDA** to the Arduino's **SDA** pin (A4 on Arduino Uno)
- **SCL** to the Arduino's **SCL** pin (A5 on Arduino Uno)

### Software Setup & Execution
1. **Prepare the IDE:** Open the Arduino IDE on your computer.
2. **Install Dependencies:** Ensure you have the `Adafruit_LiquidCrystal` library installed. You can add it via the Library Manager (`Sketch` > `Include Library` > `Manage Libraries...`).
3. **Load the Code:** Open the `zed.cpp` file. *(Note: If you are using the standard Arduino IDE, you may need to rename this file to `zed.ino` or paste its contents into a fresh `.ino` sketch).*
4. **Configure the Display:** Verify the I2C address on line 5: `Adafruit_LiquidCrystal lcd(0);`. If your display remains blank after uploading, you may need to change `0` to your specific I2C address, such as `0x27` or `0x3F`.
5. **Upload:** Select your specific Arduino board and COM port from the `Tools` menu, then click **Upload**.
6. **Experience:** Sit back as the backlight illuminates and the words begin their timed, rhythmic dance across the glass.
