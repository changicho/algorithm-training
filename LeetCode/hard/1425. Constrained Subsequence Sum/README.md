# 1425. Constrained Subsequence Sum

[링크](https://leetcode.com/problems/constrained-subsequence-sum/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 원소의 갯수를 N이라 하자.

모든 subsequence를 탐색할 경우 시간 복잡도는 O(2^N)이다. 이는 제한시간 내에 불가능하다.

힙을 이용해 현재 탐색한 index까지 기존의 최대값을 저장하고, 이를 이용해 현재 index의 최대값을 갱신할 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

힙에 O(N)의 공간 복잡도를 사용한다.

### 힙

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     204      | O(N \* log_2(N)) |    O(N)     |

현재 방문한 index까지 직전에 subsequence들의 최대값을 알 수 있다면 이를 이용해 현재 index의 최대값을 갱신할 수 있다.

다음과 같은 data를 가지는 힙을 생성한다.

- val : 현재 index까지의 최대값
- index : 현재 index

여기서 힙은 max heap으로 설정하고 val을 기준으로 정렬한다.

이후 현재 index까지 순회하며 heap의 top에 있는 값이 현재 index에서 k번째 전의 값보다 작은 경우 pop한다.

이는 현재 index에서 k번째 전의 값은 현재 값에 더할 수 없기 때문이다.

직전 heap의 최대값에 현재 값을 더하고, index를 갱신한 값을 힙에 삽입한다.

이 과정중에 최대값을 갱신하고, 이를 반환한다.

```cpp
struct Data {
  int val, index;

  bool operator<(const Data& b) const { return val < b.val; }
};

int constrainedSubsetSum(vector<int>& nums, int k) {
  size_t size = nums.size();

  priority_queue<Data> pq;
  // max heap
  pq.push({nums[0], 0});
  int answer = nums[0];

  for (int i = 1; i < size; i++) {
    while (i - pq.top().index > k) {
      pq.pop();
    }

    int cur = max(0, pq.top().val) + nums[i];
    answer = max(answer, cur);
    pq.push({cur, i});
  }

  return answer;
}
```

## 고생한 점
