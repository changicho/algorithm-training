# 223. Rectangle Area

[링크](https://leetcode.com/problems/rectangle-area/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 좌표는 총 4개이다. (a1, a2, b1, b2)

각 좌표의 넓이를 계산 후, 겹치는 부분의 넓이를 빼 계산할 수 있다.

이 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

넓이를 계산하는 데 별도의 추가 공간을 사용하지 않는다.

### 넓이 계산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      26      |    O(1)     |    O(1)     |

사각형을 각각 A, B라 하자.

두 사각형의 넓이의 합을 구하고, 겹치는 부분의 넓이를 제거한다.

하나의 좌표에 대해 두 구간이 겹치는 지는 다음과 같이 판단 가능하다.

- aLeft ~ aRight , bLeft ~ bRight의 구간
- (bLeft < aRight) && (aLeft < bRight) 인 경우

두 사각형이 맞물려있는 경우는 겹친 구간이 없으므로 (같은 변에서 만난 경우) 같은 경우는 포함하지 않는다.

만약 두 좌표 구간이 겹친 경우 겹친 구간은 다음과 같이 구할 수 있다.

- 겹치는 구간의 left : max(aLeft, bLeft)
- 겹치는 구간의 right : min(aRight, bRight)

이를 x, y좌표 모두에 대해 탐색하고 넓이를 구한다.

```cpp
bool isOverlapped(int a1, int a2, int b1, int b2) {
  return a2 > b1 && b2 > a1;
}

int getArea(int x1, int y1, int x2, int y2) {
  int yDiff = y2 - y1, xDiff = x2 - x1;

  return yDiff * xDiff;
}

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2,
                int by2) {
  int ret = 0;
  ret += getArea(ax1, ay1, ax2, ay2);
  ret += getArea(bx1, by1, bx2, by2);

  if (isOverlapped(ax1, ax2, bx1, bx2) && isOverlapped(ay1, ay2, by1, by2)) {
    int x1 = max(ax1, bx1), x2 = min(ax2, bx2);
    int y1 = max(ay1, by1), y2 = min(ay2, by2);

    ret -= getArea(x1, y1, x2, y2);
  }
  return ret;
}
```

## 고생한 점
