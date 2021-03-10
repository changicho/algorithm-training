# 1708. 볼록 껍질

[링크](https://www.acmicpc.net/problem/1708)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   24.906    |       2       |

## 설계

### 시간 복잡도

점의 개수 N은 최대 100,000개이다.

### 공간 복잡도

정답은 N이하이므로 최악의 경우 100,000이다. 이는 int형으로 충분하다.

### 볼록 껍질 (Convex Hull)

점들이 막 주어져 있을때 모든 점을 포함하는 볼록한 다각형을 의미한다.

컨벡스 헐에서 연속한 세 점을 한 쪽 방향으로 잡고 CCW 방향으로 탐색하면 동일한 컨벡스 헐을 생성할 수 있다.

1. 컨벡스 헐에 무조건 들어가는 점 하나를 잡는다. (보통 가장 x좌표가, y좌표가 작은 점)
2. 그 점을 기준으로 기울기 순으로 정렬한다. 같은 기울기면 거리 순으로 정렬.
3. 점들을 그룹에 순서대로 넣는다.
4. 넣으면서 그룹의 제일 최근 3점의 ccw방향이 아니면 그 세 점중 중간 점을 뺀다.
5. 3~4를 반복하면서 1번점까지 돌아온다.

이때 1번과 2번의 경우 정렬을 수행해야한다.

1번에서 수행하는 정렬의 경우 컨벡스 헐의 점을 좌표에 따라 정렬한다.

2번에서 기울기를 구할 때는 벡터의 내적을 이용해 구한다.

따라서 점을 다음과 같은 구조체로 표현할 수 있다.

```cpp
struct Point {
  int x, y;
  int xDiff, yDiff;

  bool operator<(const Point &B) const {
    // 벡터의 내적을 이용해 사이각을 구함
    if (1LL * (yDiff * B.xDiff) != 1LL * (xDiff * B.yDiff)) {
      return 1LL * (yDiff * B.xDiff) < 1LL * (xDiff * B.yDiff);
    }
    if (y != B.y) {
      return y < B.y;
    }
    return x < B.x;
  }
};
```

1번과 2번을 수행하기 위해 1번에서 정렬된 각 점들을 기준점을 기준으로 다시 정렬해준다.

```cpp
sort(points.begin(), points.end());
// 첫번째 점(기준점)에 맞춰 기준과의 거리를 계산
for (int i = 1; i < N; i++) {
  points[i].xDiff = points[i].x - points.front().x;
  points[i].yDiff = points[i].y - points.front().y;
}
sort(points.begin(), points.end());
```

이후 컨벡스 헐을 구성하는 점들이 담긴 stack을 생성하고 탐색을 이어나간다.

```cpp
stack<int> s;

s.push(0);
s.push(1);

int next = 2;

while (next < N) {
  while (s.size() >= 2) {
    int first, second;
    second = s.top();
    s.pop();
    first = s.top();

    if (isCCW(points[first], points[second], points[next])) {
      s.push(second);
      break;
    }
  }

  s.push(next);
  next += 1;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      40      |       0        |

## 고생한 점
