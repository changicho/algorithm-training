# 2270. Number of Ways to Split Array

[링크](https://leetcode.com/problems/number-of-ways-to-split-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 경우마다 모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

prefix sum을 이용해 미리 특정 구간 까지의 합을 구할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

위 prefixSum을 응용해 모든 수의 합을 구한 뒤 왼쪽부터 포인터를 이동하며 감소하며 풀이할 수 있다. 이 경우도 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

포인터 이동을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     172      |    O(N)     |    O(N)     |

prefixSum을 2개 선언한다.

- 왼쪽부터의 합
- 오른쪽 부터의 합

이후 index를 이동시키며 left subArray의 합이 right subArray의 합보다 큰 경우를 count한다.

이 때 양쪽 subArray의 원소는 최소 1개 이상이여야 한다.

```cpp
int waysToSplitArray(vector<int>& nums) {
  int size = nums.size();

  vector<long long> prefixSum(size + 1, 0), rPrefixSum(size + 1, 0);
  // prefixSum[i] = ~ nums[i-1]
  // rPrefixSum[i] = nums[i] ~
  for (int i = 0; i < size; i++) {
    int rI = size - 1 - i;

    prefixSum[i + 1] = prefixSum[i] + nums[i];
    rPrefixSum[rI] = rPrefixSum[rI + 1] + nums[rI];
  }

  int sameCount = 0;
  for (int i = 0; i < size - 1; i++) {
    if (prefixSum[i + 1] >= rPrefixSum[i + 1]) {
      sameCount++;
    }
  }
  return sameCount;
}
```

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     170      |    O(N)     |    O(1)     |

미리 원소들의 합을 구해놓는다.

이후 맨 왼쪽부터 순회하며 다음 연산을 수행한다.

- 현재 숫자를 합에서 뺀다.
- 현재 숫자를 새로운 합에 더한다.

이후 이 두 합을 비교해 정답인경우 count한다.

여기서 맨 마지막 숫자는 순회하지 않음에 유의한다. (subArray의 원소는 최소 1개 이상이여야 함)

```cpp
int waysToSplitArray(vector<int>& nums) {
  int size = nums.size();

  long long curSum = 0;
  long long beforeSum = 0;
  for (int& num : nums) {
    beforeSum += num;
  }

  int sameCount = 0;
  for (int i = 0; i < size - 1; i++) {
    curSum += nums[i];
    beforeSum -= nums[i];

    if (curSum >= beforeSum) sameCount++;
  }
  return sameCount;
}
```

## 고생한 점

sum의 범위가 int형을 초과할 수 있다.