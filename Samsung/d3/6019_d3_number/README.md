# 6019. 기차 사이의 파리

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWajaTmaZw4DFAWM)

난이도\_d3_41%

## 정리

내 코드 : 30 ms;
빠른 코드 : 20 ms;

소숫점 이하 X 자리를 표시해야 하므로 아래외 같은 방법을 이용했다.

```cpp
cout << fixed;
cout.precision(NUMBER);
```

두 기차가 부딛히기 전까지 파리는 계속 이동한다.
즉 거리 / 속력 = 시간 을 이용해 풀면 된다.
(기차 사이의 거리) / (기차 A 속력 + 기차 B 속력) = (파리가 이동 가능한 시간)
파리가 이동 가능한 시간을 구하고 파리의 속력과 곱해주면 된다.

이 때 입력을 정수로 받았으므로, 연산에서 (double) 로 casting 해줘야한다.
