# Untie (9pts, 20pts)

[링크](https://codingcompetitions.withgoogle.com/codejam/round/0000000000c95b94/0000000000cad9c1)

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 C라 하자.

모든 valid한 경우에 대해 만들어보고 이를 C와 비교해 최소 diff를 구하는 경우 O(3^C)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 구한다.

이 경우 시작점과 끝점에 대해서도 비교를 진행해야 하며, 이는 모든 시작점과 끝점의 경우에 대해서 순회하며 구할 수 있다. (총 6가지 경우)

각 경우마다 동적 계획법을 이용하는 경우 O(C)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(C)의 공간 복잡도를 사용한다.

### 동적 계획법

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(C)     |    O(C)     |

시작과 끝점이 겹치면 안되므로 가능한 경우는 총 6가지 이다.

각각의 경우마다 아래와 같은 동적 계획법을 사용할 수 있다.

```cpp
// definition
int dp[i][type]; // i번째 문자까지 type으로 끝나는 경우의 최소 diff

// init
dp[0][start] = 0;

// update
for (int type = 0; type <= 2; type++) {
  for (int before = 0; before <= 2; before++) {
    if (before == type) continue;

    int curCost = dp[i - 1][before] + (nums[i] != type ? 1 : 0);

    dp[i][type] = min(dp[i][type], curCost);
  }
}
```

각 과정마다 현재 번째에서 현재 type으로 끝날 때, 이전 번째에서 연결 가능한 type에서 값을 갱신한다.

이 때 현재 번째의 문자가 현재 type과 다르면 cost를 1 증가시킨다.

이를 모든 시작, 끝점의 가능한 경우에 대해 구하며 이 경우 중 최소 diff를 구한다.

```cpp
int getMinDist(vector<int> &nums) {
  int size = nums.size();
  int dp[1001][3] = {
      0,
  };
  memset(dp, -1, sizeof(dp));

  dp[0][nums[0]] = 0;

  for (int i = 1; i < size; i++) {
    // cur type, minimum cost
    for (int type = 0; type <= 2; type++) {
      int minimum = INT_MAX;

      for (int before = 0; before <= 2; before++) {
        if (before == type) continue;
        if (dp[i - 1][before] < 0) continue;

        int curCost = dp[i - 1][before] + (nums[i] != type ? 1 : 0);

        minimum = min(minimum, curCost);
      }

      if (minimum != INT_MAX) dp[i][type] = minimum;
    }
  }

  return dp[size - 1][nums[size - 1]];
}

int solution(string &line) {
  int size = line.size();
  vector<int> nums(size);
  for (int i = 0; i < size; i++) {
    if (line[i] == 'R') {
      nums[i] = 0;
    } else if (line[i] == 'P') {
      nums[i] = 1;
    } else {
      nums[i] = 2;
    }
  }

  int answer = INT_MAX;
  for (int front = 0; front <= 2; front++) {
    for (int back = 0; back <= 2; back++) {
      if (front == back) continue;

      int beforeFront = nums[0], beforeBack = nums[size - 1];
      int diffCost = 0;
      if (nums[0] != front) {
        diffCost++;
        nums[0] = front;
      }
      if (nums[size - 1] != back) {
        diffCost++;
        nums[size - 1] = back;
      }
      int curCost = getMinDist(nums) + diffCost;
      answer = min(answer, curCost);

      nums[0] = beforeFront;
      nums[size - 1] = beforeBack;
    }
  }

  return answer;
}
```

## 고생한 점
