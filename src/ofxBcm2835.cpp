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
    return bcm2835_init();
}

bool ofxBcm2835::close() {
    return bcm2835_close();
}

void ofxBcm2835::pinMode(int pin, int mode) {
    int port = digitalPinToPort(pin);
    bcm2835_gpio_fsel(port, mode == OUTPUT ? BCM2835_GPIO_FSEL_OUTP : BCM2835_GPIO_FSEL_INPT);
}

void ofxBcm2835::digitalWrite(int pin, int state) {
    int port = digitalPinToPort(pin);
    bcm2835_gpio_write(port, state);
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