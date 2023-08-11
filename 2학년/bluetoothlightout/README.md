# **[프로젝트 2] : 홈 IOT 블루투스 스위치**
[블루투스 스위치 Github] <br>
[블루투스 스위치 동작영상]

[블루투스 스위치 Github]: https://github.com/Lateaksoo/Microprocesser/tree/master/2%ED%95%99%EB%85%84/bluetoothlightout
[블루투스 스위치 동작영상]: https://www.youtube.com/watch?v=yp7es9QME1U

### **개요**
- ATMEGA 2560 과 Bluetooth 모듈을 이용한 무선 스위치 제어장치
- 스마트폰 어플리케이션과 Bluetooth를 이용하여 통신
- 서보모터를 이용하여 스위치 제어

### **사용된 부품**

|부품명|사용 개수|사용 목적|
|---|---|---
|ATMEGA 2560 | 1 | |
|HC-06 Bluetooth 모듈   |1   |Bluetooth 통신
|Servo Motor| 2 | 전등 제어

### **개발 중 어려웠던 점**
서보모터를 방에 있는 스위치에 고정하는 점이 어려워 손으로 고정하여 실험을 했다.   
서보모터의 힘보다 접착력이 약해서 서보모터가 들리는 현상이 발생하여 실 사용에는 어려움이 있었다.   
접착하는 방법에 대해 개선해야 할 점이 있다. 또한 적용할 수 있는 방 불 스위치가 한정적이다.

이렇게 양쪽으로 on/off 되는 스위치에만 적용 가능하다 <br>
<img src="https://github.com/Lateaksoo/Microprocesser/blob/master/2%ED%95%99%EB%85%84/bluetoothlightout/Image/switch.png?raw=true" alt="아두이노" width="400">


### **프로그램 주요 코드 설명**

>#### **[Bluetooth 통신으로 받은 값 저장]**
```c++
// Bluetooth로 받은 값을 char 형으로 저장
 char value;
  if(bt.available()){
    value=(char)bt.read(); 
  }
```


>#### **[Bluetooth 통신으로 '1' 을 받았을 때 동작]**
1번 서보모터를 동작시켜 방 스위치를 꺼지도록 누른다.
```c++
// 1 받았을 때 꺼짐
 if(value == '1')
  {
    myservo1.write(0);
    myservo2.write(30);
  }
```

>#### **[Bluetooth 통신으로 '1' 을 받았을 때 동작]**
2번 서보모터를 동작시켜 방 스위치를 켜지도록 1번 서보모터가 누른 반대쪽을 누른다.
```c++
// 2 받았을 때 켜짐
 if(value == '2')
  {
    myservo1.write(30);
    myservo2.write(0);
  }

```
