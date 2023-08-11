# **[프로젝트 1] : 엘리베이터**
[엘리베이터 Github] <br>
[엘리베이터 동작영상]

[엘리베이터 Github]: https://github.com/Lateaksoo/Microprocesser/tree/master/elevator#readme
[엘리베이터 동작영상]: https://www.youtube.com/watch?v=zzhDEOv490g

### **개요**
- ATMEGA 2560 과 모터 및 센서를 이용한 엘리베이터 시스템 구현
- I2C 통신을 이용하여 두 보드간 통신 
- RFID 통신을 이용하여 관리자 카드 기능 구현
- LCD를 이용한 실시간 화면 표시
- Interrupt 를 이용한 버튼의 동작

**앞부분 모습** <br>
<img src="https://github.com/Lateaksoo/Microprocesser/blob/master/elevator/Image/front.png?raw=true" alt="아두이노" width="400">

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



### **개발 중 어려웠던 점**
아두이노는 하나의 Thread만이 동작하기 때문에 delay를 최대한 쓰지 않고 구현해야 하는 점이 힘들었다.   
LCD에 애니메이션을 표시하면 중간에 다른 동작을 할 수 없는 문제가 발생했다. 이를 해결하고자 듀얼코어에서 아이디어를 착안<br>
두개의 아두이노 보드를 사용하기로 했다. 각자 다른 프로그램을 Upload 하고 서로의 상태를 I2C 통신을 이용해 상수값으로 주고 받아 공유 할 수 있도록 구현했다. 

**ATMEGA 2560을 두개 연결한 모습** <br>
<img src="https://github.com/Lateaksoo/Microprocesser/blob/master/elevator/Image/ATMEGA_dual.png?raw=true" alt="아두이노" width="400">


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
```c++
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
```c++
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
```c++
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
 ```c++
 //Interrupt
 const int SECOND_FLOOR_BUTTON = 3;

 attachInterrupt(digitalPinToInterrupt(SECOND_FLOOR_BUTTON), middleFloorStop, FALLING);
```


<br><br><br>

RFID 모듈로 통신하여 Card UID 가 일치하는 카드를 태그 시 Relay 모듈을 이용하여 전원 차단

[Relay 동작영상]

[Relay 동작영상]: https://www.youtube.com/watch?v=AJ8Z8YYLbc4

특정 카드만 인식하도록 코드를 설정했다.    
<span style="color:red">실제로는 보안상 노출하지 않는것이 좋다.</span>
<span style="background-color:#FFE6E6"> 빨강형광펜 </span>
 ```c++
/**
  RFID 관련
*/
const String MANAGER_CARD = "83 4F 6D 02";  // 관리자 카드 번호

byte nuidPICC[4];                           //카드 ID를 비교하기 위한 배열
MFRC522 mfrc522(SS_PIN, RST_PIN);           // RFID 객체
```
<br>

bool타입 변수로 RFID 태그 여부를 저장한다.
 ```c++
 /**
  릴레이 관련 변수
*/
const int RELAY_PIN = 13;
bool isTaged = true;
```


카드가 태그되었다면 카드의 UID 값을 읽어와서 관리자 카드번호와 맞는지 비교한다. 
 ```c++
  /* 태그 카드 관련 */
  if (!mfrc522.PICC_IsNewCardPresent()) return; //새로운 카드가 없으면 return
  if (!mfrc522.PICC_ReadCardSerial()) return;   //일련번호가 없다면 return

  String tagedCard = "";                        //Card UID를 저장할 빈 문자열

//카드의 UID 배열을 16진수 문자열로 전환하여 저장
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    tagedCard.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    tagedCard.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  tagedCard.toUpperCase();                      //모두 대문자로 변환

//관리자 카드번호와 맞는지 검증
  if (tagedCard.substring(1) == MANAGER_CARD) {
    relayToggle();
    transferData(MANAGER_TAGED);
  }
```
   <br>
   
Relay모듈을 이용하여 엘리베이터 전원을 차단한다.    
스위치가 작동하지 않고 LCD에 
<span style="color:skyblue">점검중</span>
이란 문구가 표시된다.

 ```c++
// 릴레이 토글 함수
void relayToggle() {
  digitalWrite(RELAY_PIN, isTaged);
  presentFloorDigitOff();
  isTaged = !isTaged;
}
```
