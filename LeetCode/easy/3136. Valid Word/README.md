# 3136. Valid Word

[링크](https://leetcode.com/problems/valid-word/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

단어의 길이를 N이라 하자.

순회를 이용해 조건을 판별할 경우 O(N)의 시간 복잡도를 갖는다.

### 공간 복잡도

O(1)의 공간 복잡도를 갖는다. (상수 공간 사용)

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

각 조건을 판별하는 함수를 작성 후 순회를 통해 각 조건을 판별한다.

```cpp
unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
unordered_set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j',
                                  'k', 'l', 'm', 'n', 'p', 'q', 'r',
                                  's', 't', 'v', 'w', 'x', 'y', 'z'};

bool isOnlyDigitsEnglish(string &word) {
  for (char &c : word) {
    if (!isdigit(c) && !islower(c) && !isupper(c)) return false;
  }
  return true;
}

bool hasVowelConsonant(string &word) {
  int vowel = 0, consonant = 0;
  for (char &c : word) {
    if (vowels.count(tolower(c)) > 0)
      vowel++;
    else if (consonants.count(tolower(c)) > 0)
      consonant++;
  }

  return vowel > 0 && consonant > 0;
}

bool isValid(string word) {
  return word.size() >= 3 && isOnlyDigitsEnglish(word) &&
          hasVowelConsonant(word);
}
```

## 고생한 점
