#ifndef __ENDPOS_
#define __ENDPOS_

class EndPos
{
    private:
        int PosX; // 0 if detected
        int PosPhi; // 0 if detected
    public:
        void init_sensors(uint8_t pinUp, uint8_t pinDown);
        int getPosPhiUp();
        int getPosPhiDown();
        void Serial_Print();
}


#endif

