#include <MoveMotors.h>
#include <Arduino.h>

void Motor::init_motor(uint8_t pwr_pin, uint8_t dir_pin, int pos)
{
    pinMode(pwr_pin, OUTPUT);
    digitalWrite(pwr_pin, LOW); // initial state as off
    this->dir_pin=dir_pin;
    this->pwr_pin=pwr_pin;
    this->pos=pos;
    this->pwr=0;
    this->rot="NaN"; // means error ie no rotation
}
// switch motor power on and off
void Motor::switch_pwr(char pwr)
{
   /* TO BE IMPLEMENTED:
        - TIMED SWITCH
        - DEGREES -> SECONDS
   */
    if(pwr=="on")
    {
        digitalWrite(pwr_pin, HIGH);
        this->pwr = 1;
    }
    if(pwr=="off")
    {
        digitalWrite(pwr_pin, LOW);
        this->pwr = 0;
    }
}
void Motor::rotate(int dir)
{
    if(dir==0)
    {
        pinMode(this->dir_pin, OUTPUT);
        digitalWrite(this->dir_pin, LOW);
        this->rot = "Left";
    }
    if(dir==1)
    {
        pinMode(this->dir_pin, OUTPUT);
        digitalWrite(this->dir_pin, HIGH);
        this->rot = "Right";
    }

/*     switch(dir) */
/*     { */
/*         case 0: */
/*             pinMode(this->dir_pin, OUTPUT); */
/*             digitalWrite(this->dir_pin, LOW); */
/*             this->rot = dir; */
/*             break; */
/*         case 1: */
/*             pinMode(this->dir_pin, OUTPUT); */
/*             digitalWrite(this->dir_pin, HIGH); */
/*             this->rot = dir; */
/*             break; */
/*         default: */
/*             break; */
/*     } */
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
