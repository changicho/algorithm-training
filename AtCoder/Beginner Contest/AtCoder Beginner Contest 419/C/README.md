# C - King's Summit

[링크](https://atcoder.jp/contests/abc419/tasks/abc419_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

사람의 수를 N이라 하자.

모든 사람을 중점으로 이동 시킬 수 있다.

이 경우 각 좌표별 최대값과 최소값을 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

중점을 구하는 데 O(1)의 공간 복잡도를 사용한다.

### 중점으로 이동

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)    |    O(1)    |

y, x좌표에 대해서 가장 큰 값과 작은 값을 구한다.

이후 두 값의 평균을 구한 뒤, 해당 좌표로 다른 모든 사람들을 이동 시킨다.

이 때 소숫점으로 나누어지는 경우 올림처리해 최대 이동 거리를 구한다.

```cpp
struct Axis {
  int y, x;
};

auto solution(int size, vector<Axis> &people) {
  int yMin = INT_MAX, yMax = INT_MIN;
  int xMin = INT_MAX, xMax = INT_MIN;

  for (Axis &p : people) {
    yMin = min(yMin, p.y);
    yMax = max(yMax, p.y);

    xMin = min(xMin, p.x);
    xMax = max(xMax, p.x);
  }

  int yDiff = ceil(((double)yMax - yMin) / 2);
  int xDiff = ceil(((double)xMax - xMin) / 2);
  int answer = max(yDiff, xDiff);

  return answer;
}
```

## 고생한 점
