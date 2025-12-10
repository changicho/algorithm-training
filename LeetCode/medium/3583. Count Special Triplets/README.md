# 3583. Count Special Triplets

[링크](https://leetcode.com/problems/count-special-triplets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

hash map을 이용해 두번의 순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

값의 범위가 10^5로 제한되어 있으므로, 고정 길이 배열을 사용할 경우에도 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용하기 위해 O(N)의 공간 복잡도를 사용한다.

값의 범위가 10^5로 제한되어 있으므로, 고정 길이 배열을 사용할 경우 O(M)의 공간 복잡도를 사용한다. (M = 10^5)

### prefix suffix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     586      |    O(N)     |    O(M)     |

조건을 만족하는 i <= j <= k에 대해 탐색할 때 j를 기준으로 왼쪽 부분과 오른쪽 부분으로 나누어 생각할 수 있다.

왼쪽부터 순회하며 j이전까지와 j이후 index까지의 값의 갯수를 관리한다.

이를 이용해 현재 정답의 경우의 수를 갱신한다.

```cpp
int specialTriplets(vector<int>& nums) {
  const int MOD = 1e9 + 7;
  int leftCount[100001] = {
      0,
  };
  int rightCount[100001] = {
      0,
  };

  for (int& num : nums) {
    rightCount[num]++;
  }

  int answer = 0;
  for (int& num : nums) {
    rightCount[num]--;

    if (num * 2 <= 1e5) {
      long long count = leftCount[num * 2];
      count *= rightCount[num * 2];
      count %= MOD;

      answer += count;
      answer %= MOD;
    }

    leftCount[num]++;
  }
  return answer;
}
```

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     586      |    O(N)     |    O(N)     |

문제 조건에 따라 i < j < k를 만족하는 i, j, k에 대해 nums[i] = nums[j] \* 2 && nums[k] = nums[j] \* 2를 만족하는 경우의 수를 구해야 한다.

j를 순회하며 현재까지 prefix count와 suffix count를 구한다.

이후 각 nums[j]에 대해 만족하는 경우의 수를 구한다.

```cpp
int specialTriplets(vector<int> &nums) {
  int MOD = 1e9 + 7;

  int size = nums.size();

  unordered_map<int, int> rightCount;
  unordered_map<int, int> leftCount;
  for (int &num : nums) {
    rightCount[num]++;
  }
  int answer = 0;
  for (int &num : nums) {
    rightCount[num]--;

    int target = num * 2;

    if (leftCount.count(target) != 0 && rightCount.count(target) != 0) {
      long long cur = 1;
      cur *= leftCount[target];
      cur %= MOD;
      cur *= rightCount[target];
      cur %= MOD;

      answer += cur;
      answer %= MOD;
    }

    leftCount[num]++;
  }
  return answer;
}
```

## 고생한 점
