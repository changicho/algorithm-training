# 3318. Find X-Sum of All K-Long Subarrays I

[링크](https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N, subArray의 크기를 K, 값을 X라 하자.

모든 subArray를 만드는 데 슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도가 필요하다.

이후 각 subArray에서 정답을 구하는 데 힙을 사용할 경우 O(K \* log(X))의 시간 복잡도가 필요하다.

따라서 최종 시간 복잡도는 O(N \* K \* log(X))이다.

### 공간 복잡도

힙에 O(X)의 공간 복잡도가 필요하다.

### counts & heap

| 내 코드 (ms) |     시간 복잡도     | 공간 복잡도 |
| :----------: | :-----------------: | :---------: |
|      16      | O(N \* K \* log(X)) |    O(X)     |

각 subArray의 원소의 갯수들을 센 뒤, 갯수와 값에 대해 min heap을 사용해 X개의 원소를 유지한다.

이후 해당 원소들을 이용해 정답을 구한다.

이를 모든 subArray에 대해 반복한다.

```cpp
int calc(unordered_map<int, int> &counts, int x) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  for (auto [key, val] : counts) {
    pq.push({val, key});
    if (pq.size() > x) {
      pq.pop();
    }
  }

  int ret = 0;
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    ret += cur.first * cur.second;
    x--;
  }
  return ret;
}

vector<int> findXSum(vector<int> &nums, int k, int x) {
  int size = nums.size();

  unordered_map<int, int> counts;
  for (int i = 0; i < k; i++) {
    counts[nums[i]]++;
  }
  vector<int> answer;
  for (int left = 0, right = k - 1; right < size; left++, right++) {
    int cur = calc(counts, x);
    answer.push_back(cur);

    if (right + 1 < size) {
      counts[nums[left]]--;
      if (counts[nums[left]] == 0) {
        counts.erase(nums[left]);
      }
      counts[nums[right + 1]]++;
    }
  }
  return answer;
}
```

## 고생한 점
