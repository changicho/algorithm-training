# 2981. Find Longest Special Substring That Occurs Thrice I

[링크](https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s의 길이를 N이라 하자.

순회를 이용해 풀이하며, 각 과정마다 만들 수 있는 sub string의 count를 증가시킨다.

이에 O(N^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 문자별로 길이에 따른 갯수를 저장해야 한다.

이에 O(N)의 공간 복잡도가 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |   O(N^2)    |    O(N)     |

문자열을 순회하며 특정 문자의 연속된 갯수를 센다. 

이후 각 문자별로 만들 수 있는 sub string을 길이별로 count를 증가한다.

이후 정답을 구한다.

```cpp
int maximumLength(string s) {
  int answer = -1;

  int dp[26][51] = {
      0,
  };

  char before = ' ';
  int count = 0;
  for (char &c : s) {
    if (before != c) {
      count = 0;
    }

    count++;
    before = c;

    for (int len = 1; len <= count; len++) {
      dp[c - 'a'][len]++;
    }
  }

  for (int c = 0; c < 26; c++) {
    for (int len = 1; len <= 50; len++) {
      if (dp[c][len] >= 3) {
        answer = max(answer, len);
      }
    }
  }
  return answer;
}
```

## 고생한 점
