# B - You're a teapot

[링크](https://atcoder.jp/contests/abc418/tasks/abc418_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

완전 탐색을 수행할 경우 O(N^3)의 시간 복잡도를 사용한다.

중복 순회를 줄일 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^2)    |    O(1)     |

가능한 모든 문자열 쌍에 대해서 정답의 조건을 확인한다.

```cpp
double solution(string &s) {
  int size = s.size();

  double answer = 0.0;
  for (int left = 0; left < size; left++) {
    if (s[left] != 't') continue;

    double count = 0;
    for (int right = left; right < size; right++) {
      int length = right - left + 1;

      count += s[right] == 't';

      if (s[right] != 't') continue;
      if (length < 3) continue;
      double cur = (count - 2) / (length - 2);

      answer = max(answer, cur);
    }
  }
  return answer;
}
```

### 완전 탐색 (중복 순회)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |   O(N^3)    |    O(1)     |

```cpp
double getCost(string &s, int left, int right) {
  int size = right - left + 1;
  if (size < 3) return 0.0;
  if (s[left] != 't' || s[right] != 't') return 0.0;

  char target = 't';
  double count = 0;

  for (int i = left; i <= right; i++) {
    count += s[i] == target;
  }
  return (count - 2) / (size - 2);
}

double solution(string &s) {
  int size = s.size();

  double answer = 0.0;
  for (int left = 0; left < size; left++) {
    for (int right = left; right < size; right++) {
      double cur = getCost(s, left, right);

      answer = max(answer, cur);
    }
  }
  return answer;
}
```

## 고생한 점
