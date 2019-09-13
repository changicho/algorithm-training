# 7732. 시간 개념

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWrDLM0aRA8DFARG)

난이도\_d3

## 정리

- 진법 (notation)

60 진법을 구현하는 문제. struct 로 문제를 풀려 했으나 배열로 풀었다.
delete로 메모리를 동적 할당하는 데 에러가 발생한다. 메모리 동적 할당에 대해 더 알아봐야겠다.

시, 분, 초 를 출력할 때 빈 자리에 0을 출력해주는 방법으로 C++ 에서 제공하는 cout.fill 과 cout.width 를 사용했다.

```cpp
cout.fill('0');
cout.width(2);
cout << integer;
```

이렇게 한번의 cout 에만 적용됨에 유의한다.

변수를 전역에 할당하나, 지역에 할당하나 같은 메모리 양을 사용하는것으로 보아, solution 함수 내에서 선언된 변수들은 바로 사라지는 듯 하다.
