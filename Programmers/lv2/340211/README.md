# [PCCP 기출문제] 3번 / 충돌위험 찾기

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/340211)

| 난이도 |
| :----: |
|  LV2   |

## 설계

### 시간 복잡도

로봇의 갯수를 N, 좌표의 갯수를 M이라 하자.

시뮬레이션을 수행해 각 로봇의 이동과 충돌을 구한다.

이에 O(N \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표별 충돌을 구현하기 위해 hash set을 사용할 수 있다. 이에 O(N)의 공간 복잡도를 사용한다.

시뮬레이션 마다 로봇을 저장해야 하므로 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|  O(N \* M)  |    O(N)     |

각 로봇들의 이동 우선순위는 다음과 같다.

- y축
- x축

따라서 이동하는 순서는 정해져 있다.

각 시간마다 로봇의 이동을 시뮬레이션하고 충돌이 발생하는 좌표들을 구한다.

이후 이를 더해 정답을 구한다.

이 때 시작위치부터 충돌이 일어날 수 있음에 유의한다.

```cpp
struct Axis {
  int y, x;

  int convert() { return y * 1000 + x; }
};

struct Robot {
  Axis cur;
  queue<Axis> goals;
};

Axis move(Axis cur, Axis goal) {
  int yDiff = goal.y - cur.y;
  int xDiff = goal.x - cur.x;

  if (abs(yDiff) > 0) {
    cur.y += (yDiff > 0 ? 1 : -1);
  } else if (abs(xDiff) > 0) {
    cur.x += (xDiff > 0 ? 1 : -1);
  }

  return cur;
}

bool isSame(Axis &a, Axis &b) { return a.y == b.y && a.x == b.x; }

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
  int size = routes.size();

  queue<Robot> robots;

  for (int i = 0; i < size; i++) {
    Robot r;

    for (int &p : routes[i]) {
      r.goals.push({points[p - 1][0], points[p - 1][1]});
    }
    r.cur = r.goals.front();

    robots.push(r);
  }

  int answer = 0;
  while (!robots.empty()) {
    int size = robots.size();

    unordered_set<int> visited;
    unordered_set<int> crashPoints;

    while (size--) {
      Robot r = robots.front();
      robots.pop();

      r.cur = move(r.cur, r.goals.front());

      if (visited.count(r.cur.convert()) > 0) {
        crashPoints.insert(r.cur.convert());
      }
      visited.insert(r.cur.convert());

      if (isSame(r.cur, r.goals.front())) {
        r.goals.pop();
      }
      if (r.goals.empty()) continue;
      robots.push(r);
    }

    answer += crashPoints.size();
  }

  return answer;
}
```

## 고생한 점
