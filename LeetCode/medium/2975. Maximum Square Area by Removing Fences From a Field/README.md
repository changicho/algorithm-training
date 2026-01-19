# 2975. Maximum Square Area by Removing Fences From a Field

[링크](https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

각 배열마다 만들 수 있는 선분 사이의 거리를 완전 탐색으로 구할 수 있다. 이에 O(N^2 + M^2)의 시간 복잡도를 사용한다.

이후 두 집합에서 공통된 값을 찾기 위해 각각의 원소를 확인하는데, 이 과정에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N^2 + M^2)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|     1909     | O(N^2 + M^2) | O(N^2 + M^2) |

시작선분과 끝선분이 존재하며 사이에 선분들이 존재한다.

사이 선분들은 제거가 가능하며, 가능한 선분의 조합으로 만들 수 있는 구간 사이의 크기를 모두 구한다.

이를 hFences, vFences에 대해 각각 수행한 뒤, 공통된 크기 중 최댓값을 구한다.

이 때 시작 선분과 끝 선분을 이용해서도 구간 크기를 구해야 한다.

```cpp
unordered_set<int> check(int limit, vector<int>& nums) {
  int start = 1;
  unordered_set<int> ret;
  ret.insert(limit - start);

  int size = nums.size();
  for (int i = 0; i < size; i++) {
    int num = nums[i];
    ret.insert(num - 1);
    ret.insert(limit - num);

    for (int j = i + 1; j < size; j++) {
      ret.insert(abs(nums[j] - nums[i]));
    }
  }
  return ret;
}

int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
  const int MOD = 1e9 + 7;

  unordered_set<int> hSet = check(m, hFences), vSet = check(n, vFences);

  int answer = -1;
  for (int num : hSet) {
    if (vSet.count(num) > 0) {
      answer = max(answer, num);
    }
  }
  if (answer == -1) return -1;
  return (long long)answer * answer % MOD;
}
```

## 고생한 점
