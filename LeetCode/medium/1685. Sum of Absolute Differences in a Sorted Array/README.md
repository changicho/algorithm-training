# 1685. Sum of Absolute Differences in a Sorted Array

[링크](https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 10^5)

매번 직접 구할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

prefix sum, suffix sum을 이용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

반환할 정답 배열에 O(N)의 공간 복잡도를 사용한다.

prefix sum을 미리 구해놓을 경우 O(N)의 공간 복잡도를 사용한다.

입력받은 배열을 그대로 사용하고 각 순회마다 prefix sum을 구할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     102      |    O(N)     |    O(N)     |

현재 index를 i라 하자. nums는 정렬되어 있으므로 i 왼쪽에는 현재 값 이하이 수, i 오른쪽에는 현재 값 이상의 수들이 존재한다.

따라서 각 index마다의 다른 수들과의 절대값의 차이는 각 index 왼쪽부분의 합, 오른쪽 부분의 합을 이용해 바로 구할 수 있다.

- 현재 값과 왼쪽 부분에 속한 수를 곱한 값에서 왼쪽 부분의 합을 빼준다.
- 현재 값과 오른쪽 부분에 속한 수를 곱한 값에서 오른쪽 부분의 합을 빼준다.

이를 이용해 prefix sum, suffix sum을 구하고 순회하며 정답을 구할 수 있다.

```cpp
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
  int size = nums.size();

  vector<int> leftSums(size, 0);
  vector<int> rightSums(size, 0);
  for (int i = 0; i < size; i++) {
    if (i - 1 >= 0) leftSums[i] = leftSums[i - 1];
    leftSums[i] += nums[i];
  }
  for (int i = size - 1; i >= 0; i--) {
    if (i + 1 < size) rightSums[i] = rightSums[i + 1];
    rightSums[i] += nums[i];
  }

  vector<int> answer(size, 0);
  for (int i = 0; i < size; i++) {
    int leftCount = i;
    int rightCount = size - i - 1;

    if (i - 1 >= 0) {
      answer[i] += leftCount * nums[i] - leftSums[i - 1];
    }
    if (i + 1 < size) {
      answer[i] += rightSums[i + 1] - rightCount * nums[i];
    }
  }

  return answer;
}
```

### prefix sum (space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      85      |    O(N)     |    O(1)     |

위 방법에서 값의 갱신이 순차적으로 일어나므로 leftSum, rightSum을 갱신하며 정답을 구할 수 있다.

```cpp
vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
  int size = nums.size();

  int leftSum = 0;
  int rightSum = 0;
  for (int& num : nums) {
    rightSum += num;
  }

  for (int i = 0; i < size; i++) {
    int leftCount = i;
    int rightCount = size - i - 1;

    int curAnswer = 0;
    rightSum -= nums[i];

    if (i - 1 >= 0) {
      curAnswer += leftCount * nums[i] - leftSum;
    }
    if (i + 1 < size) {
      curAnswer += rightSum - rightCount * nums[i];
    }

    leftSum += nums[i];

    nums[i] = curAnswer;
  }

  return nums;
}
```

## 고생한 점
