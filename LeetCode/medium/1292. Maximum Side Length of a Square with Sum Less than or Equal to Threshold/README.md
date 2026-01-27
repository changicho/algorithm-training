# 1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold

[링크](https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

2차원 배열의 행의 갯수를 R, 열의 갯수를 C라고 하자.

각 구간에 대한 합을 빠르게 구하기 위해 prefix sum을 사용한다.

이 경우 O(R \* C)의 시간 복잡도를 사용한다.

이후 가능한 정사각형의 길이에 대해 탐색을 진행한다.

이를 모든 좌표에 대해 모두 확인할 경우 O(R \* C \* min(R, C))의 시간 복잡도를 사용한다.

혹은 이전 최대 길이부터 탐색을 진행할 경우 O(R \* C + min(R, C))의 시간 복잡도를 사용한다. 

이는 O(R \* C)의 시간 복잡도이다.

### 공간 복잡도

prefix sum에 O(R \* C)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(R \* C)  |  O(R \* C)  |

특정 구간 직사각형의 합을 빠르게 구하기 위해 prefix sum을 사용한다.

각 좌표마다 가능한 정사각형의 변의 길이에 대해 확인을 진행한다.

이 때 이전에 구한 최대 길이 + 1부터 탐색을 진행한다.

현재 시작점을 (y, x), 변의 길이를 length라고 할 때, 구간 합은 다음과 같이 구할 수 있다.

- 특정 구간의 합을 sum(Y, X) 이라 할때 이는 0,0부터 (Y, X)까지의 합을 나타낸다.
- (y, x) ~ (y + length - 1, x + length - 1) 구간의 합은
- sum(y + length - 1, x + length - 1) - sum(y + length - 1, x - 1) - sum(y - 1, x + length - 1) + sum(y - 1, x - 1) 이다.

위 방법을 이용해 가능한 최대 변의 길이를 갱신한다.

```cpp
int maxSideLength(vector<vector<int>>& mat, int threshold) {
  int rows = mat.size(), cols = mat[0].size();

  vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      dp[y + 1][x + 1] = dp[y + 1][x] + dp[y][x + 1] - dp[y][x] + mat[y][x];
    }
  }

  int answer = 0;
  int limit = min(rows, cols);
  for (int y = 0; y < rows; y++) {
    for (int x = 0; x < cols; x++) {
      for (int length = answer + 1; length <= limit; length++) {
        if (y + length > rows || x + length > cols) break;
        int sum = dp[y + length][x + length] - dp[y + length][x] -
                  dp[y][x + length] + dp[y][x];

        if (sum <= threshold) {
          answer = max(answer, length);
        } else {
          break;
        }
      }
    }
  }
  return answer;
}
```

## 고생한 점
