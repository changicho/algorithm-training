# 1688. Count of Matches in Tournament

[링크](https://leetcode.com/problems/count-of-matches-in-tournament/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

시뮬레이션을 수행할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

수학적 방법을 이용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

재귀함수를 사용하지 않을 경우 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       | O(log_2(N)) |    O(1)     |

주어진 조건대로 시뮬레이션을 수행한다.

```cpp
int numberOfMatches(int n) {
  int answer = 0;
  while (n > 1) {
    answer += n / 2;
    n -= n / 2;
  }
  return answer;
}
```

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

결과적으로 각 과정마다 현재 남은 수의 절반씩 더하게 된다.

이를 마지막 1명이 남을 때 까지 반복하므로 결국 N-1이 정답이 된다.

```cpp
int numberOfMatches(int n) { return n - 1; }
```

## 고생한 점
