# 2411. Smallest Subarrays With Maximum Bitwise OR

[링크](https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

각 숫자를 비트로 변환 후 비트들의 갯수들을 계산할 수 있다. 비트 변환에 O(log_2(maximum))의 시간 복잡도를 사용하며 이는 O(1)이다. (32비트)

오른쪽부터 순회하며 슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 문제를 해결할 수 있다.

혹은 오른쪽부터 순회하며 필요한 비트가 나타나는 index를 기록해 사용할 경우 O(N)의 시간 복잡도로 문제를 해결할 수 있다.

### 공간 복잡도

각 비트를 저장하는데 O(1)의 공간 복잡도를 사용한다.

각 index마다 필요한 최대값을 저장하는데 O(N)의 공간 복잡도를 사용한다.

정답에 대한 공간 복잡도는 O(N)이다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      87      |    O(N)     |    O(N)     |

오른쪽 부터 순회하며 각 index에서 subarrray를 시작했을 때 필요한 xor 최대값을 구한다.

이후 오른쪽부터 슬라이딩 윈도우를 사용해 해당 index마다 최대값을 충족하는 윈도우의 길이를 구한다.

```cpp
vector<int> smallestSubarrays(vector<int>& nums) {
  int size = nums.size();
  vector<int> target(size);
  for (int i = size - 1, bit = 0; i >= 0; i--) {
    bit |= nums[i];

    target[i] = bit;
  }

  int bits[32] = {
      0,
  };

  function<int(void)> convert = [&]() {
    int bit = 0;
    for (int i = 0; i < 32; i++) {
      if (bits[i] > 0) {
        bit |= (1 << i);
      }
    }
    return bit;
  };

  vector<int> answer(size);
  for (int left = size - 1, right = size - 1; left >= 0; left--) {
    for (int i = 0; i < 32; i++) {
      if (nums[left] & (1 << i)) {
        bits[i]++;
      }
    }

    while (left < right && convert() == target[left]) {
      for (int i = 0; i < 32; i++) {
        if (nums[right] & (1 << i)) {
          bits[i]--;
        }
      }
      right--;
    }
    if (right < size - 1 && convert() != target[left]) {
      right++;
      for (int i = 0; i < 32; i++) {
        if (nums[right] & (1 << i)) {
          bits[i]++;
        }
      }
    }

    answer[left] = right - left + 1;
  }
  return answer;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(1)     |

오른쪽 부터 순회하며 필요한 비트가 나타나는 index를 기록한다.

이후 각 필요한 비트에 대해 가장 먼저 나타나는 index 중 가장 큰 값이 현재 subrray의 오른쪽 끝이 된다.

이를 이용해 길이를 구한다.

```cpp
vector<int> smallestSubarrays(vector<int>& nums) {
  int size = nums.size();

  vector<int> lastPositions(31, -1);
  vector<int> answer(size);
  for (int i = size - 1; i >= 0; --i) {
    int last = i;

    for (int bit = 0; bit < 31; ++bit) {
      if (!(nums[i] & (1 << bit))) {
        if (lastPositions[bit] != -1) {
          last = max(last, lastPositions[bit]);
        }
      } else {
        lastPositions[bit] = i;
      }
    }
    answer[i] = last - i + 1;
  }
  return answer;
}
```


## 고생한 점
