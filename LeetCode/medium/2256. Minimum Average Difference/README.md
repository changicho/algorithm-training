# 2256. Minimum Average Difference

[링크](https://leetcode.com/problems/minimum-average-difference/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 index에 대해 leftSum과 rightSum을 직접 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

prefix sum을 이용해 각 index마다 sum을 미리 구해놓을 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 미리 모두 구해놓을 경우 O(N)의 시간 복잡도를 사용한다.

각 index를 순회하며 합을 구할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     118      |    O(N)     |    O(1)     |

왼쪽에서부터 1 ~ N개의 원소를 고르고 평균의 차이의 절대값을 구해야 한다.

이 때 왼쪽부터 1개 이상을 고를 수 있으나, 오른쪽부터 0개를 고를 수 있음에 유의한다.

모든 수의 합을 미리 구하고 왼쪽부터 순회하며 leftSum에 더한다.

모든 합에서 leftSum을 뺀 값이 오른쪽의 sum이므로 이를 이용해 평균의 절대값의 차이를 계산한다.

이를 구현하면 다음과 같다.

```cpp
int minimumAverageDifference(vector<int>& nums) {
  int size = nums.size();
  long long leftSum = 0, rightSum = 0;
  for (int& num : nums) {
    rightSum += num;
  }

  long long minimum = rightSum;
  int answer = 0;
  for (int i = 0; i < size; i++) {
    leftSum += nums[i];
    rightSum -= nums[i];

    long long cur;
    if (i == size - 1) {
      cur = abs(leftSum / (i + 1));
    } else {
      cur = abs(leftSum / (i + 1) - rightSum / (size - (i + 1)));
    }

    if (cur < minimum) {
      minimum = cur;
      answer = i;
    }
  }

  return answer;
}
```

## 고생한 점
