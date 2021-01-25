# 12852. 1로 만들기 2

[링크](https://www.acmicpc.net/problem/12852)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Silver I |   52.488    |      0.5      |

## 설계

### 시간 복잡도

X는 최대 10^6인 자연수이다.

X부터 1까지 탐색을 진행할 때 다음 두가지 방법을 이용할 수 있다.

- BFS
- 동적 계획법

BFS의 경우 최악의 경우 시간 복잡도는 O(N) 이하이다.

동적 계획법의 경우 최악의 경우 시간 복잡도는 O(N) 이다.

두 방법 모두 제한시간 0.5초 내에 충분하다.

### 공간 복잡도

X는 최대 10^6인 자연수이다.

저장해야 되는 정보는 다음과 같다.

- 현재 노드 (index)
- 부모 노드
- 1까지 도달하는데 거치는 노드의 수

이 값 모두 int형으로 충분하다.

### BFS

BFS를 이용해 X에서 1까지 탐색할 수 있다.

이 때 저장해야 할 정보는 다음과 같다.

- 현재까지 거쳐온 노드의 정보

노드의 정보에서 가장 마지막에 저장되어있는 것이 현재 방문한 노드이므로 vector로만 나타낼 수 있다.

이 때 이전에 방문한 정점을 다시 방문하지 않도록 주의한다.

```cpp
queue<Status> q;
vector<int> answer;
q.push({{N}});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  int node = cur.history.back();
  if (node == 1) {
    answer = cur.history;
    break;
  }
  if (visited[node]) continue;
  visited[node] = true;

  vector<int> new_history = cur.history;

  if (node % 3 == 0) {
    new_history.push_back(node / 3);
    q.push({new_history});
    new_history.pop_back();
  }
  if (node % 2 == 0) {
    new_history.push_back(node / 2);
    q.push({new_history});
    new_history.pop_back();
  }
  if (node - 1 > 0) {
    new_history.push_back(node - 1);
    q.push({new_history});
    new_history.pop_back();
  }
}
```

### 동적 계획법

동적 계획법을 이용하고, 각 상황별로 어느 노드에서 현재 노드로 왔는지를 기록한다.

이 떄의 시간 복잡도는 O(N)이다.

다음 자료구조에서 나타내는 정보는 다음과 같다.

- 현재 노드 (index)
- 부모 노드
- 1까지 도달하는데 거치는 노드의 수

```cpp
struct Edge {
  int length; // 1까지 도달하는데 거치는 노드의 수
  int from;   // 부모 노드
};
Edge dp[1000001]; // 현재 노드 index
```

일반 식은 다음과 같다.

```cpp
dp[i] = min({dp[i - 1].length + 1, i - 1}, {dp[i / 2].length + 1, i / 2}, {dp[i / 3].length + 1, i / 3})
```

현재 index에서의 dp값은 현재 index로 도달할 수 있는 3가지 경우 중에서 가장 length가 짧은 경우이다.

초기 값은 다음과 같다.

```cpp
dp[1] = {0, 0};
```

이 방법으로 bottom-up 방식으로 풀이한다.

X가 1인 경우는 보장되므로 2부터 탐색을 진행한다.

이 때 i번째를 구할 때 i-1번쨰를 이용해 먼저 구해 초기값을 할당하지 않도록 구성한다.

```cpp
for (int i = 2; i <= N; i++) {
  dp[i] = {dp[i - 1].length + 1, i - 1};
  if (i % 2 == 0 && dp[i].length > dp[i / 2].length + 1) {
    dp[i] = {dp[i / 2].length + 1, i / 2};
  }
  if (i % 3 == 0 && dp[i].length > dp[i / 3].length + 1) {
    dp[i] = {dp[i / 3].length + 1, i / 3};
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

정답의 첫 줄에 거치는 노드의 수를 출력하지 않아 틀림
