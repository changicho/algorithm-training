# 1401. Circle and Rectangle Overlapping

[링크](https://leetcode.com/problems/circle-and-rectangle-overlapping/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

좌표를 이용해 원의 중심과 사각형의 변과의 최소 거리를 구할 수 있다.

이에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표를 이용해 계산하는데 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

원의 중심부터 사각형의 각 변의 최소 거리를 구한다.

각 축마다 거리를 구한 뒤 피타고라스의 정리를 이용해 실제 거리를 구한다.

이 때 사각형 내부와 원이 겹칠 수 있으므로 이 경우는 각 축의 거리는 0으로 취급한다.

```cpp
bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
  long long xDiff = 0;
  if (xCenter < x1 || xCenter > x2) {
    xDiff = min(abs(x1 - xCenter), abs(x2 - xCenter));
  }
  long long yDiff = 0;
  if (yCenter < y1 || yCenter > y2) {
    yDiff = min(abs(y1 - yCenter), abs(y2 - yCenter));
  }
  return pow(xDiff, 2) + pow(yDiff, 2) <= radius * radius;
}
```

## 고생한 점
