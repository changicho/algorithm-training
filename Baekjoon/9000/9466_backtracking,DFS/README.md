# 9466. 텀 프로젝트

[링크](https://www.acmicpc.net/problem/9466)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold IV |   24.814    |       3       |

## 설계

### 시간 복잡도

학생의 수는 N (2 ≤ N ≤ 100,000) 으로 주어진다.

모든 경우를 탐색하는 경우 최악의 경우 O(N^2) 가량 소모되며, 이는 제한시간 내에 불가능하다.

따라서 노드에서 탐색할 때 백트래킹을 이용해 시간복잡도를 줄여야 한다.

### 공간 복잡도

정답은 학생의 수를 넘지 않으므로 최악의 경우도 100,000 이하이다. 따라서 int형으로 선언한다.

### 재귀 호출

재귀 호출에서 이미 방문한 정점을 판단하는 방식은 다음 두 가지가 존재한다.

```cpp
void recursive(int node) {
  visited[node] = true;
  int next = graph[node];

  if (visited[next]) {
    return
  }
  recursive(next);
}
```

```cpp
void recursive(int node) {
  if (visited[node]) {
    return
  }

  visited[node] = true;
  int next = graph[node];
  recursive(next);
}
```

위 두 가지 방법 중에서 두번째 방법은 중복의 여부를 함수를 호출한 뒤에 판단하므로 시간이 더 걸린다.

따라서 시간 제한이 치명적인 경우는 첫번째 방법을 사용한다.

### 깊이 우선 탐색

방문 여부와, 사이클이 생기는지 여부를, 이전에 탐색했는지 여부를 판단하기 위해 다음과 같은 배열들을 사용한다.

```cpp
int graph[LIMIT];
bool visited[LIMIT];
bool isFilled[LIMIT];
bool isDone[LIMIT];
```

여기서 방문배열과 사이클배열은 사이클을 구할 때 사용한다.

이전에 탐색이 끝났는지 여부를 판단하는 이유는 현재 방문한 노드가 이전에 방문한 노드이지만, 사이클이 아닌 경우를 판단하기 위함이다.

다음 노드가 이전에 방문한 노드이며, 이전에 탐색이 완료된 노드가 아닌 경우에는 연결된 다음 노드부터 사이클을 만들어준다.

```cpp
void fillRecursive(int node) {
  isFilled[node] = true;
  int next = graph[node];

  if (isFilled[next]) {
    return;
  }

  fillRecursive(next);
}

void recursive(int node) {
  visited[node] = true;

  int next = graph[node];
  if (!visited[next]) {
    recursive(next);
  } else if (!isDone[next]) {
    fillRecursive(next);
  }

  isDone[node] = true;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     536      |       88       |

## 고생한 점

재귀호출의 방법을 변경해 시간복잡도를 최적화 해야 했음.
