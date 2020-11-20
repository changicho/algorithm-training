# 2188. 축사 배정

[링크](https://www.acmicpc.net/problem/2188)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   46.913    |

## 설계

### 시간 복잡도

소의 수, 축사의 수는 각각 최대 200개 이하이다.

이분 매칭을 사용할 경우 시간복잡도 O(V+E) 번 만에 가능하다.

최악의 경우 노드간의 간선의 개수는 200(199)/2 개가 주어질 수 있다.

이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

소의 수는 최대 200 이하이므로 정답은 int형으로 충분하다.

### 이분 매칭

축사당 한마리의 소만 가능하며, 각 소는 이동할 수 있는 축사 목록이 정해져있다.

이 경우 소를 가장 많이 채우는 경우를 구해야 하므로 이분 매칭을 이용해 구현한다.

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
|      0       |       0        |

## 고생한 점
