# C - Not Covered Points

[링크](https://atcoder.jp/contests/abc462/tasks/abc462_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

점의 갯수를 N이라 하자.

각 점마다 특정 축에 대해 정렬 후 순차적으로 방문하며 다른 축의 값들을 저장한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회하며 이전에 방문한 점들의 다른 축의 값과 현재 값을 비교해 포함하는 경우를 판단한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     176      | O(N \* log_2(N)) |    O(N)     |

각 좌표마다 0,0부터 (y,x)까지 포함하는 직사각형에 다른 점들이 포함되어있는지 확인해야 한다.

이를 위해 x좌표에 대해 정렬 후 탐색한다.

방문때마다 이전에 방문한 점들의 y좌표들 목록에서 현재 y좌표보다 작은 경우

현재 x보다 작으며 y보다 작은 점이 존재한다.

따라서 이 경우 정답의 경우에 포함하지 않는다.

그 외의 경우 정답에 추가한다.

작은 값들을 빠르게 찾기 위해 BST set을 사용하며 lower bound를 사용한다.

```cpp
ll solution(int size, vector<int>& x, vector<int>& y) {
  int answer = 0;

  vector<pair<int, int>> points;
  for (int i = 0; i < size; i++) {
    points.push_back({x[i], y[i]});
  }
  sort(points.begin(), points.end());

  set<int> s;
  s.insert(INT_MIN);
  s.insert(INT_MAX);
  for (int i = 0; i < size; i++) {
    int y = points[i].second;

    // find there are lower than y
    auto it = prev(s.lower_bound(y));

    if (*it == INT_MIN) answer++;

    s.insert(y);
  }

  return answer;
}
```

## 고생한 점
