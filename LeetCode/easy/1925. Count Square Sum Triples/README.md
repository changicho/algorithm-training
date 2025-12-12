# 1925. Count Square Sum Triples

[링크](https://leetcode.com/problems/count-square-sum-triples/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자. 모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용한다.

두개의 수를 고정하고 나머지를 구할 수 있다. 이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

사용하는 변수는 모두 상수 개수이므로 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색 (두개 고정)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |   O(N^2)    |    O(1)     |

A^2 + B^2 = C^2 를 만족하는 (A, B, C) 쌍의 개수를 구한다.

A와 B를 고정한 뒤, C가 유효한 정수인지 구한다.

```cpp
int countTriples(int n) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int target = i * i + j * j;
      int sq = sqrt(int(target));
      double sqD = sqrt(double(target));

      if (sq <= n && sq == sqD) answer++;
    }
  }

  return answer;
}
```

## 고생한 점
