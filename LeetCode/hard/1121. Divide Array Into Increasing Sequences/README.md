# 1121. Divide Array Into Increasing Sequences

[링크](https://leetcode.com/problems/divide-array-into-increasing-sequences/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

중복된 원소의 수가 만들 수 있는 최대한의 subsequences 갯수를 넘어선 경우 불가능하다.

순회를 이용해 각 원소의 중복된 개수를 센다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열은 이미 정렬되어 있으므로 중복된 원소를 세는데 O(1)의 공간 복잡도를 사용한다.

### 중복 원소 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

최소 subsequences의 크기는 K이다.

현재 nums에서 만들 수 있는 최대한의 subsequences의 크기는 nums의 길이를 K로 나눈 값이다. 이는 `ceil(N / K)` 이다.

이 값보다 특정 원소의 수가 많은 경우 정답 조건을 만족할 수 없다.

배열은 정렬되어있으므로 연이은 중복된 원소의 값을 순회 가능하다. 이를 이용해 갯수를 구하며 정답을 만들 수 없는 경우 false를 반환한다.

```cpp
bool canDivideIntoSubsequences(vector<int>& nums, int k) {
  int size = nums.size();

  int before = nums[0], count = 0;
  for (int& num : nums) {
    if (num == before) {
      count++;
    } else {
      before = num;
      count = 1;
    }

    // need start count more than available
    if (count * k > size) return false;
  }
  return true;
}
```

## 고생한 점
