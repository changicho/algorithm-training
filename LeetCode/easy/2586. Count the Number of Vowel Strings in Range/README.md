# 2586. Count the Number of Vowel Strings in Range

[링크](https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

words의 크기를 N이라 하자.

각 word가 시작과 끝이 모음 단어인지 판단하는데 O(1)의 시간 복잡도를 사용한다.

left ~ right까지 순회하며 이를 판단하는데 최대 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 문자열을 순회하며 판단하며 정답을 증가시킬 경우 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

left ~ right까지 순회하며 각 문자열의 첫번째와 마지막 문자가 모음인지 판단한다.

```cpp
unordered_set<char> vowels = {'a', 'e', 'o', 'i', 'u'};

bool isVowel(char &c) { return vowels.count(c) > 0; }

bool isVowelWord(string &word) {
  return isVowel(word.front()) && isVowel(word.back());
}

int vowelStrings(vector<string> &words, int left, int right) {
  int size = words.size();

  int count = 0;
  for (int i = left; i <= right; i++) {
    if (isVowelWord(words[i])) count++;
  }
  return count;
}
```

## 고생한 점
