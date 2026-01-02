# 961. N-Repeated Element in Size 2N Array

[링크](https://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회를 이용해 갯수를 셀 경우 O(N)의 시간 복잡도를 사용한다.

정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

배열의 원소의 종류를 M (10^5)라 하자.

갯수를 세기 위한 배열을 사용할 경우 O(M)의 공간 복잡도를 사용한다.

정렬에 O(N)의 공간 복잡도를 사용한다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(M)     |

원소의 갯수를 세 N/2개인 원소를 반환한다.

```cpp
int repeatedNTimes(vector<int>& nums) {
  int size = nums.size();

  int count[10001] = {
      0,
  };
  for (int& num : nums) {
    count[num]++;

    if (count[num] == size / 2) return num;
  }
  return -1;
}
```

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

배열의 원소가 정렬되어있는 경우 N/2개인 원소는 다음 3가지 중 하나이다.

- 가장 작은 값 : 왼쪽 절반에 모두 존재
- 가장 큰 값 : 오른쪽 절반에 모두 존재
- 중간 값 : 양쪽 절반에 걸쳐 존재

따라서 정렬 후 위 3가지 경우를 확인해 반환한다.

```cpp
int repeatedNTimes(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int half = size / 2;
  if (nums[0] == nums[half - 1]) return nums[0];
  if (nums[half] == nums[size - 1]) return nums[size - 1];

  return nums[half];
}
```

## 고생한 점
