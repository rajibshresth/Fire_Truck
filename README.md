# Fire_Truck

## The Build

|Arduino|Flame Sensor|
|-------|------------|
|Pin 10	|DO, Right Flame Sensor|
|Pin 9	|DO, Left Flame Sensor|
|Pin 8	|DO, Middle Flame Sensor|
|GND	|GND, Right, Left and Straight Flame Sensor|
|5V	|VCC, Right, Left and Straight Flame Sensor|

|Arduino	|Water Pump|
|-------|------------|
|Pin 6	|Water Pump|
|GND	|GND, Right, Left and Straight Flame Sensor|

|Arduino	|Servo Motor|
|-------|------------|
|Pin 11	|Servo Motor|
|GND	|GND|
|5V 	|VCC|


|Driver |Module	Motor|
|-------|------------|
|Output |1	Left Motor|
|Output |2	Left Motor|
|Output |3	Right Motor|
|Output| 4	Right Motor|


|Motor Driver Module|	Node MCU|
|-------|------------|
|IN1|	GPIO15(D8)|
|IN2|	GPIO13(D)|
|IN3|	GPIO2(D4)|
|IN4|	GPIO0(D3)|
|Enable 1	|GPIO14(D5)|
|Enable 2	|GPIO12(D6)|

## Circuit Layout
![image](https://user-images.githubusercontent.com/48651522/112641048-1bdbcf80-8e6a-11eb-810a-ab9cc655b000.png)
![image](https://user-images.githubusercontent.com/48651522/112641115-29915500-8e6a-11eb-902a-3aa9520c7ac5.png)

## Working Video
https://www.youtube.com/watch?v=KY998VfwrAU
