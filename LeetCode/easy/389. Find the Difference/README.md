# 389. Find the Difference

[링크](https://leetcode.com/problems/find-the-difference/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이를 L이라 하자.

두 문자열을 정렬 후 투 포인터를 이용해 순차적으로 순회해 추가된 문자를 구할 수 있다.

이 경우 O(L \* log_2(L))의 시간 복잡도를 사용한다.

각 문자 count를 이용해 추가된 문자를 찾을 수 있다.

이 경우 O(L)의 시간 복잡도를 사용한다.

bit 연산 (XOR)을 이용해 풀이할 경우 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬의 경우 별도의 공간 복잡도를 사용하지 않는다.

count를 할 경우 hash map에 O(26)의 공간 복잡도를 사용한다. 이는 O(1)이다.

bit연산의 경우 O(1)의 공간 복잡도를 사용한다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(L)     |    O(1)     |

두 문자열의 각 문자들을 순회하며 count한 뒤 알파벳 소문자를 순회하며 갯수가 다른 알파벳을 찾는다.

```cpp
char findTheDifference(string s, string t) {
  int length = s.length();

  unordered_map<char, int> countS, countT;
  for (char &c : s) {
    countS[c]++;
  }
  for (char &c : t) {
    countT[c]++;
  }

  for (char c = 'a'; c <= 'z'; c++) {
    if (countS[c] < countT[c]) return c;
  }
  return 'a';
}
```

### 정렬 & 투포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      7       | O(L \* log_2(L)) |    O(1)     |

정렬 이후 투 포인터를 이용해 순차적으로 순회한다.

이 때 두 index의 문자가 다른경우 t의 해당 문자를 반환한다.

```cpp
char findTheDifference(string s, string t) {
  sort(s.begin(), s.end());
  sort(t.begin(), t.end());
  // use two pointer
  int length = s.length();

  int idxS = 0, idxT = 0;

  while (idxS < length && idxT < length + 1 && s[idxS] == t[idxT]) {
    idxS++;
    idxT++;
  }

  return t[idxT];
}
```

### XOR

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(L)     |    O(1)     |

두 문자열은 글자 하나만 다르고 나머지는 같다.

따라서 xor연산을 모든 글자에 대해서 수행하는 경우 추가된 하나의 문자만 남는다.

```cpp
char findTheDifference(string s, string t) {
  int bit = 0;
  for (char &c : s) {
    bit ^= c;
  }
  for (char &c : t) {
    bit ^= c;
  }

  return (char)bit;
}
```

## 고생한 점
