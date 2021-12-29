# 1335. Minimum Difficulty of a Job Schedule

[링크](https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

jobDifficulty를 N, 입력받은 d를 D라고 하자.

완전 탐색 방법으로 모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이다.

이는 각 원소마다 subArray의 끝으로 설정할지 아닐지를 판단하면 되기 때문이다.

각 과정에서 중복되는 연산이 발생하므로 동적 계획법으로 문제를 풀이할 수 있다.

이를 사용할 때 경우의 수는 N \* D 가지이다.

현재 경우를 update할 때 O(N)의 시간 복잡도를 사용하므로 최종 시간 복잡도는 O(N^2 \* D)이다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N \* D)의 공간을 사용한다.

이후 해당 구간의 maximum을 빠르게 구하기 위해 동적 계획법을 사용할 경우 O(N^2)의 공간을 사용한다.

따라서 공간 복잡도는 O(N \* (N + D))이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 |   공간 복잡도   |
| :----------: | :---------: | :-------------: |
|      73      | O(N^2 \* D) | O(N \* (N + D)) |

DFS로 모든 경우를 탐색한다고 가정해보자. 아래와 같은 함수의 형태가 될것이다.

```cpp
void DFS(int index, int split, vector<int> subArray, int sum) {
  if (index == jobDifficulty.size() && split == d) {
    answer = min(sum, answer);
    return;
  }
  if(split >= d) return;

  // skip case
  subArray.push_back(jobDifficulty[index]);
  DFS(index + 1, split, subArray, sum);

  // split case
  DFS(index + 1, split + 1, {jobDifficulty[index],}, sum);
}
```

여기서 중복되는 경우가 발생할 수 있으며 이는 다음 2가지에 의해 결정된다.

- index : 현재 index. 이전 index들을 방문했음
- split : 현재까지 만든 subArray의 갯수

따라서 다음 2개의 수를 이용해 동적 계획법을 사용할 수 있다.

```cpp
dp[index][split]; // index, split minimum total cost

// initialize
dp[index][1]; = maximumValue(0 ~ index)
dp[index][split] = MAXIMUM;

// update
// 0 <= j < index
dp[index][split] = min(dp[j][split - 1] + maximumValue(j ~ index), dp[index][split])
```

여기서 일반식의 경우 현재 값을 계산할 때 이전 단계의 split의 데이터를 이용해 현재 subArray의 경우에 대해서 미리 구할 수 있다.

즉 split - 1인 상태에서 dp값을 모두 구해놨기 때문이다.

여기서 구간에 대한 maximumValue을 구하기 위해 다음과 같은 동적 계획법을 사용한다.

```cpp
maximum[from][to]; // maximum value of from ~ do

// initialize maximum
for (int i = 0; i < size; i++) {
  maximum[i][i] = jobDifficulty[i];
}

// update
for (int from = 0; from < size; from++) {
  for (int to = from + 1; to < size; to++) {
    maximum[from][to] = max(maximum[from][to - 1], jobDifficulty[to]);
  }
}
```

edge case는 다음과 같다.

- days로 나눌 수 없는 경우 (jobDifficulty의 크기가 d보다 작을때)

이를 구현하면 다음과 같다.

```cpp
int minDifficulty(vector<int>& jobDifficulty, int d) {
  int size = jobDifficulty.size();
  // dp[index][split] : minimum cost when range(0 ~ index), split
  vector<vector<long>> dp(size, vector<long>(d + 1, INT_MAX));
  // maximum[from][to] : maximum value of from ~ do
  vector<vector<int>> maximum(size, vector<int>(size, 0));

  // initialize maximum
  for (int i = 0; i < size; i++) {
    maximum[i][i] = jobDifficulty[i];
  }
  for (int from = 0; from < size; from++) {
    for (int to = from + 1; to < size; to++) {
      maximum[from][to] = max(maximum[from][to - 1], jobDifficulty[to]);
    }
  }

  // initialize dp
  for (int i = 0; i < size; i++) {
    dp[i][1] = maximum[0][i];
  }

  for (int split = 2; split <= d; split++) {
    for (int index = 0; index < size; index++) {
      for (int before = 0; before < index; before++) {
        long curCost = dp[before][split - 1] + maximum[before + 1][index];

        dp[index][split] = min(curCost, dp[index][split]);
      }
    }
  }

  if ((int)dp[size - 1][d] == INT_MAX) return -1;
  return (int)dp[size - 1][d];
}
```

## 고생한 점
