# 1016. 제곱 ㄴㄴ 수

[링크](https://www.acmicpc.net/problem/1016)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   19.614    |       2       |

## 설계

### 시간 복잡도

입력 받는 범위에서 min은 최대 1,000,000,000,000까지, max는 ≤ min + 1,000,000 까지이다.

min ~ max 범위를 탐색하는데 들어가는 시간 복잡도는 O(1,000,000) 이므로 전부 탐색할 수 있다.

매 숫자마다 특정 x의 x^2로 나누어지는지 판별해야 한다. 이를 매 숫자마다 하면 시간복잡도를 초과하므로 min ~ max 범위에 에라토스테네스의 채 방법을 응용해 나누어 떨어지는지 여부를 판단한다.

### 공간 복잡도

min과 max는 long long 형으로 선언해야한다.

### 에라토스테네스의 채

일반 에라토스테네스의 채가 자연수에 대해서 필터링을 수행했다면, 이 문제에서는 제곱수에 대해서 필터링을 수행한다.

이 때 min ~ max 숫자가 매우 클 수 있으므로 해당 범위에서만 수행해야한다.

따라서 visited 배열의 index의 실제 index는 index + min 이다.

```cpp
int size = to - from + 1;
vector<bool> visited(size, false);

for (long long squared_number = 2; squared_number * squared_number <= to; squared_number++) {
  long long squared = squared_number * squared_number;

  long long number = (from / squared) * squared;
  if (number < from) {
    number += squared;
  }

  while (number <= to) {
    int index = number - from;

    visited[index] = true;
    number += squared;
  }
}
```

여기서 방문하지 않은 숫자의 개수가 정답이다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      12      |       4        |

## 고생한 점
