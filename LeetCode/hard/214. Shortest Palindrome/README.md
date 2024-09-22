# 214. Shortest Palindrome

[링크](https://leetcode.com/problems/shortest-palindrome/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

KMP 알고리즘을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

KMP 알고리즘을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### KMP 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(N)     |

문자열 s와 s를 뒤집은 문자열 reversed를 이어붙인 문자열 line을 생성한다.

이 때 중간에 구분하기 위해 특수문자를 추가한다.

이 문자열에 대해 KMP 알고리즘을 수행하고 패턴 index들을 구한다.

이 과정에서 맨 마지막 값이 현재 문자열과 뒤집은 문자열의 중복된 부분의 길이이다.

```cpp
vector<int> getPatternIndexes(const string& s) {
  int size = s.size();

  vector<int> pIndexes(size, 0);
  int index = 0;

  for (int i = 1; i < size; i++) {
    while (index > 0 && s[i] != s[index]) {
      index = pIndexes[index - 1];
    }
    if (s[i] == s[index]) {
      index++;
    }
    pIndexes[i] = index;
  }
  return pIndexes;
}

string shortestPalindrome(string s) {
  int size = s.size();

  string reversed = string(s.rbegin(), s.rend());

  string line = s + "#" + reversed;

  vector<int> pIndexes = getPatternIndexes(line);

  int palindromeLength = pIndexes.back();

  string prefix = reversed.substr(0, size - palindromeLength);
  return prefix + s;
}
```

## 고생한 점
