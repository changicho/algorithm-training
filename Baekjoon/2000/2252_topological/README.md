# 2252. 줄 세우기

[링크](https://www.acmicpc.net/problem/2252)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   52.576    |       2       |

## 설계

### 시간 복잡도

학생의 수는 최대 32,000 명이다. 학생의 키를 비교한 횟수는 최대 100,000 까지이다.

위상정렬 알고리즘을 이용할 경우 시간 복잡도는 O(V + E) 이므로 제한 시간 2초 내에 충분하다.

### 공간 복잡도

정답의 수는 32,000 이하임이 보장되므로 int형으로 선언한다.

### 위상 정렬

위상 정렬을 위해 다음과 같은 자료 형들을 선언한다.

```cpp
vector<vector<int> > graph(N + 1);  // 각 노드마다 다음 노드로 연결할 수 있는 그래프
vector<int> inDegree(N + 1);        // 각 노드별 진입차수 (현재 노드로 들어오는 노드의 수)
vector<int> result(N);              // 정답의 방문 순서
```

그래프는 다음과 같이 생성한다.

```cpp
int from, to;
for (int i = 0; i < M; i++) {
  cin >> from >> to;

  inDegree[to] += 1;
  graph[from].push_back(to);
}
```

큐를 생성하고 진입차수가 0인 노드들(맨 앞에 설 수 있는 노드들)을 큐에 집어넣는다.

```cpp
queue<int> q;
for (int node = 1; node <= N; node++) {
  if (inDegree[node] == 0) {
    q.push(node);
  }
}
```

다음으로 위상 정렬을 수행한다.

```cpp
for (int index = 0; index < N; index++) {
  if (q.empty()) {
    break;
  }

  int cur = q.front();
  q.pop();
  result[index] = cur;

  for (int next : graph[cur]) {
    inDegree[next]--;

    if (inDegree[next] == 0) {
      q.push(next);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      32      |       8        |

## 고생한 점
