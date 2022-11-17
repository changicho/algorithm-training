# 947. Most Stones Removed with Same Row or Column

[링크](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

stones의 갯수를 N이라 하자. (N은 최대 10^3)

각 stone의 좌표의 범위는 0 ~ 10^4까지이다. 각 stone마다 연결할 수 있는 다른 stone에 대해 직접 좌표로 탐색할 경우 O(10^4)의 시간 복잡도를 사용한다.

이를 모든 stone에 대해 반복할 경우 O(10^7)의 시간 복잡도를 사용하며 제한시간 내에 불가능할 수 있다.

각 좌표마다의 stone들을 빠르게 접근하기 위해 hash map을 이용하며 x, y좌표에 대해 각각 판단한다.

연결할 수 있는 stone들을 그룹으로 볼 수 있다. 해당 그룹들을 만들기 위해 union find 알고리즘을 사용할 수 있다.

이 경우 대략 O(1)의 시간 복잡도로 merge와 find를 수행할 수 있다.

이를 모든 stone에 대해 수행하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 좌표에 대해 모두 2차원 배열로 관리할 경우 O(10^8)의 공간 복잡도를 사용하며 이는 메모리 초과가 발생한다.

좌표를 하나의 key로 관리하기 위해 변환을 사용한다.

각 좌표에 대해 hash map으로 stone들을 저장할 수 있다.

이 경우 O(N)의 공간 복잡도를 사용한다.

각 좌표에 대해서 union find를 사용하기 위해 O(N)의 공간 복잡도를 사용한다.

### union find

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     125      |    O(N)     |    O(N)     |

stone의 y, x를 하나의 key로 관리하기 위해 convert 함수를 생성하고 사용한다.

빠르게 다른 돌들을 검색하기 위해 각 y좌표, x좌표에 대해 돌들을 묶어 저장한다.

연결된 stone들을 한줄로 나열한다고 생각하자.

연결되어있는 돌 중 하나씩 제거해 가장 많은 수를 제거한다고 했을 때, 한 줄에는 하나의 돌을 남기고 모두 제거할 수 있다.

따라서 연결된 그룹들의 갯수 만큼만 돌을 남기고 모두 제거할 수 있다.

union find를 이용해 연결할 수 있는 돌들끼리 모두 연결한다.

이후 그룹의 갯수를 세고 정답을 구한다.

```cpp
unordered_map<int, int> parents;
int parentCount = 0;

int convert(int y, int x) { return y * 100000 + x; };

int find(int node) {
  if (parents[node] == node) return node;
  return parents[node] = find(parents[node]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) return;
  if (a > b) swap(a, b);

  parentCount--;
  parents[b] = a;
}

int removeStones(vector<vector<int>> &stones) {
  int size = stones.size();
  unordered_map<int, unordered_set<int>> boardYx, boardXy;

  // initialize
  parentCount = size;
  for (vector<int> &stone : stones) {
    int y = stone[1], x = stone[0];

    boardYx[y].insert(x);
    boardXy[x].insert(y);

    int index = convert(y, x);
    parents[index] = index;
  }

  for (vector<int> &stone : stones) {
    int y = stone[1], x = stone[0];
    int cur = convert(y, x);

    for (int curX : boardYx[y]) {
      int next = convert(y, curX);
      merge(cur, next);
    }
    for (int curY : boardXy[x]) {
      int next = convert(curY, x);
      merge(cur, next);
    }
  }

  return size - parentCount;
}
```

## 고생한 점
