# 2210. Count Hills and Valleys in an Array

[링크](https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

순회를 이용해 hill와 valley를 찾는다면, O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

중복을 제거한 별도 배열을 사용할 경우 O(N)의 공간 복잡도를 갖는다.

순회만 사용한다면 O(1)의 공간 복잡도를 갖는다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 index를 순회하며 이전 숫자와 같은 숫자들을 건너뛴다.

각 과정에서 hill과 valley인 경우 각각 증가시킨다.

이후 hill과 valley의 합을 반환한다.

```cpp
int countHillValley(vector<int>& nums) {
  int size = nums.size();

  int hill = 0;
  int valley = 0;
  for (int i = 1; i < size - 1; i++) {
    while (i < size - 1 && nums[i - 1] == nums[i]) {
      i++;
    }
    if (i == size - 1) break;
    int before = nums[i - 1];
    int cur = nums[i];
    while (i < size - 1 && nums[i] == nums[i + 1]) {
      i++;
    }
    if (i == size - 1) break;
    int next = nums[i + 1];

    if (before < cur && cur > next) {
      hill++;
    }
    if (before > cur && cur < next) {
      valley++;
    }
  }

  return hill + valley;
}
```

## 고생한 점
