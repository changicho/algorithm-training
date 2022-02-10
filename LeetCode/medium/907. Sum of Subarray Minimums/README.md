# 907. Sum of Subarray Minimums

[링크](https://leetcode.com/problems/sum-of-subarray-minimums/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

주어진 배열의 길이를 N이라 하자.

모든 구간의 범위를 탐색하는데 O(N^2)의 시간 복잡도를 사용한다.

해당 구간의 min값은 동적 계획법을 이용할 경우 O(N^2)의 시간 복잡도로 알 수 있다.

모노토닉 스택을 이용해 한번의 순회로 해당 구간의 min값을 바로 알 수 있다. 이 순회에 O(N)의 시간 복잡도를 사용한다.

여기에 동적 계획법을 이용해 직전 index까지의 minimum의 합을 이용할 경우 총 O(N)의 시간복잡도로 풀이가 가능하다.

### 공간 복잡도

동적 계획법을 이용할 경우 O(N^2)의 공간 복잡도를 사용한다.

모노토닉 스택을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 모노토닉 스택 & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      80      |    O(N)     |    O(N)     |

dp를 다음과 같이 선언한다.

```cpp
dp[i]; // sum of minimum of subarrays end with i (arr[0 ~ i])

// update
dp[i] = dp[i - 1] + countCurrent;

// initialize
dp[0] = arr[0];
```

즉 0 ~ i 범위의 minimum값들에 대해 dp를 선언해 이전 값을 이용해 구할 수 있다.

현재 범위까지의 minimum값을 선언하는것은 모노토닉 스택을 이용해 구할 수 있다.

모노토닉 스택을 이용해 현재까지 순회하며 작은 index들만 stack에 남도록 한다.

이 경우 stack.top()에서부터 현재 index까지 범위에 속한 값들은 현재 값이 minimum인 subArray이다.

따라서 해당 subArray의 갯수만큼 현재 수를 더하면된다.

이를 모든 index에 대해 반복한다.

이후 dp의 모든 값을 더해 가능한 모든 subArray에서의 갯수를 구한다.

```cpp
int sumSubarrayMins(vector<int>& arr) {
  int size = arr.size();
  stack<int> minStack;
  // dp[i] : sum of minimum of subarrays end with i (arr[0 ~ i])
  vector<int> dp(size, 0);

  for (int i = 0; i < size; i++) {
    // pop until current index's value is bigest
    while (!minStack.empty() && arr[i] <= arr[minStack.top()]) {
      minStack.pop();
    }

    if (minStack.empty()) {
      dp[i] = ((i + 1) * arr[i]) % MOD;
    } else {
      int prevMinIdx = minStack.top();
      dp[i] = (dp[prevMinIdx] + (i - prevMinIdx) * arr[i]) % MOD;
    }

    minStack.push(i);
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer += dp[i];
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
