# 18. 4Sum

[링크](https://leetcode.com/problems/4sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자 배열의 크기는 최대 200이다. 4가지 숫자를 브루트 포스로 구하는 경우 탐색에 들어가는 시간 복잡도는 O(N^4) 이다. 이는 TLE가 발생한다.

정렬을 수행하면 투 포인터를 이용해 구할 수 있다. 투 포인터를 2개의 수에 대해 적용하고, 나머지 2개의 수는 브루트 포스를 통해 탐색한다.

이 경우 2개의 수를 정하는데 O(N^2), 남은 2개의 수를 정하는데 투 포인터로 O(N)의 시간 복잡도로 풀이가 가능하다.

따라서 O(N^3)의 시간 복잡도로 풀이가 가능하다.

두 영역으로 나누는 경우를 생각해보자.

4개의 수를 2개씩 쪼개 hash map에 합과 pair를 저장한다. 이 과정에 O(N^2)의 시간 복잡도를 사용한다. 이후 pair를 탐색하며 hash map에 현재 합과 더해서 target을 만들 수가 있는지 판단한다.

하나의 값마다 pair의 경우의 수는 최대 N^2개까지 생길 수 있다. 따라서 최악의 경우 시간 복잡도는 O(N^4)이므로 제한시간 내에 불가능하다.

### 공간 복잡도

정렬, 정답을 저장할 배열의 공간 복잡도가 필요하다.

정답을 담을 공간에 O(N)의 공간 복잡도를 사용한다.

정답에서 중복된 경우를 제거하기 위해 hash set을 사용할 수 있다. 이 경우 O(N)의 공간 복잡도를 사용한다.

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     151      |   O(N^3)    |    O(N)     |

first, second, third, fourth 네 index를 찾아야한다.

first, second를 브루트 포스로 탐색하며 고정하고 third, fourth를 투 포인터로 탐색해 정답을 찾을 수 있다.

정답이 중복되는 경우를 다음 두가지 방법으로 막을 수 있다.

- hash set을 이용
- 연속되는 값이 같은 경우 건너뜀 (backtracking)

backtracking을 이용하는 경우가 더 빠르다.

```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> answers;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  for (int idx1 = 0; idx1 < size - 3; idx1++) {
    // check duplicate
    if (idx1 > 0 && nums[idx1] == nums[idx1 - 1]) continue;
    // backtracking
    if ((long)nums[idx1] + nums[idx1 + 1] + nums[idx1 + 2] + nums[idx1 + 3] >
        target)
      break;
    if ((long)nums[idx1] + nums[size - 1] + nums[size - 2] + nums[size - 3] <
        target)
      continue;

    for (int idx2 = idx1 + 1; idx2 < size - 2; idx2++) {
      // check duplicate
      if (idx2 > idx1 + 1 && nums[idx2] == nums[idx2 - 1]) continue;
      long leftPart = nums[idx1] + nums[idx2];
      // backtracking
      if (leftPart + nums[idx2 + 1] + nums[idx2 + 2] > target) break;
      if (leftPart + nums[size - 1] + nums[size - 2] < target) continue;

      int idx3 = idx2 + 1;
      int idx4 = size - 1;

      while (idx3 < idx4) {
        long sum = leftPart + nums[idx3] + nums[idx4];

        if (sum == target) {
          answers.push_back({nums[idx1], nums[idx2], nums[idx3], nums[idx4]});

          idx3++, idx4--;

        } else if (sum < target) {
          idx3++;
        } else if (sum > target) {
          idx4--;
        }
        // check duplicate
        while (idx3 < idx4 && nums[idx3] == nums[idx3 - 1]) idx3++;
        while (idx3 < idx4 && nums[idx4] == nums[idx4 + 1]) idx4--;
      }
    }
  }

  return answers;
}
```

hash set을 이용해 정답의 경우 중복을 제거할 수 있다.

이 경우 hash set에 O(N)의 공간 복잡도를 사용하며, 다음과 같이 구현한다.

```cpp
struct VectorHash {
  size_t operator()(const std::vector<int>& v) const {
    std::hash<int> hasher;
    size_t seed = 0;
    for (int i : v) {
      seed ^= hasher(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};

unordered_set<vector<int>, VectorHash> hashSet;
```

## 고생한 점

테스트 케이스가 변경되어 4개의 수의 합이 int형을 넘어서는 경우가 발생했다.
