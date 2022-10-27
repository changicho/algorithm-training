# 1662. Check If Two String Arrays are Equivalent

[링크](https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

word1, word2의 크기의 합을 N, 각 단어의 평균 길이를 L이라 하자.

각 문자들을 방문해야 하므로 최소 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

별도의 문자열을 사용하는 경우 O(N \* L)의 공간 복잡도를 사용한다.

투 포인터를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### extra space

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |  O(N \* L)  |  O(N \* L)  |

두 배열의 각 단어들을 새로운 문자열에 순서대로 붙이고, 이를 비교한다.

```cpp
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
  string line1 = "", line2 = "";
  for (string& word : word1) {
    line1 += word;
  }
  for (string& word : word2) {
    line2 += word;
  }

  return line1 == line2;
}
```

### two pointer

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      11      |  O(N \* L)  |    O(1)     |

word1, word2에 대해 wordIdx, stringIdx를 선언하고 이를 하나씩 비교한다.

```cpp
bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
  int word1Idx = 0, word2Idx = 0;
  int string1Idx = 0, string2Idx = 0;

  while (word1Idx < word1.size() && word2Idx < word2.size()) {
    if (word1[word1Idx][string1Idx] != word2[word2Idx][string2Idx]) {
      return false;
    }

    string1Idx++;
    string2Idx++;

    if (string1Idx == word1[word1Idx].size()) {
      word1Idx++;
      string1Idx = 0;
    }
    if (string2Idx == word2[word2Idx].size()) {
      word2Idx++;
      string2Idx = 0;
    }
  }

  return word1Idx == word1.size() && word2Idx == word2.size();
}
```

## 고생한 점
