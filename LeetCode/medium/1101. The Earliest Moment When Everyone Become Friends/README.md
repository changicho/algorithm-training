# 1101. The Earliest Moment When Everyone Become Friends

[링크](https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

노드의 개수를 N, 로그의 개수를 M이라 하자.

우선 로그를 시간별로 순회하기 위해서는 정렬을 수행해야 하며 이 연산에 O(M \* log_2(M))의 시간 복잡도를 사용한다.

모든 인원이 친구인지 확인하는 데 O(N)의 시간 복잡도를 사용한다.

혹은 merge 마다 그룹의 노드를 더할 경우 O(1)의 시간 복잡도로 확인이 가능하다.

친구와의 연결 관계를 나타내기 위해서 유니온 파인드를 사용한다.

이 경우 merge에 O(a(N))만큼의 시간복잡도를 사용하며 이는 거의 상수이므로 O(1)이다.

따라서 최종 시간 복잡도는 O(N + M \* log_2(M))이 된다.

### 공간 복잡도

정렬에 O(M)의 공간 복잡도를 사용한다.

유니온 파인드를 사용하기 위해 O(N) 크기만큼의 공간을 사용한다.

### 유니온 파인드

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      52      | O(N + M \* log_2(M)) |  O(N + M)   |

로그들을 우선 timestamp에 대해서 정렬한다.

이후 각 로그들에 대해서 병합을 수행한다.

병합 이후 모든 노드들이 하나로 연결되었는지 검사하고, 모두 연결되었으면 현재 timestamp를 반환한다.

```cpp
vector<int> parents;
vector<int> counts;

int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);
  if (parentA == parentB) return;

  if (parentA > parentB) swap(parentA, parentB);
  if (counts[parentA] < counts[parentB]) swap(parentA, parentB);

  parents[parentB] = parentA;
  counts[parentA] += counts[parentB];
}

int earliestAcq(vector<vector<int>>& logs, int n) {
  parents.resize(n);
  counts.resize(n, 1);

  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  sort(logs.begin(), logs.end());

  int answer = -1;
  for (vector<int>& log : logs) {
    int timestamp = log[0];
    int first = find(log[1]), second = find(log[2]);

    merge(first, second);

    if (counts[find(first)] == n) {
      answer = timestamp;
      break;
    }
  }
  return answer;
}
```

### 유니온 파인드 - rank

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      52      | O(N + M \* log_2(M)) |  O(N + M)   |

merge를 수행할 때마다 그룹중에서 노드의 개수가 많은 쪽을 부모로 선택한다.

이는 이후에 find연산을 수행할 때 find연산의 횟수를 줄이기 위함이다.

또한 노드의 개수를 각 부모마다 저장할 경우 모든 노드가 하나의 그룹인지 여부를 바로 판단할 수 있다.

이 연산을 위해서 counts 배열을 생성하고 merge연산에 노드 개수별 우선순위 연산을 추가한다.

```cpp
vector<int> parents;
vector<int> counts;

int find(int node) {
  if (parents[node] == node) return node;

  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  int parentA = find(a), parentB = find(b);
  if (parentA == parentB) return;

  if (parentA > parentB) swap(parentA, parentB);
  if (counts[parentA] < counts[parentB]) swap(parentA, parentB);

  parents[parentB] = parentA;
  counts[parentA] += counts[parentB];
}

int earliestAcq(vector<vector<int>>& logs, int n) {
  parents.resize(n);
  counts.resize(n, 1);

  for (int i = 0; i < n; i++) {
    parents[i] = i;
  }

  sort(logs.begin(), logs.end());

  int answer = -1;
  for (vector<int>& log : logs) {
    int timestamp = log[0];
    int first = find(log[1]), second = find(log[2]);

    merge(first, second);

    if (counts[find(first)] == n) {
      answer = timestamp;
      break;
    }
  }
  return answer;
}
```

## 고생한 점
