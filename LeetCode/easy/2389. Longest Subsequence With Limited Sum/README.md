# 2389. Longest Subsequence With Limited Sum

[링크](https://leetcode.com/problems/longest-subsequence-with-limited-sum/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N, queries의 크기를 M이라 하자.

nums의 크기의 합으로 query 이하의 수를 만들 때 가장 많은 숫자를 선택하고자 한다.

이를 위해 정렬 후, 부분합 & 이분탐색을 이용한다.

이 경우 정렬에 O(N _ log_2(N))의 시간 복잡도를, 정답을 이분탐색으로 생성하는데 O(M _ log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + M) \* log_2(N))이다.

### 공간 복잡도

부분합을 저장하는데 O(N)의 공간 복잡도를 사용한다.

정답으로 반환하는 배열에 O(M)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      32      | O((N + M) \* log_2(N)) |  O(N + M)   |

각 query에 대해서 가장 많은 수를 선택하기 위해선 가장 작은 값들부터 더해 query를 넘는지를 판단하면 된다.

따라서 nums를 오름차순으로 정렬 후 왼쪽부터 각 수를 더했을 때의 sum을 부분합으로 생성한다.

이후 각 query마다 이분탐색 (upper_bound)를 이용해 query이하의 sum을 찾고 해당 sum은 몇개의 수로 구성되어있는지를 정답에 저장한다.

```cpp
vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
  int n = nums.size(), m = queries.size();

  sort(nums.begin(), nums.end());
  vector<int> subArr(n + 1, 0);
  for (int i = 0; i < n; i++) {
    subArr[i + 1] = subArr[i] + nums[i];
  }

  vector<int> answer(m);
  for (int i = 0; i < m; i++) {
    int idx = upper_bound(subArr.begin(), subArr.end(), queries[i]) -
              subArr.begin() - 1;

    answer[i] = idx;
  }

  return answer;
}
```

## 고생한 점
