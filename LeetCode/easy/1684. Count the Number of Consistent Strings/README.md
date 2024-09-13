# 1684. Count the Number of Consistent Strings

[링크](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열 allowed의 길이는 최대 26이다.

배열 words의 크기를 N, 각 문자열의 평균 길이를 M이라 하자.

각 문자열을 순회하며 불가능한 알파벳이 존재하는지 판단하는 데 O(N \* M)의 시간 복잡도가 필요하다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      39      |  O(N \* M)  |    O(1)     |

allowed에 포함된 알파벳을 체크배열에 표시한다.

이후 words의 word를 순회하며 불가능한 알파벳이 존재하는 경우 count하지 않는다.

```cpp
int countConsistentStrings(string allowed, vector<string> &words) {
  bool check[26] = {false};
  for (char &c : allowed) {
    check[c - 'a'] = true;
  }

  int answer = 0;
  for (string &word : words) {
    bool isFine = true;
    for (char &c : word) {
      if (check[c - 'a'] == false) isFine = false;
    }

    answer += isFine;
  }
  return answer;
}
```

## 고생한 점
