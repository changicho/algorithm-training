# 6692. 다솔이의 월급 상자

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWdXofhKFkADFAWn&categoryId=AWdXofhKFkADFAWn&categoryType=CODE)

난이도\_d3_64%

## 정리

내 코드 : 13 ms
빠른 코드 : 8 ms

소숫점을 처리하는 문제

```cpp
cout << fixed;
cout.precision(6);
```

위 코드를 쓰면 모든 출력을 소숫점 6자리까지 강제화 한다.
소숫점 7자리가 넘는 수의 경우 반올림 처리하므로, precision 메소드의 인자값을 어떻게 할지 처리해야함.
