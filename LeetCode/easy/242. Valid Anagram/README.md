# 242. Valid Anagram

[링크](https://leetcode.com/problems/valid-anagram/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

아나그램의 경우 구성하고 있는 알파벳들의 종류와 각 갯수가 동일하다.

따라서 정렬, 혹은 count를 이용해 문제를 풀이할 수 있다.

이 경우 정렬에는 O(N \* log_2(N))의 시간 복잡도가 소요되며 count의 경우는 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

단어의 길이를 N이라 하자.

정렬의 경우 별도의 공간이 필요하지 않다.

count를 하는 경우 O(N)만큼의 공간이 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

첫번째 문자열을 순회해며 각 문자와 그 문자의 갯수를 count한다.

이후 두번째 문자열을 순회하며 count의 갯수를 줄여나간다.

만약 음수가 나오는 문자가 존재한다면 두 문자열은 서로 애너그램이 아니다.

```cpp
bool isAnagram(string s, string t) {
  if (s.length() != t.length()) return false;

  unordered_map<char, int> m;

  for (char c : s) {
    m[c] += 1;
  }

  for (char c : t) {
    m[c] -= 1;
    if (m[c] < 0) return false;
  }

  return true;
}
```

### sort

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(N \* log_2(N)) |    O(1)     |

두 문자열을 정렬한다.

두 문자열이 같으면 서로 애너그램이고 아니면 애너그램이 아니다.

```cpp
bool isAnagram(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());

  return s == t;
}
```

## 고생한 점
