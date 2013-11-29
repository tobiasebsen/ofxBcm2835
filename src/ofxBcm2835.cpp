//
//  ofxBcm2835.cpp
//  bcm2835
//
//  Created by Tobias Ebsen on 29/11/13.
//
//

#include "ofxBcm2835.h"
#include "bcm2835.h"

bool ofxBcm2835::init() {
#if defined(TARGET_RASPBERRY_PI)
    return bcm2835_init();
#else
    return false;
#endif
}

bool ofxBcm2835::close() {
#if defined(TARGET_RASPBERRY_PI)
    return bcm2835_close();
#else
    return false;
#endif
}

void ofxBcm2835::pinMode(int pin, int mode) {
#if defined(TARGET_RASPBERRY_PI)
    int port = digitalPinToPort(pin);
    if (mode == OUTPUT)
        bcm2835_gpio_fsel(port, BCM2835_GPIO_FSEL_OUTP);
    if (mode == INPUT)
        bcm2835_gpio_fsel(port, BCM2835_GPIO_FSEL_INPT);
    if (mode == INPUT_PULLUP) {
        bcm2835_gpio_fsel(port, BCM2835_GPIO_FSEL_INPT);
        bcm2835_gpio_set_pud(port, BCM2835_GPIO_PUD_UP);
    }
#endif
}

void ofxBcm2835::digitalWrite(int pin, int state) {
#if defined(TARGET_RASPBERRY_PI)
    int port = digitalPinToPort(pin);
    bcm2835_gpio_write(port, state);
#endif
}

int ofxBcm2835::digitalRead(int pin) {
#if defined(TARGET_RASPBERRY_PI)
    int port = digitalPinToPort(pin);
    return bcm2835_gpio_lev(port);
#endif
}

int ofxBcm2835::digitalPinToPort(int pin) {
    switch (pin) {
        case 3: return RPI_GPIO_P1_03;
        case 5: return RPI_GPIO_P1_05;
        case 7: return RPI_GPIO_P1_07;
        case 8: return RPI_GPIO_P1_08;
        case 10: return RPI_GPIO_P1_10;
        case 11: return RPI_GPIO_P1_11;
        case 12: return RPI_GPIO_P1_12;
        case 13: return RPI_GPIO_P1_13;
        case 15: return RPI_GPIO_P1_15;
        case 16: return RPI_GPIO_P1_16;
        case 18: return RPI_GPIO_P1_18;
        case 19: return RPI_GPIO_P1_19;
        case 21: return RPI_GPIO_P1_21;
        case 22: return RPI_GPIO_P1_22;
        case 23: return RPI_GPIO_P1_23;
        case 24: return RPI_GPIO_P1_24;
        case 26: return RPI_GPIO_P1_26;
    }
    return 0;
}