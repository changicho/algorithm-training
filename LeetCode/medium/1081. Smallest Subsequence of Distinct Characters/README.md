# 1081. Smallest Subsequence of Distinct Characters

[링크](https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

모든 경우에 대해 탐색하며 정답으로 가능한 경우를 찾을 경우 시간 복잡도는 O(2^N)이다. 이는 제한시간 내에 불가능하다.

스택을 이용해 가장 유리한 경우를 탐색할 수 있다. 이 경우 한번의 순회로 정답을 찾을 수 있다.

따라서 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

스택에는 알파벳만을 저장할 경우 O(1)의 공간 복잡도를 사용한다.

### 스택 & 그리디

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

문자열 s에 존재하는 모든 알파벳의 수를 센다.

이후 왼쪽부터 순회하며 다음을 수행한다.

- 현재 알파벳의 count를 감소시킨다.
- 만약 이전까지 순회하며 현재 알파벳을 선택한 경우 스킵한다.
- 현재 알파벳을 선택한 뒤 스택에 존재하는 값들을 비교한다.
- 현재 알파벳보다 큰 값이 존재하고, 이후에 또 등장할 경우 pop한다.

이렇게 현재 채워넣을 수 있는 값들 중에서 가장 알파벳순으로 앞선 문자들을 선택해 정답을 생성한다.

```cpp
string smallestSubsequence(string s) {
  int counts[26] = {
      0,
  };
  bool choosen[26] = {
      0,
  };
  for (char &c : s) {
    counts[c - 'a']++;
  }

  string answer = "";
  for (char &c : s) {
    counts[c - 'a']--;
    if (choosen[c - 'a']) {
      continue;
    }
    choosen[c - 'a'] = true;

    while (!answer.empty() && answer.back() > c &&
            counts[answer.back() - 'a'] > 0) {
      choosen[answer.back() - 'a'] = false;
      answer.pop_back();
    }

    answer.push_back(c);
  }
  return answer;
}
```

## 고생한 점
