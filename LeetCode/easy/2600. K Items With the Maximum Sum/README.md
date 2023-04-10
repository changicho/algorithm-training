# 2600. K Items With the Maximum Sum

[링크](https://leetcode.com/problems/k-items-with-the-maximum-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수들 numOnes, numZeros, numNegOnes의 합을 N이라 하자.

이를 모두 배열로 만든 후 K개의 수를 고를 경우 O(N)의 시간 복잡도를 사용한다.

각 수를 순회하며 직접 구할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

직접 배열을 선언할 경우 O(N)의 공간 복잡도를 사용한다.

직접 구할 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(1)     |    O(1)     |

정답은 다음 3 가지 경우중 하나이다.

- 1로만 구성된경우
- 1과 0으로만 구성된 경우
- 1, 0, -1로만 구성된 경우

k를 numOnes, numZeros, numNegOnes에 대해 비교하며 정답을 구한다.

```cpp
int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
  int sum = 0;
  if (numOnes >= k) {
    return k;
  }
  sum += numOnes;
  k -= numOnes;
  if (numZeros >= k) {
    return sum;
  }
  k -= numZeros;
  return sum - k;
}
```

## 고생한 점
