# 1009. 분산처리

[링크](https://www.acmicpc.net/problem/1009)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Bronze III |   26.224    |

## 설계

### 시간 복잡도

브루트 포스 방법으로 하는 경우 시간 복잡도는

```cpp
5 * 1,000,000
```

따라서 제한시간 1초 내에 충분하다.

제곱의 시간을 줄이기 위해 log(N) 의 방법을 사용하는 경우 시간 복잡도는

```cpp
log(1,000,000) <= 20
```

이므로 이 또한 제한시간 1초 내에 충분하다.

### 공간 복잡도

100 이하의 자연수를 1,000,000 번 곱하는 경우 수가 매우 크므로, 1의 자리만 계산함

### 분할 정복 기법

A^B 제곱은 다음과 같이 나타낼 수 있다.

```cpp
A^(B/2) * A^(B/2)     // B가 짝수인 경우
A^(B/2) * A^(B/2) * A // B가 홀수인 경우
```

여기서 A^(B/2)는 중복되는 값이므로 한번만 계산하면 된다.

B/2가 1이 될 때까지 재귀호출하며 계산하고, 이를 이용해 최종 값을 구할 수 있다.

```cpp
int divide(int number, int count) {
  if (count == 1) {
    return number;
  }

  int val = divide(number, count / 2);
  if (count % 2 == 1) {
    return (val * val * number) % 10;
  }
  return (val * val) % 10;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
