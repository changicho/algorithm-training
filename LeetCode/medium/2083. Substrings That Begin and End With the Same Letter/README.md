# 2083. Substrings That Begin and End With the Same Letter

[링크](https://leetcode.com/problems/substrings-that-begin-and-end-with-the-same-letter/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도가 필요하다.

왼쪽부터 순회하며 이전에 나온 문자들을 저장해놓으면 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 문자마다 count할 경우 O(1)의 공간 복잡도가 필요하다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(1)     |

이전까지 나온 문자들의 갯수를 저장해놓는다.

이후 현재 문자로 시작하는 문자열의 갯수를 구할 때, 이전에 나온 문자들의 갯수를 이용한다.

```cpp
long long numberOfSubstrings(string s) {
  long long answer = 0;
  int counts[26] = {
      0,
  };

  for (char &c : s) {
    answer += counts[c - 'a'];
    counts[c - 'a']++;
  }
  return answer + s.size();
}
```

## 고생한 점
