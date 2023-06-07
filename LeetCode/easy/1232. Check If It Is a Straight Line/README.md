# 1232. Check If It Is a Straight Line

[링크](https://leetcode.com/problems/check-if-it-is-a-straight-line/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 coordinates의 길이를 N이라 하자.

좌표를 정렬 후 연속된 두 점의 기울기에 대해 비교할 수 있다.

이 때 점들이 이미 정렬되어있는경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

기준 기울기를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 기울기 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

입력받은 좌표들은 정렬되어있으므로 연속된 두 점들의 기울기를 비교해 모두 같은지 비교하면 된다.

이 때 두 점의 x, y에 대한 차이를 이용해 기울기를 구할 수 있다.

만약 같은 기울기여도 x, y에 대한 차이가 다른 경우가 존재할 수 있으므로 이를 고려해야 한다.

이를 위해 gcd를 이용해 두 차이를 나누거나, 기준 기울기를 구하는 x, y에 대한 차이와 현재 차이를 비교하면 된다.

만약 기울기가 0이거나 무한인 경우를 고려해야 한다.

이를 구현하면 다음과 같다.

```cpp
bool checkStraightLine(vector<vector<int>> &coordinates) {
  int size = coordinates.size();

  int xDiff = coordinates[1][0] - coordinates[0][0];
  int yDiff = coordinates[1][1] - coordinates[0][1];

  for (int i = 1; i < size; i++) {
    int curXDiff = coordinates[i][0] - coordinates[i - 1][0];
    int curYDiff = coordinates[i][1] - coordinates[i - 1][1];

    if (curXDiff * yDiff != xDiff * curYDiff) {
      return false;
    }
  }
  return true;
}
```

## 고생한 점
