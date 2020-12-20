# 11403. 경로 찾기

[링크](https://www.acmicpc.net/problem/11403)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   52.992    |

## 설계

### 시간 복잡도

1 ≤ N ≤ 100 이다.

각 정점에서 다른 모든 정점 대해여 경로의 여부를 판단해야한다.

이를 위해 플로이드 와셜 알고리즘을 사용한다.

이 경우 시간 복잡도는 O(N^3) 이다.

### 공간 복잡도

각 정점당 연결의 여부를 cost를 1로 둘 경우, 정점끼리 비용의 최대치는 100 이내이다.

따라서 int형으로 costs 배열을 선언한다.

### 플로이드 와셜

문제에서 주어지는 정점의 연결구조에서, 자기자신으로 연결이 보장되지 않음에 유의하자.

연결이 끊김에 대한 처리는 cost로 불가능한 값을 미리 설정해 처리한다.

```cpp
for (int y = 0; y < N; y++) {
  for (int x = 0; x < N; x++) {
    cin >> costs[y][x];

    if (costs[y][x] == 1) continue;
    costs[y][x] = MAX;
  }
}
```

```cpp
for (int through = 0; through < N; through++) {
  for (int from = 0; from < N; from++) {
    for (int to = 0; to < N; to++) {
      costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
