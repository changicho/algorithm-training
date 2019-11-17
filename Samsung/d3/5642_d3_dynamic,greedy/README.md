# 5642. [Professional] 합

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXQm2SqdxkDFAUo&categoryId=AWXQm2SqdxkDFAUo&categoryType=CODE&&&)

난이도\_d3_27%

## 정리

dynamic programing, greedy algorithm 을 이용해 풀이할 수 있다.

입력받은 값을 하나하나 더해 합을 만든다.
i 번째 까지 수의 합을 구했을 때, 음수가 나오면 합을 초기화 한다.
i+1 번째 부터 반복

위 과정을 수행하며 max 의 값을 갱신

점화식으로 표현한다면

(i 번째 까지 합) = (i 번째 값) + (i-1 번째 까지 합)

c++ 에서 제일 빠른 경우 218 ms
내 코드는 240 ms

모든 값을 입력받고, 순회하면서 답을 구했으나 입력 받으면서 답을 구하면 복잡도를 줄였다.
O(2N) 에서 O(N) 으로

개선 결과 217 ms 가 나왔다. 큰 의미는 없는듯...

메모리 변화
기존 : 13,132 kb
개선 : 12,624 kb

큰 차이가 없다.

## 방법

입 출력 속도를 빠르게 하는 방법들.

```cpp
// cin, cout 속도를 빠르게 하기 위한 코드 선언
ios_base ::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

```cpp
cout << endl;
cout << '\n';
```

위 방법을 사용할 시 지켜야 할 것

- scanf와 printf와 섞어서 사용하지 말것
- 싱글 쓰레드 환경에서만 사용 (알고리즘 문제 풀이에는 상관없음)
- 그래도 시간초과가 난다면 C 표준입출력 함수들을 사용

사실 cin, cout을 쓰기 보다는 scanf와 printf를 사용하면 입출력 속도를 빠르게 할 수 있다.
