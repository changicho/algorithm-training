# 2501. Longest Square Streak in an Array

[링크](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 숫자들을 hash set에 삽입하고, 수를 순회하며 제곱수의 길이를 센다.

이 경우 제곱수를 순회하는데 최대 O(1)의 시간 복잡도를 사용하며, 이를 모든 수에 대해 반복하므로 O(N)의 시간복잡도를 순회에 사용한다.

(수의 범위가 작으므로)

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash set을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     250      |    O(N)     |    O(N)     |

각 수를 hash set에 저장한다.

이후 수를 순회하면서 해당 수의 제곱, 제곱... 을 탐색하며 최대 연속된 길이를 찾는다.

이 때 시작길이에서 더 증가하지 못한 경우는 정답을 갱신하지 않는다.

```cpp
int longestSquareStreak(vector<int>& nums) {
  int answer = -1;

  unordered_set<long> s;

  for (int& num : nums) {
    s.insert(num);
  }

  for (int num : s) {
    long sq = num;
    int length = 1;
    while (s.count(sq * sq) > 0) {
      sq *= sq;
      length++;
    }

    if (length > 1) {
      answer = max(answer, length);
    }
  }

  return answer;
}
```

## 고생한 점
