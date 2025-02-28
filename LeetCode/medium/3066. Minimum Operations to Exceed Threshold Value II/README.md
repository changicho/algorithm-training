# 3066. Minimum Operations to Exceed Threshold Value II

[링크](https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 경우마다 가장 작은 값 2개를 찾아야한다.

이를 위해 힙을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      87      | O(N \* log_2(N)) |    O(N)     |

힙에 모든 원소를 넣고 조건을 만족할 때 까지 연산을 반복한다.

힙에서 가장 작은 값 2개를 꺼내어 조건을 만족한 값을 다시 힙에 넣어 다음번 연산때 빠르게 숫자를 찾는다.

```cpp
int minOperations(vector<int>& nums, int k) {
  priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

  int answer = 0;
  while (pq.size() >= 2 && pq.top() < k) {
    long long first = pq.top();
    pq.pop();
    long long second = pq.top();
    pq.pop();

    pq.push(min(first, second) * 2 + max(first, second));

    answer++;
  }

  if (pq.empty() || pq.top() < k) return -1;
  return answer;
}
```

## 고생한 점
