# 290. Word Pattern

[링크](https://leetcode.com/problems/word-pattern/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

단어의 개수를 N이라 하자.

패턴에 맞는 단어들을 매칭이 되어있는지 확인해야하며 이는 한번의 순회로 패턴 테이블을 생성해 가능하다.

이에 들어가는 시간 복잡도는 O(N)이다.

### 공간 복잡도

테이블을 만들어야 하므로 O(N)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

pattern의 알파벳과 해당하는 위치의 각 word들을 패턴으로 묶어준다.

이 때 패턴 알파벳과 단어를 서로 테이블로 묶어줘 패턴에 해당하는 단어가 중복되지 않도록 처리한다.

word를 추출하는것은 stream string을 통해 가능하다.

```cpp
vector<string> split(string s) {
  stringstream ss(s);

  vector<string> ret;
  string temp;
  while (ss >> temp) {
    ret.emplace_back(temp);
  }
  return ret;
}
```

단어와 패턴, 패턴과 단어를 매칭하는 hash map을 생성한다.

이후 추출한 단어들과 패턴을 순차적으로 같이 순회하며 다음과 같은 경우를 판별한다.

- 현재 단어와 패턴이 나타나지 않은 경우 : hash map에 둘다 저장
- 현재 단어와 패턴이 hash map에 있는 경우와 같은 : PASS
- 그 외의 경우 : 에러

이를 구현하면 다음과 같다.

```cpp
bool wordPattern(string pattern, string s) {
  vector<string> tokens = split(s);

  if (pattern.size() != tokens.size()) return false;
  unordered_map<char, string> patternToWord;
  unordered_map<string, char> wordToPattern;

  for (int i = 0; i < pattern.size(); i++) {
    char key = pattern[i];
    string val = tokens[i];

    if (patternToWord.count(key) == 0 && wordToPattern.count(val) == 0) {
      patternToWord[key] = val;
      wordToPattern[val] = key;
    } else if (patternToWord[key] == val && wordToPattern[val] == key) {
      continue;
    } else {
      return false;
    }
  }
  return true;
}
```

### convert

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

입력받은 pattern과 s를 hash map을 이용해 패턴으로 변환한다.

이후 두 패턴이 같은지 판단한다.

```cpp
string convert(vector<string> &words) {
  unordered_map<string, int> um;

  string ret = "";
  for (string &word : words) {
    if (um.count(word) == 0) {
      um[word] = um.size();
    }
    ret += to_string(um[word]);
  }

  return ret;
}
```

## 고생한 점
