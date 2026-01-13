# A - Octave

[링크](https://atcoder.jp/contests/abc440/tasks/abc440_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 두 수를 이용해 값을 구하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

입력받은 두 수와 결과값을 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
long long solution(long long x, long long y) {
  long long d = pow(2, y);

  return x * d;
}
```

## 고생한 점
