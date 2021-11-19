# 448. Find All Numbers Disappeared in an Array

[링크](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

N개의 수를 정렬 한 이후에 i번째와 i+1번째 수 중 빈 수를 채워넣어서 정답을 구할 수 있다.

이 경우 시간 복잡도는 O(N \* log_2(N))이다.

hash set을 이용해 1 ~ N까지의 수 중 배열에 없는 숫자만 고를 수 있다. 이 경우 시간 복잡도는 O(N)이다.

원소의 종류는 1 ~ N까지만 가능하며 빈 숫자가 있을 경우 해당 구간의 값은 다른 값과 중복될 것이다. 이를 이용해 위치해야만 하는 위치로 swap하며 이후 확인할 경우 one pass로 구현이 가능하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

hash set을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

one pass로 구현할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      64      | O(N \* log_2(N)) |    O(1)     |

원소들을 정렬한 후에 i, i+1번째 원소를 비교하고 빈 숫자를 정답에 삽입한다.

이 때 index가 첫번째, 마지막인 경우에 1 ~ N을 만족하지 않을 수 있으므로 별도로 추가해준다.

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
  // 1. sort nums
  sort(nums.begin(), nums.end());

  vector<int> answer;

  // 2. fill 1 ~ nums.front()
  if (nums.front() != 1) {
    for (int i = 1; i < nums.front(); i++) {
      answer.emplace_back(i);
    }
  }

  // 3. fill nums.front() ~ nums.back()
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] - nums[i - 1] == 1) continue;

    for (int num = nums[i - 1] + 1; num < nums[i]; num++) {
      answer.emplace_back(num);
    }
  }

  // 4. fill nums.back() ~ n
  if (nums.back() != nums.size()) {
    for (int i = nums.back() + 1; i <= nums.size(); i++) {
      answer.emplace_back(i);
    }
  }

  return answer;
}
```

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      96      |    O(N)     |    O(N)     |

hash set에 배열의 원소를 모두 삽입한다.

이후 1 ~ N까지 순회하며 hash set에 없는 숫자를 정답에 삽입한다.

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
  vector<int> answer;

  int size = nums.size();
  unordered_set<int> us;

  for (int& num : nums) {
    us.insert(num);
  }

  for (int num = 1; num <= size; num++) {
    if (!us.count(num)) {
      answer.push_back(num);
    }
  }

  return answer;
}
```

### 적합한 위치에 삽입하기

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      56      |    O(N)     |    O(1)     |

배열을 순회한다.

이 때 각 숫자가 올바른 위치에 있지 않은경우, 해당 위치의 숫자가 올바를 때까지 swap을 수행한다.

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer;
  for (int i = 0; i < size; i++) {
    int num = nums[i];

    // pass case : nums[num - 1] == num
    // swap until nums[num - 1] is pass case
    while (nums[num - 1] != num) {
      swap(nums[i], nums[num - 1]);
      num = nums[i];
    }
  }

  // count missing number
  for (int i = 1; i <= size; i++) {
    if (i != nums[i - 1]) answer.push_back(i);
  }

  return answer;
}
```

### 방문 숫자 체크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      56      |    O(N)     |    O(1)     |

숫자를 순회하며 해당 숫자가 원래 위치해야 할 위치의 값을 음수로 변경한다.

이를 모든 배열의 원소에 대해 진행할 경우 배열안에 존재하는 숫자들은 모두 음수가 된다.

따라서 이후 순회에서 양수인 수의 index를 정답에 삽입한다.

```cpp
vector<int> findDisappearedNumbers(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer;

  for (int& num : nums) {
    // set nums[num - 1] value to minus
    // if ith value is minus, it is in the nums
    nums[abs(num) - 1] = -abs(nums[abs(num) - 1]);
  }

  for (int i = 0; i < size; i++) {
    if (nums[i] > 0) {
      answer.push_back(i + 1);
    }
  }

  return answer;
}
```

## 고생한 점
