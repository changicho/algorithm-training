# 1005. ACM Craft

[링크](https://www.acmicpc.net/problem/1005)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Gold III |   21.645    |       1       |

## 설계

유사한 문제

- [백준.2056.작업](https://www.acmicpc.net/problem/2056)

### 시간 복잡도

노드의 개수는 최대 1,000개이다.

간선의 개수 K는 최대 100,000 까지이다.

각 작업에 앞선 작업들이 존재하므로 위상 정렬을 이용한다.

이 때의 시간 복잡도는 O(V + E) 이다.

이는 제한시간 1초 내에 충분하다.

### 공간 복잡도

각 작업의 최대 걸리는 시간은 100,000 까지이다.

노드의 최대 개수는 1,000개 까지이므로 최악의 경우 정답은 100,000,000 이다.

이는 int형으로 충분하다.

### 위상 정렬

위상 정렬은 순서가 정해져있는 작업 차례로 수행해야 할 때, 그 순서를 결정해주는 알고리즘이다.

```cpp
vector<vector<int> > graph;
vector<int> inDegree; // index 노드에서 갈 수 있는 노드의 개수
vector<int> result; // 정점을 방문하는 순서

// 진입 차수가 0인 노드를 큐에 삽입합니다
queue<int> q;
for (int node = 1; node <= N; node++) {
  if (inDegree[node] == 0) {
    q.push(node);
  }
}

// 정렬이 완전히 수행되려면 N개의 노드를 전부 방문합니다
for(int node = 1; node <= N; node++) {
  if(q.empty()) {
    // n개를 방문하기 전에 큐가 비어버리면 사이클이 발생한 것
    // (이전에 진입차수가 0인 정점이 없었다는 의미이므로)
    break;
  }

  int cur = q.front();
  q.pop();
  result[node] = cur;

  for(int next : graph[cur]) {
    inDegree[next]--;

    // 새롭게 진입차수가 0이 된 정점을 큐에 삽입합니다
    if(inDegree[next] == 0) {
      q.push(next);
    }
  }
}
```

### 위상 정려에서 비용의 최소

위상 정렬을 수행하는 동안 각 index 까지 도달하는데 들어가는 cost를 갱신한다.

여기서 현재 작업과 연결되어 수행될 작업을 끝내기 위해 소요되는 시간은 최대 값이 되도록 해야한다.

'처음부터 현재 작업까지를 소요되는 시간 + 다음 작업 하나를 끝내는 데 필요한 시간' 값이 최대가 되어야 한다.

예시로 작업 A를 수행하기 위해 B와 C를 선행해야 하는 경우, B와 C중에 더 오래걸리는 작업을 수행해야 한다.

```cpp
// costs : 해당 index까지 방문하는데 들어가는 최소 비용
// times 각 정점의 비용 (이전 정점에서 현재 정점까지 도달하는 데 비용)
vector<int> costs, times;
for (int node = 1; node <= N; node++) {
  cin >> cost;
  costs[node] = times[node] = cost;
}

// 모든 노드를 방문하지 않아도 됨
while (!q.empty()) {
  int cur = q.front();
  q.pop();

  for (int next : graph[cur]) {
    times[next] = max(times[next], costs[next] + times[cur]);

    inDegree[next] -= 1;
    if (inDegree[next] == 0) {
      q.push(next);
    }
  }
}

// times를 이용해 정답을 구하면 된다.
answer = times[target];
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     164      |       8        |

## 고생한 점
