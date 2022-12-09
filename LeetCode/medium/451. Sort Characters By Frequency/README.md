# 451. Sort Characters By Frequency

[링크](https://leetcode.com/problems/sort-characters-by-frequency/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 S의 길이를 N이라 하자.

각 문자들을 빈도에 따라 정렬해야 한다.

이를 위해 각 문자별로 counting 후 이를 정렬한다.

문자는 최대 대소문자 각 26가지 + 숫자 10가지 이므로 62가지이다.

이를 정렬할 경우 O(1)의 시간 복잡도를 사용한다.

이 정렬된 자료는 다시 문자로 생성해 반환할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답으로 생서하는 문자열에 O(N)의 공간 복잡도를 사용한다.

각 글자를 counting후 생성할 때 O(1)의 공간 복잡도를 사용한다.

### counting후 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(1)     |

각 글자수를 counting한뒤 빈도순으로 정렬한다.

이후 각 글자에 대한 counting을 순회하며 새로운 문자로 생성 후 반환한다.

```cpp
struct Char {
  char key;
  int count;

  bool operator<(const Char &b) const {
    if (count != b.count) return count > b.count;
    return key < b.key;
  }
};

string frequencySort(string s) {
  unordered_map<char, int> counts;

  for (char &c : s) {
    counts[c]++;
  }

  vector<Char> chars;
  for (auto &it : counts) {
    char key = it.first;
    int count = it.second;

    chars.push_back({key, count});
  }

  sort(chars.begin(), chars.end());

  string ret = "";
  for (Char &cur : chars) {
    ret += string(cur.count, cur.key);
  }
  return ret;
}
```

## 고생한 점
