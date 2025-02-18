# 1910. Remove All Occurrences of a Substring

[링크](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s, part의 길이를 각각 N, M이라 하자.

스택을 이용해 비교하며 직접 문자열을 제거할 경우 O(N \* M)의 시간 복잡도가 필요하다.

KMP알고리즘을 이용해 문자열을 제거할 경우 O(N + M)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답 문자열에 O(N)의 공간 복잡도가 필요하다.

### 스택 & 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |  O(N \* M)  |    O(N)     |

스택을 이용해 현재까지 순회한 마지막 문자열이 part와 일치하는경우 이를 제거한다.

이후 다음 문자를 추가하며 다시 part와 일치하는지 검사한다.

```cpp
bool check(string &s, string &part) {
  if (s.size() < part.size()) return false;

  return s.substr(s.size() - part.size()) == part;
}

string removeOccurrences(string s, string part) {
  string answer = "";
  for (char &c : s) {
    answer.push_back(c);

    if (check(answer, part)) {
      answer.erase(answer.size() - part.size());
    }
  }
  return answer;
}
```

## 고생한 점
