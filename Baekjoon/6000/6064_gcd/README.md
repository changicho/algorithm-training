# 6064. 카잉 달력

[링크](https://www.acmicpc.net/problem/6064)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   23.580    |

## 설계

### 시간 복잡도

(1 ≤ M, N ≤ 40,000, 1 ≤ x ≤ M, 1 ≤ y ≤ N) 이다.

M, N을 이용해 모든 경우를 수행해 보는 경우 시간 복잡도는 40,000^2 이며 이는 제한시간 내에 불가능하다.

따라서 나머지 정리를 이용해 풀이한다.

### 공간 복잡도

입력받는 수의 최대 값은 40,000 이므로 int형으로 선언한다.

### 하나의 수를 고정

x를 먼저 고정하고, y를 변화시키며 가능한 경우가 있는지 탐색한다.

x를 고정했을 때 y의 수식은 다음과 같다.

y = (x + i \* M) % N

이 i를 변화시키며 y가 문제에서 주어진 y인지 검사한다.

```cpp
for (int i = 0; x + i * M <= limit; i++) {
  int cnt_y = (x + i * M) % N;

  if (y == cnt_y || (N == y && cnt_y == 0)) {
    year = x + i * M;
    break;
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      32      |       0        |

## 고생한 점
