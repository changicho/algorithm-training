# 3097. Shortest Subarray With OR at Least K II

[링크](https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 목표 숫자를 K라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이므로 제한시간 내에 불가능하다.

슬라이딩 윈도우와 이분 탐색을 이용해 풀이할 수 있다.

이 경우 O(N \* log(N))의 시간 복잡도로 풀이가 가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

각 윈도우마다 비트의 갯수를 저장할 공간이 필요하다.

이에 O(1)의 공간 복잡도가 필요하다.

이분 탐색에 O(1)의 공간 복잡도가 필요하다.

### 이분 탐색 & 슬라이딩 윈도우

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     569      | O(N \* log(N)) |    O(1)     |

각 윈도우의 크기에 대해 이분 탐색을 수행한다.

이후 해당 크기의 윈도우가 조건을 만족하는지 검사한다.

```cpp
int convert(int bits[32]) {
  int number = 0;
  for (int bit = 0; bit < 32; bit++) {
    if (bits[bit] > 0) {
      number |= (1 << bit);
    }
  }
  return number;
}

bool check(vector<int>& nums, int target, int k) {
  int size = nums.size();
  int bits[32] = {0};

  for (int right = 0, left = right - k + 1; right < size; right++, left++) {
    for (int bit = 0; bit < 32; bit++) {
      if (nums[right] & (1 << bit)) {
        bits[bit]++;
      }
    }

    if (left - 1 >= 0) {
      for (int bit = 0; bit < 32; bit++) {
        if (nums[left - 1] & (1 << bit)) {
          bits[bit]--;
        }
      }
    }

    if (right >= k - 1 && convert(bits) >= target) {
      return true;
    }
  }
  return false;
}

int minimumSubarrayLength(vector<int>& nums, int k) {
  int size = nums.size();
  int left = 1, right = size + 1;
  int answer = -1;

  while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(nums, k, mid)) {
      answer = mid;

      right = mid;
    } else {
      left = mid + 1;
    }
  }

  return answer;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      30      |    O(N)     |    O(1)     |

위 방법에서 윈도우의 크기에 대해 슬라이딩 윈도우를 사용해 유효한지 검사했으므로,

슬라이딩 윈도우만을 사용해 유효한 윈도우를 탐색한다.

```cpp
int convert(int bits[32]) {
  int ret = 0;
  for (int bit = 0; bit < 32; bit++) {
    if (bits[bit] > 0) {
      ret |= (1 << bit);
    }
  }
  return ret;
}

int minimumSubarrayLength(vector<int>& nums, int k) {
  int size = nums.size();

  int answer = INT_MAX;

  int bits[32] = {0};
  for (int right = 0, left = 0; right < size; right++) {
    for (int bit = 0; bit < 32; bit++) {
      if (nums[right] & (1 << bit)) {
        bits[bit]++;
      }
    }

    while (left <= right && convert(bits) >= k) {
      answer = min(answer, right - left + 1);

      for (int bit = 0; bit < 32; bit++) {
        if (nums[left] & (1 << bit)) {
          bits[bit]--;
        }
      }
      left++;
    }
  }

  return answer == INT_MAX ? -1 : answer;
}
```

## 고생한 점
