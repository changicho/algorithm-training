# 1496. Path Crossing

[링크](https://leetcode.com/problems/path-crossing/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

path의 길이를 N이라 하자.

path를 순회하며 이동시키도 각 좌표를 hash set에 저장 후 중복 여부를 판별할 수 있다.

이 경우 순회에 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

각 좌표를 순회하며 hash set에 저장한다.

이 때 최악의 경우 이동하는 길이는 최대 10^4 이므로 y,x좌표를 모두 int형에 저장할 수 있다.

```cpp
struct Axis {
  int y, x;

  int convert() { return y * 100000 + x; }
};
Axis dirs[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

Axis convert(char &c) {
  switch (c) {
    case 'N': {
      return dirs[0];
    }
    case 'S': {
      return dirs[2];
    }
    case 'E': {
      return dirs[3];
    }
    case 'W': {
      return dirs[1];
    }
  }
  return {0, 0};
}

bool isPathCrossing(string path) {
  unordered_set<int> visited;

  Axis cur = {0, 0};
  visited.insert(cur.convert());

  for (char &c : path) {
    Axis dir = convert(c);

    cur.y += dir.y, cur.x += dir.x;
    if (visited.count(cur.convert())) return true;
    visited.insert(cur.convert());
  }
  return false;
}
```

## 고생한 점
