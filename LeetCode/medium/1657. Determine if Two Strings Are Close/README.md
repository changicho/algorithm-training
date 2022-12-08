# 1657. Determine if Two Strings Are Close

[링크](https://leetcode.com/problems/determine-if-two-strings-are-close/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

word1, word2의 길이를 각각 N, M이라 하자.

각 단어의 글자를 순회하며 count하고 나타난 알파벳에 대해 판단할 수 있다.

이 경우 순회에 O(N + M)의 시간 복잡도를 사용한다.

각 알파벳의 종류는 최대 26가지이다. 이 count에 대해 정렬하는 데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

counts와 나타난 알파벳을 판단하는데 O(1)의 공간 복잡도를 사용한다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     212      |  O(N + M)   |    O(1)     |

문제에서 각 글자들은 다른 글자로 바꿀 수 있다. (단어에서 나타난 알파벳들 끼리만)

따라서 알파벳의 출현 빈도와, 출현한 알파벳의 종류만 같은 경우 정답으로 볼 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<int> getCounts(string &word) {
  vector<int> counts(26, 0);

  for (char &c : word) {
    counts[c - 'a']++;
  }

  sort(counts.begin(), counts.end());
  return counts;
}

int getMask(string &word) {
  int bit = 0;
  for (char &c : word) {
    bit |= 1 << (c - 'a');
  }
  return bit;
}

bool closeStrings(string word1, string word2) {
  vector<int> count1 = getCounts(word1), count2 = getCounts(word2);
  int bit1 = getMask(word1), bit2 = getMask(word2);
  return count1 == count2 && bit1 == bit2;
}
```

## 고생한 점
