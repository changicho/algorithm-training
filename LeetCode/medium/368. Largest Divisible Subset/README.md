# 368. Largest Divisible Subset

[링크](https://leetcode.com/problems/largest-divisible-subset/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 수를 subset에 포함할 때 해당 수가 subset에서 가장 큰 수라고 가정하자.

이를 위해 수를 미리 정렬할 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

정렬된 수들에 대해 탐색을 진행하며 이전까지 숫자들에 가장 긴 subset의 길이를 미리 알고 있는 경우,

현재 수보다 작은 값들에 대한 subset을 탐색하며 현재 subset의 길이를 갱신할 수 있다.

이렇게 동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |   O(N^2)    |    O(N)     |

각 수들을 정렬할 경우 다음과 같은 방법을 사용할 수 있다.

- 현재 수를 포함하는 subset의 최대 길이를 구하고자 할 때 현재 수보다 작은 값들을 탐색하며 subset의 길이를 갱신한다.
- 이전 수들의 subset들의 최대 길이는 이미 구해져 있다.
- 따라서 현재 수화 이전 수가 나누어 떨어지는 경우 subset의 길이를 갱신할 수 있다.

subset의 최소 길이는 1 이므로 초기값은 1이 된다.

이 때 정답으로 배열을 반환해야 하므로 정답이 갱신될 때마다 해당 subset의 가장 큰 수의 index를 저장한다.

또한 각 수들의 subset의 최대 길이일 때의 직전 subset의 index를 저장한다.

이를 이용해 최대 길이를 구하고 index를 역으로 순회하며 정답 배열을 구한다.

```cpp
vector<int> largestDivisibleSubset(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  vector<int> dp(size, 1);
  vector<int> prevI(size, -1);

  int maxI = 0;
  for (int cur = 1; cur < size; cur++) {
    for (int before = 0; before < cur; before++) {
      if (nums[cur] % nums[before] == 0 && dp[cur] < dp[before] + 1) {
        dp[cur] = dp[before] + 1;
        prevI[cur] = before;

        if (dp[cur] > dp[maxI]) {
          maxI = cur;
        }
      }
    }
  }

  vector<int> answer;
  while (maxI >= 0) {
    answer.push_back(nums[maxI]);
    maxI = prevI[maxI];
  }

  reverse(answer.begin(), answer.end());
  return answer;
}
```

## 고생한 점
