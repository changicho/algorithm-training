# 1498. Number of Subsequences That Satisfy the Given Sum Condition

[링크](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 갯수를 N이라 하자.

특정 원소들을 이용해 만들 수 있는 모든 경우의 수를 구할 경우 O(2^N)의 시간 복잡도를 사용하며 이는 제한 시간 내에 불가능하다.

따라서 해당 원소를 포함하는 가능한 subSequence들의 갯수 (길이)를 구하고 이를 이용해 정답에 추가한다.

정렬을 이용해 가능한 subSequence에 포함되는 원소의 수를 빠르게 구할 수 있다.

이 경우 정렬에 O(N * log_2(N))의 시간 복잡도를 사용한다.

이후 각 원소마다 이분 탐색을 이용해 가능한 subSequence의 갯수를 구할 수 있다. 이 경우 O(N * log_2(N))의 시간 복잡도를 사용한다.

투 포인터를 이용해 가능한 subSequence의 갯수를 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

가능한 경우의 수를 구하기 위해 pow값들을 구해놓는다. 이에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 투 포인터

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     140      | O(N * log_2(N)) |    O(N)     |

현재 원소 num을 꼭 포함하며, num이 최소값인 subSequence의 최대 길이를 length라 하자.

이 경우 num을 제외한 나머지 원소들은 모두 num 이상의 값이다.

또한 최대값은 target - num 이하의 값이다.

따라서 subSequence에서 num을 포함하는 모든 경우에 대해서 정답에 추가할 수 있다.

이 경우 경우의 수는 2^(length - 1)이다.

값에 대한 탐색을 빠르게 하기 위해 정렬을 이용한다.

이후 투 포인터를 이용해 left, right 값의 합이 target 이하인 최대 길이의 subSequence를 찾는다.

```cpp
int numSubseq(vector<int>& nums, int target) {
  sort(nums.begin(), nums.end());

  int size = nums.size();
  int answer = 0;

  int pows[100001] = {
      0,
  };
  pows[0] = 1;
  for (int i = 1; i <= size; i++) {
    pows[i] = pows[i - 1] * 2;
    pows[i] %= MOD;
  }

  int left = 0, right = size - 1;
  while (left <= right) {
    if (nums[left] + nums[right] <= target) {
      // in range left ~ right, suqSequence must contain nums[left]
      // length is (right - left + 1) : count of (left ~ right)
      // the case of subsequence size is pow(length - 1)

      int length = right - left + 1;
      answer += pows[length - 1];
      answer %= MOD;
      left++;
    } else {
      right--;
    }
  }

  return answer;
}
```

## 고생한 점
