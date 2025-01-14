# 3417. Zigzag Grid Traversal With Skip

[링크](https://leetcode.com/problems/zigzag-grid-traversal-with-skip/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

2차원 배열 grid의 크기를 R \* C라 하자.

시뮬레이션을 수행할 경우 O(R \* C)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답에 포함되는 값들의 개수는 R \* C 이므로 이만큼의 공간 복잡도가 필요하다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(R \* C)  |  O(R \* C)  |

한 행에서 2칸씩 이동하며 각 행마다 오른쪽, 왼쪽 이동을 수행한다.

이 때 직전 행에서 끝에서 끝난 경우 다음 행에서는 끝에서 시작하지 않는다.

```cpp
vector<int> zigzagTraversal(vector<vector<int>>& grid) {
  vector<int> answer;

  int rows = grid.size();
  int cols = grid[0].size();

  bool startZero = true;
  for (int y = 0; y < rows; y++) {
    bool isRight = y % 2 == 0;

    if (isRight) {
      int x = 0 + !startZero;

      for (; x < cols; x += 2) {
        answer.push_back(grid[y][x]);
      }

      startZero = x == cols;
    } else {
      int x = cols - 1 - !startZero;

      for (; x >= 0; x -= 2) {
        answer.push_back(grid[y][x]);
      }

      startZero = x == -1;
    }
  }

  return answer;
}
```

## 고생한 점
