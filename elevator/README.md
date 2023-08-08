# **[프로젝트 1] : 엘리베이터**
[엘리베이터 Github] <br>
[엘리베이터 동작영상]

[엘리베이터 Github]: https://github.com/Lateaksoo/Microprocesser/tree/master/elevator#readme
[엘리베이터 동작영상]: https://www.youtube.com/watch?v=zzhDEOv490g

### **개요**
- ATMEGA 2560 과 모터 및 센서를 이용한 엘리베이터 시스템 구현
- RFID 를 이용하여 관리자 점검 카드 기능
- Interrupt를 이용한 버튼 동작

### **개발 중 어려웠던 점**
아두이노는 하나의 Thread만이 동작하기 때문에 delay를 최대한 쓰지 않고 구현해야 하는 점이 힘들었다.   
LCD에 애니메이션을 표시하면 중간에 다른 동작을 할 수 없는 문제가 발생했다. 이를 해결하고자 듀얼코어에서 아이디어를 착안<br>
두개의 아두이노 보드를 사용하기로 했다. 각자 다른 프로그램을 Upload 하고 서로의 상태를 I2C 통신을 이용해 상수값으로 주고 받아 공유 할 수 있도록 구현했다. 

### **프로그램 주요 코드 설명**

2개의 ATMEGA 2560을 이용하여 Multi Thread를 구현하고자 하였다. <br>
두 보드는 I2C 통신을 이용하여 통신 상수를 주고 받는다.

#### [Master Board I2C 통신]
```c++
// I2C 통신 함수
void transferData(char data) {
  Wire.beginTransmission(SLAVE);  // data 전송 시작
  Wire.write(data);               // buffer에 data 저장
  Wire.endTransmission();         // buffer에 저장된 data 전송
}
```
#### [Master Board 통신용 상수]
```c
/**
 통신 용 상수
*/
const char UP = 'u';
const char DOWN = 'd';
const char FIRST_FLOOR_ARRIVED = 'f';
const char SECOND_FLOOR_ARRIVED = 's';
const char THIRD_FLOOR_ARRIVED = 't';
const char EMERGENCY_STOPPED = 'e';
const char MANAGER_TAGED = 'm';
```
---
#### [Slave Board I2C 통신 수신]
```Arduino
/**
  통신 데이터 저장 배열
*/
byte rec[128];

/*
    master로부터 받은 데이터를 rec에 저장
*/
void record(int receiveNum) {
  for (int i = 0; i < receiveNum; i++) {
    rec[i] = Wire.read();
  }
}
```
#### [Slave Board 통신용 상수]
```Arduino
/**
 통신 용 상수
*/
const char UP = 'u';
const char DOWN = 'd';
const char FIRST_FLOOR_ARRIVED = 'f';
const char SECOND_FLOOR_ARRIVED = 's';
const char THIRD_FLOOR_ARRIVED = 't';
const char EMERGENCY_STOPPED = 'e';
```

<br>

2층 버튼에 Interrupt 기능을 사용하여 엘리베이터가 이동중일때 2층 버튼을 누르면 멈추도록 구현하였다.
 ```Arduino
 //Interrupt
 const int SECOND_FLOOR_BUTTON = 3;

 attachInterrupt(digitalPinToInterrupt(SECOND_FLOOR_BUTTON), middleFloorStop, FALLING);
```


<br><br><br>




### **사용된 부품**
|부품명|사용 개수|사용 목적|
|---|---|---
|ATMEGA 2560 Master| 1 |Step Motor 동작, 7-Segment 동작, RC522 RFID 동작, Relay 동작, 버튼 동작 |
|ATMEGA 2560 Slave| 1 |LCD 동작,부저 동작, 비상정지 버튼 동작|
|Push-Button   |4   |엘리베이터의 각 층 버튼 구현 및 비상 호출 버튼
|28BYJ-48 Step Motor|1 |엘리베이터의 상하 이동 
|7-Segment | 3 | 각 층의 번호 표시
|Piezo Buzzer|1 | 엘리베이터 층 도착시 알림음 재생
|RC522 RFID  |1  |엘리베이터 관리자 점검 카드
|Relay Module|1 | 엘리베이터 전원 차단 기능
|LCD | 1| 엘리베이터 움직임 애니메이션, 층 수 표시, 점검중 표시
