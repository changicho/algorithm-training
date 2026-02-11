# B - Digit Sum

[링크](https://atcoder.jp/contests/abc444/tasks/abc444_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N, 각 숫자의 자릿수를 M이라 하자.

각 숫자별로 자리수별로 순회하는데 총 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 연산에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(N \* M)  |    O(1)     |

각 숫자를 순회하며 숫자의 자릿수 합이 k인 경우를 카운트한다.

```cpp
bool check(int num, int k) {
  int sum = 0;
  while (num) {
    sum += num % 10;
    num /= 10;
  }

  return sum == k;
}

int solution(int n, int k) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    if (check(i, k)) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
