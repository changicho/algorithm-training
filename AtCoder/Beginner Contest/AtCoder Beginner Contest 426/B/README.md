# B - The Odd One Out

[링크](https://atcoder.jp/contests/abc426/tasks/abc426_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

순회하며 하나만 존재하는 문자를 찾는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자의 수를 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

순회하며 각 문자의 갯수를 센 뒤 이 중 1개인 문자를 반환한다.

```cpp
auto solution(string &s) {
  int counts[26] = {
      0,
  };

  for (char &c : s) {
    counts[c - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (counts[i] == 1) {
      return (char)('a' + i);
    }
  }

  return 'a';
}
```

## 고생한 점
