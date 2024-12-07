# 3363. Find the Maximum Number of Fruits Collected

[링크](https://leetcode.com/problems/find-the-maximum-number-of-fruits-collected/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 정방 배열의 크기를 N^2라 하자.

3 지점에서 이동하는 경우 중, 대각선으로 이동하는 경우는 고정되어있다. 또한 목적지에 도달하기 위해 최대 이동 범위는 정해져있다.

동적 계획법을 사용해 이동하는 경우의 수를 구할 수 있으므로 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

동적 계획법에 사용할 2차원 배열을 선언해야 하므로 공간 복잡도는 O(N^2)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |   O(N^2)    |   O(N^2)    |

3 지점에서 출발했을 때, 대각선으로 이동해야 하는 경로는 고정되어 있다.

또한 나머지 출발점에서도 도착점으로 도달하기 위해선 대각선 이동경로를 초과해서 이동할 수 없다.

따라서 동적 계획법을 이용해 각 지점에서 출발했을 때의 최대값을 구할 수 있다.

이 때 대각선 이동경로는 불변이므로 미리 fruits를 제거해놓는다.

```cpp
int maxCollectedFruits(vector<vector<int>>& fruits) {
  int size = fruits.size();

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer += fruits[i][i];
    fruits[i][i] = 0;
  }

  vector<vector<int>> dpU2D(size, vector<int>(size, -1));
  dpU2D[0][size - 1] = fruits[0][size - 1];
  fruits[0][size - 1] = 0;

  for (int y = 0; y < size - 1; y++) {
    for (int x = 0; x < size; x++) {
      if (dpU2D[y][x] == -1) continue;

      for (int d = -1; d <= 1; d++) {
        if (x + d < 0 || x + d >= size) continue;
        dpU2D[y + 1][x + d] =
            max(dpU2D[y + 1][x + d], dpU2D[y][x] + fruits[y + 1][x + d]);
      }
    }
  }

  vector<vector<int>> dpL2R(size, vector<int>(size, -1));
  dpL2R[size - 1][0] = fruits[size - 1][0];
  fruits[size - 1][0] = 0;

  for (int x = 0; x < size - 1; x++) {
    for (int y = 0; y < size; y++) {
      if (dpL2R[y][x] == -1) continue;

      for (int d = -1; d <= 1; d++) {
        if (y + d < 0 || y + d >= size) continue;
        dpL2R[y + d][x + 1] =
            max(dpL2R[y + d][x + 1], dpL2R[y][x] + fruits[y + d][x + 1]);
      }
    }
  }

  return answer + dpU2D[size - 1][size - 1] + dpL2R[size - 1][size - 1];
}
```

## 고생한 점
