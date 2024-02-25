# A - Yay!

[링크](https://atcoder.jp/contests/abc342/tasks/abc342_a)

| 난이도 |
| :----: |
|  150   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 L이라 하자.

S를 순회하며 하나만 존재하는 문자열의 위치를 찾는다. 이에 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

알파벳 소문자들의 갯수를 저장하는데 O(1)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(L)     |    O(1)     |

S를 순회하며 각 알파벳의 갯수를 센다.

이후 갯수가 1개인 문자열의 위치를 찾아 반환한다.

```cpp
int solution(string &s) {
  int size = s.size();
  int counts[26] = {
      0,
  };

  for (char &c : s) {
    counts[c - 'a']++;
  }

  for (int i = 0; i < size; i++) {
    if (counts[s[i] - 'a'] == 1) return i + 1;
  }

  return size;
}
```

## 고생한 점
