# 440. K-th Smallest in Lexicographical Order

[링크](https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N까지의 수를 모두 문자열로 저장하고 정렬 후 반환할 경우 O(N \* log_2(N))의 시간 복잡도를 사용하며 이는 N이 매우 크므로 불가능하다.

각 과정마다 현재 들어갈 자리수를 구하는 방법을 이용해 정답을 구할 수 있다. 이 경우 O(log_10(N)^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 자리수별로 구할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix search

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      0       | O(log_10(N)^2) |    O(1)     |

각 자리별로 (앞자리부터) 범위를 줄여가며 탐색한다.

이 때 k번째 수를 찾기 위해 범위를 줄여나가며 k를 함께 줄여나간다.

```cpp
int findKthNumber(int n, int k) {
  int result = 1;

  while (k > 1) {
    long count = 0, left = result, right = result + 1;
    while (left <= n) {
      count += min((long)n + 1, right) - left;

      left *= 10;
      right *= 10;
    }

    if (k > count) {
      k -= count;
      result++;
    } else {
      k--;
      result *= 10;
    }
  }
  return result;
}
```

## 고생한 점
