# arduino-displays
Libaries, wiring, and example code for various small displays used with Arduino and other microprocessors



| Image | Chipset  | Type | Resolution  | Interface | Code  | Purchase |
| -------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- |
| ![](Images/TM1637.jpg) | TM1637 | 7-segment | 4-digit | <a href="https://green-possum-today.blogspot.com/2018/10/a-comparison-of-tm1637-protocol-with.html">Custom Serial (I2C variant)</a> | https://github.com/avishorp/TM1637 | https://www.banggood.com/custlink/GDD3zSq2qk |
| ![](Images/MAX7219.jpg) | MAX7219 | 7-segment  | 8-digit | SPI | https://github.com/wayoda/LedControl |  |
| ![](Images/MAX7219_matrix.jpg) | MAX7219 | 8x8 | 8x8 | SPI | https://github.com/wayoda/LedControl / https://github.com/MajicDesigns/MD_Parola |  |
| ![](Images/LCD1602.jpg) | HD44780 | LCD | 16x2 character (each char 5x8) | I2C | https://github.com/mathertel/LiquidCrystal_PCF8574 |  |
| ![](Images/LCD2004.jpg) | HD44780 | LCD  | 20x4 character (each char 5x8) | I2C | https://github.com/mathertel/LiquidCrystal_PCF8574 |  |
| ![](Images/LCD12864.jpg) | [ST7920] (Identifiabale by pins labelled PSB/NC ) | LCD | 128x64 | SPI | https://github.com/olikraus/u8g2 (using constructor as U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, 10, 8); )|  |
| ![](Images/RepRapDiscount.jpg) | [ST7920 "RepRap Discount")](#ST7920) | LCD | 128x64 | SPI | https://github.com/olikraus/u8g2 (using constructor as U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, 10, 8); )| https://www.banggood.com/custlink/K33E9qkcUv |
| ![](Images/ANet.jpg) | [ST7920 ("ANet")](#ST7920) | LCD | 128x64 | SPI | https://github.com/olikraus/u8g2 (using constructor as U8G2_ST7920_128X64_1_HW_SPI u8g2(U8G2_R0, 10, 8); )| https://www.banggood.com/custlink/3KGYiMkCzy |
| ![](Images/OLED91.jpg) | SSD1306 | OLED | 128x32  | I2C | https://github.com/lexus2k/lcdgfx |  |
| ![](Images/OLED96.jpg) | SSD1306 | OLED | 128x64 | I2C | https://github.com/lexus2k/lcdgfx |  |
| ![](Images/eInk.jpg) | e-Ink  | e-Ink | Variable | SPI | https://github.com/waveshare/e-Paper |  |
| ![](Images/tft.jpg) | ILI9486 | TFT | Variable | 8-bit parallel | https://github.com/prenticedavid/MCUFRIEND_kbv |  |



#ST7920
ST7920 is a popular controller chip used to 12864 LCD panels.
