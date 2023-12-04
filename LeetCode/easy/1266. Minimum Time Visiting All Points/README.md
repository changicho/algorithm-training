# 1266. Minimum Time Visiting All Points

[링크](https://leetcode.com/problems/minimum-time-visiting-all-points/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

점의 갯수를 N이라 하자.

직전 점에서 현재 점으로 이동할 때 거리를 각 좌표의 차이를 이용해 구할 수 있다. 이는 O(1)의 시간 복잡도를 사용한다.

이를 모든 점에 반복하므로 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

좌표의 차이를 이용해 거리를 구할 때 별도의 공간이 필요하지 않다.

따라서 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(1)     |

현재 점에서 다음 점으로 이동할 때 거리는 다음과 같다.

- x좌표의 차이
- y좌표의 차이
- 두 차이값 중 큰 값

이는 y,x축에 대해서 각각 한칸씩 이동하거나 둘 모두를 한칸씩 이동할 수 있기 때문이다.

이를 이용해 각 좌표를 순회하며 이동 거리를 구해 더한다.

```cpp
int getDist(vector<int> &a, vector<int> &b) {
  int xDiff = abs(a[0] - b[0]);
  int yDiff = abs(a[1] - b[1]);
  return max(xDiff, yDiff);
}

int minTimeToVisitAllPoints(vector<vector<int>> &points) {
  int answer = 0;
  vector<int> cur = points[0];

  for (vector<int> &p : points) {
    answer += getDist(p, cur);
    cur = p;
  }
  return answer;
}
```

## 고생한 점
