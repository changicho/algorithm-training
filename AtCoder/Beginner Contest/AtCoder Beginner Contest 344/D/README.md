# D - String Bags

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

문자열 T의 길이를 L, 문자열 배열 A의 크기를 N, 총 문자열의 갯수를 M이라 하자.

동적 계획법을 이용해 풀이할 경우 각 경우마다 문자열을 붙일 수 있는지 판단해야 하므로 O(L \* M)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(L)의 공간 복잡도가 필요하다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |  O(L \* M)  |    O(L)     |

단어 배열 A를 순회하며 현재 단어들을 이전에 만들어진 단어들에 붙여 T의 prefix를 만들 수 있는지 판단한다.

이 때 이전에 만들어진 단어의 최소 횟수를 dp로 관리한다.

배열의 현재 단어 묶음을 words라 하자.

이 경우 words를 순회하며 각 단어를 이전에 만들어진 단어들에 붙여 T의 prefix를 만들 수 있는지 판단한다.

이 때 각 words에서 단어를 하나만 선택할 수 있으므로 dp에 바로 반영하지 않고, words를 순회한 이후 값을 dp에 반영한다.

```cpp
for (string &word : v) {
  int len = word.size();

  for (int i = 0; i < size; i++) {
    if (i + len > size) break;
    if (dp[i] == INT_MAX) continue;

    if (target.substr(i, len) == word) {
      dp2[i + len] = min(dp2[i + len], dp[i] + 1);
    }
  }
}
```

이를 A를 순회하며 반복한다.

```cpp
int solution(string &target, vector<vector<string>> &arr) {
  int size = target.size();

  vector<int> dp(size + 1, INT_MAX);
  dp[0] = 0;

  for (vector<string> &v : arr) {
    vector<int> dp2 = dp;

    for (string &word : v) {
      int len = word.size();

      for (int i = 0; i < size; i++) {
        if (i + len > size) break;
        if (dp[i] == INT_MAX) continue;

        if (target.substr(i, len) == word) {
          dp2[i + len] = min(dp2[i + len], dp[i] + 1);
        }
      }
    }

    dp = dp2;
  }

  if (dp.back() == INT_MAX) {
    return -1;
  }
  return dp.back();
}
```

## 고생한 점
