# 4061. Minimum Queen Moves to Reach Target

[링크](https://leetcode.com/problems/minimum-queen-moves-to-reach-target/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 좌표를 비교한다.

두 좌표에 대해 각 축에 대한 차이를 구한 뒤 이를 이용해 최소 이동 횟수를 구한다.

이 때 대각선 이동 또한 고려할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표 비교에 O(1)의 공간 복잡도를 사용한다.

### 좌표 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

각 축에 대한 좌표의 차이를 각각 yDiff, xDiff라 하자.

퀸은 최소 2번의 이동으로 다른 모든 좌표로 이동이 가능하다.

이 때 같은 대각선에 위치했는지, 같은 축에 위치했는지에 따라 최소 이동 횟수가 다르다.

xDiff와 yDiff가 같은 경우 같은 대각선에 위치했다고 판단 가능하며 둘 중 하나가 0인 경우는 같은 축에 위치한 경우이다.

이를 이용해 정답을 구한다.

```cpp
int minQueenMoves(vector<int>& source, vector<int>& target) {
  int hitCount = 0;

  int yDiff = abs(source[0] - target[0]);
  int xDiff = abs(source[1] - target[1]);
  if (yDiff == 0) hitCount++;
  if (xDiff == 0) hitCount++;
  if (yDiff == xDiff) hitCount++;

  if (hitCount >= 2) return 0;
  if (hitCount >= 1) return 1;
  return 2;
}
```

## 고생한 점
