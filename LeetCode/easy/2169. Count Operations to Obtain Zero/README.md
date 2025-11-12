# 2169. Count Operations to Obtain Zero

[링크](https://leetcode.com/problems/count-operations-to-obtain-zero/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수를 N, M이라 하자.

시뮬레이션을 사용할 경우 최대 O(max(N, M))의 시간 복잡도를 사용한다.

유클리디안 알고리즘(수학)을 사용할 경우 O(log_2(max(N, M)))의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(max(N, M)) |    O(1)     |

조건에 맞춰 연산을 수행한다.

```cpp
int countOperations(int num1, int num2) {
  int answer = 0;
  while (num1 > 0 && num2 > 0) {
    answer++;

    if (num1 >= num2) {
      num1 -= num2;
    } else {
      num2 -= num1;
    }
  }
  return answer;
}
```

## 고생한 점
