# 836. Rectangle Overlap

[링크](https://leetcode.com/problems/rectangle-overlap/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 좌표를 비교하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

좌표 비교에 O(1)의 공간 복잡도를 사용한다.

### 좌표 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

한 축에서 겹치는 판단을 x, y축 둘다 수행하고 둘다 겹치는지 판단한다.

```cpp
bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
  bool xFlag = rec2[0] < rec1[2] && rec1[0] < rec2[2];
  bool yFlag = rec2[1] < rec1[3] && rec1[1] < rec2[3];

  return xFlag && yFlag;
}
```

## 고생한 점
