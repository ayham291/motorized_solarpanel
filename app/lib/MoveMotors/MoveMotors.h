#ifndef __MOVE_
#define __MOVE_

class Motor
{
private:
    int pwr_pin;
    int dir_pin;
    int pos;
    int pwr;
    char rot;
public:
    void init_motor(uint8_t pwr_pin, uint8_t dir_pin, int pos);
    void switch_pwr(char pwr);
    void rotate(int dir);
    int get_pwr();
    int get_dir();
    int get_rot();
};

#endif

