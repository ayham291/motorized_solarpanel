#ifndef __ENDPOS_
#define __ENDPOS_

#include <Arduino.h>

class EndPos
{
    private:
        int PosPhiUp; // 0 if detected
        int PosPhiDown; // 0 if detected
        uint8_t pinUp;
        uint8_t pinDown;
    public:
        void init_sensors(uint8_t pinUp, uint8_t pinDown);
        int getPosPhiUp();
        void read_pins();
        int getPosPhiDown();
        void Serial_Print();
};

#endif
