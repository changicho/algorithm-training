# 1218. Longest Arithmetic Subsequence of Given Difference

[링크](https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자. (N <= 10^5)

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다. 이는 제한시간 내에 불가능하다.

이전에 방문했던 숫자들로 끝나는 수열의 길이를 hash map을 이용해 저장해놓는다고 하자.

이를 이용해 현재 최대값을 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법 & hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     192      |    O(N)     |    O(N)     |

배열의 subArray 중에서 difference로 증가하는 순열 중 최대 길이를 찾아야 한다.

따라서 배열의 순서가 arr의 순서를 벗어나면 안되므로 현재까지 방문한 index에서는 index 이하의 값들만 사용해야 한다.

이전에 방문했던 숫자들로 끝나는 수열의 길이를 hash map을 이용해 저장해놓는다고 하자.

이 경우 현재 값에서 difference를 뺀 값이 hash map에 존재한다면, 해당 값으로 끝나는 수열의 길이에 1을 더한 값이 현재 값으로 끝나는 수열의 길이가 된다.

만약 존재하지 않는 경우 현재 값으로 시작하고 끝나는 수열의 길이는 1이 된다.

이를 구현하면 다음과 같다.

```cpp
int longestSubsequence(vector<int>& arr, int difference) {
  int size = arr.size();
  unordered_map<int, int> counts;

  int answer = 1;

  for (int i = 0; i < size; i++) {
    int num = arr[i];

    if (counts.count(num - difference) > 0) {
      counts[num] = counts[num - difference] + 1;
    }

    counts[num] = max(counts[num], 1);
    answer = max(answer, counts[num]);
  }
  return answer;
}
```

## 고생한 점
