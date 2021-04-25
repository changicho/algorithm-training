# 39. Combination Sum

[링크](https://leetcode.com/problems/combination-sum/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

N을 숫자의 갯수, M을 target 값이라 하자

모든 경우를 탐색하는경우 최악의 경우 시간 복잡도는 N^M이다.

이는 숫자의 최소값이 1임이 보장되고 최악의 경우 M까지 더하는 데 M번을 더해야 하기 때문이다.

다만 문제에서 정답으로 가능한 수는 150 이하임이 보장된다.

### 공간 복잡도

## 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(N^M)    |    O(M)     |

완전 탐색을 수행하며 현재 배열의 합과 target의 차이가 0인 경우, 0 미만인 경우 탐색을 중지할 수 있다.

처음 candidates 배열을 편의상 정렬하고 사용한다.

이는 이후에 불가능한 조합이 나오는 경우를 빨리판단하기 위해서이다.

속도 최적화

- 차이를 통해 0인지 판단을 하면 되므로 target값을 전역으로 보관하고 있을 필요가 없다.
- reference를 넘겨 새로운 vector를 생성하지 않는다.
- 정답이 될 수 없는경우 탐색을 중지한다.

```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> ret;
  vector<int> numbers;

  sort(candidates.begin(), candidates.end());

  recursive(candidates, target, 0, numbers, ret);

  return ret;
}

void recursive(vector<int>& nums, int target, int index, vector<int>& numbers, vector<vector<int>>& results) {
  for (int i = index; i < nums.size(); i++) {
    if (target < nums[i]) {
      break;
    }
    if (target == nums[i]) {
      numbers.push_back(nums[i]);
      results.push_back(numbers);
      numbers.pop_back();

      break;
    }

    numbers.push_back(nums[i]);
    recursive(nums, target - nums[i], i, numbers, results);
    numbers.pop_back();
  }
}
```

### 백트래킹 - 정렬을 사용하지 않는 경우

위 방법과 동일하지만 정렬을 수행하지 않고 정답을 구할 수 있다.

이는 문제에서 요구하는 정답의 vector들이 꼭 정렬되어 있지 않아도 되기 때문이다.

```cpp
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<vector<int>> results;
  vector<int> prefix;

  recursive(candidates, target, 0, prefix, results);

  return results;
}

void recursive(vector<int>& nums, int target, int start, vector<int>& prefix, vector<vector<int>>& results) {
  for (int i = start; i < nums.size(); i++) {
    if (target == nums[i]) {
      prefix.push_back(nums[i]);
      results.push_back(prefix);
      prefix.pop_back();
    } else if (target - nums[i] > 0) {
      prefix.push_back(nums[i]);
      recursive(nums, target - nums[i], i, prefix, results);
      prefix.pop_back();
    }
  }
}
```

## 고생한 점
