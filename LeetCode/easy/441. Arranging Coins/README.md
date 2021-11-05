# 441. Arranging Coins

[링크](https://leetcode.com/problems/arranging-coins/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N에 대해서 1부터 K까지의 합이 N이하인 최대의 K를 찾는다고 하자.

직접 모든 경우를 구할 경우 sqrt(N)까지 반복하면 되므로 시간 복잡도는 O(sqrt(N))이 된다.

이를 이분 탐색으로 구할 경우 시간 복잡도는 O(log_2(N))이 된다.

수학적인 방법을 사용할 경우 공식에 의해 O(1)의 시간 복잡도로 구한다.

### 공간 복잡도

직접 모든 경우를 구한 경우, 이분 탐색, 수학적인 방법을 사용할 때 O(1)의 시간 복잡도를 사용한다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       | O(sqrt(N))  |    O(1)     |

직접 모든 경우를 순회하며 구한다.

1부터 k까지의 합이 n 이하가 되는 가장 큰 k를 구해야 한다.

각 층별로 개수를 증가시키며 시뮬레이션을 돌린다.

이후 마지막에 남은 숫자가 층을 모두 채울 수 있는지를 판별한다.

```cpp
int arrangeCoins(int n) {
  int level = 1;
  int temp = n;

  while (temp >= level) {
    temp -= level;
    level++;
  }

  if (temp < level) {
    level -= 1;
  }

  return level;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(log_2(N)  |    O(1)     |

1부터 k까지의 합이 n 이하가 되는 가장 큰 k를 구해야 한다.

이를 이분탐색으로 구한다.

1부터 k까지의 합이 n 이하가 되는 가장 큰 k를 구한다.

```cpp
long getSum(int n) {
  return ((long)n * ((long)n + 1) / 2);
}

int arrangeCoins(int n) {
  int left = 0, right = n;

  int answer = 0;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (getSum(mid) > (long)n) {
      right = mid - 1;
    } else {
      answer = mid;
      left = mid + 1;
    }
  }

  return answer;
}
```

## 고생한 점
