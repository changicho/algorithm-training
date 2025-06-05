# 3355. Zero Array Transformation I

[링크](https://leetcode.com/problems/zero-array-transformation-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N, queries의 길이를 Q라 하자.

각 index마다의 diff를 저장 후 배열을 순회하며 쿼리 이후 1이상의 값이 남는지 확인한다.

이에 쿼리를 순회해 diff를 저장하는데 O(Q) 시간 복잡도를 사용한다.

이후 배열을 순회하는데 O(N) 시간 복잡도를 사용한다.

따라서 전체 시간 복잡도는 O(N + Q)이다.

### 공간 복잡도

각 index마다의 diff를 저장하기 위해 O(N) 공간 복잡도를 사용한다.

### diff array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |  O(N + Q)   |    O(N)     |

쿼리를 순회하며 쿼리의 left, right에 대해 변경되는 diff를 저장한다.

left일 때 감소하는 값이 1 증가하고 right + 1일 때 감소하는 값이 1 감소한다.

이후 배열을 순회하며 diff를 누적하여 현재 index의 nums값 보다 큰지 확인한다.

```cpp
bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
  int size = nums.size();

  vector<int> diffs(size + 1, 0);
  for (vector<int>& q : queries) {
    int l = q[0], r = q[1];

    diffs[l]++;
    diffs[r + 1]--;
  }

  int diff = 0;
  for (int i = 0; i < size; i++) {
    diff += diffs[i];

    if (nums[i] > diff) return false;
  }
  return true;
}
```

## 고생한 점
