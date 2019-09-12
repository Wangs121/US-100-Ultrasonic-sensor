#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "US_100.h"

US100::US100(char Echo,char Trig,unsigned short t)
{
	Echo_pin = Echo;
	Trig_pin = Trig;
	wait_Time = t;
	GPIO_Mode();
  get_distance = &US100::GPIO_get_Distance;
}
US100::US100(unsigned int t)
{
  wait_Time = t;
  get_distance = &US100::UART_get_Distance;
}
void US100::GPIO_Mode(void)
{
	pinMode(Echo_pin,INPUT);
	pinMode(Trig_pin,OUTPUT);
}
unsigned long US100::get_Distance(void)
{
  return (*this.*get_distance)();
}
unsigned long US100::GPIO_get_Distance(void)
{
 
	digitalWrite(Trig_pin,HIGH);
	delayMicroseconds(wait_Time);
	digitalWrite(Trig_pin,LOW);

	Time_Echo_us = pulseIn(Echo_pin,HIGH);
	if((Time_Echo_us < 60000) && (Time_Echo_us > 1))     //a valid pulse width should be between (1, 60000).
		return (Time_Echo_us*34/100)/2; 
	return 0;
}

unsigned long US100::UART_get_Distance(void)
{
	Serial.flush();     // clear receive buffer of serial port
	Serial.write(0X55); // trig US-100 begin to measure the distance
	delay(500);          //delay wait_Time(ms) to wait result
	if(Serial.available() >= 2)                    //when receive 2 bytes 
    {
       
        HighLen = Serial.read();                   //High byte of distance
        LowLen  = Serial.read();                   //Low byte of distance
        Distance  = HighLen*256 + LowLen;             //Calculate the distance
        if((Distance > 1) && (Distance < 10000))        //normal distance should between 1mm and 10000mm (1mm, 10m)
        {
			  return Distance;
        }
    }
	return 0;
}

unsigned long US100::get_Temperature(void)
{
	Serial.flush();       // clear receive buffer of serial port
	Serial.write(0X50);   // trig US-100 begin to measure the temperature
	delay(wait_Time);          //delay wait_Time(ms) to wait result
	if(Serial.available() >= 1)            //when receive 1 bytes 
    {
        Temperature = Serial.read();     //Get the received byte (temperature)
        if((Temperature > 1) && (Temperature < 130))   //the valid range of received data is (1, 130)
        {
            return (Temperature - 45);                           //Real temperature = Received_Data - 45
        }
    }
	return 0;
}
