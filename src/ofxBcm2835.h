//
//  ofxBcm2835.h
//  bcm2835
//
//  Created by Tobias Ebsen on 29/11/13.
//
//

#pragma once

#define INPUT   0x00
#define OUTPUT  0x01

#define LOW     0x00
#define HIGH    0x01

class ofxBcm2835 {
public:

    static bool init();
    static bool close();
    
    static void pinMode(int pin, int mode);
    static void digitalWrite(int pin, int state);
    
    static int digitalPinToPort(int pin);
};
