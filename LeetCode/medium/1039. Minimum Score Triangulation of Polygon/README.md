# 1039. Minimum Score Triangulation of Polygon

[링크](https://leetcode.com/problems/minimum-score-triangulation-of-polygon/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 values의 크기를 N이라 하자.

동적 계획법을 사용할 경우 O(N^3)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법에 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(N^3)    |   O(N^2)    |

다각형을 3각형들로 분할하며 이 때 3각형 각 변의 곱들의 합이 최소가 되는 문제이다.

각 경우마다 현재 3각형을 구성하는 점을 기준으로 왼쪽과 오른쪽의 다각형들을 분할하며 최소값을 갱신한다.

이를 위해 다음과 같은 동적 계획법을 사용한다.

```cpp
// definition
int dp[left][right]; // left ~ right 까지의 index로 다각형을 분할했을 때 최소값

// init
dp[i][i + 1] = 0; // 다각형을 만들지 못하는 경우

// update
dp[left][right] = min(dp[left][through] + dp[through][right] + values[left] * values[through] * values[right])
```

이를 이용해 각 경우마다 최소값을 갱신한다.

이 때 left ~ right가 작은 순서대로 갱신해야 한다.

```cpp
int minScoreTriangulation(vector<int>& values) {
  int size = values.size();

  int dp[51][51] = {
      0,
  };

  for (int diff = 2; diff < size; diff++) {
    for (int left = 0; left < size - diff; left++) {
      int right = left + diff;

      dp[left][right] = INT_MAX;
      for (int through = left + 1; through < right; through++) {
        int cur = dp[left][through] + dp[through][right] +
                  values[left] * values[through] * values[right];

        dp[left][right] = min(dp[left][right], cur);
      }
    }
  }
  return dp[0][size - 1];
}
```

## 고생한 점
