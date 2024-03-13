# 2485. Find the Pivot Integer

[링크](https://leetcode.com/problems/find-the-pivot-integer/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 N까지 순회하며 각 자리수 까지의 합을 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

prefix sum을 이용할 경우 이전 순회에서 구한 합을 이용할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

각 과정마다 sum을 구하고 비교할 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색과 수학을 이용해 구할 수 있다. 이 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

직전까지의 합을 저장해 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

```cpp
int pivotInteger(int n) {
  int leftSum = 0, rightSum = (n + 1) * n / 2;

  for (int i = 1; i <= n; i++) {
    leftSum += i;
    if (leftSum == rightSum - leftSum + i) {
      return i;
    }
  }
  return -1;
}
```

### binary search & math

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

arithmetic progression sum formula를 이용해 1부터 N까지의 합을 S, 그 중 하나의 수를 X라 했을 때,

X^2 가 S인 경우가 존재할 경우 1~X, X~N까지의 합이 같다.

따라서 이분 탐색을 이용해 X를 찾는다.

이 때 X가 작은 경우는 X^2가 S보다 작고, X가 큰 경우는 X^2가 S보다 크다.

이를 이용해 X^2 - S가 0에 가장 가까운 X를 찾는다.

이후 X^2가 S인 경우에만 X를 반환한다.

```cpp
int pivotInteger(int n) {
  int left = 1, right = n;
  int sum = n * (n + 1) / 2;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (mid * mid - sum < 0) {
      // pick right part
      left = mid + 1;
    } else {
      // pick left part
      right = mid;
    }
  }

  if (left * left == sum) {
    return left;
  }

  return -1;
}
```

## 고생한 점
