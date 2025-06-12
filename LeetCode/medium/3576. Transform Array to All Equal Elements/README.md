# 3576. Transform Array to All Equal Elements

[링크](https://leetcode.com/problems/transform-array-to-all-equal-elements/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

각 배열의 모든 원소를 1, -1 두 경우중 하나로 맞추는 경우를 모두 탐색한다.

이 때 왼쪽부터 순차적으로 바꿀 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 임시 배열을 사용하는데 이 때 O(N)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      14      |    O(N)     |    O(N)     |

nums의 원소를 모두 1로 바꾸는 경우를 가정해보자.

한번의 연산에 i, i+1 번째 원소를 모두 뒤집을 수 있다.

이 연산을 왼쪽부터 수행하며 모두 1로 변경할 수 있는지 확인한다.

이후 해당 횟수가 K번 이하인지 확인한다.

이를 -1에 대해서도 똑같이 수행한다.

```cpp
bool check(vector<int> nums, int k, int target) {
  int size = nums.size();

  int count = 0;
  for (int i = 0; i < size - 1; i++) {
    if (nums[i] != target) {
      nums[i] *= -1;
      nums[i + 1] *= -1;
      count++;
    }
  }

  if (nums[size - 1] != target) return false;
  return count <= k;
}

bool canMakeEqual(vector<int>& nums, int k) {
  bool first = check(nums, k, 1);
  bool second = check(nums, k, -1);

  return first || second;
}
```

## 고생한 점
