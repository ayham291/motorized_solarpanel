#include <MoveMotors.h>

void Motor::init_motor(uint8_t pwr_pin, uint8_t dir_pin, int pos)
{
    pinMode(pwr_pin, OUTPUT);
    digitalWrite(pwr_pin, HIGH); // initial state as off
    this->dir_pin=dir_pin;
    this->pwr_pin=pwr_pin;
    this->pos=pos;
    this->pwr=0;
    this->rot=NXN; // means error ie no rotation
}
// switch motor power on and off
void Motor::switch_pwr(int pwr)
{
    if(pwr==ON)
    {
        digitalWrite(pwr_pin, LOW);
        this->pwr = 1;
    }
    if(pwr==OFF)
    {
        digitalWrite(pwr_pin, HIGH);
        this->pwr = 0;
    }
}
void Motor::rotate(int dir)
{
    if(dir==RIGHT)
    {
        pinMode(this->dir_pin, OUTPUT);
        digitalWrite(this->dir_pin, LOW);
        this->rot = RIGHT;
        this->dir = UP;
        switch_pwr(ON);
    }
    if(dir==LEFT)
    {
        pinMode(this->dir_pin, OUTPUT);
        digitalWrite(this->dir_pin, HIGH);
        this->rot = LEFT;
        this->dir = DOWN;
        switch_pwr(ON);
    }
}
// getter methods
int Motor::get_pwr()
{
    return this->pwr;
}
int Motor::get_dir()
{
    return this->dir;
}
char Motor::get_rot()
{
    return this->rot;
}
