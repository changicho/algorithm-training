# 7965. 퀴즈

[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWuSh2IKmu0DFASy&categoryId=AWuSh2IKmu0DFASy&categoryType=CODE)

난이도 : d4
정답률 : \_33%

## 설계

### 메모이제이션

N번째 답을 구할 때, N-1 번째 답을 이용하자.

### 제곱

7 ^ 7 의 경우를 생각해보자.

(7 X 7 X 7 X 7) X (7 X 7) X 7 로 표현할 수 있다.

이렇게 N^N을 A^4 X B^2 X C^1 로 치환 할 수 있다면 계산 시간을 줄일 수 있다.

7을 2진수로 바꾸면 111 이고, 각 자리수별로 N^4, N^2, N을 나타낸다.

이를 전부 곱하면 N^7이고, 모든 제곱을 이렇게 표현할 수 있다.

```cpp
long long my_pow(int first, int second) {
  long long power = 1;

  while (second != 0) {
    if (second & 1) {
      power = (power * first) % MOD;
    }
    first = (first * first) % MOD;

    second >>= 1;
  }

  return power;
}
```

## 정리

내 코드 : 239 ms;
빠른 코드 : 190 ms;

제곱을 구하는 시간 복잡도를 줄이는 것이 목표인 문제.

N의 N제곱을 구할 때, N을 곱하는 횟수를 2진수의 갯수로 묶었다.

위 방법을 이용하면 logN 번을 수행해 제곱을 구할 수 있다.

## 고생한 점

제곱의 시간복잡도를 줄이는 방법은 다른사람의 풀이를 참고했다.

나머지 연산 때문에 페르마의 소정리를 이용할까 했으나, 이용하지 않아도 된다.
