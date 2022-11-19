# 374. Guess Number Higher or Lower

[링크](https://leetcode.com/problems/guess-number-higher-or-lower/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 N까지 모든 경우를 시도해 볼 경우 O(N)의 시간 복잡도를 사용한다.

이분 탐색을 이용해 탐색할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

탐색을 진행하는 데 별도의 추가 공간이 필요하지 않다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(log_2(N)) |    O(1)     |

guess의 응답은 다음과 같다.

- -1 : 현재 숫자가 num보다 작음
- 0 : 현재 숫자가 num임
- 1 : 현재 숫자가 num보다 큼

이를 이용해 각 요청마다 반대의 경우는 제외하고 탐색을 이어나갈 수 있다.

```cpp
int guessNumber(int n) {
  if (guess(n) == 0) return n;

  long left = 0, right = n;
  while (left < right) {
    int mid = left + (right - left) / 2;

    int result = guess(mid);
    if (result == 1) {
      // pick right
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }

  return left;
}
```

## 고생한 점
