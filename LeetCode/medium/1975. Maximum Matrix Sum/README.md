# 1975. Maximum Matrix Sum

[링크](https://leetcode.com/problems/maximum-matrix-sum/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 크기를 R \* C라 하자.

인접한 수 들에 -1을 곱할 수 있다. 이 경우 음수들을 양수로도 바꿀 수 있는지 판단하는 데 음수의 개수를 세어야 한다.

이 때 모든 수의 합과 -1을 남길 수를 정하는 데 순회가 필요하다. 이에 시간 복잡도는 O(R \* C)이다.

### 공간 복잡도

각 최소값과 합을 구하는 데 O(1)의 공간 복잡도가 필요하다.

### greedy

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |    O(1)     |

인접한 두 수에 -1을 곱할 수 있다.

음수들에 -1을 곱해 양수로 바꿀 수 있으며 음수의 수가 짝수인 경우 모두 바꿀 수 있고 음수인 경우 하나를 남길 수 있다.

이 때 남겨진 하나의 음수는 가장 절대값이 작은 음수여야 한다.

이를 이용해 모든 수의 절대값의 합을 구한 뒤 음수의 수를 세고, 음수의 수가 홀수인 경우 가장 작은 음수의 절대값을 빼준다.

```cpp
long long maxMatrixSum(vector<vector<int>>& matrix) {
  long long sum = 0;
  int minimumAbs = INT_MAX;
  int negative = 0;

  for (vector<int>& row : matrix) {
    for (int& num : row) {
      sum += abs(num);

      if (num < 0) {
        negative++;
      }

      minimumAbs = min(minimumAbs, abs(num));
    }
  }

  if (negative % 2 == 1) {
    sum -= 2 * minimumAbs;
  }

  return sum;
}
```

## 고생한 점
