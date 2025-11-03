# 3186. Maximum Total Damage With Spell Casting

[링크](https://leetcode.com/problems/maximum-total-damage-with-spell-casting/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 powers의 크기를 N이라 하자.

정렬에 O(N \* log_2(N))의 시간이 소요된다.

이후 각 power를 순회하며 현재 power - 2 미만인 index를 같이 갱신한다.

이를 이용해 현재 최대값을 갱신하는데 순회에 O(N)의 시간이 소요된다.

따라서 전체 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 동적 계획법

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      62      | O(N \* log_2(N)) |    O(N)     |

power를 오름차순으로 정렬한다.

이후 다음과 같은 dp배열을 생성한다.

```cpp
// definition
long long dp[i]; // i번째 power까지 고려했을 때의 최대 damage

// initialize
dp[0] = power[0];

// update
dp[i] = max(dp[i], dp[i-1]);
// power[i-1] == power[i] or power[i-1] + 2 > power[i]
dp[i] = max(dp[i], dp[i-1] + power[i]);
// power[j] + 2 < power[i]
dp[i] = max(dp[i], dp[j] + power[i]);
```

만약 직전 값이 같거나 차이가 2 미만이라면 직전 값과 더하는 것이 최대값이 될 수 있다.

특정 index까지의 최대값을 미리 저장한 경우, 현재 값 - 2 미만인 최대 index를 찾아 더하는 것도 최대값이 될 수 있다.

혹은 직전 dp값을 그대로 가져오는 것도 가능하다.

이를 이용해 정답을 갱신한다.

```cpp
long long maximumTotalDamage(vector<int>& power) {
  int size = power.size();

  sort(power.begin(), power.end());

  // skip -2, -1
  vector<long long> maximums(size, 0);

  maximums[0] = power[0];

  long long before = power[0];
  for (int i = 1, j = 0; i < size; i++) {
    while (j + 1 < i && power[j + 1] + 2 < power[i]) {
      j++;
    }

    long long cur = power[i];

    if (power[i] == power[i - 1] || power[i] - 2 > power[i - 1]) {
      cur = max(cur, before + power[i]);
    }

    if (power[j] + 2 < power[i]) {
      cur = max(cur, maximums[j] + power[i]);
    }

    maximums[i] = max(maximums[i - 1], cur);
    before = cur;
  }

  return maximums.back();
}
```

## 고생한 점
