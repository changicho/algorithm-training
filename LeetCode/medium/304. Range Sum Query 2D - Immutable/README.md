# 304. Range Sum Query 2D - Immutable

[링크](https://leetcode.com/problems/range-sum-query-2d-immutable/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

행의 개수를 N, 열의 개수를 M이라 하자.

매번 range에 대해서 값을 구할 경우 한번 range의 sum을 구하는 데 O(N \* M)의 시간 복잡도가 사용된다.

이 range sum을 최소 10^4번 이상 구해야하며 이를 브루트 포스 방법으로 풀이할 경우 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 부분합을 미리 구하고 range sum을 빠른 시간 내에 검색한다.

부분합을 모두 구할 경우 시간 복잡도는 O(N \* M)이 사용된다.

range sum의 경우는 O(1)의 시간 복잡도롤 구할 수 있다.

### 공간 복잡도

부분합 배열을 저장해야 하며 이는 O(N \* M)크기의 공간 복잡도를 사용한다.

### 동적 계획법 (부분합)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     715      |  O(N \* M)  |  O(N \* M)  |

2차원 배열에서 특정 부분의 합을 부분합을 이용해 구한다.

dp배열을 다음과 같이 설정한다.

```cpp
dp[y][x]; // 0,0에서 y,x까지 모든 원소의 합
```

이를 이용해 특정 구간의 좌표가 주어졌을 때 부분합을 다음과 같이 구할 수 잇다.

```cpp
int sumRegion(int row1, int col1, int row2, int col2) {
  int all = dp[row2][col2];
  int fromUp = row1 > 0 ? dp[row1 - 1][col2] : 0;
  int fromLeft = col1 > 0 ? dp[row2][col1 - 1] : 0;
  int duplicated = row1 > 0 && col1 > 0 ? dp[row1 - 1][col1 - 1] : 0;

  return all - fromUp - fromLeft + duplicated;
}
```

이는 부분합중에서 y,x까지의 값을 구하고 빼야할 부분합을 빼서 구할 수 있기 때문이다.

dp의 점화식과 초기값은 다음과 같다.

```cpp
for (int y = 0; y < rows; y++) {
  for (int x = 0; x < cols; x++) {
    int fromUp = y > 0 ? dp[y - 1][x] : 0;
    int fromLeft = x > 0 ? dp[y][x - 1] : 0;
    int duplicated = y > 0 && x > 0 ? dp[y - 1][x - 1] : 0;

    dp[y][x] = fromUp + fromLeft - duplicated + matrix[y][x];
  }
}
```

이를 구현하면 다음과 같다.

```cpp
class NumMatrix {
 private:
  int dp[201][201] = {
      0,
  };

 public:
  NumMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix.front().size();

    for (int y = 0; y < rows; y++) {
      for (int x = 0; x < cols; x++) {
        int fromUp = y > 0 ? dp[y - 1][x] : 0;
        int fromLeft = x > 0 ? dp[y][x - 1] : 0;
        int duplicated = y > 0 && x > 0 ? dp[y - 1][x - 1] : 0;

        dp[y][x] = fromUp + fromLeft - duplicated + matrix[y][x];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int all = dp[row2][col2];
    int fromUp = row1 > 0 ? dp[row1 - 1][col2] : 0;
    int fromLeft = col1 > 0 ? dp[row2][col1 - 1] : 0;
    int duplicated = row1 > 0 && col1 > 0 ? dp[row1 - 1][col1 - 1] : 0;

    return all - fromUp - fromLeft + duplicated;
  }
};
```

## 고생한 점
