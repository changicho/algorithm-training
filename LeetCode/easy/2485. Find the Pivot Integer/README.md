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

## 고생한 점
