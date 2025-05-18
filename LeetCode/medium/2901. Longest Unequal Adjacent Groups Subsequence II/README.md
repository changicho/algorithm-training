# 2901. Longest Unequal Adjacent Groups Subsequence II

[링크](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 words, groups의 크기를 N이라 하자.

동적 계획법을 사용하는데 O(N^2)의 시간 복잡도를 가진다.

### 공간 복잡도

각 index마다 이전까지 만들 수 있는 최대 길이를 저장하기 위해 O(N)의 공간 복잡도를 가진다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |   O(N^2)    |    O(N)     |

각 index마다 이전 index에서 현재 index까지 만들 수 있는 최대 길이를 저장한다.

이를 index가 왼쪽부터 순회하며 최대 길이를 구한다.

이후 역순으로 정답을 구한다.

```cpp
bool check(string& s1, string& s2) {
  if (s1.size() != s2.size()) return false;

  int diff = 0;
  for (int i = 0, size = s1.size(); i < size; i++) {
    if (s1[i] != s2[i]) diff++;
    if (diff > 1) return false;
  }
  return diff == 1;
}

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
  int size = groups.size();
  vector<int> dp(size, 1);
  vector<int> prev(size, -1);

  int index = 0;
  for (int i = 1; i < size; i++) {
    for (int before = 0; before < i; before++) {
      if (!check(words[i], words[before])) continue;
      if (groups[i] == groups[before]) continue;
      if (dp[before] + 1 <= dp[i]) continue;

      dp[i] = dp[before] + 1;
      prev[i] = before;
    }

    if (dp[i] > dp[index]) {
      index = i;
    }
  }

  vector<string> answer;
  while (index != -1) {
    answer.emplace_back(words[index]);
    index = prev[index];
  }

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
