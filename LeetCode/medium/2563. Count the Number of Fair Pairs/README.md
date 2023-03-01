# 2563. Count the Number of Fair Pairs

[링크](https://leetcode.com/problems/count-the-number-of-fair-pairs/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자. (N <= 10^5)

각 값을 정렬 후, 특정 값에 대해서 가능한 범위를 찾아 이 갯수를 정답에 더할 수 있다.

이 경우 정렬에 O(N \* log_2(N)), 순회에 O(N)의 시간 복잡도를 사용한다.

각 범위를 이분 탐색을 이용해 탐색할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

정렬에 별도의 공간을 사용할 경우 최대 O(N)의 공간 복잡도를 사용한다.

이분탐색에 별도의 공간 복잡도를 사용하지 않는다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     255      | O(N \* log_2(N)) |    O(1)     |

각 수를 정렬한다.

특정 수를 선택했을 때, fair가 될 수 있는 수의 갯수를 이분 탐색을 이용해 구할 수 있다.

이는 현재 수를 num으로 고정했을 때 나머지 수의 범위는 아래와 같기 때문이다.

- (lower - num) ~ (upper - cur)

이를 이용해 각 숫자마다의 다른 fair의 수를 정답에 더한다.

```cpp
long long countFairPairs(vector<int>& nums, int lower, int upper) {
  int size = nums.size();

  long long answer = 0;

  sort(nums.begin(), nums.end());

  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    int leftI = lower_bound(nums.begin() + (i + 1), nums.end(), lower - cur) -
                nums.begin();
    int rightI =
        upper_bound(nums.begin() + (i + 1), nums.end(), upper - cur) -
        nums.begin();

    int curCount = rightI - leftI;
    answer += curCount;
  }

  return answer;
}
```

## 고생한 점
