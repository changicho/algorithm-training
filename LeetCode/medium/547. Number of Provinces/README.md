# 547. Number of Provinces

[링크](https://leetcode.com/problems/number-of-provinces/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N이라 하자.

연결된 노드끼리 묶음을 만들기 위해 다음과 같은 방법을 사용 가능하다.

- DFS, BFS
- 유니온 파인드

BFS로 탐색할 경우 시간 복잡도는 O(N^2)이다.

유니온 파인드를 이용할 경우 시간 복잡도는 O(N^3)이다.

### 공간 복잡도

BFS를 이용할 경우 방문을 저장할 배열이 필요하므로 O(N)의 공간 복잡도를 사용한다.

유니온 파인드를 이용할 경우 부모를 저장하는 배열에 O(N)의 공간 복잡도를, 함수의 call stack에 최대 O(N)의 공간 복잡도를 사용하므로 O(N)의 공간 복잡도를 사용한다.

### BFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^2)    |    O(N)     |

모든 노드를 탐색하며, 해당 노드와 인접한 모든 노드를 방문 처리한다.

이 떄 이미 방문한 노드일 경우 건너 뛴다.

이를 모든 노드에 대해서 반복해 그룹의 개수를 센다.

```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
  int size = isConnected.size();
  vector<bool> visited(size, false);

  int answer = 0;
  for (int start = 0; start < size; start++) {
    if (visited[start]) continue;
    answer += 1;

    visited[start] = true;
    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int cur = q.front();
      q.pop();

      for (int next = 0; next < size; next++) {
        if (isConnected[cur][next] == 0) continue;
        if (visited[next]) continue;

        visited[next] = true;
        q.push(next);
      }
    }
  }
  return answer;
}
```

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |   O(N^3)    |    O(N)     |

각 노드들을 탐색하며 연결된 노드들 끼리 merge를 수행한다.

이후 노드들은 parent를 기준으로 묶여있으므로 parent의 개수를 세서 문제를 풀이한다.

find, merge는 다음과 같이 구현한다.

```cpp
int find(int node, vector<int>& parents) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node], parents);
}

void merge(int a, int b, vector<int>& parents) {
  // make a smaller
  if (a > b) swap(a, b);
  if (parents[a] == parents[b]) return;

  int parentA = find(a, parents);
  int parentB = find(b, parents);

  parents[parentB] = parentA;
  find(b, parents);
}
```

이후 모든 노드에 대해서 find 연산을 수행해 parent들을 갱신해줘야 한다.

```cpp
int findCircleNum(vector<vector<int>>& isConnected) {
  int size = isConnected.size();
  vector<int> parents(size);

  for (int node = 0; node < size; node++) {
    parents[node] = node;
  }

  for (int from = 0; from < size; from++) {
    for (int to = from + 1; to < size; to++) {
      if (isConnected[from][to] != 1) continue;

      merge(from, to, parents);
    }
  }

  // update parents
  for (int node = 0; node < size; node++) {
    find(node, parents);
  }

  unordered_set<int> counts;
  for (int parent : parents) {
    counts.insert(parent);
  }

  return counts.size();
}
```

## 고생한 점
