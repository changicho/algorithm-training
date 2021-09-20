# 931. Minimum Falling Path Sum

[링크](https://leetcode.com/problems/minimum-falling-path-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 행의 개수를 N, 열의 개수를 M이라 하자.

모든 경우를 탐색할 경우 각 좌표마다 3개의 값 중 하나를 선택할 수 있다.

이 때의 시간 복잡도는 O((N \* M)^3)이 된다.

이는 제한시간 내에 불가능하므로 동적 계획법을 이용한다.

이 경우 한번의 순회로 해결이 가능하므로 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

dp배열에서 직전의 열만 사용 가능하므로 O(M)크기의 dp배열만 존재하면 된다.

따라서 공간 복잡도는 O(M)이다.

### 동적 계획법 (one row)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N \* M)  |    O(M)     |

dp식을 다음과 같이 설정한다.

```cpp
dp[y][x]; // matrix[y][x] 값을 골랐을 때 만들 수 있는 최소값
```

점화식은 다음과 같다.

```cpp
minimum = min(dp[y-1][x-1], dp[y-1][x], dp[y-1][x+1]);
dp[y][x] = minimum + matrix[y][x];
```

초기값은 다음과 같다.

```cpp
dp[0][x] = matrix[0][x];
```

점화식에서 직전 값만을 사용하므로 모든 rows에 대한 dp를 저장할 필요없이 직전 값의 dp만을 이용할 수 있다.

따라서 dp배열을 M의 크기만큼만 생성하고 이를 이용한다.

```cpp
int minFallingPathSum(vector<vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix.front().size();
  int limit = 100001;

  vector<int> dp(cols, 0);

  for (int x = 0; x < cols; x++) {
    dp[x] = matrix.front()[x];
  }

  for (int y = 1; y < rows; y++) {
    vector<int> temp(cols, limit);

    for (int x = 0; x < cols; x++) {
      int left = max(0, x - 1);
      int right = min(cols - 1, x + 1);

      int minimum = dp[left];
      for (int i = left; i <= right; i++) {
        minimum = min(dp[i], minimum);
      }

      temp[x] = minimum + matrix[y][x];
    }

    dp = temp;
  }

  int answer = limit;
  for (int val : dp) {
    answer = min(val, answer);
  }
  return answer;
}
```

## 고생한 점
