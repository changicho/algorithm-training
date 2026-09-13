# 4035. Maximum Valid Split Positions I

[링크](https://leetcode.com/problems/maximum-valid-split-positions-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N, 최대값을 M이라 하자.

gcd연산에 O(log_2(M))의 시간 복잡도를 사용한다.

각 원소를 제거한 뒤 prefix, suffix를 이용해 정답을 구할 경우 O(N^2 \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix, suffix에 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색 & prefix + suffix

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     1454     | O(N^2 \* log_2(M)) |    O(N)     |

각 배열의 원소를 하나씩 삭제한 경우마다 prefix, suffix를 사용해 특정 index까지의 양 옆 부분의 gcd를 구한다.

이후 정답을 갱신한다.

```cpp
int maxValidSplits(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  for (int target = -1; target < size; target++) {
    vector<int> arr;
    for (int i = 0; i < size; i++) {
      if (i == target) continue;
      arr.push_back(nums[i]);
    }

    int aSize = arr.size();
    vector<int> prefix(aSize);
    vector<int> suffix(aSize);

    prefix[0] = arr[0];
    suffix[aSize - 1] = arr[aSize - 1];

    for (int i = 1; i < aSize; i++) {
      prefix[i] = gcd(arr[i], prefix[i - 1]);
      suffix[aSize - 1 - i] =
          gcd(arr[aSize - 1 - i], suffix[aSize - 1 - i + 1]);
    }

    int score = 0;
    for (int i = 0; i < aSize - 1; i++) {
      if (prefix[i] == suffix[i + 1]) score++;
    }

    answer = max(score, answer);
  }
  return answer;
}
```

## 고생한 점
