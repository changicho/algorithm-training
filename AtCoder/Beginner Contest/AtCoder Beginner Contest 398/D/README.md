# D - Bonfire

[링크](https://atcoder.jp/contests/abc398/tasks/abc398_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

바람이 부는 방향 문자열 S의 크기를 N이라 하자.

특정 시점에 특정 좌표에 연기가 존재하는지 prefix sum을 이용해 판단할 수 있다.

이 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 방문 좌표를 저장하는데 O(N)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |    O(N)     |    O(N)     |

각 시간마다 0,0 좌표에서 연기가 발생하며 바람이 부는 방향에 따라 모든 연기가 이동한다.

이 때 연기가 생성될 때 이전 시점의 이동 방향은 해당 연기에 영향을 끼치지 않는다.

현재까지 최초시점의 연기가 이동한 경로를 저장할 수 있다.

따라서 현재 특정 좌표에 연기가 존재하는지 판단할 때, 현재 최초 시점의 연기와 특정 좌표를 뺏을 때 이전에 해당 좌표에 연기가 존재 했었는지로 판단할 수 있다.

```text
이동 경로
WWNNWSWEW...

T=5 일 때 연기의 이동 경로 (괄호로 감싸져있는 경로)
WWNN[WSWEW]...

현재 시점에서 해당 이동경로를 뺏을 때 이전에 해당 좌표에 연기가 존재했는지 판단 (괄호로 감싸져 있는 경로)
[WWNN]WSWEW...
```

```cpp
// -200,000 ~ 200,000
struct Axis {
  int y, x;

  Axis operator+(const Axis &a) const { return {y + a.y, x + a.x}; }
  Axis operator-(const Axis &a) const { return {y - a.y, x - a.x}; }

  long long convert() { return (long long)y * 1000000 + x; }

  bool operator==(const Axis &a) const { return y == a.y && x == a.x; }
};

unordered_map<char, Axis> dirMap = {
    {'N', {-1, 0}},
    {'W', {0, -1}},
    {'S', {1, 0}},
    {'E', {0, 1}},
};

string solution(int size, int row, int col, string &s) {
  string answer = "";

  Axis target = {row, col};

  unordered_set<long long> visited;

  visited.insert(0);
  Axis cur = {0, 0};

  for (int i = 0; i < size; i++) {
    Axis dir = dirMap[s[i]];

    cur = cur + dir;

    Axis before = cur - target;

    if (visited.find(before.convert()) != visited.end()) {
      answer += '1';
    } else {
      answer += '0';
    }

    visited.insert(cur.convert());
  }

  return answer;
}
```

## 고생한 점
