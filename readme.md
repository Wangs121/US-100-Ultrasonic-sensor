## A library for Arduino to use US-100 Ultrasound sensor .
* ### use GPIO mode and UART mode to get Distance 
* ### use UART to get Temperature
#### Using UART:

* ##### initialize
``` C++
US100 mysonic1(2,3,50);
```
*  ##### Get Distance:
``` C++
mysonic1.get_Distance();
```

####  Using GPIO:
* ##### initialize
``` C++
US100 mysonic1(100);
```
*  ##### Get Distance:
``` C++
mysonic1.get_Distance();
```

see more in example folder.

