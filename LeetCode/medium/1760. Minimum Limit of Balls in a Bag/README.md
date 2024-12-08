# 1760. Minimum Limit of Balls in a Bag

[링크](https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N, 최대값을 M이라 하자.

이분 탐색을 사용해 특정 값이 최대값이 되도록 만들 수 있는지 판별한다.

이에 O(N)의 시간 복잡도가 소요된다.

이를 M에 대해 이분탐색을 사용할 경우 O(N \* log_2(M))의 시간 복잡도가 소요된다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      29      | O(N \* log_2(M)) |    O(1)     |

배열 nums에 maxOperations번 연산을 수행해 최대값을 limit 이하로 만들 수 있는지 판별한다.

그리고 limit을 찾는 이분 탐색을 수행한다.

판별은 다음과 같이 수행할 수 있다.

- nums의 현재 숫자를 num이라 하자.
- num을 limit로 나눈 값을 올림 처리한 값에, 한번의 연산 횟수를 뺀 값이 연산 횟수이다.
- 이 값의 합이 maxOperations보다 작은지 판단한다.

이 때 한번의 연산 횟수를 빼는 이유는 연산 결과에서 해당 limit값 이하의 값이 마지막에 남기 때문이다.

```cpp
bool calc(vector<int> &nums, int limit, int oper) {
  int count = 0;
  for (int &num : nums) {
    int curCount = num / limit + (num % limit > 0) - 1;
    count += curCount;

    if (count > oper) return false;
  }
  return true;
}

int minimumSize(vector<int> &nums, int maxOperations) {
  int left = 1, right = *max_element(nums.begin(), nums.end()) + 1;

  int answer = INT_MAX;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (calc(nums, mid, maxOperations)) {
      // pick left part
      right = mid;
      answer = mid;
    } else {
      // pick right part
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
