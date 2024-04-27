# 1289. Minimum Falling Path Sum II

[링크](https://leetcode.com/problems/minimum-falling-path-sum-ii/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

grid의 한 행의 길이를 N이라 하자.

동적 계획법을 이용해 각 행마다 이전 행까지의 최소값을 이용해 현재 행의 최소값을 갱신할 수 있다.

이 경우 O(N^3)의 시간 복잡도가 소요된다.

직전 행에서 가장 작은 2가지 값들 중 하나를 선택하게 된다.

이를 각 행마다 반복하므로 O(N^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

공간복잡도에 최적화된 동적 계획법에 O(N)의 공간 복잡도를 사용한다.

직전 행에서 가장 작은 두가지 값을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     253      |   O(N^3)    |    O(N)     |

각 x좌표까지 진행했을 때의 최소값을 저장하며 갱신한다.

이를 이용해 현재 행의 최소값을 갱신할 때 다음과 같은 방식을 사용한다.

- 현재 x와 이전 x'가 같은 경우 해당 값을 선택할 수 없다. (열이 연속되면 안됨)
- x'를 순회하며 최소값을 찾고 이를 이용해 현재 x의 최소값을 갱신한다.

이를 동적 계획법으로 풀이하면 아래와 같다.

```cpp
int minFallingPathSum(vector<vector<int>>& grid) {
  int size = grid.size();

  vector<int> dp(size, INT_MAX);

  for (int x = 0; x < size; x++) {
    dp[x] = grid[0][x];
  }
  for (int y = 1; y < size; y++) {
    vector<int> newDp(size, INT_MAX);
    for (int x = 0; x < size; x++) {
      for (int before = 0; before < size; before++) {
        if (x == before) continue;

        newDp[x] = min(newDp[x], dp[before] + grid[y][x]);
      }
    }

    dp = newDp;
  }

  int answer = INT_MAX;
  for (int x = 0; x < size; x++) {
    answer = min(answer, dp[x]);
  }
  return answer;
}
```

### 2개의 최소값

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |   O(N^2)    |    O(1)     |

탐색을 진행하며 각 행마다 특정 x에서 끝나는 최소값, 두번째로 작은 최소값을 찾는다.

이후 현재 x에서의 최소값을 갱신할 때 위의 두 값을 사용할 수 있다.

- 만약 이전 최소값이 x로 끝나는 경우 두번째로 작은 최소값을 사용한다.
- 그 외의 경우 최소값을 사용한다.

```cpp
vector<int> findTwoMinimum(vector<int>& row) {
  int first = INT_MAX, second = INT_MAX;
  for (int& num : row) {
    if (num < first) {
      // second = exchange(first, x);
      second = first;
      first = num;
    } else if (num < second)
      second = num;
  }
  return {first, second};
}

int minFallingPathSum(vector<vector<int>>& grid) {
  int size = grid.size();

  for (int y = 1; y < size; y++) {
    vector<int> minimums = findTwoMinimum(grid[y - 1]);

    for (int x = 0; x < size; x++) {
      if (grid[y - 1][x] == minimums[0]) {
        grid[y][x] += minimums[1];
      } else {
        grid[y][x] += minimums[0];
      }
    }
  }

  int answer = INT_MAX;
  for (int& num : grid[size - 1]) {
    answer = min(answer, num);
  }
  return answer;
}
```

### 2개의 최소값 (최적화)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      25      |   O(N^2)    |    O(1)     |

위 풀이에서 입력받은 배열을 사용하지 않는 경우는 아래와 같다.

```cpp
struct Minimum {
  int first, second;
  int firstI, secondI;
};

int minFallingPathSum(vector<vector<int>>& grid) {
  int size = grid.size();

  Minimum before = {INT_MAX, INT_MAX, -1, -1};
  for (int x = 0; x < size; x++) {
    if (grid[0][x] < before.first) {
      before.second = before.first;
      before.secondI = before.firstI;

      before.first = grid[0][x];
      before.firstI = x;
    } else if (grid[0][x] < before.second) {
      before.second = grid[0][x];
      before.secondI = x;
    }
  }

  for (int y = 1; y < size; y++) {
    Minimum cur = {INT_MAX, INT_MAX, -1, -1};

    for (int x = 0; x < size; x++) {
      int newCost =
          (x == before.firstI ? before.second : before.first) + grid[y][x];

      if (newCost < cur.first) {
        cur.second = cur.first;
        cur.secondI = cur.firstI;

        cur.first = newCost;
        cur.firstI = x;
      } else if (newCost < cur.second) {
        cur.second = newCost;
        cur.secondI = x;
      }
    }

    before = cur;
  }

  return before.first;
}
```

## 고생한 점
