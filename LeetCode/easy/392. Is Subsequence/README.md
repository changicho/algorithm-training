# 392. Is Subsequence

[링크](https://leetcode.com/problems/is-subsequence/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

s의 길이를 N, t의 길이를 M이라 하자.

투 포인터를 이용해 탐색할 경우 시간 복잡도는 O(N + M)이 된다.

각 글자들에 대한 index들을 저장한 뒤 이분탐색으로 풀이할 경우 시간 복잡도는 O(N \* log_2(M))이다.

동적 계획법을 이용할 경우 N과 M의 모든 경우에 대해서 탐색하므로 시간 복잡도는 O(N \* M)이 된다.

### 공간 복잡도

투 포인터를 이용할 경우 별도의 공간 복잡도가 필요하지 않으므로 O(1)이다.

이분 탐색으로 풀이할 경우 t의 값들에 대한 모든 index를 알아야 하므로 공간 복잡도는 O(M)이 된다.

동적 계획법을 이용할 경우 N, M의 경우에 대한 값들을 알아야 하므로 공간 복잡도는 O(N \* M)이 된다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

t를 탐색하며 현재 s의 index번째 값이 나오는 경우 index를 증가시킨다.

index가 s의 길이와 같은지를 판별해 t 안에 s의 subsequence가 있는지 검사할 수 있다.

```cpp
bool isSubsequence(string s, string t) {
  int lengthS = s.length(), lengthT = t.length();

  if (lengthS > lengthT) return false;
  int index = 0;

  for (int i = 0; i < lengthT; i++) {
    if (s[index] == t[i]) {
      index += 1;
    }

    if (index == lengthS) break;
  }

  return index == lengthS;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(M)) |    O(M)     |

문자열 t의 각 글자마다의 index를 저장한다. (오름차순)

이후 s의 문자열의 문자를 각각 탐색하며 t의 글자마다의 index가 이전에 나온 index를 초과하는 값들을 찾는다.

이 과정에서 초과하는 값이 없는 경우는 subsequence가 없다고 판별할 수 있다.

```cpp
bool isSubsequence(string s, string t) {
  unordered_map<char, vector<int>> um;
  int lengthS = s.length(), lengthT = t.length();

  for (int i = 0; i < lengthT; ++i) {
    um[t[i]].push_back(i);
  }

  int prev = -1;
  for (char c : s) {
    if (um.find(c) == um.end()) return false;

    vector<int> &arr = um[c];
    int index = upper_bound(arr.begin(), arr.end(), prev) - arr.begin();
    if (index == arr.size()) return false;

    prev = arr[index];
  }

  return true;
}
```

### 동적 계획법 (Longest Common Substring)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |  O(N \* M)  |  O(N \* M)  |

이 문자열을 LCS문제로 볼 수 있다. (s를 모두 포함하는 촤장 공통 문자열)

따라서 행과 열을 각각 s, t에 대해서 설정하고 각각의 index에 대해서 이동시키며 문제를 해결한다.

현재 s의 글자와 t의 글자가 같은 경우 둘다 다음 index로 증가시키며 최장 길이를 증가시킨다.

만약 불가능한 경우는 s, t에서 각각 이어진 값중에 최대값을 현재 최장 길이로 설정한다.

이후 최장 공통 문자열의 길이가 s의 길이와 같은지 검사한다.

```cpp
bool isSubsequence(string s, string t) {
  int lengthS = s.size();
  int lengthT = t.size();

  vector<vector<int>> dp(lengthS + 1, vector<int>(lengthT + 1, 0));

  for (int i = 1; i <= lengthS; ++i) {
    for (int j = 1; j <= lengthT; ++j) {
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp.back().back() == s.length();
}
```

## 고생한 점
