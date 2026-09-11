# 4034. Minimum Bishop Moves to Reach Target

[링크](https://leetcode.com/problems/minimum-bishop-moves-to-reach-target/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

보드의 크기는 8^2 이다.

BFS로 모든 경우를 탐색할 수 있다. 이 경우 각 좌표마다 다음 방향으로 총 16칸 탐색한다. (대각선, 역대각선)

이에 O(8^2 \* 16)의 시간 복잡도를 사용하며 이는 O(1)이다.

수학을 이용해 이동 횟수를 구할 수 있다. 이 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

BFS에 O(8^2)의 시간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

두 좌표가 서로 다른 색의 칸에 속한 경우 비숍은 이동 불가능하다.

이는 칸이 무슨 색인지 좌표값을 이용해 판단할 수 있다.

하나의 좌표에서 다른 좌표로 이동하는데 같은 대각선에 있으면 1번, 그 외의 경우는 최대 2번의 이동을 한다.

이를 이용해 정답을 구한다.

```cpp
struct Axis {
  int y, x;
};

int minBishopMoves(vector<int>& source, vector<int>& target) {
  Axis s = {source[0] - 1, source[1] - 1};
  Axis t = {target[0] - 1, target[1] - 1};

  if ((s.y + s.x) % 2 != (t.y + t.x) % 2) return -1;
  if (abs(s.y - t.y) == abs(s.x - t.x)) return 1;

  return 2;
}
```

## 고생한 점
