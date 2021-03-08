# 2150. Strongly Connected Component

[링크](https://www.acmicpc.net/problem/2150)

|   난이도   | 정답률(\_%) | 시간 제한(초) |
| :--------: | :---------: | :-----------: |
| Platinum V |   47.764    |       2       |

## 설계

### 시간 복잡도

정점 V(1 ≤ V ≤ 10,000)와 간선 E(1 ≤ E ≤ 100,000)가 주어진다.

### 공간 복잡도

SCC의 개수는 최대 V개 까지이므로 10,000 개 이다.

따라서 int형으로 선언한다.

### 강한 연결 요소 (Strongly Connected Component)

### 코사라주 알고리즘

> 실행시간 32ms

시간복잡도는 O(V + E). 두번의 DFS를 수행함.

주어지는 방향 그래프와 주어지는 방향 그래프의 방향을 모두 역으로 뒤집은 역방향 그래프를 생성한다.

그리고 탐색하는 순서대로 정점을 저장할 스택이 필요하다.

우선 정방향 그래프로 DFS를 수행하며 _끝나는 순서대로_ 스택에 삽입해줍니다.

이때 DFS는 모든 정점에 대해서 수행한다.

스택에서 pop하는 순서대로 역방향 그래프로 DFS를 수행하여 한 정점에서 탐색되는 모든 다른 정점들을 같은 SCC로 묶습니다.

이후 SCC를 문제 양식에 맞게 정렬한다.

```cpp
// 정방향 탐색
void dfs(int vertex) {
  visited[vertex] = true;

  for (int next : graph[vertex]) {
    if (visited[next]) {
      continue;
    }
    dfs(next);
  }
  st.push(vertex);
}
```

```cpp
// 역방향 탐색
void dfs_reverse(int vertex, vector<int> *connected) {
  visited[vertex] = true;

  connected->push_back(vertex);

  for (int next : graph_reverse[vertex]) {
    if (visited[next]) {
      continue;
    }

    dfs_reverse(next, connected);
  }
}
```

```cpp
// 모든 정점에 대해 정방향 탐색
for (int vertex = 1; vertex <= V; vertex++) {
  if (visited[vertex]) {
    continue;
  }
  dfs(vertex);
}

memset(visited, 0, sizeof(visited));

// 스택에 쌓인 순서대로 모든 정점에 대해서 역방향 탐색
while (!st.empty()) {
  int cur = st.top();
  st.pop();

  if (visited[cur]) {
    continue;
  }

  vector<int> connected;
  dfs_reverse(cur, &connected);
  scc.push_back(connected);
}
```

```cpp
// 정렬을 이용해 정점 순서대로 정렬한다.
inline bool compare(vector<int> a, vector<int> b) {
  return a.front() < b.front();
}

for (vector<int> &cur : scc) {
  sort(cur.begin(), cur.end());
}
sort(scc.begin(), scc.end(), compare);
```

### 타잔 알고리즘

> 실행 시간 28ms

DFS 한번 실행하므로 시간 복잡도는 O(V + E)이다.

DFS로 탐색할 때 생성되는, DFS 트리의 간선의 정보를 이용한다.

모든 정점에서 수행되는 DFS로 SCC를 구한다.

ALL DFS로 탐색하며 Spanning Tree를 만드며, DFS의 호출 순서에 따라 정점을 stack에 push한다.

이후 간선 분류를 통하여 먼저 호출 되는 정점이 더 높은 우선 순위를 가진다고 생각하자.

이는 먼저 호출되는 정점에 parents값을 낮게 설정해 고려한다.

가장 높이 올라갈 수 있는 정점을 찾는데 이 때 here->there가 교차간선이지만 아직 there가 SCC에 속하지 않는다면 parents(there) 또한 고려한다.

DFS가 끝나기전에 ret과 parents(here)가 같다면 stack에서 pop하면서 here (현재 정점)가 나올 때까지 같은 SCC로 분류한다.

```cpp
// 초기화
int parents[10000 + 1], groupTable[10000 + 1];
memset(discover, -1, sizeof(parents));
memset(groupTable, -1, sizeof(groupTable));
```

```cpp
int dfs(int here) {
  parents[here] = callCount++;
  int ret = parents[here];

  st.push(here);

  for (int there : graph[here]) {
    // 다음 정점이 방문하지 않았거나, SCC로 분류되지 않은 경우
    if (parents[there] == -1) {
      int parent = dfs(there);
      ret = min(ret, parent);
    } else if (groupTable[there] == -1) {
      ret = min(ret, parents[there]);
    }
  }

  // 현재 정점이 SCC의 시작 정점인 경우
  if (ret == parents[here]) {
    vector<int> connected;

    while (true) {
      int vertex = st.top();
      st.pop();

      groupTable[vertex] = scc.size();
      connected.push_back(vertex);

      if (vertex == here) {
        break;
      }
    }

    sort(connected.begin(), connected.end());
    scc.push_back(connected);
  }
  return ret;
}
```

```cpp
for (int vertex = 1; vertex <= V; vertex++) {
  if (discover[vertex] == -1) {
    dfs(vertex);
  }
}
sort(scc.begin(), scc.end(), compare);
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      32      |       4        |

## 고생한 점
