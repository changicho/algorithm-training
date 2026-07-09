# 288. Unique Word Abbreviation

[링크](https://leetcode.com/problems/unique-word-abbreviation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연산마다의 총 문자열의 길이의 합을 N이라 하자.

hash map을 이용해 구현할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      48      |    O(N)     |    O(N)     |

hash set에 변환한 문자열과 원본 문자열을 각각 저장한다.

이후 각 조건에 따라 값을 반환한다.

- 값을 저장할 때 중복값들은 하나로 처리한다.
- 단어가 유니크하며 변환한 단어도 1개인 경우 true
- 혹은 변환한 값도 없는 경우 true

```cpp
class ValidWordAbbr {
 private:
  string convert(string& word) {
    string ret = "";
    int size = word.size();

    ret += word.front();
    if (size - 2 > 0) {
      ret += to_string(size - 2);
    }
    ret += word.back();
    return ret;
  }

  unordered_set<string> origin;
  unordered_map<string, int> um;

 public:
  ValidWordAbbr(vector<string>& dictionary) {
    for (string& d : dictionary) {
      if (origin.count(d) > 0) continue;
      origin.insert(d);
      string c = convert(d);

      um[c]++;
    }
  }

  bool isUnique(string word) {
    string c = convert(word);

    if (um.count(c) == 0) return true;
    if (origin.count(word) && um[c] == 1) return true;
    return false;
  }
};
```

## 고생한 점
