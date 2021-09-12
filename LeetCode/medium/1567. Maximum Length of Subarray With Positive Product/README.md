# 1567. Maximum Length of Subarray With Positive Product

[링크](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 경우를 탐색하 경우 range의 left, right에 대해서 모두 검색할 때 시간 복잡도는 O(N^2)가 된다.

이는 제한 시간 내에 불가능하다.

따라서 한번 순회를 하며 가능한 sub array의 곱이 양수가 되는 최대의 경우를 찾는다.

이 때의 시간 복잡도는 O(N)이다.

### 공간 복잡도

직전의 값만 필요하므로 O(1)의 공간 복잡도를 소요한다.

### prefix suffix

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     112      |    O(N)     |    O(1)     |

sub array의 모든 원소의 곱이 양수인지를 판단해야 한다.

만약 값으로 0이 나오는 경우는 기존까지의 값이 모두 초기화 된다. 따라서 해당 경우에는 값을 초기화 해줘야 한다.

음수가 두번 나오는 경우는 양수가 되며 이 값이 최대값이 될 수도 있다.

따라서 음수를 포함하는 경우마다 별도의 탐색을 진행하지 않고, 왼쪽에서부터 오른쪽에서 부터 탐색을 진행해 sub array들을 구한다.

```javascript
// 음수인 수를 minus라고 하자
[...left, minus, ...right];
```

해당 경우에서 가장 큰 product는 left혹은 right가 된다.

음수가 홀수번 나오는 경우 또한 마찬가지이다. (음수끼리 곱하면 양수가 되므로 결국 하나를 기준점으로 왼쪽 오른쪽이 나뉨)

음수가 짝수번 나오는 경우는 음수들을 곱하면 짝수가 되므로 sub array의 product가 정답의 후보가 될 수 있다.

따라서 left, right중 하나인 답을 구하기 위해서 정방향으로, 역방향으로 두번 순회해 정답을 구한다.

```cpp
int getMaxLen(vector<int> &nums) {
  int size = nums.size();

  int answer = 0;
  int temp = 0;
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (temp == 0) {
      count = 0;
      temp = 1;
    }
    temp = temp * (nums[i] == 0 ? 0 : (nums[i] > 0 ? 1 : -1));
    count += 1;

    if (0 < temp) {
      answer = max(answer, count);
    }
  }

  temp = 0;
  count = 0;
  for (int i = size - 1; i >= 0; i--) {
    if (temp == 0) {
      count = 0;
      temp = 1;
    }
    temp = temp * (nums[i] == 0 ? 0 : (nums[i] > 0 ? 1 : -1));
    count += 1;

    if (0 < temp) {
      answer = max(answer, count);
    }
  }

  return answer;
}
```

이를 one pass로 구현할 경우 다음과 같다.

```cpp
int getMaxLen(vector<int> &nums) {
  int size = nums.size();

  int answer = 0;
  int left = 0, right = 0;
  int leftCount = 0, rightCount = 0;

  for (int i = 0; i < size; i++) {
    int leftIdx = i, rightIdx = size - 1 - i;

    // left part
    if (left == 0) {
      leftCount = 0;
      left = 1;
    }
    left = left * (nums[leftIdx] == 0 ? 0 : (nums[leftIdx] > 0 ? 1 : -1));
    leftCount += 1;
    if (0 < left) answer = max(answer, leftCount);

    // right part
    if (right == 0) {
      rightCount = 0;
      right = 1;
    }
    right = right * (nums[rightIdx] == 0 ? 0 : (nums[rightIdx] > 0 ? 1 : -1));
    rightCount += 1;
    if (0 < right) answer = max(answer, rightCount);
  }

  return answer;
}
```

### dynamic programming one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     104      |    O(N)     |    O(1)     |

모든 수를 순회한다.

이 때 현재 숫자가 0이 되는 경우는, 0을 포함한 sub array는 정답이 될 수 없으므로 직전까지 순회하며 갱신했던 count를 초기화한다.

여기서 현재 subArray의 음수의 숫자를 함께 count하며, 현재 subArray의 제일 왼쪽에 있는 음수의 index또한 저장해 이용한다.

```cpp
int getMaxLen(vector<int> &nums) {
  int size = nums.size();
  int firstNegative = -1, zeroPosition = -1;
  int countNegative = 0, answer = 0;

  for (int i = 0; i < size; i++) {
    if (nums[i] < 0) {
      countNegative++;

      if (firstNegative == -1) firstNegative = i;
    }

    if (nums[i] == 0) {
      countNegative = 0;
      firstNegative = -1;
      zeroPosition = i;
      continue;
    }

    if (countNegative % 2 == 0) {
      answer = max(i - zeroPosition, answer);
    } else {
      answer = max(i - firstNegative, answer);
    }
  }

  return answer;
}
```

## 고생한 점
