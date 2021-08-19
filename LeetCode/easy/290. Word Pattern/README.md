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

### hahs map

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

```cpp
bool wordPattern(string pattern, string s) {
  unordered_map<char, string> table;
  unordered_map<string, char> reversed;

  vector<string> words = split(s);

  int length = pattern.length();
  int size = words.size();

  if (size != length) return false;

  for (int i = 0; i < size; i++) {
    char p = pattern[i];
    string word = words[i];

    if (table.find(p) != table.end() && table[p] != word) {
      return false;
    } else {
      table[p] = word;
    }

    if (reversed.find(word) != reversed.end() && reversed[word] != p) {
      return false;
    } else {
      reversed[word] = p;
    }
  }

  return true;
}
```

## 고생한 점
