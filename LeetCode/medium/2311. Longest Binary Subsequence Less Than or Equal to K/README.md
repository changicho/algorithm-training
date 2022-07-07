# 2311. Longest Binary Subsequence Less Than or Equal to K

[링크](https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

S의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

맨 뒤부터 탐색을 진행하며 greedy한 방법을 이용한다.

이 경우 O(N)의 시간 복잡도를 사용한다.

혹은 동적 계획법을 이용해 해당 index에 대한 최선의 값을 갱신한다.

이 경우 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

그리디 알고리즘을 이용할 경우 현재 cost와 길이를 저장할 공간이 필요하다.

이는 O(1)의 공간 복잡도를 사용한다.

동적 계획법을 사용할 경우 각 index마다의 최대값을 저장해야한다.

이는 O(N)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

최대한 '0'은 많이 가져갈 수록 유리하다. 이는 '0'을 추가해도 cost는 바뀌지 않을 가능성이 생기기 때문이다.

이와 같은 이유로 left에 붙는 '0'들은 cost에 영향을 끼치지 않는다.

따라서 오른쪽에서부터 순회하며 '0'과 '1'을 최대한 추가해나간다.

한 비트가 추가될 때마다 cost는 2배가 되며, 이는 현재 '1'을 추가할 때 모든 cost가 K이하인지 비교하게된다.

이를 이용해 구현하면 다음과 같다.

```cpp
int longestSubsequence(string s, int k) {
  int length = s.length();

  int answer = 0, cost = 1;
  for (int i = length - 1; i >= 0; i--) {
    if (s[i] == '0' || cost <= k) {
      if (s[i] == '1') k -= cost;

      answer++;
    }

    if (cost <= k) cost *= 2;
  }

  return answer;
}
```

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      55      |   O(N^2)    |    O(N)     |

dp식을 다음과 같이 정의한다.

- 길이가 i일 때의 subSequence의 최소값

이후 각 문자를 순차적으로 순회하며 dp값을 갱신해나간다.

여기서 현재 문자를 더했을 때의 cost를 계산 후 이전 dp들을 갱신한다.

```cpp
int longestSubsequence(string s, int k) {
  // dp[i] : the minimum value of subsequence with length i
  int dp[1010] = {};
  int length = 0;

  for (char& c : s) {
    int curCost = dp[length] * 2 + c - '0';

    if (curCost <= k) {
      length++;
      dp[length] = curCost;
    }

    for (int i = length; i > 0; --i) {
      dp[i] = min(dp[i], dp[i - 1] * 2 + c - '0');
    }
  }
  return length;
}
```

## 고생한 점
