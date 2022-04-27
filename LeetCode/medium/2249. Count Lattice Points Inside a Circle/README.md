# 2249. Count Lattice Points Inside a Circle

[링크](https://leetcode.com/contest/weekly-contest-290/problems/count-lattice-points-inside-a-circle/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

circles의 갯수를 N, 평균 반지름을 R 이라고 하자.

각 원을 한번 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

이후 가능한 범위의 점들을 순회해야 하며 이는 y, x축이 각 지름마다 가능하다. 따라서 각 원마다 O(R^2)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* R^2)를 사용한다.

### 공간 복잡도

각 원마다 점을 순회해야 하므로 점들의 좌표의 범위는 각각 200 \* 200까지 가능하다.

따라서 O(1)의 공간 복잡도를 사용한다.

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     370      | O(N \* R^2) |    O(1)     |

각 원들을 순회하며 원의 중점에서 범위 내의 점들을 순회한다.

이는 각 원의 (중점 - R) ~ (중점 + R) 까지 순회한다. 각 점들과 중점사이의 거리가 R 이하인지 판단하고 hash set에 저장한다.

이를 이용해 중복을 방지한다.

이를 구현하면 다음과 같다.

```cpp
int convert(int &y, int &x) { return y * 1000 + x; }

double getDistance(int &y1, int &x1, int &y2, int &x2) {
  int yDiff = y2 - y1, xDiff = x2 - x1;
  return sqrt(yDiff * yDiff + xDiff * xDiff);
}

int countLatticePoints(vector<vector<int>> &circles) {
  unordered_set<int> points;

  for (vector<int> &c : circles) {
    int y = c[1], x = c[0], r = c[2];

    for (int y2 = y - r; y2 <= y + r; y2++) {
      for (int x2 = x - r; x2 <= x + r; x2++) {
        double length = getDistance(y, x, y2, x2);

        if (r >= length) points.insert(convert(y2, x2));
      }
    }
  }

  return points.size();
}
```

## 고생한 점
