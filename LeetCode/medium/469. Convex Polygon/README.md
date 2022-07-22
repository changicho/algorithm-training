# 469. Convex Polygon

[링크](https://leetcode.com/problems/convex-polygon/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

points의 크기를 N이라 하자.

연이은 3개의 점이 이루는 벡터의 외적을 모든 점에 대해 대해 구하며 이를 이용해 정답을 구한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

연이은 3개의 점이 이루는 외적을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |    O(N)     |    O(1)     |

3개의 연이은 점 P(i), P(i+1), P(i+2)가 존재한다고 하자.

연이은 3개의 점에 대해 두 벡터의 외적 (P(i+1) - P(i)) x (P(i+2) - P(i))값은 도형이 다각형일경우 모든 점에 대해 부호가 변경되지 않는다.

이를 이용해 외적을 모두 구하고 부호가 변경되는지 판단한다.

```cpp
long getDet(vector<int> &a, vector<int> &b, vector<int> &c) {
  return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
}

bool isConvex(vector<vector<int>> &points) {
  int size = points.size();

  bool isPositive = 0, isNegative = 0;
  for (int i = 0; i < size; i++) {
    int i1 = i;
    int i2 = (i + 1) % size;
    int i3 = (i + 2) % size;

    long det = getDet(points[i1], points[i2], points[i3]);
    isPositive |= (det > 0);
    isNegative |= (det < 0);
    if (isPositive && isNegative) return false;
  }

  return true;
}
```

```cpp
long getDet(vector<int> &a, vector<int> &b, vector<int> &c) {
  return (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0]);
}

bool isConvex(vector<vector<int>> &points) {
  int size = points.size();

  bool isPositive = 0, isNegative = 0;
  for (int i = 0; i < size; i++) {
    int i1 = i;
    int i2 = (i + 1) % size;
    int i3 = (i + 2) % size;

    long det = getDet(points[i1], points[i2], points[i3]);
    isPositive |= (det > 0);
    isNegative |= (det < 0);
    if (isPositive && isNegative) return false;
  }

  return true;
}
```

## 고생한 점
