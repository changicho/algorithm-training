# 930. Binary Subarrays With Sum

[링크](https://leetcode.com/problems/binary-subarrays-with-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

prefix sum을 hash map에 저장하며 count할 경우 시간 복잡도는 O(N)이다.

슬라이딩 윈도우를 사용할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

hash map에 prefix sum을 저장할 경우 O(N)의 공간 복잡도가 필요하다.

슬라이딩 윈도우에 별도의 공간 복잡도를 사용하지 않는다.

### prefix sum & hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      43      |    O(N)     |    O(N)     |

nums를 왼쪽부터 순회하며 prefix sum을 구한다.

이후 현재 prefix sum에서 goal을 뺀 이전에 나온 prefix sum의 갯수만큼 정답에 더한다.

이후 현재 prefix sum의 갯수를 증가시킨다.

```cpp
int numSubarraysWithSum(vector<int>& nums, int goal) {
  unordered_map<int, int> counts;

  int answer = 0;
  counts[0] = 1;
  int sum = 0;
  for (int& num : nums) {
    sum += num;

    answer += counts[sum - goal];

    counts[sum]++;
  }
  return answer;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(1)     |

슬라이딩 윈도우를 사용해 현재 윈도우의 sum이 goal과 같을 때 까지 조정한다.

이 때 sum이 goal보다 많은 경우 왼도우의 left를 이동해야 한다.

이 때 left가 이동할 때마다 prefixZeros를 변화시킨다.

- left가 이동하며 0이 윈도우에서 사라지면 prefixZeros를 증가시킨다.
- left가 이동하며 1이 윈도우에서 사라지면 prefixZeros를 초기화한다.

현재 sum이 goal과 같은 경우 정답에 현재까지 나온 prefixZeros의 갯수를 더해야 한다.

이는 현재 subArray에서 앞에 붙은 0의 갯수 + 1개만큼 정답에 더해지기 때문이다.

```cpp
int numSubarraysWithSum(vector<int>& nums, int goal) {
  int size = nums.size();

  int answer = 0;
  int sum = 0;
  int prefixZeros = 0;

  for (int left = 0, right = 0; right < size; right++) {
    sum += nums[right];

    while (left < right && (nums[left] == 0 || sum > goal)) {
      if (nums[left] == 1) {
        prefixZeros = 0;
      } else {
        prefixZeros++;
      }

      sum -= nums[left];
      left++;
    }

    if (sum == goal) {
      answer += 1 + prefixZeros;
    }
  }

  return answer;
}
```

## 고생한 점
