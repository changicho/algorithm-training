# 2550. Count Collisions of Monkeys on a Polygon

[링크](https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. (N <= 10^9)

원숭이들이 움직이는 경우의 수는 2^N개 이며, 이를 모두 충돌이 발생하는지 판단할 경우 O(2^N \* N)의 시간 복잡도를 사용한다.

전체 경우의 수에서 원숭이들이 움직이며 충돌이 발생하지 않는 경우의 수를 구할 수 있다. 이 경우 2^N을 직접 구할 경우 O(N)의 시간 복잡도를 사용한다.

분할 정복으로 2^N을 구할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

분할 정복을 재귀호출로 구현할 경우 O(log_2(N))의 공간 복잡도를 사용한다.

### 분할 정복

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) | O(log_2(N)) |

원숭이들이 움직이며 한번이라도 부딛히지 않는 경우의 수는 2가지 경우이다.

- 모두 시계 방향으로 이동
- 모두 반시계 방향으로 이동

따라서 전체 경우의 수 (2^N)에서 2를 뺀 값을 반환한다.

이 때 2^N은 매우 큰 값이며, 직접 구할 수 없으므로 각 과정마다 분할 정복으로 pow를 직접 구현한다.

```cpp
long long MOD = 1e9 + 7;

long long myPow(int n) {
  if (n == 0) return 1;
  if (n == 1) return 2;

  long long ret = 1;
  if (n % 2 == 1) {
    ret *= 2;
    ret %= MOD;
  }
  int temp = myPow(n / 2);
  ret *= temp;
  ret %= MOD;
  ret *= temp;
  ret %= MOD;
  return ret;
}

int monkeyMove(int n) {
  int answer = myPow(n);

  answer -= 2;
  if (answer < 0) answer += MOD;

  return answer;
}
```

## 고생한 점
