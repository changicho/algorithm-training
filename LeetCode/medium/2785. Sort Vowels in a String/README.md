# 2785. Sort Vowels in a String

[링크](https://leetcode.com/problems/sort-vowels-in-a-string/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 문자열 s의 길이를 N이라 하자.

문자열의 모음들만 정렬하면 된다. 이에 카운팅 정렬을 이용할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

s의 모음들을 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

별도의 정답 문자열을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

문자열의 모음들만 추출 후 정렬한다.

이후 원본 문자열에서 모음들을 순서대로 대체한다.

```cpp
bool is_vowel(char c) {
  c = tolower(c);
  return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
}

string sortVowels(string s) {
  int size = s.size();

  string keys = "AEIOUaeiou";
  int counts[256] = {
      0,
  };
  for (char &c : s) {
    if (is_vowel(c)) {
      counts[c]++;
    }
  }

  string vowels = "";
  for (char &key : keys) {
    vowels += string(counts[key], key);
  }

  int index = 0;
  for (int i = 0; i < size; i++) {
    char c = s[i];

    if (is_vowel(c)) {
      s[i] = vowels[index];
      index++;
    }
  }
  return s;
}
```

## 고생한 점
