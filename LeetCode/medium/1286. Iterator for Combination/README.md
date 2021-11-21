# 1286. Iterator for Combination

[링크](https://leetcode.com/problems/iterator-for-combination/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 cur의 길이를 N이라 하자.

미리 모든 조합을 구해놓은 뒤 이를 이용해 구현할 경우 조합을 생성하는 데 O(2^N)의 시간 복잡도가 소요된다.

이후에 next, hasNext연산은 O(1)의 시간 복잡도가 소요된다.

bit masking을 이용해 구현할 수 도 있다. 이 경우 next를 구현할 때 비스마스크를 이용해 문자열을 생성하는데 O(N), 비트를 업데이트 하는데 O(1)의 시간 복잡도가 소요된다.

hasNext연산은 비트를 업데이트 할 때 구현하므로 O(1)의 시간 복잡도가 소요된다.

### 공간 복잡도

미리 모든 조합을 구하는 경우 O(2^N)의 공간 복잡도를 사용한다.

bit masking을 사용하는 경우 입력받은 문자열 등을 저장하는데 O(N)의 공간 복잡도를 사용한다.

### 모든 경우 구하기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(2^N)    |   O(2^N)    |

미리 모든 조합의 경우를 DFS를 이용해 탐색한다.

이 때 입력받은 cur문자열은 오름차순으로 정렬되어있으므로 DFS를 수행할 때 자연스럽게 lexicographical order로 조합을 생성할 수 있다.

next가 호출될 때마다 현재의 combination을 반환하고 index를 증가시킨다.

이후 index가 초과할 경우 next가 존재하지 않는다.

```cpp
class CombinationIterator {
 private:
  int index = 0;
  vector<string> combinations;
  string str;
  // search all combinations using DFS
  void recursive(string &cur, int length, int index) {
    if (cur.length() == length) {
      combinations.push_back(cur);

      return;
    }
    if (index == str.length()) {
      return;
    }

    cur += str[index];
    recursive(cur, length, index + 1);
    cur.pop_back();
    recursive(cur, length, index + 1);
  }

 public:
  CombinationIterator(string characters, int combinationLength) {
    str = characters;
    string line = "";
    recursive(line, combinationLength, 0);
  }

  string next() {
    string ret = combinations[index];
    index++;
    return ret;
  }

  bool hasNext() { return index != combinations.size(); }
};
```

### bit masking

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

모든 cur의 원소에 대해서 비트 마스킹을 이용한다. (최대 15글자 까지이므로)

비트마스크에서 1의 개수가 combinationLength와 같은 경우들만 next가 호출될 때 반환하면 되며, 맨 앞글자부터 이용하기 위해 모든 비트가 1인 경우부터 탐색을 진행한다.

만약 cur의 길이가 5이고, combinationLength가 3인 경우는 다음 비트부터 시작한다.

```cpp
11100
```

이후 비트마스크를 업데이트 할 때 Gospel's hack 알고리즘을 이용해 바로 구할 수 있다.

이를 구현하면 다음과 같다.

```cpp
class CombinationIterator {
  string s;
  int n, length, mask = 0;
  bool has_next = true;

 public:
  CombinationIterator(string s, int n) {
    this->s = s;
    this->n = n;
    this->length = s.length();
    mask = (1 << n) - 1 << (length - n);
  }

  string next() {
    string combination = "";
    for (int index = length - 1; index >= 0; index--) {
      if (mask & 1 << index) {
        combination += s[length - 1 - index];
      }
    }
    updateMask();
    return combination;
  }
  // using Gospel's hack
  void updateMask() {
    int t = mask + 1, u = t ^ mask, v = t & mask;

    mask = v - (v & -v) / (u + 1);
    has_next = mask != 0;
  }

  bool hasNext() { return has_next; }
};
```

## 고생한 점
