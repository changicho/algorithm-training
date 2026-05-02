# 2833. Furthest Point From Origin

[링크](https://leetcode.com/problems/furthest-point-from-origin/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 이동과 빈칸의 수를 센 뒤 그리디하게 최대 차이를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

갯수를 세는데 O(1)의 공간 복잡도를 사용한다.

### 카운팅 & 그리디

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

고정된 L, R 이동을 센 뒤 해당 이동으로 0에서 떨어진 위치를 찾는다.

이후 남은 빈칸들을 0에서 멀어지는 방향으로만 이동시키는 경우가 가장 0에서 멀리 떨어진 경우이다.

```cpp
int furthestDistanceFromOrigin(string moves) {
  int size = moves.size();

  int dir = -1;
  int answer = 0;

  int leftCount = 0, rightCount = 0;
  int blankCount = 0;
  for (char& c : moves) {
    if (c == 'L') {
      leftCount++;
    } else if (c == 'R') {
      rightCount++;
    } else {
      blankCount++;
    }
  }

  int diff = abs(leftCount - rightCount);

  return diff + blankCount;
}
```

## 고생한 점
