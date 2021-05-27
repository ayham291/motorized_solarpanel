#ifndef __MOVE_
#define __MOVE_
#include <Arduino.h>
#include <EndPos.h>

#define NXN 3
#define ON 1
#define OFF 0
#define LEFT 0
#define RIGHT 1
#define UP 1
#define DOWN 0


class Motor
{
private:
    int pwr_pin;
    int dir_pin;
    int dir;
    int pos;
    int pwr;
    int rot;
    EndPos endPos;
public:
    void init_motor(uint8_t pwr_pin, uint8_t dir_pin, int pos);
    void switch_pwr(int pwr);
    void rotate(int dir);
    int get_pwr();
    int get_dir();
    char get_rot();
};

#endif

