# 9527. 1의 개수 세기

[링크](https://www.acmicpc.net/problem/9527)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   38.135    |       1       |

## 설계

### 시간 복잡도

A와 B는 최대 10^16 까지의 수 이다.

매 경우마다 직접 계산할 경우 시간내에 풀이가 불가능하다.

따라서 수학적 방법을 이용해 계산한다.

### 공간 복잡도

10^16 까지이므로 long long형으로 선언한다.

### 1부터 N까지 1의 개수 f(N) 구현

1 ~ x 까지의 모든 f(x)의 합을 f(S)로 둔다. 이 경우 a~b 까지의 1의 개수는 f(b) - f(a-1)을 구해 알 수 있다.

각 비트의 자리마다 가질 수 있는 비트의 수를 이용한다.

현재 비트 자리수에서 가질 수 있는 수들을 구한다.

```cpp
long long digit_count(long long number) {
  long long ret = 0;

  for (int i = 0; i < 55; i++) {
    ret += ((number + 1) >> (i + 1) << i);
    ret += max((long long)0, (number + 1) % (1LL << (i + 1)) - (1LL << i));
  }

  return ret;
}
```

```cpp
long long digit_count(long long number) {
  number++;
  long long from = 1, to = number;
  long long ret = 0;

  while (to) {
    if (number & from) {
      ret += number % from + (number - number % (from * 2)) / 2;
    } else {
      ret += (number - number % from) / 2;
    }
    from *= 2;
    to /= 2;
  }

  return ret;
}
```

### 시프트 연산

```cpp
x >> 1 // x / 2
x << 1 // x * 2
```

### 1부터 X까지 비트의 합

```cpp
(k + 1) / (2^(k + 1)) * 2^k + max(0, (k + 1) % (2 % k + 1) - 2^k)
```

### 1ll

> The LL makes the integer literal of type long long.

```cpp
1   << 40 // int
1LL << 40 // long long
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
