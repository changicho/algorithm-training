# 1488. Avoid Flood in The City

[링크](https://leetcode.com/problems/avoid-flood-in-the-city/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 rains의 크기를 N이라 하자.

비가 내리지 않는 경우 힙을 이용해 가장 유리한 호수를 선택할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 가진다.

혹은 이분 탐색을 이용해 홍수가 나지 않도록 비가 내리지 않는 날을 선택할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 가진다.

### 공간 복잡도

힙, BST set에 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     150      | O(N \* log_2(N)) |    O(N)     |

현재 비가 오지 않는경우, 기존에 물이 차있던 호수 중 가장 빨리 해당 호수에 비가 오는 호수를 마르게 하는 편이 유리하다.

따라서 각 호수마다 다음 홍수가 언제 오는지 미리 계산한다.

이후 비가 오는날 해당 호수가 홍수가 날 수 있는 날을 우선순위 큐에 저장하며, 비가 오지 않는 날에는 우선순위 큐에서 가장 빨리 홍수가 날 수 있는 호수를 선택해 마르게 한다.

만약 이미 물이 차있는 호수에 비가 오는 경우, 홍수가 나므로 빈 배열을 반환한다.

```cpp
vector<int> avoidFlood(vector<int>& rains) {
  int size = rains.size();

  unordered_map<int, int> before;
  vector<int> nexts(size, size + 1);
  for (int i = 0; i < size; i++) {
    int r = rains[i];
    if (r == 0) continue;
    if (before.count(r)) {
      nexts[before[r]] = i;
    }

    before[r] = i;
  }

  // index, value
  priority_queue<pair<int, int>> pq;
  unordered_map<int, int> count;

  vector<int> answer;
  for (int i = 0; i < size; i++) {
    int r = rains[i];

    if (r == 0) {
      if (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();

        answer.push_back(cur.second);
        count[cur.second]--;
      } else {
        answer.push_back(1);
      }
    } else {
      if (count[r] > 0) return {};

      answer.push_back(-1);

      pq.push({-nexts[i], r});
      count[r]++;
    }
  }

  return answer;
}
```

### BST set (이분 탐색)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     115      | O(N \* log_2(N)) |    O(N)     |

위 방법에서 이번엔 비가 오지 않는 날을 set에 저장해둔다.

이후 홍수가 날 수 있는 날인 경우 해당 호수가 이미 찬 날부터 현재까지 비가 오지 않는 날 중 가장 빠른 날을 이분 탐색으로 찾는다.

```cpp
vector<int> avoidFlood(vector<int>& rains) {
  int size = rains.size();
  vector<int> answer(size, 1);

  set<int> zeroSet;
  unordered_map<int, int> lastI;

  for (int i = 0; i < size; i++) {
    int r = rains[i];

    if (r == 0) {
      zeroSet.insert(i);
    } else {
      answer[i] = -1;

      if (lastI.count(r)) {
        auto it = zeroSet.lower_bound(lastI[r]);
        if (it == zeroSet.end()) {
          return {};
        }
        answer[*it] = r;
        zeroSet.erase(it);
      }
      lastI[r] = i;
    }
  }
  return answer;
}
```

## 고생한 점
