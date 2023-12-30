# 1897. Redistribute Characters to Make All Strings Equal

[링크](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

words의 단어의 갯수를 N, 평균 길이를 L이라 하자.

각 단어들의 알파벳 수를 세고 이 갯수들이 N으로 나누어 떨어지는 경우 모두 같은 단어로 만들 수 있다.

이 경우 시간 복잡도는 O(N \* L)이다.

### 공간 복잡도

알파벳 갯수를 세는 데 O(1)의 공간 복잡도가 필요하다.

### counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      18      |  O(N \* L)  |    O(1)     |

각 단어들의 알파벳 수를 세고 이 갯수들이 N으로 나누어 떨어지는 경우 모두 같은 단어로 만들 수 있다.

이를 위해 모든 단어들의 알파벳 갯수를 센다.

```cpp
bool makeEqual(vector<string> &words) {
  int size = words.size();

  int count[26] = {
      0,
  };
  for (string &word : words) {
    for (char &c : word) {
      count[c - 'a']++;
    }
  }

  for (int i = 0; i < 26; i++) {
    int c = count[i];

    if (c % size != 0) return false;
  }
  return true;
}
```

## 고생한 점
