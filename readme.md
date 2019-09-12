## A library to use US-100 Ultrasound sensor easier.

### for example :

Using GPIO to read distance:

``` c++
#include <US_100.h>

//use GPIO to read tempeature
//    US-100   ARDUINO
//Pin  Echo      P2
//Pin  Trig      P3

//attach to P2(Echo) and 3(Trig)
//wait 50us after send command(shoud be more than 10)
US100 mysonic1(2,3,50);

void setup() {
Serial.begin(9600);
}

void loop() {
Serial.println(mysonic1.get_Distance());
}
```



see more in example folder.