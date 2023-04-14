# 2602. Minimum Operations to Make All Array Elements Equal

[링크](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, queries의 크기를 M이라 하자.

각 과정마다 직접 구할 경우 O(N \* M)의 시간 복잡도를 사용하며, 이는 제한시간 내에 불가능하다.

nums를 정렬 후 prefix sum을 구하고 이후 쿼리를 순회하며 정답을 구할 수 있다.

이 때 각 쿼리마다 이분 탐색을 이용해 절대값의 차이의 합을 구할 수 있다.

이 경우 O((N + M) \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 구하는 데 O(N)의 공간 복잡도를 사용한다.

### prefix sum & 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     269      | O((N + M) \* log_2(N)) |    O(N)     |

nums의 원소들에 대해 특정 query에 대해 절대값들의 차이의 합을 다음과 같이 구할 수 있다.

- nums를 순회하며 직접 구한다.
- nums에서 query 미만의 값들, 이상의 값들을 둘로 나눈뒤 아래 식을 적용한다.
  - 미만의 값들의 합을 구하고 query와 이 갯수를 곱한 값의 차를 구해 더한다.
  - 이상의 값들의 합을 구하고 query와 이 갯수를 곱한 값의 차를 구해 더한다.

여기서 첫번째 방법은 제한 시간 내에 불가능하므로 두번째 방법을 이용한다.

이를 위해 query 이상의 값들의 위치를 찾기 위해 정렬 후 이분 탐색을 사용한다.

이를 구현하면 다음과 같다.

```cpp
long long calc(vector<long long> &prefixes, vector<int> &nums, int query) {
  int size = nums.size();

  int center = lower_bound(nums.begin(), nums.end(), query) - nums.begin();

  long long ret = 0;
  // left part
  ret += abs(prefixes[center] - (long long)query * (center));
  // right part
  ret += abs(prefixes[size] - prefixes[center] -
              (long long)query * (size - center));

  return ret;
}

vector<long long> minOperations(vector<int> &nums, vector<int> &queries) {
  vector<long long> answer;

  sort(nums.begin(), nums.end());

  int size = nums.size();
  vector<long long> prefixes(size + 1, 0);
  for (int i = 0; i < size; i++) {
    prefixes[i + 1] = prefixes[i] + nums[i];
  }

  for (int &query : queries) {
    answer.push_back(calc(prefixes, nums, query));
  }
  return answer;
}
```

## 고생한 점
