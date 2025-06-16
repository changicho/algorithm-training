# 3572. Maximize Y‑Sum by Picking a Triplet of Distinct X‑Values

[링크](https://leetcode.com/problems/maximize-ysum-by-picking-a-triplet-of-distinct-xvalues/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 x, y의 길이를 N이라 하자.

각 x좌표마다 최대인 y값들을 저장 후 이 중 최대 3개를 선택한다.

hash map을 사용해 저장할 경우 O(N) 의 시간 복잡도를 사용한다.

이후 3개의 값을 선택할 때 우선순위 큐를 사용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표들을 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### hash map & heap

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |    O(N)     |    O(N)     |

각 x좌표에 해당하는 y좌표 중 최대값을 저장한다.

이를 위해 hash map을 사용한다.

이후 저장된 y좌표 중 최대 3개를 선택하기 위해 우선순위 큐를 사용한다.

```cpp
int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
  int size = x.size();
  unordered_map<int, int> yMax;

  for (int i = 0; i < size; i++) {
    yMax[x[i]] = max(yMax[x[i]], y[i]);
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (auto [k, v] : yMax) {
    pq.push(v);
    if (pq.size() > 3) pq.pop();
  }

  if (pq.size() < 3) return -1;
  int answer = 0;
  while (!pq.empty()) {
    answer += pq.top();
    pq.pop();
  }
  return answer;
}
```

## 고생한 점
