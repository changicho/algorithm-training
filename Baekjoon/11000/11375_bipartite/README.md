# 11375. 열혈강호

[링크](https://www.acmicpc.net/problem/11375)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   39.245    |

## 설계

### 시간 복잡도

직원의 수 N과 과일의 수 M은 1 ≤ N, M ≤ 1,000 이다.

각 직원마다 하나의 과일을 매칭할 때, 최대 매칭 수를 찾아야 하므로 이분 매칭을 사용한다.

이 때 시간 복잡도는 O(V+E) 이다.

최악의 경우 복잡도는 대략 1000^2 정도이므로 제한시간 내에 충분하다.

### 공간 복잡도

정답의 수는 최대 1,000 이므로 int형으로 선언한다.

### 이분 매칭

2188번 축사 배정 문제와 동일하다.

```cpp
int visited[SIZE];
int matchingTable[SIZE];

vector<vector<int>> graph;

int recursive(int from) {
  if (visited[from]) return false;

  visited[from] = true;

  for (int to : graph[from]) {
    if (matchingTable[to] == 0 || recursive(matchingTable[to])) {
      matchingTable[to] = from;

      return true;
    }
  }
  return false;
}
```

```cpp
for (int node = 1; node <= N; node++) {
  memset(visited, 0, sizeof(visited));

  if (recursive(node)) answer++;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|              |                |

## 고생한 점
