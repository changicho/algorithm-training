# 2486. Append Characters to String to Make Subsequence

[링크](https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N, t의 길이를 M이라 하자.

s를 순회하며 t의 문자들이 존재하는지 비교할 수 있다.

이후 찾지 못한 수 만큼 뒤에 더하면된다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

index만을 저장하므로 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(1)     |

s에 존재하는 subsequence로 t에 존재하는 문자를 만들 수 있는 갯수를 센다.

여기서 결국에는 t의 prefix를 만들면 되므로 s를 순회하며 현재 t에서 찾아야 하는 문자를 찾을 때 마다 카운트해준다.

t에서 찾지 못한 문자의 수 만큼 s에 더한다.

```cpp
int appendCharacters(string s, string t) {
  int idx = 0;

  for (int i = 0; i < s.size() && idx < t.size(); i++) {
    if (s[i] == t[idx]) idx++;
  }

  return t.size() - idx;
}
```

## 고생한 점
