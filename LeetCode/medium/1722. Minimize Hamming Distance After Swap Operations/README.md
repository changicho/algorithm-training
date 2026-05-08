# 1722. Minimize Hamming Distance After Swap Operations

[링크](https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 연결의 갯수를 M이라 하자.

연결된 index들끼리 그룹을 만들 만들 수 있다. 이를 위해 disjoint set을 사용할 경우 O(M + a(N))의 시간 복잡도를 사용한다.

여기서 a(N)은 애크만 상수이며 이는 무시한다.

이후 각 그룹마다 차이의 수를 구할 때 hash map을 사용할 경우 총 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

disjoint set에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     123      |  O(N + M)   |    O(N)     |

swap이 가능한 index들 끼리 그룹으로 묶는다. (유니온 파인드)

이후 각 그룹의 index들을 순회하며 source에 존재하는 값의 count를 증가시키고 target에 존재하는 값의 count는 감소시킨다.

이를 이용해 hash map에 남은 count가 0이 아닌 경우 차이가 존재함을 알 수 있다.

이후 해당 차이를 2로 나눈 값을 정답에 더하며 이를 각 그룹마다 반복한다.

```cpp
vector<int> parents;

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parents[b] = a;
}

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
  int size = source.size();
  parents.resize(size);
  for (int i = 0; i < size; i++) {
    parents[i] = i;
  }

  for (vector<int>& e : allowedSwaps) {
    merge(e[0], e[1]);
  }

  vector<vector<int>> groups(size);
  for (int i = 0; i < size; i++) {
    groups[find(i)].push_back(i);
  }
  int answer = 0;
  for (int p = 0; p < size; p++) {
    unordered_map<int, int> count;
    for (int& i : groups[p]) {
      count[source[i]]++;
      count[target[i]]--;
    }

    int diff = 0;
    for (auto [key, val] : count) {
      diff += abs(val);
    }

    answer += diff / 2;
  }
  return answer;
}
```

## 고생한 점
