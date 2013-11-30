//
//  ofxBcm2835.h
//  bcm2835
//
//  Created by Tobias Ebsen on 29/11/13.
//
//

#pragma once

namespace ofxBcm2835 {

#define INPUT           0x00
#define OUTPUT          0x01
#define INPUT_PULLUP    0x02
    
#if !defined(LOW) && !defined(HIGH)
#define LOW     0x00
#define HIGH    0x01
#endif

    bool init();
    bool close();
    
    void pinMode(int pin, int mode);
    void digitalWrite(int pin, int state);
    int  digitalRead(int pin);
    
    int digitalPinToPort(int pin);
    
    class ClassSerial {
    public:
        ClassSerial() : uart0_filestream(-1) {}

        void begin(int speed);
        void end();

        int  write(unsigned char* buf, int len);

    private:
        int uart0_filestream;
    };
    
    static ClassSerial Serial;
}
