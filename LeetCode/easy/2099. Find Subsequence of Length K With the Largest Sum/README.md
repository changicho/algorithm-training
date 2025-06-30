# 2099. Find Subsequence of Length K With the Largest Sum

[링크](https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

순서를 유지하며 가장 큰 K개의 원소를 찾는다.

이를 위해 정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

nums의 원소와 index를 쌍으로 묶은 후 정렬한다.

이후 가장 큰 K개의 원소를 찾은 뒤 이를 index 순서로 정렬한다.

```cpp
vector<int> maxSubsequence(vector<int> &nums, int k) {
  int size = nums.size();

  vector<pair<int, int>> arr;
  for (int i = 0; i < size; i++) {
    arr.push_back({nums[i], i});
  }

  sort(arr.begin(), arr.end(), greater<pair<int, int>>());

  sort(arr.begin(), arr.begin() + k,
        [](auto &a, auto &b) { return a.second < b.second; });

  vector<int> answer;

  for (int i = 0; i < k; i++) {
    answer.push_back(arr[i].first);
  }

  return answer;
}
```

## 고생한 점
