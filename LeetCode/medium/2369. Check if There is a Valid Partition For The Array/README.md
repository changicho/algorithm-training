# 2369. Check if There is a Valid Partition For The Array

[링크](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자. (N <= 10^5)

각 index마다 방문 가능 여부를 체크하고 이를 이용해 탐색을 진행한다.

이 때 중복 여부를 체크하기 위해 동적 계획법 (메모이제이션)을 이용한다.

하나의 index에서 방문 가능한 index를 찾는데 O(1)의 시간 복잡도가 소요된다.

이를 모든 index에 대해 반복하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 index에 대해 방문 가능 여부를 체크해야 하므로 O(N)의 공간 복잡도가 필요하다.

최대 3개의 index를 방문 가능한 index로 설정할 수 있으므로 최적화 할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법 (bottom up, space optimized)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     216      |    O(N)     |    O(1)     |

현재 index에서 방문 가능한 다음 index 묶음을 nexts라고 하자.

방문 가능한 각 index마다 nexts를 탐색하며 방문 가능 여부를 체크한다.

이를 위해 모든 index에 대해 방문 가능 여부를 체크하고, 맨 마지막 index에 도달했을 때 방문 가능 여부를 반환할 수 있다.

여기서 사용하는 데이터는 다음 3개의 index에 해당하는 방문 가능 여부이다.

따라서 아래와 같은 방법으로 공간 복잡도를 최적화 할 수 있다.

- (현재 index + 1) % 3

이를 이용해 방문 여부를 체크하며 중복을 줄이고 정답을 구한다.

```cpp
vector<int> validNext(vector<int>& nums, int i) {
  int size = nums.size();
  vector<int> ret;
  if (i + 1 < size && nums[i] == nums[i + 1]) {
    ret.push_back(i + 1);
  }

  if (i + 2 < size) {
    if (nums[i] == nums[i + 1] && nums[i] == nums[i + 2]) {
      ret.push_back(i + 2);
    } else if (nums[i] + 1 == nums[i + 1] && nums[i + 1] + 1 == nums[i + 2]) {
      ret.push_back(i + 2);
    }
  }
  return ret;
}

bool validPartition(vector<int>& nums) {
  int size = nums.size();

  bool valid[3] = {
      false,
  };
  for (int next : validNext(nums, 0)) {
    valid[next % 3] = true;
  }
  for (int i = 0; i < size - 1; i++) {
    if (!valid[i % 3]) continue;
    valid[i % 3] = false;

    for (int next : validNext(nums, i + 1)) {
      valid[next % 3] = true;
    }
  }

  return valid[(size - 1) % 3];
}
```

## 고생한 점
