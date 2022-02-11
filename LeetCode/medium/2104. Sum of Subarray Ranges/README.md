# 2104. Sum of Subarray Ranges

[링크](https://leetcode.com/problems/sum-of-subarray-ranges/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

범위의 가능한 경우의 수는 N^2개 이다.

각 subArray에 대해 직접 모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용한다.

각 범위의 min, max를 미리 구해놓고 이용할 경우 O(N^2)의 시간 복잡도를 사용한다.

모노토닉 스택과 동적 계획법을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

범위의 min, max에 대해 동적 계획법을 사용할 경우 O(N^2)의 공간 복잡도를 사용한다.

모노토닉 스택과 동적 계획법을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 범위 탐색 & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     144      |   O(N^2)    |   O(N^2)    |

다음과 같은 dp를 생성할 수 있다.

```cpp
rangeMin[left][right]; // minimum value of left ~ right
rangeMax[left][right]; // maximum value of left ~ right

// initialize
rangeMin[i][i] = nums[i];
rangeMax[i][i] = nums[i];

// update
for (int left = 0; left < size; left++) {
  for (int right = left + 1; right < size; right++) {
    rangeMin[left][right] = min(rangeMin[left][right - 1], nums[right]);
    rangeMax[left][right] = max(rangeMax[left][right - 1], nums[right]);
  }
}
```

이를 이용해 각 구간별로 최소값과 최대값을 O(1)의 시간 복잡도로 알 수 있다.

range의 탐색에는 O(N^2)의 시간 복잡도를 사용하므로 이를 이용해 모든 구간의 최대값과 최소값을 구할 수 있다.

이 때 dp를 갱신할 때 직전값만 사용하므로 이를 최적화 할 수 있다.

이를 구현하면 다음과 같다.

```cpp
long long subArrayRanges(vector<int>& nums) {
  int size = nums.size();

  long long answer = 0;
  for (int left = 0; left < size; left++) {
    int maximum = nums[left], minimum = nums[left];

    for (int right = left + 1; right < size; right++) {
      maximum = max(maximum, nums[right]);
      minimum = min(minimum, nums[right]);

      answer += maximum - minimum;
    }
  }
  return answer;
}
```

### 모노토닉 스택 & 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

`907. Sum of Subarray Minimums` 문제에서 사용한 방법을 사용해 O(N)의 시간 복잡도로 각 구간의 최소값과 최대값을 구할 수 있다.

각 구간의 최대값은 더하고 최소값은 빼야하므로 이를 2가지로 분리해서 생각할 수 있다.

- 각 구간의 최대값들을 구하고 정답에 다 더한다.
- 각 구간의 최소값들을 구하고 정답에 다 뺀다.

각 구간의 minimum 값의 합을 구하기 위한 dp를 다음과 같이 선언한다.

```cpp
dp[i]; // sum of minimum of subarrays end with i (arr[0 ~ i])

// update
dp[i] = dp[i - 1] + countCurrent;

// initialize
dp[0] = arr[0];
```

즉 0 ~ i 범위의 minimum값들의 갯수를 이전 값을 이용해 구할 수 있다.

현재 범위까지의 minimum값을 선언하는것은 모노토닉 스택을 이용해 구할 수 있다.

모노토닉 스택을 이용해 현재까지 순회하며 작은 index들만 stack에 남도록 한다.

이 경우 stack.top()에서부터 현재 index까지 범위에 속한 값들은 현재 값이 minimum인 subArray이다.

따라서 해당 subArray의 갯수만큼 현재 수를 더하면된다.

이를 모든 index에 대해 반복한다.

이후 dp의 모든 값을 더해 가능한 모든 subArray에서의 갯수를 구한다.

이를 최대값에도 반복해 정답을 구한다.

```cpp
long long subArrayRanges(vector<int>& nums) {
  int size = nums.size();

  stack<int> minStack, maxStack;

  // minDP[i] : sum of minimum of subarrays end with i (nums[0 ~ i])
  vector<long long> minDP(size, 0);
  // maxDP[i] : sum of maximum of subarrays end with i (nums[0 ~ i])
  vector<long long> maxDP(size, 0);

  for (int i = 0; i < size; i++) {
    // pop until current index's value is bigest
    while (!minStack.empty() && nums[i] <= nums[minStack.top()]) {
      minStack.pop();
    }

    if (minStack.empty()) {
      minDP[i] = ((i + 1) * (long)nums[i]);
    } else {
      int prevMinIdx = minStack.top();
      minDP[i] = (minDP[prevMinIdx] + (i - prevMinIdx) * (long)nums[i]);
    }

    minStack.push(i);
  }

  for (int i = 0; i < size; i++) {
    // pop until current index's value is smallest
    while (!maxStack.empty() && nums[i] >= nums[maxStack.top()]) {
      maxStack.pop();
    }

    if (maxStack.empty()) {
      maxDP[i] = ((i + 1) * (long)nums[i]);
    } else {
      int prevMaxIdx = maxStack.top();
      maxDP[i] = (maxDP[prevMaxIdx] + (i - prevMaxIdx) * (long)nums[i]);
    }

    maxStack.push(i);
  }

  long long answer = 0;
  for (int i = 0; i < size; i++) {
    answer += maxDP[i];
    answer -= minDP[i];
  }

  return answer;
}
```

## 고생한 점

overflow가 발생하므로 타입 변환을 이용해줘야한다.
