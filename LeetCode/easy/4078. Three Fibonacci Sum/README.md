# 4078. Three Fibonacci Sum

[링크](https://leetcode.com/problems/three-fibonacci-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

시뮬레이션으로 정답을 구할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

세개의 연이은 피보나치 수열의 합을 매번 갱신하며 N 이상이 될 때까지 반복한다.

이후 N과 합이 같은지 반환한다.

```cpp
bool threeFibonacciSum(int n) {
  int a = 0, b = 1, c = 1;

  int sum = a + b + c;

  while (sum < n) {
    a = b;
    b = c;
    c = a + b;

    sum = a + b + c;
  }
  return sum == n;
}
```

## 고생한 점
