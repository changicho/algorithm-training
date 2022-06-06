# 444. Sequence Reconstruction

[링크](https://leetcode.com/problems/sequence-reconstruction/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, sequences의 모든 연결구조 관계의 크기를 V라 하자. (노드의 번호는 1 ~ N까지)

서로 위상의 관계가 있으므로 위상 정렬을 이용하고 nums가 유일한 정렬 방법임을 탐색한다.

각 노드의 연결 관계는 sequences를 모두 순회하며 표현할 수 있다. 이를 모두 순회하는 데 O(V)의 시간 복잡도를 사용한다.

위상 정렬에 O(N + V)의 시간 복잡도를 사용한다.

### 공간 복잡도

그래프 공간을 표현하는 데 O(V)의 공간 복잡도를 사용한다.

위상정렬을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

따라서 총 공간 복잡도는 O(N + V)이다.

### 위상 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |  O(N + V)   |  O(N + V)   |

각 sequence에서 i, i+1번째 노드를 연결 관계로 보고 그래프를 생성한다.

이후 위상 정렬을 이용해 각 원소들을 순회한다.

이는 이미 sequence들이 nums의 subSequence이기 때문에 nums를 만들 수 있는 관계로 볼 수 있기 때문이다.

이 과정 중에서 유일한 결과만이 가능한지 판단한다.

(위상정렬 과정 중 q의 크기가 계속 1을 유지하는지)

이를 구현하면 다음과 같다.

```cpp
bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
  int size = nums.size();
  vector<int> inDegrees(size + 1, 0);
  vector<vector<int>> graph(size + 1);

  for (vector<int>& sequence : sequences) {
    int curSize = sequence.size();
    for (int i = 0; i < curSize - 1; i++) {
      int from = sequence[i], to = sequence[i + 1];

      graph[from].push_back(to);
      inDegrees[to]++;
    }
  }

  queue<int> q;
  for (int n = 1; n <= size; n++) {
    if (inDegrees[n] == 0) q.push(n);
  }

  if (q.size() > 1) return false;
  while (q.size() == 1) {
    int cur = q.front();
    q.pop();

    for (int& next : graph[cur]) {
      inDegrees[next]--;

      if (inDegrees[next] == 0) q.push(next);
    }
  }

  if (q.size() > 1) return false;

  return true;
}
```

### 관계 비교 (one pass)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      77      |  O(N + V)   |  O(N + V)   |

각 sequence를 순회하며 현재 각 노드들의 연결 구조가 다른 sequence에서도 동일하게 나타나는지 판단한다.

이는 nums의 순서대로만 sequence를 만족해야 하기 때문이다.

미리 nums를 순회하며 order를 정하고, 이후 sequence를 순회하며 연결 구조가 깨지는 지를 판단한다.

이때 중복된 경우가 생성될 수 있으므로, 만약 (i), (i+1) 번째 두 노드에 대해서 연결 구조를 방문하는것이 확실한 경우 i번째 노드에 대해 최소 요구조건을 만족 했다고 볼 수 있다.

따라서 i번째에 대해서 최소 조건을 충족했으므로 마킹한다.

맨 마지막 노드는 마킹할 수 없으므로 N-1개의 마킹이 완료된 경우 유일한 order임을 판단할 수 있다.

이를 구현하면 다음과 같다.

```cpp
bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
  int size = nums.size();

  vector<int> order(size + 1);
  vector<bool> visited(size + 1, false);
  for (int i = 0; i < size; i++) {
    order[nums[i]] = i;
  }

  int toMatch = size - 1;
  for (vector<int>& sequence : sequences) {
    for (int i = 1; i < sequence.size(); i++) {
      int from = sequence[i - 1], to = sequence[i];

      if (order[from] >= order[to]) return false;
      if (visited[from] == false && order[from] + 1 == order[to]) {
        visited[from] = true;
        --toMatch;
      }
    }
  }

  return toMatch == 0;
}
```

## 고생한 점
