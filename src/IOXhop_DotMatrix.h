#ifndef __IOXHOP_DOTMATRIX_H__
#define __IOXHOP_DOTMATRIX_H__

#include "Arduino.h"
#include "SPI.h"

class IOXhop_DotMatrix {
    private:
        int _cs_pin, _dio_pin, _clk_pin;
        int display_number;

        uint8_t *bufferDisplay = NULL;

        void _write(uint8_t cmd, uint8_t data) ;
        int calcTextWidth(String text) ;

    public:
#if defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_ARCH_ESP8266)
        IOXhop_DotMatrix(int max_device=8, int cs=5, int dio=23, int clk=18) ;
#else
        IOXhop_DotMatrix(int max_device=8, int cs=13) ;
#endif
        void begin() ;

        void shutdown(bool value = false) ;
        void intensity(int level = 15) ;

        void invertColor(bool showOnDisplay = true) ;
        void show() ;
        void showText(String text, int top = 0, int left = 0, bool invert = false) ;
        void showTextCenter(String text) ;

        void scrollInLeft(String text, int speed) ;
        void scrollOutLeft(String text, int speed) ;
        void scrollInRight(String text, int speed) ;
        void scrollOutRight(String text, int speed) ;
        void scrollInTop(String text, int speed) ;
        void scrollOutTop(String text, int speed) ;
        void scrollInBottom(String text, int speed) ;
        void scrollOutBottom(String text, int speed) ;

};

#endif