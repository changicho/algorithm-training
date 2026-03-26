# D - Make Target 2

[링크](https://atcoder.jp/contests/abc449/tasks/abc449_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

입력받은 범위 숫자를 L, R, D, U라 하고 각 범위를 R, C라 하자.

각 축마다 연속된 black 구간의 수를 셀 수 있다.

이 경우 O(R + C)의 시간 복잡도를 사용한다.

### 공간 복잡도

숫자를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 축 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(R + C)   |    O(1)     |

문제 조건에 따라 black과 white를 표현할 경우 아래와 같은 방사형 모양이 된다.

```plain_text
0 0 0 0 0 0 0
0 1 1 1 1 1 0
0 1 0 0 0 1 0
0 1 0 1 0 1 0
0 1 0 0 0 1 0
0 1 1 1 1 1 0
0 0 0 0 0 0 0
```

여기서 각 축에 대해서 순회하며, 현재 축에 연속된 black 구간의 수를 셀 수 있다.

이 때 교차점의 경우 중복 카운트가 될 수 있으므로 하나의 축에서 카운트 할 때 수를 줄인다.

```cpp
long long solution(int left, int right, int down, int up) {
  long long answer = 0;

  for (int x = left; x <= right; x++) {
    // black case
    if (x % 2 == 0) {
      int curDown = max(down, -abs(x) + 1);
      int curUp = min(up, abs(x) - 1);
      int count = curUp - curDown + 1;

      answer += max(count, 0);
    }
  }

  for (int y = down; y <= up; y++) {
    // black case
    if (y % 2 == 0) {
      int curLeft = max(left, -abs(y));
      int curRight = min(right, abs(y));
      int count = curRight - curLeft + 1;

      answer += max(count, 0);
    }
  }

  return answer;
}
```

## 고생한 점
