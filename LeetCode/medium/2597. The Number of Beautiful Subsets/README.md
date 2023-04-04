# 2597. The Number of Beautiful Subsets

[링크](https://leetcode.com/problems/the-number-of-beautiful-subsets/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 20)

N이 크지 않으므로 가능한 모든 부분집합에 대해 판단할 수 있다.

이때 경우의 수는 2^N개가 된다.

각 경우마다 불가능한 경우는 백트래킹을 사용해 무시할 수 있다.

이 경우 시간 복잡도는 O(2^N)이다.

### 공간 복잡도

DFS를 이용해 모든 경우를 판단할 경우 call stack에 O(N)의 공간 복잡도를 사용한다.

각 수마다 사용했는지 여부를 판단하는데 O(1000)의 공간 복잡도를 사용한다.

### 완전 탐색 & 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     140      |   O(2^N)    |    O(N)     |

각 수별로 조합 가능한 모든 경우의 수는 2^N개이다.

이 중에서 모든수를 선택하지 않는 경우는 정답에서 제외한다.

각 수들이 중복될 수 도 있으며, 현재 선택한 수에서 K만큼 차이나는 수가 선택된 경우 해당 수는 선택이 불가능하다.

이를 이용해 백트래킹을 수행한다.

```cpp
int answer = 0;
vector<int> nums;
int k;

int visited[1001];

void recursive(int index) {
  if (index == nums.size()) {
    answer++;
    return;
  }

  // not pick cur
  recursive(index + 1);

  int num = nums[index];
  if ((num - k < 0 || visited[num - k] == 0) &&
      (num + k > 1000 || visited[num + k] == 0)) {
    visited[num]++;
    recursive(index + 1);
    visited[num]--;
  }
}

int beautifulSubsets(vector<int>& nums, int k) {
  this->nums = nums;
  this->k = k;

  recursive(0);

  return answer - 1;
}
```

## 고생한 점
