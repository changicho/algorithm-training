# E - Reachability Query

[링크](https://atcoder.jp/contests/abc420/tasks/abc420_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

노드의 수를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 간선이 추가되거나 색이 변한다.

혹은 연결된 노드들 중에 검은색 노드가 있는지 판단한다.

유니온 파인드를 사용해 각 그룹별 연결과 검은색 노드의 개수를 관리한다.

이에 O(N + Q \* a(N))의 시간 복잡도를 가진다. 여기서 a는 아커만 함수이며 상수이다.

따라서 O(N + Q)의 시간 복잡도를 가진다.

### 공간 복잡도

유니온 파인드에 O(N)의 공간 복잡도를 사용한다.

각 노드마다 색에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     594      |  O(N + Q)   |    O(N)     |

노드들의 연결을 유니온 파인드로 관리한다.

이 때 각 노드들 마다 의 색을 별도 배열에 관리하며, 각 그룹별 부모 노드에 현재 그룹의 검은색 노드의 개수를 관리한다.

두 노드가 연결될 때 각 그룹의 검은색 노드의 개수를 부모 노드에 갱신한다.

특정 노드의 색이 변경되는 경우 그룹의 검은색 노드의 개수를 갱신한다.

따라서 특정 그룹에 검은색 노드가 하나 이상 존재하는 경우를 판별할 때 갯수를 이용해 빠르게 판별할 수 있다.

```cpp
vector<bool> solution(int n, int qSize, vector<vector<int>> &queries) {
  vector<int> parents(n + 1, -1);

  // 0 : white, 1 : black
  vector<int> colors(n + 1, 0);
  vector<int> blackCounts(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    parents[i] = i;
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (a > b) swap(a, b);
    parents[b] = a;
  };

  vector<bool> answer;

  for (vector<int> &query : queries) {
    int type = query[0];

    if (type == 1) {
      int a = query[1];
      int b = query[2];

      a = find(a);
      b = find(b);

      if (a == b) continue;

      merge(a, b);
      int newParent = find(a);

      blackCounts[newParent] = blackCounts[a] + blackCounts[b];
    } else if (type == 2) {
      int node = query[1];
      int parent = find(node);

      blackCounts[parent] -= colors[node];
      // toggle color
      colors[node] = 1 - colors[node];
      // colors[node] ^= 1;
      // colors[node] = colors[node] == 1 ? 0 : 1;
      blackCounts[parent] += colors[node];
    } else if (type == 3) {
      int node = query[1];
      int parent = find(node);

      answer.push_back(blackCounts[parent] > 0);
    }
  }

  return answer;
}
```

## 고생한 점
