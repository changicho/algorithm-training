# 18. 4Sum

[링크](https://leetcode.com/problems/4sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

숫자 배열의 크기는 최대 200이다. 4가지 숫자를 브루트 포스로 구하는 경우 탐색에 들어가는 시간 복잡도는 O(N^4) 이다. 이는 TL이 발생한다.

따라서 다음 두가지 방법을 이용해 풀이할 수 있다.

- 투 포인터 O(N^3)
- 두 영역으로 나눔 O(N^3)

### 공간 복잡도

정렬에 들어가는 시간 복잡도와 정답을 저장할 배열의 시간 복잡도가 소요된다.

- 정렬 : O(N)
- 해시 : O(N)

### 투 포인터

> set 사용 : 44ms, index로 중복 제거 : 12ms

first, second, third, fourth 네 index를 찾아야한다.

first, second를 브루트 포스로 탐색하며 고정하고 third, fourth를 투 포인터로 탐색해 정답을 찾을 수 있다.

이때 탐색에 들어가는 시간 복잡도는 O(N^3) 이다.

정답이 중복되는 경우를 다음 두가지 방법으로 막을 수 있다.

- set을 이용
- 연속되는 값이 같은 경우 건너뜀 (backtracking)

backtracking을 이용하는 경우가 더 빠르다.

```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> answers;
  int size = nums.size();
  sort(nums.begin(), nums.end());

  for (int first = 0; first < size - 3; first++) {
    // check duplicate
    if (first > 0 && nums[first] == nums[first - 1]) continue;
    // backtracking
    if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) break;
    if (nums[first] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target) continue;

    for (int second = first + 1; second < size - 2; second++) {
      // check duplicate
      if (second > first + 1 && nums[second] == nums[second - 1]) continue;
      // backtracking
      if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break;
      if (nums[first] + nums[second] + nums[size - 1] + nums[size - 2] < target) continue;

      int third = second + 1;
      int fourth = size - 1;

      while (third < fourth) {
        int sum = nums[first] + nums[second] + nums[third] + nums[fourth];

        if (sum == target) {
          answers.push_back({nums[first], nums[second], nums[third], nums[fourth]});

          third++;
          fourth--;
          // check duplicate
          while (third < fourth && nums[third] == nums[third - 1]) third++;
          while (third < fourth && nums[fourth] == nums[fourth + 1]) fourth--;
        } else if (sum < target) {
          third++;
        } else if (sum > target) {
          fourth--;
        }
      }
    }
  }

  return answers;
}
```

## 해시

> 96ms

결국 정답은 first, second, third, fourth 네 index를 찾아야한다.

여기서 first, second로 만들 수 있는 모든 합을 map에 저장한다.

이후 third, fourth를 브루트포스로 검색하며 더했을 때의 값이 이전 map에 저장되어있는지 확인한다.

이 때, index의 중복을 피해야 하므로 map에 저장할 때 index또한 같이 저장한다.

따라서 first, second, third, fourth 값에서 중복되는 index가 없도록 한다.

```cpp
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    set<vector<int>> s;
    map<int, vector<pair<int, int>>> m;

    for (int first = 0; first < nums.size() - 1; first++) {
      for (int second = first + 1; second < nums.size(); second++) {
        m[nums[first] + nums[second]].push_back({first, second});
      }
    }

    for (int third = 0; third < nums.size() - 1; third++) {
      for (int fourth = third + 1; fourth < nums.size(); fourth++) {
        int sum = nums[third] + nums[fourth];

        if (m.find(target - sum) == m.end()) {
          continue;
        }

        vector<pair<int, int>> parts = m[target - sum];

        for (pair<int, int> cur : parts) {
          if (isSame({third, fourth}, cur)) break;

          if (!isSame({third, fourth}, cur)) {
            vector<int> v = {nums[cur.first], nums[cur.second], nums[third], nums[fourth]};
            sort(v.begin(), v.end());
            s.insert(v);
          }
        }
      }
    }

    vector<vector<int>> answers;
    for (vector<int> cur : s) {
      answers.push_back(cur);
    }
    return answers;
  }
  bool isSame(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first == p2.first || p1.second == p2.second) {
      return true;
    }
    if (p1.first == p2.second || p2.first == p1.second) {
      return true;
    }
    return false;
  }
};
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      12      |

## 고생한 점
