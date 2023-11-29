# 1814. Count Nice Pairs in an Array

[링크](https://leetcode.com/problems/count-nice-pairs-in-an-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. nums의 값중 최대값을 M이라 하자.

각 수를 뒤집는 데 O(log_10(M))의 시간 복잡도가 소요된다. 이는 거의 O(1)이다.

각 수를 순회하며 해당 수와 뒤집은 수의 차이를 hash map에 저장한다.

순회마다 해당 diff를 이용해 정답을 갱신한다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      95      |    O(N)     |    O(N)     |

문제에서 주어진 조건식은 다음과 같다.

```cpp
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])

// it means
nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])
```

위 식에서 결국 현재 값으로 만들 수 있는 차이를 diff라 할 때, 다른 수들로 만들 수 있는 해당 diff 값이 몇개인지 세고 정답에 더하면 된다.

따라서 각 수를 순회하며 diff를 hash map에 count하고, 순회마다 정답을 갱신한다.

```cpp
const int MOD = 1e9 + 7;

int reverse(int num) {
  int result = 0;
  while (num > 0) {
    result = result * 10 + num % 10;
    num /= 10;
  }

  return result;
}

int countNicePairs(vector<int>& nums) {
  unordered_map<int, int> um;

  int answer = 0;
  for (int& num : nums) {
    int cur = num - reverse(num);

    answer += um[cur];
    answer %= MOD;

    um[cur]++;
  }

  return answer;
}
```

## 고생한 점
