# D - Suddenly, A Tempest

[링크](https://atcoder.jp/contests/abc432/tasks/abc432_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

입력받은 폭풍의 횟수를 N이라 하자.

각 좌표들을 구간집합으로 관리할 수 있다. 이 경우 폭풍마다 최대 2개씩 분리되므로 최대 구간의 갯수는 (2^N)개가 된다.

각 좌표 구간끼리 서로 이어져있는 경우 연결해야 한다. 이를 위해 union-find를 사용할 수 있다.

이 탐색에 O((2^N)^2 \* a(2^N))의 시간 복잡도를 사용하며 이는 O(2^(N + N))이 된다. (a는 아커만 함수)

이후 이를 정리하는데 O(2^N \* log(2^N))의 시간 복잡도를 사용한다.

총 시간 복잡도는 O(2^(N + N))이 된다.

### 공간 복잡도

유니온 파인드에 최대 O(2^N)의 공간 복잡도를 사용한다.

### 좌표 구간 & 유니온 파인드

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      1       | O(2^(N + N)) |   O(2^N)    |

각 좌표를 다음과 같은 구간으로 관리한다.

```cpp
struct Area {
  // x1,y1 : 구간의 왼쪽 아래 좌표
  // x2,y2 : 구간의 오른쪽 위 좌표
  long long x1, y1, x2, y2;

  // 구간의 크기
  long long size() { return (x2 - x1 + 1) * (y2 - y1 + 1); }
};
```

이후 각 폭풍마다 기존 구간을 다음과 같이 나눈다.

이 때 구간이 나뉘는 경우와 나뉘지 않는 경우가 존재한다.

이후 만들어진 여러개의 구간에 대해서 서로 이어져 있는지 판단하며 이어진 경우 유니온 파인드를 이용해 합친다.

서로 연결되어있는지 판단은 다음과 같이 진행한다.

- x축으로 이어져 있는지 판단.
  - 두 구간의 x축이 서로 맞닿아 있는지 판단. `(a.x2 + 1 == b.x1 || b.x2 + 1 == a.x1)`
  - 두 구간의 y축이 겹치는지 판단. `(a.y2 >= b.y1 && b.y2 >= a.y1)`
- y축으로 이어져 있는지 판단.
  - 두 구간의 y축이 서로 맞닿아 있는지 판단. `(a.y2 + 1 == b.y1 || b.y2 + 1 == a.y1)`
  - 두 구간의 x축이 겹치는지 판단. `(a.x2 >= b.x1 && b.x2 >= a.x1)`

이렇게 유니온 파인드를 모두 수행한 이후 각 루트 노드에 해당하는 구간의 크기를 구하며 정렬하여 반환한다.

```cpp
struct Storm {
  char type;
  long long A;
  long long B;
};

struct Area {
  long long x1, y1, x2, y2;

  long long size() { return (x2 - x1 + 1) * (y2 - y1 + 1); }
};

auto solution(int n, long long x, long long y, vector<Storm>& storms) {
  vector<Area> areas;
  areas.push_back({0, 0, x - 1, y - 1});

  for (Storm& storm : storms) {
    vector<Area> next_areas;

    if (storm.type == 'X') {
      // x < A : down B
      // x >= A : up B
      for (auto& area : areas) {
        if (area.x2 < storm.A) {
          // down B
          Area newArea = {area.x1, area.y1 - storm.B, area.x2,
                          area.y2 - storm.B};
          next_areas.push_back(newArea);
        } else if (area.x1 >= storm.A) {
          // up B
          Area newArea = {area.x1, area.y1 + storm.B, area.x2,
                          area.y2 + storm.B};
          next_areas.push_back(newArea);
        } else {
          // split
          Area downArea = {area.x1, area.y1 - storm.B, storm.A - 1,
                           area.y2 - storm.B};
          Area upArea = {storm.A, area.y1 + storm.B, area.x2,
                         area.y2 + storm.B};
          next_areas.push_back(downArea);
          next_areas.push_back(upArea);
        }
      }
    } else {
      // y < A : left B
      // y >= A : right B

      for (auto& area : areas) {
        if (area.y2 < storm.A) {
          // left B
          Area newArea = {area.x1 - storm.B, area.y1, area.x2 - storm.B,
                          area.y2};
          next_areas.push_back(newArea);
        } else if (area.y1 >= storm.A) {
          // right B
          Area newArea = {area.x1 + storm.B, area.y1, area.x2 + storm.B,
                          area.y2};
          next_areas.push_back(newArea);
        } else {
          // split
          Area leftArea = {area.x1 - storm.B, area.y1, area.x2 - storm.B,
                           storm.A - 1};
          Area rightArea = {area.x1 + storm.B, storm.A, area.x2 + storm.B,
                            area.y2};
          next_areas.push_back(leftArea);
          next_areas.push_back(rightArea);
        }
      }
    }

    areas = next_areas;
  }

  int areaSize = areas.size();

  vector<int> parents(areaSize, 0);
  for (int i = 0; i < areaSize; i++) {
    parents[i] = i;
  }
  vector<long long> childrens(areaSize, 0);
  for (int i = 0; i < areaSize; i++) {
    childrens[i] = areas[i].size();
  }

  function<int(int)> find = [&](int node) {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int)> merge = [&](int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (a > b) swap(a, b);
    parents[b] = a;
    childrens[a] += childrens[b];
    childrens[b] = 0;
  };

  function<bool(Area, Area)> isConnected = [](Area a, Area b) {
    // check x connected
    if (a.x2 + 1 == b.x1 || b.x2 + 1 == a.x1) {
      if (a.y2 >= b.y1 && b.y2 >= a.y1) {
        return true;
      }
    }

    // check y connected
    if (a.y2 + 1 == b.y1 || b.y2 + 1 == a.y1) {
      if (a.x2 >= b.x1 && b.x2 >= a.x1) {
        return true;
      }
    }

    return false;
  };

  for (int i = 0; i < areaSize; i++) {
    for (int j = i + 1; j < areaSize; j++) {
      if (isConnected(areas[i], areas[j])) {
        merge(i, j);
      }
    }
  }

  vector<long long> answer;

  for (int i = 0; i < areaSize; ++i) {
    if (parents[i] == i && childrens[i] > 0) {
      answer.push_back(childrens[i]);
    }
  }
  sort(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
