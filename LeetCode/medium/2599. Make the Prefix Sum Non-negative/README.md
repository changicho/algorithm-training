# 2599. Make the Prefix Sum Non-negative

[링크](https://leetcode.com/problems/make-the-prefix-sum-non-negative/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 시도할 경우 O(2^N)의 시간 복잡도가 소요되므로 제한시간 내에 불가능하다.

힙을 이용해 가장 작은 값을 제거하며 탐색할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

힙에 O(N)의 공간 복잡도가 필요하다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      19      | O(N \* log_2(N)) |    O(N)     |

왼쪽부터 순회하며 현재 prefix sum을 계산한다.

이 때 현재까지 sum이 음수가 되는 경우가 존재하며 이 경우 현재 합에 포함되어 있는 원소들 중 가장 낮은 값을 제거해야 한다.

이를 위해 현재까지 합을 저장할 때 구성하는 원소들 또한 힙에 저장한다.

이후 가장 낮은 값을 힙에서 꺼내 현재 합에서 빼주며, 이를 반복한다.

```cpp
int makePrefSumNonNegative(vector<int>& nums) {
  long long sum = 0;

  priority_queue<int, vector<int>, greater<int>> pq;

  int answer = 0;
  for (int& num : nums) {
    sum += num;
    pq.push(num);

    while (!pq.empty() && sum < 0) {
      sum -= pq.top();
      answer++;
      pq.pop();
    }
  }

  return answer;
}
```

## 고생한 점
