# 3727. Maximum Alternating Sum of Squares

[링크](https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

문제 조건에 따라 제곱값을 정렬 후 유리한 순으로 선택한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      59      | O(N \* log_2(N)) |    O(N)     |

각 값을 제곱한 배열을 만든 뒤 해당 배열을 정렬한다.

문제 조건에 따라 순서를 마음대로 뒤바꿀 수 있으므로 + 부분에 큰 N/2개의 값을, 나머지를 -부분에 할당한다.

이 때 N이 홀수인 경우 (N+1)/2 개를 선택 가능함에 유의한다.

```cpp
long long maxAlternatingSum(vector<int>& nums) {
  int size = nums.size();
  for (int& num : nums) {
    num *= num;
  }
  sort(nums.begin(), nums.end());

  long long minusPart =
      accumulate(nums.begin(), nums.begin() + size / 2, 0LL);
  long long plusPart = accumulate(nums.begin() + size / 2, nums.end(), 0LL);

  return plusPart - minusPart;
}
```

## 고생한 점
