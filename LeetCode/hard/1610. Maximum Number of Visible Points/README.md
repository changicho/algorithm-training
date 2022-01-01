# 1610. Maximum Number of Visible Points

[링크](https://leetcode.com/problems/maximum-number-of-visible-points/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

점의 개수를 N개라 하자.

각 점마다 순회하며 기준점과 점의 x, y축의 차이를 이용해 각도를 구할 수 있다. (acos, asin, atan을 이용)

현재 범위를 탐색하기 위한 angle의 범위는 각도들을 시작점으로 설정해 탐색하며 구할 수 있다.

(정답의 범위가 여러개 일 때, 무조건 가장 작은 각도에서 시작하는 범위를 포함한다)

이 각도들을 원점에서부터 모든 angle에 대해서 포함 가능한지 비교할 경우 O(N^2)의 시간 복잡도를 사용한다.

이를 최적화 하기 위해 각도들을 정렬 후 슬라이딩 윈도우를 이용할 수 있다.

이 경우 정렬에 O(N \* log_2(N)), 슬라이딩 윈도우를 사용하는 데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 점들을 각도로 변경하는 데 O(N)의 공간 복잡도를 사용한다.

이후 슬라이딩 윈도우를 이용할 때 queue, deque를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     552      | O(N \* log_2(N)) |    O(N)     |

각 점들을 각도로 변경하기 위해 atan을 이용한다.

이 때 해당 점이 원점과 같은 경우는 어느각도에서도 볼 수 있으므로 각도를 구하지 않고 미리 정답에 더한다.

이후 각도들을 정렬한 뒤 탐색할 범위의 시작점들로 설정한다.

이후 각 시작점들을 오름차순으로 탐색하며 슬라이딩 윈도우를 이용한다.

슬라이딩 윈도우의 갱신은 다음과 같다.

현재 각도를 from, 범위의 끝 각도를 to라고 하자.

- 슬라이딩 윈도우에서 to보다 작은 탐색할 각도들을 push한다.
- 슬라이딩 윈도우에서 from보다 작은 각도들을 pop한다.
- 이 때 각도가 360도를 초과하는 경우를 고려하기 위해 360을 더한 후 탐색할 각도에 포함한다.

이를 구현하면 다음과 같다.

```cpp
int visiblePoints(vector<vector<int>> &points, int angle,
                  vector<int> &location) {
  vector<double> angles;
  int sames = 0;

  // get angle from all points
  for (vector<int> &point : points) {
    int py = point[1], px = point[0];
    int ly = location[1], lx = location[0];

    int width = px - lx;
    int height = py - ly;

    // find same point
    if (width == 0 && height == 0) {
      sames += 1;
      continue;
    }

    // compress width and height
    if (width == 0 || height == 0) {
      if (width > 0) width = 1;
      if (height > 0) height = 1;
    } else {
      int div = gcd(width, height);
      width /= div;
      height /= div;
    }

    double a = atan2(height, width) * 180 / PI;

    if (a < 0) a += 360;
    angles.push_back(a);
  }

  // sort angles by accending
  sort(angles.begin(), angles.end());

  queue<double> q;
  deque<double> visible;
  set<double> froms;

  for (double &a : angles) {
    q.push(a);
    froms.insert(a);
  }

  int answer = sames;
  // iterate all angles
  for (auto &from : froms) {
    double to = from + angle;

    // use sliding window to find visible points of from ~ to angle
    while (!q.empty() && from <= q.front() && q.front() <= to) {
      double a = q.front();
      visible.push_back(a);
      q.pop();
      // push angle for (from ~ to) range over 360
      // if angle is 10, it is same 370 (360 + 10) degree
      q.push(a + 360);
    }

    while (!visible.empty() && visible.front() < from) {
      visible.pop_front();
    }
    answer = max(answer, sames + (int)visible.size());
  }

  return answer;
}
```

## 고생한 점
