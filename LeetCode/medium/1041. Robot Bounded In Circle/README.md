# 1041. Robot Bounded In Circle

[링크](https://leetcode.com/problems/robot-bounded-in-circle/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

명령의 길이를 N이라 하자.

같은 경로를 순회하기 위해선 현재 시작위치, 방향이 이전 명령의 시작의 위치, 방향과 동일해야 한다.

4개의 방향만 존재하므로 결국 최대 4번 반복했을 때 하나의 사이클이 생성되어야 한다.

따라서 4번만 반복하면 되므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

이전에 시작한 좌표와 방향을 저장해야 하며 이를 위해 hash set을 사용한다.

여기에 저장되는 데이터는 총 5개 이므로 공간 복잡도는 O(1)이다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

방향은 4가지 방향밖에 없으므로 최소 4번의 연산을 수행했을 때 사이클이 존재하는 경우와 사이클이 존재하지 않는 경우를 판별할 수 있다.

시작 위치와 방향을 같이 고려해야 하므로 각 사이클마다 맨 마지막 상태가 이전의 시작 상태에 나타난 적이 있는지를 판별한다.

key값으로 위치, 방향을 같이 나타내야 하므로 set혹은 unordered_set을 사용한다.

```cpp
pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

// key를 string으로 사용하고 hash set을 사용할 경우 현재 상태를 string으로 변환해 사용
string convert(pair<pair<int, int>, int> status) {
  string ret = "";
  ret += to_string(status.first.first) + "/";
  ret += to_string(status.first.second) + "/";
  ret += to_string(status.second);
  return ret;
}

bool isRobotBounded(string instructions) {
  set<pair<pair<int, int>, int>> hashSet;

  pair<int, int> axis = {0, 0};
  int dir = 0;
  hashSet.insert({axis, dir});

  for (int i = 0; i < 4; i++) {
    pair<pair<int, int>, int> last;

    for (char c : instructions) {
      switch (c) {
        case 'G': {
          axis.first += dirs[dir].first;
          axis.second += dirs[dir].second;
          break;
        }
        case 'L': {
          dir = (dir - 1 + 4) % 4;
          break;
        }
        case 'R': {
          dir = (dir + 1 + 4) % 4;
          break;
        }
      }

      last = {axis, dir};
    }

    if (hashSet.count(last) > 0) return true;
    hashSet.insert(last);
  }

  return false;
}
```

### 시작점 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

시작 위치의 좌표는 {0, 0}이고 북쪽 방향을 바라본다.

만약 사이클이 존재한다면 이동을 수행한 후에 이 시작위치와 동일한 상태를 가지게 되므로 이를 비교한다.

```cpp
bool isRobotBounded(string instructions) {
  pair<int, int> dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  pair<int, int> axis = {0, 0};
  int dir = 0;

  for (int i = 0; i < 4; i++) {
    for (char c : instructions) {
      switch (c) {
        case 'G': {
          axis.first += dirs[dir].first;
          axis.second += dirs[dir].second;
          break;
        }
        case 'L': {
          dir = (dir - 1 + 4) % 4;
          break;
        }
        case 'R': {
          dir = (dir + 1 + 4) % 4;
          break;
        }
      }
    }

    if (axis.first == 0 && axis.second == 0 && dir == 0) return true;
  }

  return false;
}
```

## 고생한 점
