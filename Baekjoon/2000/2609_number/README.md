# 2609. 최대공약수와 최소공배수

[링크](https://www.acmicpc.net/problem/2609)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver V |   64.528    |

## 설계

### gcd

두 수 a, b가 주어질 때 (a>b)

```cpp
while (b != 0) {
  n = a % b;
  a = b;
  b = n;
}
```

이를 반복하면 최종적으로 a는 최대공약수 gcd가 된다.

재귀를 이용한 방법은 다음과 같다.

```cpp
int gcd(int a, int b) {
  if(b == 0){
    return a;
  }

  return gcd(b, a % b);
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
