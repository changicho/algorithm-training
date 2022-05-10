# 2261. K Divisible Elements Subarrays

[링크](https://leetcode.com/problems/k-divisible-elements-subarrays/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

subArray의 경우의 수를 탐색하는데, 시작 index, 끝 index 두 변수에 대해 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

각 과정에서 탐색하며 크기를 늘려가며 탐색할 때 현재 subArray의 원소의 값들을 hash set을 이용해 중복을 제거할 수 있다.

각 원소들이 p로 나누어 떨어지는 갯수가 k개 이상인지 확인하는 데 prefix sum을 사용할 경우 총 O(N)의 시간 복잡도를 사용한다.

subArray의 원소의 값을 유일하게 생성하는 데 직접 탐색할 경우 O(N)의 시간 복잡도를 사용하며, rolling hash 혹은 string으로 사용할 경우 O(1)의 시간 복잡도로 이전 값에서 현재 값을 생성할 수 있다.

따라서 총 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

hash set에 최대 경우의 수는 O(N^2)이다.

### prefix sum & hash

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     303      |   O(N^2)    |   O(N^2)    |

nums의 원소의 범위는 0 ~ 200 까지이다. 이는 char형식으로 나타낼 수 있다.

따라서 특정 subArray의 현재 형태를 string으로 관리하고, 이를 hash set의 key로 이용해 중복을 제거할 수 있다.

미리 prefixSum을 구해놓아 현재 범위에서 k, p에 대해서 정답인 경우로 O(1)의 시간 복잡도로 빠르게 판단할 수 있다.

각 subArray를 만들 수 있는 범위에 대해서 탐색하며, 정답을 구한다.

```cpp
int countDistinct(vector<int>& nums, int k, int p) {
  int size = nums.size();

  unordered_set<string> subArrays;

  vector<int> prefixSums(size + 1, 0);
  for (int i = 0; i < size; i++) {
    prefixSums[i + 1] = prefixSums[i] + (nums[i] % p == 0 ? 1 : 0);
  }

  for (int left = 0; left < size; left++) {
    string subArr = "";

    for (int right = left; right < size; right++) {
      if (prefixSums[right + 1] - prefixSums[left] > k) break;

      subArr.push_back(nums[right]);

      subArrays.insert(subArr);
    }
  }

  return subArrays.size();
}
```

### prefix sum & rolling hash

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     249      |   O(N^2)    |   O(N^2)    |

위 방법에서 key를 string으로 관리하지 않고 rolling hash를 이용해 int로 관리할 수 있다.

```cpp
int countDistinct(vector<int>& nums, int k, int p) {
  int size = nums.size();

  unordered_set<int> rollingHash;

  vector<int> prefixSums(size + 1, 0);
  for (int i = 0; i < size; i++) {
    prefixSums[i + 1] = prefixSums[i] + (nums[i] % p == 0 ? 1 : 0);
  }

  for (int left = 0; left < size; left++) {
    int curHash = 0;

    for (int right = left; right < size; right++) {
      if (prefixSums[right + 1] - prefixSums[left] > k) break;

      curHash = ((long long)curHash * 200 + nums[right]) % 10000000007;

      rollingHash.insert(curHash);
    }
  }

  return rollingHash.size();
}
```

## 고생한 점
