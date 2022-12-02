# 446. Arithmetic Slices II - Subsequence

[링크](https://leetcode.com/problems/arithmetic-slices-ii-subsequence/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

가능한 subSequence들에 대해 모두 판단할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 각 index마다 이전값들과의 차이에 대해 count를 증가시켜 정답을 구한다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N^2)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     1027     |   O(N^2)    |   O(N^2)    |

현재 index까지 방문했을 때, 이전 diff들에 대한 갯수들을 다음과 같이 정의하자.

```cpp
// init
counts[index][diff]; // count of diff's (subsequence) until index

// update
// current index is i
for (int prev = 0; prev < i; prev++) {
  long long diff = (long long)nums[i] - (long long)nums[prev];

  int beforeCount = 0;
  if (counts[prev].find(diff) != counts[prev].end()) {
    beforeCount = counts[prev][diff];
  }

  counts[i][diff] += beforeCount + 1;
  answer += beforeCount;
}

// init
counts[index][diff] = 0;
```

즉 각 index를 방문할 때마다 이전값 before들과의 diff에 대한 count를 이용해 현재까지의 subsequences를 계산한다.

이를 구현하면 다음과 같다.

```cpp
int numberOfArithmeticSlices(vector<int>& nums) {
  int size = nums.size();

  long long answer = 0;
  // key : diff, val : subsequences count
  vector<unordered_map<long long, int>> counts(size);
  for (int i = 1; i < size; i++) {
    for (int prev = 0; prev < i; prev++) {
      long long diff = (long long)nums[i] - (long long)nums[prev];

      int beforeCount = 0;
      if (counts[prev].find(diff) != counts[prev].end()) {
        beforeCount = counts[prev][diff];
      }

      counts[i][diff] += beforeCount + 1;
      answer += beforeCount;
    }
  }

  return (int)answer;
}
```

## 고생한 점
