#include <Wire.h>
#include <Arduino.h>
#include <QMC5883LCompass.h>
// values ​​for the QMC5883 control register 1
// operating mode
// #define ADDR 0x1e
#define Mode_Standby 0b00000000
#define Mode_Continuous 0b00000001
// Output data rate
#define ODR_10Hz 0b00000000
#define ODR_50Hz 0b00000100
#define ODR_100Hz 0b00001000
#define ODR_200Hz 0b00001100
// Measure range
#define RNG_2G 0b00000000
#define RNG_8G 0b00010000
// Over sampling rate
#define OSR_512 0b00000000
#define OSR_256 0b01000000
#define OSR_128 0b10000000
#define OSR_64 0b11000000

QMC5883LCompass compass;

// void writeRegister(uint8_t reg, uint8_t val)
// {
// 	Wire.beginTransmission(ADDR);
// 	Wire.write(reg);
// 	Wire.write(val);
// 	Wire.endTransmission();
// }

// //function to read results from QMC5883L
// void readData(int *x, int *y, int *z)
// {
// 	Wire.beginTransmission(ADDR);
// 	Wire.write(0x03);
// 	Wire.endTransmission();
// 	Wire.requestFrom(ADDR, 6);
// 	*x = Wire.read() << 8; //MSB  x
// 	*x |= Wire.read();		//LSB  x
// 	*y = Wire.read() << 8; //MSB z
// 	*y |= Wire.read();		//LSB  z
// 	*z = Wire.read() << 8; //MSB y
// 	*z |= Wire.read();		//LSB y
// }

// //function to set the control register 1 on QMC5883L
// void setCtrlRegister(uint8_t overSampling, uint8_t range, uint8_t dataRate, uint8_t mode)
// {
// 	writeRegister(0x09, overSampling|range|dataRate|mode);
// }

// //function to reset QMC5883L
// void softReset()
// {
// 	writeRegister(0x0a, 0x80);
// 	writeRegister(0x0b, 0x01);
// }

// //prepare hardware
// void setup()
// {
// 	Serial.begin(9600);
// 	Wire.begin();
// 	Serial.println("\rStart\n\r");
// 	// softReset();
// 	setCtrlRegister(OSR_512, RNG_8G, ODR_200Hz, Mode_Continuous);
// 	Serial.println("init done");
// }

// void loop()
// {
// 	int x;
// 	int y;
// 	int z;
// 	float azimut;
// 	readData(&x, &y, &z);
// 	azimut = -atan2(y, x) * 180.0 / PI;
// 	azimut = azimut < 0 ? 360 + azimut : azimut;
// 	Serial.print("X Value: ");
// 	Serial.println(x);
// 	Serial.print("Y Value: ");
// 	Serial.println(y);
// 	Serial.print("Z Value: ");
// 	Serial.println(z);
// 	Serial.print("Richtung: ");
// 	Serial.print(azimut);
// 	Serial.println("°");
// 	Serial.println(); //wait 1 second
// 	delay(1000);
// }
// #include <QMC5883LCompass.h>


// void writeRegister(uint8_t reg, uint8_t val)
// {
// 	Wire.beginTransmission(0x1e);
// 	Wire.write(reg);
// 	Wire.write(val);
// 	Wire.endTransmission();
// }

void setup()
{
	Serial.begin(9600);
	compass.setADDR(0x0D);
	compass.setReset();
	compass.init();
	compass.setSmoothing(5,true);
	// compass.setCalibration(-1207, 1915, -1460, 1935, -1470, 630);
	compass.setMode(Mode_Continuous,ODR_10Hz,RNG_8G,OSR_512);
}

void loop()
{
	int x, y, z;


	// Read compass values
	compass.read();

	// Return XYZ readings
	int a = compass.getAzimuth();
	x = compass.getX();
	y = compass.getY();
	z = compass.getZ();

	Serial.print("X: ");
	Serial.print(x);
	Serial.print(" Y: ");
	Serial.print(y);
	Serial.print(" Z: ");
	Serial.print(z);
	Serial.print(" AZ: ");
	Serial.print(a);
	Serial.println();
	// byte c = compass.getAzimuth();	
	char myArray[3];
	compass.getDirection(myArray, a);

	Serial.print(myArray[0]);
	Serial.print(myArray[1]);
	Serial.print(myArray[2]);
	Serial.println();
	delay(250);
}