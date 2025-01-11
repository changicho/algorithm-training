# 1408. String Matching in an Array

[링크](https://leetcode.com/problems/string-matching-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words의 크기를 N, 각 문자열의 길이를 L이라 하자.

완전 탐색을 수행할 경우 O(N^2 \* L^2)의 시간 복잡도를 사용한다.

KMP 알고리즘을 사용할 경우 O(N^2 \* L)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N \* L)의 공간 복잡도가 필요하다.

KMP 알고리즘에 O(L)의 공간 복잡도가 필요하다.

### KMP 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       | O(N^2 \* L) |  O(N \* L)  |

각 단어쌍을 비교하며 하나의 단어가 다른 단어에 포함되는지 판단하는데 KMP알고리즘을 사용한다.

sub가 main에 포함되는지 검사하며 sub의 pattern index 배열을 미리 만들어 놓고 탐색을 진행한다.

```cpp
vector<int> getLPS(string &pattern) {
  int size = pattern.size();

  vector<int> lps(size, 0);

  for (int i = 1, pI = 0; i < size; i++) {
    while (pI > 0 && pattern[i] != pattern[pI]) {
      pI = lps[pI - 1];
    }
    if (pattern[i] == pattern[pI]) {
      pI++;
      lps[i] = pI;
    }
  }
  return lps;
}

bool isSubstringOf(string &sub, string &main, vector<int> &lps) {
  int mainI = 0;
  int subI = 0;

  while (mainI < main.size()) {
    if (main[mainI] == sub[subI]) {
      subI++;
      mainI++;

      if (subI == sub.size()) return true;
    } else {
      if (subI > 0) {
        subI = lps[subI - 1];
      } else {
        mainI++;
      }
    }
  }
  return false;
}

vector<string> stringMatching(vector<string> &words) {
  int size = words.size();

  vector<string> answer;

  for (int i = 0; i < size; i++) {
    vector<int> lps = getLPS(words[i]);

    for (int j = 0; j < size; j++) {
      if (i == j) continue;

      if (isSubstringOf(words[i], words[j], lps)) {
        answer.push_back(words[i]);
        break;
      }
    }
  }

  return answer;
}
```

### 완전 탐색

| 내 코드 (ms) |  시간 복잡도  | 공간 복잡도 |
| :----------: | :-----------: | :---------: |
|      3       | O(N^2 \* L^2) |  O(N \* L)  |

각 단어 쌍에 대해 한 단어가 다른 단어에 포함되는지 검사한다.

```cpp
bool isSubstring(string &a, string &b) { return a.find(b) != -1; }

vector<string> stringMatching(vector<string> &words) {
  vector<string> answer;

  for (string &a : words) {
    bool flag = false;
    for (string &b : words) {
      if (a == b) continue;

      if (isSubstring(b, a)) {
        flag = true;
      }
    }

    if (flag) {
      answer.push_back(a);
    }
  }
  return answer;
}
```

## 고생한 점
