# 3346. Maximum Frequency of an Element After Performing Operations I

[링크](https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, nums의 값의 범위를 M이라 하자.

정렬 후 이분탐색을 사용할 수 있다. 이 떄 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 이분 탐색에 O(M \* log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + M) \* log_2(N))이다.

혹은 카운팅과 누적 합을 사용할 수 있다.

이에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

카운팅에 O(M)의 공간 복잡도를 사용한다.

### 정렬 & 이분 탐색

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     180      | O((N + M) \* log_2(N)) |    O(N)     |

nums의 범위를 minimum ~ maximum 으로 표현했을 때 정답의 후보는 minimum ~ maximum 사이의 값들이다.

따라서 해당 값들을 순회하며, 조건에 맞는 수들의 갯수와 해당 수들을 변화시켜 현재 수로 변경할 수 있는 수들의 갯수를 센다.

현재 값을 X라 할 때 (X - k) ~ (X + k) 범위에 속하는 수들을 센다.

또한 현재 X와 같은 수들의 갯수를 센다.

현재 범위에서 X와 동일하지 않은 수의 갯수를 구한 뒤, 해당 수들을 numOperations 개수만큼을 현재 수로 변경할 수 있다.

이를 이용해 현재 가능한 최대 빈도수를 갱신한다.

```cpp
int maxFrequency(vector<int>& nums, int k, int numOperations) {
  sort(nums.begin(), nums.end());

  int minimum = nums.front(), maximum = nums.back();

  int answer = 0;
  for (int num = minimum; num <= maximum; num++) {
    int rangeCount = upper_bound(nums.begin(), nums.end(), num + k) -
                      lower_bound(nums.begin(), nums.end(), num - k);

    int sameCount = upper_bound(nums.begin(), nums.end(), num) -
                    lower_bound(nums.begin(), nums.end(), num);
    int diff = rangeCount - sameCount;

    answer = max(answer, sameCount);
    answer = max(answer, sameCount + min(diff, numOperations));
  }
  return answer;
}
```

### 카운트 & 누적 합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |  O(N + M)   |    O(M)     |

위 방법에서 현재 X에 대해 이분 탐색을 이용해 구하던 수들을 누적합을 이용해 빠르게 구한다.

nums의 원소의 범위는 0 ~ 10^5 이므로 카운팅 배열과 누적합 배열을 선언한다.

```cpp
int maxFrequency(vector<int>& nums, int k, int numOperations) {
  int count[100001] = {
      0,
  };
  int minimum = INT_MAX;
  int maximum = INT_MIN;
  for (int& num : nums) {
    count[num]++;

    minimum = min(minimum, num);
    maximum = max(maximum, num);
  }

  int prefixSum[100001] = {
      0,
  };
  prefixSum[0] = count[0];
  for (int num = minimum; num <= maximum; num++) {
    prefixSum[num] += prefixSum[num - 1] + count[num];
  }

  int answer = 0;
  for (int num = minimum; num <= maximum; num++) {
    int rangeCount = prefixSum[min(num + k, maximum)] -
                      (num - k - 1 >= minimum ? prefixSum[num - k - 1] : 0);

    int sameCount = count[num];
    int diff = rangeCount - sameCount;

    answer = max(answer, sameCount);
    answer = max(answer, sameCount + min(diff, numOperations));
  }
  return answer;
}
```

## 고생한 점
