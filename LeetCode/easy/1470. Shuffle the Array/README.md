# 1470. Shuffle the Array

[링크](https://leetcode.com/problems/shuffle-the-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 원소의 갯수를 N이라 하자. (N <= 500)

각 원소의 범위는 1 ~ 3,000까지의 정수이다.

원소를 한번씩 순회하며 원하는 곳에 배치할 수 있다. 이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

여분 공간을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

추가공간 없이 값의 범위를 이용해 계산할 경우 O(1)의 공간 복잡도를 사용한다.

### 추가 공간

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(N)     |

```cpp
vector<int> shuffle(vector<int>& nums, int n) {
  vector<int> ret;

  for (int i = 0; i < n; i++) {
    ret.push_back(nums[i]);
    ret.push_back(nums[n + i]);
  }

  return ret;
}
```

### 범위 변경

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

수의 범위가 매우 작으므로 이전값과 변경해야 하는 값을 같은곳에 저장해도 값이 훼손되지 않는다.

값을 순회하며 위치해야 하는 위치에 이전값과 겹치지 않는 값을 생성하고, 이후 이를 복원한다.

```cpp
vector<int> shuffle(vector<int>& nums, int n) {
  for (int i = 0; i < nums.size(); i++) {
    nums[i] *= 10000;
  }

  for (int i = 0; i < n; i++) {
    nums[2 * i] += nums[i] / 10000;
    nums[2 * i + 1] += nums[n + i] / 10000;
  }

  for (int i = 0; i < nums.size(); i++) {
    nums[i] %= 10000;
  }

  return nums;
}
```

## 고생한 점
