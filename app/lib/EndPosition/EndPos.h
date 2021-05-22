#ifndef __ENDPOS_
#define __ENDPOS_

#include <Arduino.h>

class EndPos
{
    private:
        int PosPhiUp; // 0 if detected
        int PosPhiDown; // 0 if detected
    public:
        void init_sensors(uint8_t pinUp, uint8_t pinDown);
        int getPosPhiUp();
        int getPosPhiDown();
        void Serial_Print();
};

#endif
