# 2373. Largest Local Values in a Matrix

[링크](https://leetcode.com/problems/largest-local-values-in-a-matrix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

한 변의 길이를 N이라 하자.

각 경우마다 3^2개의 원소를 순회해야한다. 이는 O(1)의 시간 복잡도를 사용한다.

이를 (N-2)^2번 반복하면 되므로 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N^2)의 공간 복잡도를 사용한다.

### 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      37      |   O(N^2)    |   O(N^2)    |

각 좌표를 순회하며, 각 좌표를 왼쪽 위 코너로 하는 3*3 크기의 2차원 격자를 순회해 가장 큰 값을 채운다.

이 최대값을 정답으로 채우고 나머지 좌표에 대해 반복한다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
  int size = grid.size();

  vector<vector<int>> answer(size - 2, vector<int>(size - 2));

  for (int y = 0; y < size - 2; y++) {
    for (int x = 0; x < size - 2; x++) {
      answer[y][x] = grid[y][x];

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          answer[y][x] = max(answer[y][x], grid[y + i][x + j]);
        }
      }
    }
  }
  return answer;
}
```

## 고생한 점
