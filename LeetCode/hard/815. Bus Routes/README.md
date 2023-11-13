# 815. Bus Routes

[링크](https://leetcode.com/problems/bus-routes/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 routes의 크기를 N, route들의 평균 크기를 M이라 하자.

각 route들 별로 버스로 묶을 수 있다. 이후 각 버스들을 정점, 같은 route들을 가진 정점끼리는 간선으로 연결되었다고 생각하고 그래프를 생성한다.

이 때 그래프를 생성하는 데 O(N \* M)의 시간 복잡도를 사용한다.

이후 BFS를 이용해 최단 거리를 구할 수 있다. 이 경우 route들을 순회하며 다음 정점으로 이동할 때도 그래프를 순회하므로 O(N^2 \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(N \* M)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     608      | O(N^2 \* M) |  O(N \* M)  |

각 routes를 순회하며 버스들을 정점으로, 같은 route들을 가진 정점끼리는 간선으로 연결되었다고 생각하고 그래프를 생성한다.

이후 BFS를 이용해 source부터 target까지의 거리를 순회한다.

이 때 한번의 환승에 cost가 1 이므로 step별 BFS를 순회하며 최단 거리를 구할 수 있다.

```cpp
int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
  if (source == target) return 0;

  unordered_map<int, vector<int>> graph;
  for (int index = 0; index < routes.size(); index++) {
    for (int &stop : routes[index]) {
      graph[stop].push_back(index);
    }
  }

  queue<int> q;
  unordered_set<int> visited;
  for (int &route : graph[source]) {
    q.push(route);
    visited.insert(route);
  }

  int busCount = 1;
  while (q.size()) {
    int size = q.size();

    while (size--) {
      int cur = q.front();
      q.pop();

      for (int &stop : routes[cur]) {
        if (stop == target) {
          return busCount;
        }

        for (int &next : graph[stop]) {
          if (visited.count(next)) continue;

          visited.insert(next);
          q.push(next);
        }
      }
    }
    busCount++;
  }
  return -1;
}
```

```cpp
int numBusesToDestination(vector<vector<int>> &routes, int source, int target) {
  if (source == target) return 0;

  unordered_map<int, vector<int>> graph;
  for (int index = 0; index < routes.size(); index++) {
    for (int &stop : routes[index]) {
      graph[stop].push_back(index);
    }
  }

  queue<int> q;
  unordered_set<int> visited;
  for (int &route : graph[source]) {
    q.push(route);
    visited.insert(route);
  }

  int busCount = 1;
  while (q.size()) {
    int size = q.size();

    while (size--) {
      int cur = q.front();
      q.pop();

      for (int &stop : routes[cur]) {
        if (stop == target) {
          return busCount;
        }

        for (int &next : graph[stop]) {
          if (visited.count(next)) continue;

          visited.insert(next);
          q.push(next);
        }
      }
    }
    busCount++;
  }
  return -1;
}
```

## 고생한 점
