# 874. Walking Robot Simulation

[링크](https://leetcode.com/problems/walking-robot-simulation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 commands의 크기를 N, obstacles의 크기를 M이라 하자.

obstacles를 hash map에 저장해 좌표로 바로 접근할 수 있도록 한다. 저장하는데 O(M)의 시간 복잡도를 사용한다.

commands를 순회하며 이동을 수행한다. 이 때 한번의 이동마다 최대 O(9)의 시간 복잡도가 소요된다.

따라서 총 시간 복잡도는 O(N + M)이다.

### 공간 복잡도

obstacle을 저장하는 hash map에 O(M)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      84      |  O(N + M)   |    O(M)     |

시뮬레이션을 수행할 때 로봇의 다음위치에 장애물이 있는지 빠르게 판단하기 위해 hash map과 hash set을 이용한다.

이후 시뮬레이션을 직접 수행한다.

이 때 y좌표의 북쪽이 양수임에 유의한다.

```cpp
struct Axis {
  int y, x;
};

Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int calc(Axis &a) { return a.y * a.y + a.x * a.x; }

int robotSim(vector<int> &commands, vector<vector<int>> &obstacles) {
  Axis cur = {0, 0};
  int dir = 0;

  int answer = 0;

  unordered_map<int, unordered_set<int>> um;
  for (vector<int> &o : obstacles) {
    int x = o[0], y = -o[1];

    um[y].insert(x);
  }

  for (int &c : commands) {
    if (c < 0) {
      // turn
      if (c == -1) {
        dir = (dir + 1) % 4;
      } else {
        dir = (dir - 1 + 4) % 4;
      }
    } else {
      Axis move = dirs[dir];
      for (int i = 0; i < c; i++) {
        Axis next = {cur.y + move.y, cur.x + move.x};

        if (um[next.y].count(next.x)) {
          break;
        }
        cur = next;
      }

      answer = max(answer, calc(cur));
    }
  }

  return answer;
}
```

## 고생한 점
