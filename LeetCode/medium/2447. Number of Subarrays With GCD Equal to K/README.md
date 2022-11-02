# 2447. Number of Subarrays With GCD Equal to K

[링크](https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

모든 subArray에 대해 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

이 때 각 subArray에 대해 탐색하며 gcd 값을 계산할 수 있으므로 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

subArray를 직접 탐색할 경우 별도의 추가 공간을 사용하지 않는다. 따라서 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |   O(N^2)    |    O(1)     |

subArray의 범위 left ~ right를 설정하고 해당 경우에 대해서 gcd를 계산한다.

이 때 첫 값을 subArray의 시작값으로 설정 후 각 값들과의 gcd를 연속해서 구한다.

- gcd(A, B, C)는 gcd(gcd(A, B), C)와 같음

이를 구현하면 다음과 같다.

```cpp
int subarrayGCD(vector<int>& nums, int k) {
  int size = nums.size();
  int answer = 0;

  for (int left = 0; left < size; left++) {
    int divisor = nums[left];
    for (int right = left; right < size; right++) {
      divisor = gcd(nums[right], divisor);

      if (divisor < k) break;
      if (divisor == k) {
        answer++;
      }
    }
  }

  return answer;
}
```

### gcd count

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      27      | O(N \* log_2(M)) |  log_2(M)   |

```cpp
int subarrayGCD(vector<int>& nums, int k) {
  int size = nums.size();
  int answer = 0;

  unordered_map<int, int> gcds;
  for (int i = 0; i < size; i++) {
    unordered_map<int, int> new_gcds;

    if (nums[i] % k == 0) {
      gcds[nums[i]]++;
      for (auto [prev_gcd, cnt] : gcds) {
        new_gcds[gcd(prev_gcd, nums[i])] += cnt;
      }
    }

    answer += new_gcds[k];
    swap(gcds, new_gcds);
  }
  return answer;
}
```

## 고생한 점
