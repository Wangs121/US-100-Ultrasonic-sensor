#ifndef US_100_h
#define US_100_h


class US100
{
	public:

	US100(char Echo,char Trig,unsigned short t);//GPIO Mode
	US100(unsigned int t);//UART Mode
	unsigned long get_Distance(void);
	unsigned long get_Temperature(void);

	private:
	
	void GPIO_Mode(void);
	unsigned long (US100::*get_distance)(void);
	unsigned short wait_Time;//us, at least 10
	unsigned char Echo_pin;
	unsigned char Trig_pin;
	unsigned long Time_Echo_us;
	unsigned int LowLen;
	unsigned int HighLen;
	unsigned int Distance;
	unsigned long Temperature;
	unsigned long GPIO_get_Distance(void);
	unsigned long UART_get_Distance(void);
  
};
#endif
