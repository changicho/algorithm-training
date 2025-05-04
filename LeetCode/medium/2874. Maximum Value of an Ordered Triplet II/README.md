# 2874. Maximum Value of an Ordered Triplet II

[링크](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

[2873. Maximum Value of an Ordered Triplet I](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/) 와 같은 문제

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 가진다. 이는 제한시간 내에 불가능하다.

미리 right max를 구한 뒤 한번 순회를 이용해 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 가진다.

혹은 한번의 순회로 각 값을 갱신하며 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

right max를 미리 구할 경우 O(N)의 공간 복잡도를 가진다.

혹은 각 값을 갱신하며 구할 경우 O(1)의 공간 복잡도를 가진다.

### right max

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

정답은 다음과 같이 이루어진다.

```cpp
(nums[i] - nums[j]) * nums[k]
```

각 index를 시작점으로 오른쪽에 있는 값들 중 가장 큰 값을 저장하는 배열을 생성한다.

해당 배열을 사용해 nums[k]를 빠르게 구할 수 있다.

nums[i]는 이전에 나온 최대값을 사용할 수 있다.

j에 대해 순회하면서 정답을 구한 뒤 nums[i]의 최대값을 갱신한다.

```cpp
long long maximumTripletValue(vector<int>& nums) {
  int size = nums.size();
  vector<int> rightMaxs(size, 0);
  rightMaxs[size - 1] = nums[size - 1];

  for (int i = size - 2; i >= 0; i--) {
    rightMaxs[i] = max(rightMaxs[i + 1], nums[i]);
  }
  long long answer = 0;
  long long beforeMax = nums[0];
  for (int i = 1; i < size - 1; i++) {
    long long cur = beforeMax - nums[i];

    answer = max(answer, cur * rightMaxs[i + 1]);

    beforeMax = max(beforeMax, (long long)nums[i]);
  }
  return answer;
}
```

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

위 방법에서 k에 대해 순회하며, 이전의 i, j에 대해서 최대값을 갱신해 정답을 구한다.

```cpp
long long maximumTripletValue(vector<int>& nums) {
  int size = nums.size();
  long long answer = 0;

  long long maximum = 0, diffMax = 0;

  for (int k = 0; k < size; k++) {
    answer = max(answer, diffMax * nums[k]);

    diffMax = max(diffMax, maximum - nums[k]);
    maximum = max(maximum, (long long)nums[k]);
  }
  return answer;
}
```

## 고생한 점
