# 2914. Minimum Number of Changes to Make Binary String Beautiful

[링크](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

그리디 알고리즘을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

연이은 문자열만 비교하는 그리디 알고리즘을 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

가장 최소 단위로 beautiful하게 만들 경우 해당 단위보다 큰 문자열들은 모두 beautiful 하다.

따라서 연이은 문자열만 비교하며 다른 경우에 대해서만 카운트를 증가시키면 된다.

이 때 i, i+1을 비교할 때 i가 짝수인 경우에만 비교하면 된다.

```cpp
int minChanges(string s) {
  int size = s.size();
  int answer = 0;
  for (int i = 0; i < size; i += 2) {
    if (s[i] != s[i + 1]) answer++;
  }
  return answer;
}
```

## 고생한 점
