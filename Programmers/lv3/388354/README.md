# 2025 프로그래머스 코드챌린지 1차 예선 - 홀짝트리


[링크](https://school.programmers.co.kr/learn/courses/30/lessons/388354)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

노드의 수를 N, 간선의 수를 E라 하자.

간선을 이용해 그래프를 생성하는데 O(E)의 시간 복잡도를 사용한다.

한번의 순회를 이용해 홀수 짝수를 판별하고, 이를 이용해 답을 구할 수 있다.

이 경우 총 O(N + E)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프에 O(E)의 공간 복잡도를 사용한다.

각 노드마다 정보를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드 & 트리의 성질

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N + E)   |  O(N + E)   |

각 트리가 조건을 만족하는 홀짝 트리, 역홀짝 트리가 되기 위해선 다음 조건을 만족해야한다.

- 각 노드의 자식 노드의 수에 따라 홀짝 노드, 역홀짝 노드 여부를 체크한다.
- 현재 노드를 루트로 하는 트리가 되었을 때 홀짝 노드, 역홀짝 노드가 하나만 존재해야 한다.
- 이는 다른 노드가 루트가 된 경우 각 노드의 자식노드중 하나는 부모가 되므로 수가 달라지기 때문이다.

각 노드마다 자식 노드의 수 & 노드의 값에 따라 홀짝 노드, 역홀짝 노드 여부를 판별후 갯수를 센다.

이후 각 트리마다 위 조건을 만족하는 경우 정답을 증가시킨다.

```cpp
vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
  int size = nodes.size();

  vector<int> parent(size);
  vector<int> children(size);

  function<int(int)> find = [&parent, &find](int a) {
    if (parent[a] == a) {
      return a;
    }
    return parent[a] = find(parent[a]);
  };

  function<void(int, int)> merge = [&parent, &find](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);

    parent[b] = a;
  };

  unordered_map<int, int> converted;
  for (int i = 0; i < size; i++) {
    parent[i] = i;
    converted[nodes[i]] = i;
  }

  for (vector<int> &edge : edges) {
    int a = converted[edge[0]];
    int b = converted[edge[1]];

    children[a]++;
    children[b]++;

    merge(a, b);
  }

  vector<int> forward(size);
  vector<int> reverse(size);
  for (int node = 0; node < size; node++) {
    int parent = find(node);
    int val = nodes[node];

    if ((val % 2) == (children[node] % 2)) {
      forward[parent]++;
    } else {
      reverse[parent]++;
    }
  }

  int forwardCount = 0, reverseCount = 0;
  for (int node = 0; node < size; node++) {
    if (find(node) != node) continue;

    if (forward[node] == 1) forwardCount++;
    if (reverse[node] == 1) reverseCount++;
  }

  return {forwardCount, reverseCount};
}
```

## 고생한 점
