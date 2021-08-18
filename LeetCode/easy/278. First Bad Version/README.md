# 278. First Bad Version

[링크](https://leetcode.com/problems/first-bad-version/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

N의 범위가 매우 크므로 브루트 포스 방법을 수행할 경우 시간 초과가 발생한다. (브루트 포스 : O(N))

따라서 이분 탐색을 이용해 시간복잡도를 최적화한다.

이 경우 시간 복잡도는 O(log_2(N))이다.

### 공간 복잡도

이분 탐색에 별도의 공간 복잡도가 필요하지 않다. O(1)

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

최초의 bad version을 찾으면 되는 문제이다.

이분 탐색을 이용해 만약 현재 숫자가 bad version인 경우 더 작은 숫자로, 그 외의 경우는 더 큰 숫자로 변경한다.

```cpp
int firstBadVersion(int n) {
  int left = 1, right = n, mid;
  while (left <= right) {
    mid = left + (right - left) / 2;

    if (isBadVersion(mid)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return left;
}
```

## 고생한 점
