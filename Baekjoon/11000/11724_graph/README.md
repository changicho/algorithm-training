# 11724. 연결 요소의 개수

[링크](https://www.acmicpc.net/problem/11724)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   46.002    |

## 설계

### 시간 복잡도

정검은 최대 1000개, 간선의 개수는 499,500개가 최대이다.

연결점을 찾기 위해선 각 경우마다 탐색을 진행해야한다.

DFS로 모든 정점을 방문할 때, 인접 list (vector)를 이용하는 경우 시간 복잡도는 정점의 수와 간선의 수를 더한 값이다.

따라서 500,500이 최대이다.

### 공간 복잡도

각 연결점을 가지는 vector를 선언해 관리한다. 정점의 최대값은 1000 이하의 자연수이므로 int형으로 선언한다.

### 정점의 방문

재귀함수를 이용해 DFS로 정점을 방문한다.

```cpp
vector<vector<int>> links;
vector<bool> visited;

void recursive(int cur) {
  if (visited[cur]) return;

  visited[cur] = true;

  for (int to : links[cur]) {
    if (visited[to]) continue;

    recursive(to);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      92      |       0        |

## 고생한 점
