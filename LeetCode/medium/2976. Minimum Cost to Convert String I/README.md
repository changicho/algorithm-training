# 2976. Minimum Cost to Convert String I

[링크](https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

변환할 문자열의 길이를 N, 변환 가능한 알파벳의 정보 배열의 길이를 M이라 하자.

각 알파벳마다 변환 가능한 최소 cost를 플로이드 와샬을 이용해 구할 수 있다.

이 때 시간 복잡도는 O(26^3)이며 이는 17576이므로 O(1)이다.

변환 정보를 순회하며 그래프를 생성한 뒤, 문자열의 변환을 수행하는데 O(N + M)의 시간 복잡도가 필요하다.

### 공간 복잡도

그래프 정보에 O(26^2)의 공간 복잡도를 사용하며 이는 O(1)이다.

### 플로이드 와샬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     140      |  O(N + M)   |    O(1)     |

각 알파벳 별로 다른 알파벳으로 변환 가능한 최소 cost를 구한다.

이를 모든 알파벳에 대해 구해야 하므로 플로이드 와샬 알고리즘을 사용한다.

이후 source를 target으로 변환하는데 필요한 cost를 구한다.

이 때 해당 알파벳이 변환 불가능한 경우 -1을 반환한다.

```cpp
long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
  // from, to
  vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));

  for (int i = 0; i < cost.size(); i++) {
    char from = original[i], to = changed[i];
    int c = cost[i];

    dp[from - 'a'][to - 'a'] = min(dp[from - 'a'][to - 'a'], (long long)c);
  }

  for (int i = 0; i < 26; i++) {
    dp[i][i] = 0;
  }

  for (int through = 0; through < 26; through++) {
    for (int from = 0; from < 26; from++) {
      for (int to = 0; to < 26; to++) {
        if (dp[from][through] == LLONG_MAX || dp[through][to] == LLONG_MAX) {
          continue;
        }
        dp[from][to] = min(dp[from][to], dp[from][through] + dp[through][to]);
      }
    }
  }

  int size = source.size();
  long long answer = 0;
  for (int i = 0; i < size; i++) {
    char from = source[i], to = target[i];
    if (from == to) continue;

    if (dp[from - 'a'][to - 'a'] == LLONG_MAX) return -1;
    answer += dp[from - 'a'][to - 'a'];
  }
  return answer;
}
```

## 고생한 점
