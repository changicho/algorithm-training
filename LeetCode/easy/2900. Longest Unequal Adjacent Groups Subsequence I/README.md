# 2900. Longest Unequal Adjacent Groups Subsequence I

[링크](https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 words, groups의 크기를 N이라 하자.

순회를 이용해 직전 값들과 그룹이 다른지 비교할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      5       |    O(N)     |    O(N)     |

직전 값과 그룹이 다른지 같은지 비교하며 다른 경우 현재 값을 정답에 추가한다.

이후 직전 그룹의 값을 갱신한다.

```cpp
vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
  int size = words.size();

  vector<string> answer;

  int beforeG = -1;
  for (int i = 0; i < size; i++) {
    if (beforeG != groups[i]) {
      answer.push_back(words[i]);
      beforeG = groups[i];
    } else {
      continue;
    }
  }
  return answer;
}
```

## 고생한 점
