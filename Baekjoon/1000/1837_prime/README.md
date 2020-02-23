# 1837. 암호제작

[링크](https://www.acmicpc.net/problem/1837)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Bronze II |     24      |

## 설계

### 너무 큰 P의 값

P가 너무 크기때문에, P를 소수로 그냥 나눌 경우 문제가 생긴다.

다음과 같은 방법을 이용해 소수로 나누어 떨어지는지 아닌지 구한다.

```cpp
bool canDivide(string number, int p) {
  int ret = 0;

  for (int i = 0; number[i]; i++) {
    ret *= 10;
    ret += (number[i] - '0');
    ret %= p;
  }

  return ret == 0;
}
```

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  84 ms  |           |

## 고생한 점

K 미만의 값들만 체크해야 하는데, K까지 체크해서 틀렸었다.
