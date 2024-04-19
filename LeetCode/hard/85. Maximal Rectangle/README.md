# 85. Maximal Rectangle

[링크](https://leetcode.com/problems/maximal-rectangle/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

2차원 배열 matrix의 행의 갯수를 R, 열의 갯수를 C라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(R^3 \* C^3)이므로 제한시간 내에 불가능하다.

연속된 1의 갯수에 대한 동적 계획법을 이용해 시작좌표, 끝좌표에 대해 빠르게 구할 수 있다.

이 경우 O(R^2 \* C^2)의 시간 복잡도를 사용한다.

행에 대한 탐색을 진행하는 동적 계획법을 사용할 경우 O(R^2 \* C)의 시간 복잡도를 사용한다.

모노토닉 스택을 이용할 경우 O(R \* C)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

2차원 동적 계획법을 사용할 경우 O(R \* C)의 공간 복잡도가 필요하다.

행에 대한 동적 계획법에 O(C)의 공간 복잡도를 사용한다.

### 동적 계획법 (x 순회)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      42      | O(R^2 \* C) |  O(R \* C)  |

각 좌표마다 현재 좌표에서 왼쪽으로 연이은 1의 갯수를 저장하는 dp배열을 생성한다.

이후 각 좌표마다 현재 좌표에서 위로 올라가며 최대 넓이를 구한다.

```cpp
int maximalRectangle(vector<vector<char>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();

  int answer = 0;
  int dp[201][201] = {
      0,
  };

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      if (matrix[y][x] == '0') continue;

      dp[y][x] = x == 0 ? 1 : dp[y][x - 1] + 1;

      int width = dp[y][x];

      for (int by = y; by >= 0; by--) {
        width = min(width, dp[by][x]);
        answer = max(answer, width * (y - by + 1));
      }
    }
  }
  return answer;
}
```

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      19      |  O(R \* C)  |    O(C)     |

각 행을 순회하며 이전행부터 현재행까지의 연속된 1의 높이를 저장한다.

각 과정에서 높이들을 모노토닉 스택을 이용해 저장하며, 모노토닉 스택에는 높이가 낮아지는 순서대로 저장한다.

(top에 있을수록 낮아짐)

이 과정에서 모노토닉 스택의 저장된 높이의 x좌표를 이용해 넓이를 구하고 갱신한다.

```cpp
int maximalRectangle(vector<vector<char>>& matrix) {
  int rows = matrix.size(), cols = matrix[0].size();

  vector<int> heights(cols);
  int answer = 0;

  for (int y = 0; y < rows; y++) {
    stack<int> stk;

    for (int x = 0; x < cols; x++) {
      heights[x] = (matrix[y][x] == '0') ? 0 : heights[x] + 1;

      while (!stk.empty() && (heights[x] < heights[stk.top()])) {
        int left = stk.top();
        stk.pop();

        int before = (stk.empty() ? -1 : stk.top());
        int width = x - before - 1;

        answer = max(answer, heights[left] * width);
      }

      stk.push(x);
    }

    // last case
    while (!stk.empty()) {
      int left = stk.top();
      stk.pop();

      int before = (stk.empty() ? -1 : stk.top());
      int width = cols - before - 1;

      answer = max(answer, heights[left] * width);
    }
  }

  return answer;
}
```

## 고생한 점
