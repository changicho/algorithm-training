# 918. Maximum Sum Circular Subarray

[링크](https://leetcode.com/problems/maximum-sum-circular-subarray/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)가 된다.

이는 제한시간 내에 불가능하다.

동적 계획법을 이용해 합이 최대인 subArray와 최소인 subArray를 O(N)의 시간 복잡도로 찾을 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

subArray의 합만 구하면 되므로 subArray들중 합이 최대인 경우와 최소인 경우를 구한다.

이 과정에서 별도의 배열이 필요하지 않고 상수개 만큼의 변수만 필요하다.

이 경우 공간 복잡도는 O(N)이다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |    O(N)     |    O(1)     |

subArray의 부분 배열 중 최대 값, 최소 값의 경우는 다음과 같이 구할 수 있다.

0부터 i까지의 부분배열을 다음 두 파트로 나누어 생각할 수 있다.

```javascript
[...array1, ...array2];
```

최대합을 가지는 부분 배열을 구하는 것을 생각하자.

만약 array1이 합이 최대인 부분배열인 경우 array2가 시작하는 부분부터 부분합은 감소할것이다. (array2의 총 합은 음수)

만약 array2가 합이 최대인 부분배열인 경우 array2가 시작하는 부분부터 부분합이 증가할 것이다. (array1의 총 합은 음수)

이를 이용해 부분합이 0미만으로 바뀌는 지점에서 다시 탐색해 합이 최대인 부분배열을 구할 수 있다.

이는 최소합을 가지는 부분 배열을 구할 때도 마찬가지이다.

```cpp
// 최대 부분합을 구함
int getMaximumSum(vector<int> &nums) {
  int answer = nums.front();
  int sum = 0;

  for (int num : nums) {
    sum += num;
    answer = max(sum, answer);

    if (sum < 0) sum = 0;
  }

  return answer;
}

// 최소 부분합을 구함
int getMinimumSum(vector<int> &nums) {
  int answer = nums.front();
  int sum = 0;

  for (int num : nums) {
    sum += num;
    answer = min(sum, answer);

    if (sum > 0) sum = 0;
  }

  return answer;
}
```

정답에서 부분합이 연속된 경우 (시작점보다 끝점의 index가 큰 경우)는 getMaximumSum을 이용해 구할 수 있다.

부분합이 중간에 끊긴 경우 (시작점보다 끝점의 index가 작은경우)는 다음과 같이 생각할 수 있다.

```javascript
[...array1, ...minimumArray, array2];
```

입력받은 숫자 배열을 다음과 같이 나눴을 때, minimumArray부분을 제거한다면 합이 최대인 부분합을 구할 수 있다.

따라서 모든 수의 합에서 최소부분합을 제거해 정답을 구한다.

이 때 모든 부분합이 음수인 경우는 minimumArray가 nums와 동일하게 되므로 이 경우만 예외 처리한다.

```cpp
int maxSubarraySumCircular(vector<int> &nums) {
  int sum = getSum(nums);

  int maximum = getMaximumSum(nums);
  int minimum = getMinimumSum(nums);

  if (sum == minimum) return maximum;
  return max(maximum, sum - minimum);
}
```

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      86      |    O(N)     |    O(N)     |

정답을 다음과 같이 생각할 수 있다.

```javascript
[left, ... ,right];
```

즉 정답에 포함되는 left 파트와 right 파트가 존재하고 중앙에 정답에 포함되지 않는 구간이 존재한다.

따라서 left prefix sum과 right prefix sum을 구하고 i에 대해 순회하며 이를 갱신한다.

```cpp
int maxSubarraySumCircular(vector<int> &nums) {
  int size = nums.size();
  vector<int> prefixSums(size + 1, 0);
  vector<int> leftMaxs(size, 0), rightMaxs(size, 0);

  for (int i = 0; i < size; i++) {
    prefixSums[i + 1] = prefixSums[i] + nums[i];
  }

  leftMaxs[0] = nums[0];
  for (int i = 1; i < size; i++) {
    leftMaxs[i] = max(prefixSums[i + 1], leftMaxs[i - 1]);
  }
  rightMaxs[size - 1] = nums[size - 1];
  for (int i = size - 2; i >= 0; i--) {
    rightMaxs[i] = max(prefixSums.back() - prefixSums[i], rightMaxs[i + 1]);
  }

  int answer = nums.front();
  int temp = 0;
  for (int &num : nums) {
    if (temp < 0) temp = 0;
    temp += num;

    answer = max(answer, temp);
  }

  for (int i = 0; i < size - 1; i++) {
    answer = max(answer, leftMaxs[i] + rightMaxs[i + 1]);
  }

  return answer;
}
```

## 고생한 점
