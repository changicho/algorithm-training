# 2185. Counting Words With a Given Prefix

[링크](https://leetcode.com/problems/counting-words-with-a-given-prefix/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

words의 크기를 N, pref의 길이를 L이라 하자.

각 단어들을 모두 순회해야 하므로 O(N)의 시간 복잡도를 사용한다.

이 과정에서 pref와 같은지 비교해야 하므로 O(L)의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(N \* L)이 된다.

### 공간 복잡도

비교 연산에 별도의 공간 복잡도를 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 비교

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |  O(N \* L)  |    O(1)     |

각 단어를 순회하며 prefix로 시작하는경우 count를 증가시킨다.

이를 비교할 때 index를 비교하며 판단, 혹은 substr을 이용한다.

```cpp
bool isPrefix(string &word, string &pref) {
  if (word.length() < pref.length()) return false;

  // if (word.substr(0, pref.length()) != pref) return false;
  for (int i = 0; i < pref.length(); i++) {
    if (word[i] != pref[i]) return false;
  }
  return true;
}

int prefixCount(vector<string> &words, string pref) {
  int count = 0;

  for (string &word : words) {
    if (isPrefix(word, pref)) count++;
  }

  return count;
}
```

## 고생한 점
