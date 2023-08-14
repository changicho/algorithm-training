# 2811. Check if it is Possible to Split Array

[링크](https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 nums의 길이를 N이라 하자. (N <= 100)

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이다.

동적 계획법을 사용해 중복되는 경우를 제외하고 탐색을 진행할 수 있다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법 (bottom up)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      53      |   O(N^2)    |   O(N^2)    |

현재 sub array를 둘로 나누는 경우를 생각해보자.

크기가 5인 sub array를 2, 3인 두개의 sub array로 나누는 작업은 다음과 같이 생각할 수 있다.

- 1, 4 로 나눔
- 1, 3 로 나눔

즉 맨 앞과 맨 뒤에서 하나씩 빼서 나누는 경우로 생각할 수 있다.

여기서 현재 sub array의 합에서 맨 앞과 맨 뒤를 빼고 남은 sub array의 합이 m보다 크거나 같은 경우에만 탐색을 진행한다.

각 경우마다 sub array의 가장 왼쪽, 오른쪽 index를 이용해 구분하며 중복되는 경우를 제외한다.

```cpp
struct Status {
  int left, right, sum;
};

bool canSplitArray(vector<int>& nums, int m) {
  int size = nums.size();

  if (size <= 2) return true;

  int left = 0, right = size - 1;

  int sum = accumulate(nums.begin(), nums.end(), 0);

  bool visited[101][101] = {
      0,
  };

  if (sum < m) return false;

  queue<Status> q;
  q.push({left, right, sum});

  while (!q.empty()) {
    Status cur = q.front();
    q.pop();

    if (cur.right - cur.left <= 1) return true;
    if (visited[cur.left][cur.right]) continue;
    visited[cur.left][cur.right] = true;

    // check pick left
    int nextSum = cur.sum;
    if ((nextSum - nums[cur.left]) >= m) {
      q.push({cur.left + 1, cur.right, nextSum - nums[cur.left]});
    }
    if ((nextSum - nums[cur.right]) >= m) {
      q.push({cur.left, cur.right - 1, nextSum - nums[cur.right]});
    }
  }

  return false;
}
```

## 고생한 점
