# 1389. 케빈 베이컨의 6단계 법칙

[링크](https://www.acmicpc.net/problem/1389)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   54.015    |

## 설계

### 시간 복잡도

N은 최대 100이다.

플로이드 와셜 알고리즘을 사용하면 O(V^3) 만에 각 모든 정점에 대한 costs를 구할수 있다.

이 방법을 이용하면 제한시간 내에 충분하다.

### 공간 복잡도

costs는 연결된 각 정점마다 1이다. 따라서 최대 값은 100을 넘지 않으므로 int형으로 관리한다.

### 플로이드 와셜 알고리즘

단 방향 그래프에 사용할수 있다.

어떤 특정 정점을 거쳤을 때의 경로가 최단이라면 table을 update한다.

이전에 구했던 최단 경로를 통해 새로운 최단 경로를 찾는 방식으로 진행된다.

연결 관계를 나타내는 그래프를 만들어야한다.

V가 크지 않으므로 vector가 아닌 2차원 배열로 관리함에 유의하자.

연결 관계 배열은 MAX 값으로 초기화한다.

```cpp
// costs[from][to]
int costs[MAX_SIZE][MAX_SIZE];

// initialize
for (int i = 1; i <= N; i++) {
  for (int j = 1; j <= N; j++) {
    costs[i][j] = i == j ? 0 : MAX;
  }
}
```

```cpp
void floyd_warshall() {
  for (int through = 1; through <= N; through++) {
    for (int from = 1; from <= N; from++) {
      for (int to = 1; to <= N; to++) {
        costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
      }
    }
  }
  return;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
