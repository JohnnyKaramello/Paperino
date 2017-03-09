//**************************************************************
//PAPERINO: Hello World example. The shortest possible  code ;-)
//**************************************************************

#include "Adafruit_mfGFX.h"
#include "PL_microEPD.h"

#define EPD_CS      D5
#define EPD_RST     A0
#define EPD_BUSY    A1

PL_microEPD display(EPD_CS, EPD_RST, EPD_BUSY);  

void setup() {
    SPI.beginTransaction(SPISettings(8000000, MSBFIRST, SPI_MODE0));    //UC8156 supporting max. 10Mhz (writing) and 6.6Mhz (reading)
    display.begin(true);                    //Initializing. TRUE=Initial update to refresh the screen to defined state
    display.setCursor(1,4);
    display.clear();
    display.print("Hello BLUZ!!!");          //Writes content into image buffer
    display.updateFull();                   //Triggers a full image update, showing content of the imagebuffer
    delay(5000);
    display.clear();
    display.updateFull();  
    SPI.endTransaction();
}

void loop() {
}
