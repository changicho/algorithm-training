# 1298. 노트북의 주인을 찾아서

[링크](https://www.acmicpc.net/problem/1298)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   44.394    |

## 설계

### 시간 복잡도

노트북을 구입한 사람의 수는 최대 100,

추정의 내용은 최대 5,000 개이다.

각 노트북을 그래프로 생각할 경우 이분 매칭을 이용해 문제를 풀 수 있다.

이분 매칭을 간단히 표현할 경우 DFS를 이용해 시간복잡도 O(V+E)번 만에 구현할 수 있다.

### 공간 복잡도

노드의 수는 최대 100개이다. 따라서 정답은 최대 100이므로 int형으로 선언한다.

### 이분 매칭

이분 매칭(Bipartite Matching)은 네트워크 플로우의 개념중에서 이분 그래프(Bipartite Graph)에서의 최대 유량을 구하는 경우이다.

DFS를 이용해 이분 매칭을 O(V+E)의 시간 복잡도로 보다 간편하게 구현할 수 있다.

노드를 탐색하며, 각 노드에서 정점으로 연결할 때, 다른 노드가 연결되어 있는 경우

다른 노드를 다른 정점에 연결시키며 연결 할 수 있는 최대 갯수를 구한다.

이때 시작 노드가 바뀔 때마다 방문 여부를 초기화한다.

```cpp
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
