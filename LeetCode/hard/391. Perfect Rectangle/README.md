# 391. Perfect Rectangle

[링크](https://leetcode.com/problems/perfect-rectangle/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

rectangles의 크기를 N이라 하자.

모든 rectangle들이 겹치지 않고 하나의 직사각형을 이루는 것을 확인하기 위해 직접 좌표에 색칠해 판단할 수 있다. 이 경우 시간 복잡도는 O(N \* Y \* X)이며 이는 제한시간 내에 불가능하다.

각 rectangle들이 모여 하나의 직사각형을 만들 때 각 꼭지 점들은 다른 꼭지점과 좌표가 겹치게 된다. 이후 남는 겹치지 않은 점은 4개만 남게 된다. (하나의 직사각형의 꼭지점) 이를 이용해 구현할 경우 순회에 O(N)의 시간 복잡도를, map을 이용할 경우 O(log_2(N)) 혹은 hash map을 이용할 경우 O(1)의 시간 복잡도로 각 좌표마다 접근이 가능하다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 점들이 꼭지점이 될 수 있으므로 O(N)의 공간 복잡도를 사용한다.

### 꼭지점 겹치기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     131      |    O(N)     |    O(N)     |

모든 직사각형들이 모여 하나의 직사각형을 이룬다고 하자.

각 꼭지점들은 다른 꼭지점들중 일부와 겹치게 된다. (격자 좌표에서 직사각형을 연이어 큰 직사각형을 만드는 경우를 생각해보자)

여기서 최종적으로 겹치지 않은 직사각형의 꼭지점 4개만이 남게된다.

만약 겹치지 않은 경우 꼭지점이 4개 이상 남게 된다.

이를 이용해 각 꼭지점들을 count하고 남아있는 갯수를 센다.

여기서 각 꼭지점에서 겹칠 수 있는 꼭지점끼리 묶어서 생각한다.

(bottomLeft, upRight) 쌍은 다른 (upLeft, bottomRight) 쌍 꼭지점과 겹치게 된다.

즉 한 점에서 다른 꼭지점들이 겹쳤을 때 두 쌍의 갯수는 같다. (큰 직사각형을 이룰 경우)

따라서 아래와 같이 count하고 각 좌표를 비교한다.

- (bottomLeft, upRight) : 증가시킴
- (upLeft, bottomRight) : 감소시킴

만약 perfect rectangle을 이룰 경우 꼭지점을 제외한 나머지 좌표의 점의 count 값은 0이 될 것이다.

만약 특정 점의 count값의 절대값이 2 이상인 경우는 겹친 경우이다.

이를 이용해 구현한다.

```cpp
bool isRectangleCover(vector<vector<int>>& rectangles) {
  unordered_map<int, unordered_map<int, int>> corners;

  for (vector<int>& r : rectangles) {
    int x1 = r[0], y1 = r[1], x2 = r[2], y2 = r[3];
    corners[x1][y1]++;  // bottomLeft
    corners[x1][y2]--;  // upLeft
    corners[x2][y1]--;  // bottomRight
    corners[x2][y2]++;  // upRight
  }

  int cornerCount = 0;
  for (auto& it : corners) {
    for (auto& it2 : it.second) {
      if (it2.second == 0) continue;
      if (abs(it2.second) != 1) return false;

      cornerCount++;
    }
  }
  return cornerCount == 4;
}
```

## 고생한 점
