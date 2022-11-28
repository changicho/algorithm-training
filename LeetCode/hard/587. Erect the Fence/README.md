# 587. Erect the Fence

[링크](https://leetcode.com/problems/erect-the-fence/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 trees의 크기를 N이라 하자.

모든 점을 감싸는 convex hull을 생성하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 점들을 저장하고 정렬할 배열이 필요하다.

이에 O(N)의 공간 복잡도를 사용한다.

### 볼록 껍질 (convex hull)

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     104      | O(N \* log_2(N)) |    O(N)     |

그라함 스캔 알고리즘에서 모든 점에 대해 기준점과의 기울기를 구하지 않고 컨벡스 헐을 구할 수 있다.

각 좌표를 정렬 후 (y, x가 작은순으로) 시작점을 잡는다.

이후 스택을 이용해 연속된 3개의 점을 스택에 넣으면서 스택의 제일 최근 3점의 ccw방향이 아니면 그 세 점중 중간 점을 뺀다.

이를 한번 반복 후, 끝점부터 역방향으로 같은 방법으로 수행한다.

두 과정중에서 생긴 컨벡스 헐의 합집합이 현재 좌표들의 최종 컨벡스 헐이 된다.

```cpp
struct Point {
  int y, x;

  bool operator<(const Point &B) const {
    if (y != B.y) {
      return y < B.y;
    }
    return x < B.x;
  }
};

long long getInnerProduct(Point &a, Point &b, Point &c) {
  return (1LL * a.x * b.y + 1LL * b.x * c.y + 1LL * c.x * a.y) -
          (1LL * b.x * a.y + 1LL * c.x * b.y + 1LL * a.x * c.y);
}

bool isCCW(Point &a, Point &b, Point &c) {
  return getInnerProduct(a, b, c) >= 0;
}

vector<Point> getConvexHull(vector<Point> &points) {
  int size = points.size();

  vector<Point> stk;

  for (int next = 0; next < size; next++) {
    while (stk.size() >= 2) {
      Point second = stk.back();
      stk.pop_back();
      Point first = stk.back();

      if (isCCW(first, second, points[next])) {
        stk.push_back(second);
        break;
      }
    }

    stk.push_back(points[next]);
  }

  return stk;
}

public:
vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
  int size = trees.size();

  if (size <= 3) {
    return trees;
  }

  vector<Point> points;
  for (vector<int> &tree : trees) {
    int y = tree[1], x = tree[0];

    points.push_back({y, x});
  }

  sort(points.begin(), points.end());

  vector<Point> ccwPoints = getConvexHull(points);
  reverse(points.begin(), points.end());
  vector<Point> cwPoints = getConvexHull(points);

  vector<vector<int>> answer;
  for (Point &point : cwPoints) {
    answer.push_back({point.x, point.y});
  }
  for (Point &point : ccwPoints) {
    answer.push_back({point.x, point.y});
  }
  sort(answer.begin(), answer.end());
  answer.erase(unique(answer.begin(), answer.end()), answer.end());
  return answer;
}
```

## 고생한 점
