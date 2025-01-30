# 3223. Minimum Length of String After Operations

[링크](https://leetcode.com/problems/minimum-length-of-string-after-operations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

s의 각 알파벳을 세는데 O(N)의 시간 복잡도가 필요하다.

결과적으로 남는 알파벳의 갯수를 각 알파벳의 수를 이용해 구할 수 있으므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 알파벳의 수를 저장하는 데 O(1)의 공간 복잡도가 필요하다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(1)     |

각 알파벳의 수를 센다.

특정 알파벳의 수가 X라 했을 때 X가 홀수, 짝수인지 여부에 따라 남길 수 있는 문자의 수가 각각 다음과 같다.

- 짝수 : 2
- 홀수 : 1

따라서 각 알파벳의 수를 세고, 짝수인 경우 2를 더하고 홀수인 경우 1을 더한다.

이 때 갯수가 0인 경우는 무시한다.

```cpp
int minimumLength(string s) {
  int counts[26] = {
      0,
  };
  for (char &c : s) {
    counts[c - 'a']++;
  }
  int answer = 0;
  for (int i = 0; i < 26; i++) {
    if (counts[i] == 0) continue;

    if (counts[i] % 2 == 0)
      answer += 2;
    else
      answer++;
  }
  return answer;
}
```

## 고생한 점
