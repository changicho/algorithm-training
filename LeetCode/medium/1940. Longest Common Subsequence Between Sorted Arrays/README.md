# 1940. Longest Common Subsequence Between Sorted Arrays

[링크](https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

arrays의 크기를 N, 각 array의 크기를 M이라 하자.

각 숫자의 범위는 0 ~ 100 이다.

카운팅 정렬을 이용해 각 숫자의 개수를 세는 경우 시간 복잡도는 O(N \* M)이다.

### 공간 복잡도

정답 배열에 O(M)의 공간 복잡도가 필요하다.

카운팅 정렬에 O(100)의 공간 복잡도가 필요하다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |  O(N \* M)  |    O(M)     |

각 배열의 원소들을 모두 카운팅한다.

이후 카운팅한 원소의 수가 N인 것들을 작은 순으로 정답 배열에 넣는다.

```cpp
vector<int> longestCommonSubsequence(vector<vector<int>> &arrays) {
  int size = arrays.size();
  vector<int> answer;

  int counts[101] = {
      0,
  };

  for (vector<int> &arr : arrays) {
    for (int &num : arr) {
      counts[num]++;
    }
  }

  for (int num = 0; num <= 100; num++) {
    if (counts[num] == size) answer.push_back(num);
  }
  return answer;
}
```

## 고생한 점
