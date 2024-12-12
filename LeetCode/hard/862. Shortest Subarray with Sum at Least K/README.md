# 862. Shortest Subarray with Sum at Least K

[링크](https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

힙을 사용해 풀이할 경우 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

힙을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 최소 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      87      | O(N \* log_2(N)) |    O(N)     |

현재까지의 합과 index를 최소 힙에 저장한다.

이후 힙의 top에 있는 최소값과 현재 값들을 이용해 sum이 k 이상인 최소 subArray의 길이를 구할 수 있다.

```cpp
int shortestSubarray(vector<int>& nums, int k) {
  int size = nums.size();

  int answer = INT_MAX;

  // sum, index
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                  greater<>>
      minHeap;
  long long sum = 0;

  for (int i = 0; i < size; i++) {
    sum += nums[i];

    if (sum >= k) {
      answer = min(answer, i + 1);
    }

    while (!minHeap.empty() && sum - minHeap.top().first >= k) {
      answer = min(answer, i - minHeap.top().second);
      minHeap.pop();
    }

    minHeap.push({sum, i});
  }

  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
