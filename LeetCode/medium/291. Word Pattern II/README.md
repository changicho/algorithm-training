# 291. Word Pattern II

[링크](https://leetcode.com/problems/word-pattern-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, pattern의 길이를 P이라 하자.

백트래킹을 사용해 모든 경우를 탐색할 경우 시간 복잡도는 O(P * N^3)이다.

이를 좀더 최적화 할 경우 O(P * N * (N - P)^2)이다.

### 공간 복잡도

각 경우마다 pattern, 사용한 문자에 해당하는 문자열을 저장해야 한다. 이는 O(P + N)의 공간 복잡도가 필요하다.

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(P * N^3)  |  O(P + N)   |

```cpp
unordered_map<char, string> pDict;
unordered_map<string, char> sDict;

bool recursive(string &pattern, int pI, string &s, int sI) {
  int pSize = pattern.size();
  int sSize = s.size();

  if (pI == pSize || sI == sSize) {
    return pI == pSize && sI == sSize;
  }

  for (int i = sI; i < sSize; i++) {
    string key = s.substr(sI, i - sI + 1);

    if (pDict.count(pattern[pI]) && pDict[pattern[pI]] != key) continue;
    if (sDict.count(key) && sDict[key] != pattern[pI]) continue;

    bool inserted = false;
    if (!pDict.count(pattern[pI]) && !sDict.count(key)) {
      pDict[pattern[pI]] = key;
      sDict[key] = pattern[pI];
      inserted = true;
    }

    if (recursive(pattern, pI + 1, s, i + 1)) return true;

    if (inserted) {
      pDict.erase(pattern[pI]);
      sDict.erase(key);
    }
  }

  return false;
}

bool wordPatternMatch(string pattern, string s) {
  return recursive(pattern, 0, s, 0);
}
```

## 고생한 점
