# 3251. Find the Count of Monotonic Pairs II

[링크](https://leetcode.com/problems/find-the-count-of-monotonic-pairs-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N이라 하자.

nums의 각 원소의 값은 0 ~ 10^4 이다. 이 범위를 M이라 하자.

동적 계획법을 사용해 현재 값과 직전 값에 대해 탐색할 경우 시간 복잡도는 O(N \* M^2) 이다. 이는 제한시간 내에 불가능하다.

동적 계획법에서 누적 합을 이용해 현재 값을 갱신할 수 있다. 이 경우 시간 복잡도는 O(N \* M) 이다.

### 공간 복잡도

동적 계획법에 직전값만을 사용하므로 O(M)의 공간 복잡도가 필요하다.

### 동적 계획법 & 누적 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     302      |  O(N \* M)  |    O(M)     |

다음과 같은 dp를 사용한다고 하자.

```cpp
int dp[index][cur]; // index까지 탐색했을 때, 오름차순 배열의 현재값이 cur값을 가지는 경우의 수
```

여기서 특정 index의 오름, 내림차순 배열의 값의 합은 정해져 있다.

따라서 오름차순 배열의 값 cur를 고정할 경우 나머지 내림차순의 값은 정해진다.

따라서 cur가 유효한지 판별하고 유효한 경우에 dp를 갱신할 수 있다.

이 때 현재 cur에 대해서 갱신할 때 더해야 하는 직전 값의 범위는 0 ~ before 까지의 이전 dp의 합이다.

이 합 미리 prefix sum을 이용해 구해놓을 수 있다.

여기서 before의 최대값을 알 경우 현재 cur에 대해서만 탐색하면 현재 index의 dp를 모두 구할 수 있다.

cur의 범위는 다음과 같이 구한다.

```cpp
// 현재 오름차순 배열의 값이 cur일 때
// 직전 오름차순 배열의 값을 before라 하자.
cur <= nums[i]
before <= cur

// 내림차순 배열을 고려했을 때
// 유효한 cur의 범위는 다음과 같다.
nums[i-1] - before >= nums[i] - cur

// 위 식을 변환하면
before <= nums[i-1] - nums[i] + cur

// 따라서 이전 before의 최대값은 다음과 같다.
int beforeLimit = min(nums[i-1] - nums[i] + cur, cur)
```

따라서 각 index마다 dp의 prefix sum을 갱신하며 현재 dp를 구할 수 있다.

```cpp
const int MOD = 1e9 + 7;

int countOfPairs(vector<int>& nums) {
  int size = nums.size();

  vector<int> prefixSum(1001, 0);
  for (int first = 0; first <= nums[0]; first++) {
    prefixSum[first] += (first > 0 ? prefixSum[first - 1] : 0) + 1;
    prefixSum[first] %= MOD;
  }

  for (int i = 1; i < size; i++) {
    vector<int> curPrefixSum(1001, 0);

    for (int cur = 0; cur <= nums[i]; cur++) {
      int beforeLimit = min(nums[i - 1] - nums[i] + cur, cur);
      if (beforeLimit < 0) continue;

      curPrefixSum[cur] += prefixSum[beforeLimit];
      curPrefixSum[cur] %= MOD;
    }

    for (int cur = 0; cur <= nums[i]; cur++) {
      curPrefixSum[cur] += (cur > 0 ? curPrefixSum[cur - 1] : 0);
      curPrefixSum[cur] %= MOD;
    }
    prefixSum = curPrefixSum;
  }

  int answer = prefixSum[nums.back()];
  return answer;
}
```

## 고생한 점
