# 2462. Total Cost to Hire K Workers

[링크](https://leetcode.com/problems/total-cost-to-hire-k-workers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 costs의 크기를 N, k의 크기를 K, candidates의 수를 C라 하자.

각 경우마다 우선순위가 높은 값을 선택해야 하므로 heap을 이용할 수 있다.

이 경우 heap에 포함되는 원소의 갯수는 최대 N개, 일반적으로 K + 2 \* C개의 원소를 삽입한다.

각 경우마다 힙에는 2 \* C개의 원소가 들어있으므로 시간 복잡도는 O((K + C) \* log_2(C)) 이다.

### 공간 복잡도

heap에 O(C)의 공간 복잡도를 사용한다.

### heap & two pointer

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     261      | O((K + C) \* log_2(C)) |    O(C)     |

입력받은 costs에서 현재 선택할 수 있는 cost중에서 가장 우선순위가 높은 값들을 매번 선택해야한다.

매 경우마다 왼쪽, 오른쪽에서 candidates개의 원소를 선택할 수 있으므로 선택한쪽에서 선택 가능한 범위를 하나씩 증가시킬 수 있다.

따라서 우선순위 큐를 이용해 우선순위가 높은 값을 뽑으며, 투 포인터를 이용해 선택한 쪽의 범위를 증가시킨다.

이 때 모든 원소를 선택 가능한 경우 선택 범위를 더이상 증가시키지 않는다.

```cpp
struct Data {
  int cost, index;

  const bool operator<(const Data& b) const {
    if (cost != b.cost) return cost > b.cost;
    return index > b.index;
  }
};

long long totalCost(vector<int>& costs, int k, int candidates) {
  int size = costs.size();

  priority_queue<Data> pq;

  int left = candidates - 1, right = size - candidates;

  if (left >= right) {
    for (int i = 0; i < size; i++) {
      pq.push({costs[i], i});
    }
  } else {
    for (int i = 0; i <= left; i++) {
      pq.push({costs[i], i});
    }
    for (int i = size - 1; i >= right; i--) {
      pq.push({costs[i], i});
    }
  }

  long long answer = 0;
  for (int i = 0; i < k && !pq.empty(); i++) {
    Data cur = pq.top();
    pq.pop();

    answer += cur.cost;

    if (left + 1 >= right) continue;
    // pick from left
    if (cur.index <= left && (left < size - 1)) {
      left++;
      pq.push({costs[left], left});
    } else if (right > 0) {
      right--;
      pq.push({costs[right], right});
    }
  }
  return answer;
}
```

## 고생한 점
