# 2069. Walking Robot Simulation II

[링크](https://leetcode.com/problems/walking-robot-simulation-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라 하자.

각 명령마다 직접 이동할 경우 모듈러 연산을 사용해 불필요한 이동을 줄일 수 있다.

이를 직접 시뮬레이션을 수행할 경우 O(R + C)의 시간 복잡도가 소요된다.

혹은 각 명령마다 이동 위치만 관리 후 위치를 계산할 경우 O(1)의 시간 복잡도로 명령을 처리할 수 있다.

### 공간 복잡도

각 좌표를 관리하는데 O(1)의 공간 복잡도가 소요된다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      |    O(1)     |    O(1)     |

시작 위치에서 명령에 따라 이동할 때 테두리 부분만 이동하게 된다.

따라서 현재 시작 위치에서 얼마나 이동했는지만 알면 테두리의 어느부분에 존재하는지 바로 알 수 있다.

이 때 테두리를 한바퀴 도는 경우 ((R + C - 2) * 2만큼 이동하는 경우) 한바퀴를 돌게 되므로 모듈러 연산을 사용해 이동할 수 있다.

이 때 최초에는 0,0에서 동쪽을 바라보지만 이후 0,0에서는 남쪽을 바라봄에 유의한다.

```cpp
class Robot {
 private:
  int width, height, length;
  int pos = 0;
  bool hasMoved = false;

 public:
  Robot(int width, int height) {
    this->width = width;
    this->height = height;
    length = 2 * (width - 1 + height - 1);
  }

  void step(int num) {
    hasMoved = true;
    pos = (pos + num) % length;
  }

  vector<int> getPos() {
    int h = height - 1, w = width - 1;

    if (pos < width) return {pos, 0};
    if (pos <= w + h) return {w, pos - w};
    if (pos <= 2 * w + h) return {w - (pos - (w + h)), h};
    return {0, h - (pos - (2 * w + h))};
  }

  string getDir() {
    int h = height - 1, w = width - 1;

    if (!hasMoved) return "East";
    if (pos == 0) return "South";
    if (pos <= w) return "East";
    if (pos <= w + h) return "North";
    if (pos <= 2 * w + h) return "West";
    return "South";
  }
};
```

## 고생한 점
