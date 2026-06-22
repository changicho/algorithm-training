# B - Train Reservation

[링크](https://atcoder.jp/contests/abc463/tasks/abc463_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

각 행을 순회하며 각 컬럼에 빈 좌석이 있는지 탐색한다.

```cpp
bool solution(int size, char x, vector<string>& s) {
  bool answer = false;

  for (int i = 0; i < size; i++) {
    int target = x - 'A';

    if (s[i][target] == 'o') return true;
  }

  return false;
}
```

## 고생한 점
