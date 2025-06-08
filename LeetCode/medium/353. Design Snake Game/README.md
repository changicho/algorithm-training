# 353. Design Snake Game

[링크](https://leetcode.com/problems/design-snake-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 연산의 수를 N, 음식의 크기를 K라 하자.

각 연산마다 deque를 사용해 snake의 몸들의 좌표를 저장하고 관리할 수 있다.

이에 O(1)의 시간 복잡도를 사용한다.

충돌을 계산하기 위해 순회를 사용할 경우 O(M)의 시간 복잡도를 사용한다.

hash set을 사용할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

몸, 음식의 좌표를 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 데크 & 큐

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      81      |  O(N \* M)  |    O(M)     |

음식의 순서별 좌표를 저장하기 위해 큐를 사용하고, snake의 몸을 저장하기 위해 데크를 사용한다.

각 경우마다 데크의 앞과 뒤에서 pop, push 연산을 사용하기 때문에 O(1)의 시간 복잡도를 사용한다.

이후 움직이는 방향별로 좌표를 계산하고, 음식, 몸과 충돌하는지 확인한다.

```cpp
class SnakeGame {
 private:
  struct Axis {
    int y, x;
  };

  unordered_map<char, Axis> dirs = {
      {'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};

  int width, height;

  deque<Axis> snake;
  queue<Axis> foods;

  int score = 0;

  bool isSame(Axis &a, Axis &b) { return a.y == b.y && a.x == b.x; }

  bool isCrush(Axis &a) {
    for (Axis &s : snake) {
      if (isSame(a, s)) return true;
    }
    return false;
  }

 public:
  SnakeGame(int width, int height, vector<vector<int>> &food) {
    this->width = width;
    this->height = height;

    for (vector<int> &f : food) {
      int y = f[0], x = f[1];

      foods.push({y, x});
    }

    snake.push_back({0, 0});
  }

  int move(string direction) {
    if (score == -1) return -1;

    Axis dir = dirs[direction[0]];
    Axis cur = snake.front();

    Axis next = {cur.y + dir.y, cur.x + dir.x};

    if (next.y < 0 || next.y >= height || next.x < 0 || next.x >= width) {
      return score = -1;
    }

    bool matchFood = !foods.empty() && isSame(foods.front(), next);

    if (!matchFood) {
      snake.pop_back();
    }

    if (isCrush(next)) {
      return score = -1;
    }
    snake.push_front(next);

    if (matchFood) {
      foods.pop();
      score++;
    }

    return score;
  }
};
```

## 고생한 점
