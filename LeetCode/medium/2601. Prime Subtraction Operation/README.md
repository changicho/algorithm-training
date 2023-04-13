# 2601. Prime Subtraction Operation

[링크](https://leetcode.com/problems/prime-subtraction-operation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N, 소수를 구해야하는 1000까지의 범위를 P라 하자.

1000까지의 소수를 구하는 데 에라토스테네스의 채를 이용할 경우 O(P \* log_2(log_2(P)))의 시간 복잡도를 사용한다.

각 nums를 순회하며 직전 값 이상의 가장 작은 수를 만들기 위한 소수를 구하는데 이분 탐색을 사용할 경우 O(log_2(P))의 시간 복잡도를 사용한다.

이를 모두 반복할 경우 O(N \* log_2(P))의 시간 복잡도를 사용한다.

### 공간 복잡도

에라토스테네스의 채를 이용해 소수를 구하는 데 O(P)의 공간 복잡도를 사용한다.

### 에라토스테네스의 채 & 이분 탐색

| 내 코드 (ms) |               시간 복잡도               | 공간 복잡도 |
| :----------: | :-------------------------------------: | :---------: |
|      27      | O(N \* log_2(P) + P \* log_2(log_2(P))) |    O(P)     |

에라토스테네스의 채를 이용해 1000까지의 소수를 구한다.

이후 nums를 순회하며 직전 값 이상의 가장 작은 수를 만들기 위한 소수를 이분 탐색으로 구한다.

이는 최대한 현재 수를 작게 만들어야 이후 수들에 대해 오름차순으로 만들기 유리하기 때문이다.

이후 배열이 실제로 오름차순인지 확인한다.

```cpp
bool isNotPrime[1001];
vector<int> primes;

void init() {
  isNotPrime[1] = true;

  for (int i = 2; i <= 1000; i++) {
    if (isNotPrime[i]) continue;

    for (int j = 2; i * j <= 1000; j++) {
      isNotPrime[i * j] = true;
    }
  }

  for (int i = 2; i <= 1000; i++) {
    if (!isNotPrime[i]) primes.push_back(i);
  }
}

// maximum prime lower than target
int pickPrime(int target) {
  int left = 0, right = primes.size();

  int ret = -1;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (primes[mid] < target) {
      // pick right
      ret = primes[mid];
      left = mid + 1;
    } else {
      // pick left
      right = mid;
    }
  }
  return ret;
}

bool primeSubOperation(vector<int>& nums) {
  init();

  int size = nums.size();

  for (int i = 0; i < size; i++) {
    int before = (i - 1) < 0 ? 0 : nums[i - 1];

    int target = pickPrime(nums[i] - before);

    if (target == -1) continue;
    nums[i] -= target;
  }

  for (int i = 0; i < size - 1; i++) {
    if (nums[i] >= nums[i + 1]) return false;
  }
  return true;
}
```

## 고생한 점
