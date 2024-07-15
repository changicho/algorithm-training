# 2751. Robot Collisions

[링크](https://leetcode.com/problems/robot-collisions/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

로봇들의 갯수를 N이라 하자.

각 로봇들을 position 별로 정렬해 위치별로 순회할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회하며 스택을 이용해 충돌을 시뮬레이션 한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 로봇을 정렬하는데 O(N)의 공간 복잡도를 사용한다.

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 스택

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     213      | O(N \* log_2(N)) |    O(N)     |

각 로봇들을 position 별로 정렬한다.

이후 한 방향으로 순회하며, 진행 방향과 같은 로봇들은 스택에 삽입하며, 반대 방향의 경우 스택의 로봇들과 충돌을 수행한다.

만약 현재 로봇이 순회와 역방향에 스택에 남은 로봇이 없는 경우 해당 로봇은 살아남는다.

순회 이후 스택에 남은 로봇들 또한 살아남는다.

이후 살아남은 로봇들을 입력받은 index 순으로 정렬하며 정답을 만든다.

```cpp
struct Robot {
  int health;
  int position;
  char dir;
  int index;
};

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
  int size = positions.size();

  vector<Robot> robots;
  for (int i = 0; i < size; i++) {
    robots.push_back({healths[i], positions[i], directions[i], i});
  }

  sort(robots.begin(), robots.end(), [](Robot &a, Robot &b) { return a.position < b.position; });

  vector<Robot> remains;
  stack<Robot> lefts;
  for (int i = size - 1; i >= 0; i--) {
    if (robots[i].dir == 'L') {
      lefts.push(robots[i]);
    } else if (robots[i].dir == 'R') {
      bool isDestroyed = false;

      while (!lefts.empty()) {
        if (lefts.top().health > robots[i].health) {
          lefts.top().health--;
          isDestroyed = true;
          break;
        } else if (lefts.top().health == robots[i].health) {
          lefts.pop();
          isDestroyed = true;
          break;
        } else {
          robots[i].health--;
          lefts.pop();
        }
      }

      if (!isDestroyed) {
        remains.push_back(robots[i]);
      }
    }
  }

  while (!lefts.empty()) {
    remains.push_back(lefts.top());
    lefts.pop();
  }

  sort(remains.begin(), remains.end(), [](Robot &a, Robot &b) { return a.index < b.index; });

  vector<int> answer;
  for (Robot &remain : remains) {
    answer.push_back(remain.health);
  }
  return answer;
}
```

## 고생한 점
