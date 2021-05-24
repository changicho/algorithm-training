# 90. Subsets II

[링크](https://leetcode.com/problems/subsets-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 갯수를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이다.

이 때 중복된 경우를 제거해야 한다.

중복을 제거하기 위해 set을 이용할 경우 삽입에 O(log_2(N))의 시간 복잡도가 소요된다.

따라서 set을 이용할 경우 총 시간 복잡도는 O(2^N \* log_2(N)) 이다.

만약 hash set을 이용할 경우 set에 삽입하는데 O(1)의 시간 복잡도가 소요되므로 총 시간 복잡도는 O(2^N)이다.

중복을 제거하기 위해 정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

중복 이후에는 일반적인 탐색만 진행하면 되므로 총 시간 복잡도는 O(2^N) 이다.

### 공간 복잡도

set을 이용할 경우 중복된 경우를 미리 기록해야 한다. 따라서 공간 복잡도는 O(2^N)이 필요하다.

정렬을 이용할 경우 중복을 별도의 공간으로 체크하지 않는다. 따라서 O(1)의 공간 복잡도가 필요하다.

### set

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|      4       | O(2^N \* log_2(N)) |   O(2^N)    |

재귀호출로 모든 경우를 탐색하며 이 때 정답이 가능한 경우를 set에 저장해 중복을 제거한다.

```cpp
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  set<vector<int>> s;
  sort(nums.begin(), nums.end());
  vector<int> array;
  recursive(s, array, nums, 0);

  vector<vector<int>> answer;
  for (vector<int> v : s) {
    answer.push_back(v);
  }
  return answer;
}

void recursive(set<vector<int>> &s, vector<int> &array, vector<int> &nums, int index) {
  int size = nums.size();
  s.insert(array);

  for (int i = index; i < size; i++) {
    array.push_back(nums[i]);
    recursive(s, array, nums, i + 1);
    array.pop_back();
  }
}
```

### 정리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |   O(2^N)    |    O(1)     |

현재 index에서 다음 index로 넘어갈 때 중복되지 않은 숫자가 나올 때 까지 index를 증가시킨다.

```cpp
vector<vector<int>> subsetsWithDup(vector<int> &nums) {
  set<vector<int>> s;
  sort(nums.begin(), nums.end());
  vector<int> array;
  vector<vector<int>> answer;

  recursive(answer, array, nums, 0);

  return answer;
}

void recursive(vector<vector<int>> &answer, vector<int> &array, vector<int> &nums, int index) {
  int size = nums.size();
  answer.push_back(array);

  for (int i = index; i < size; i++) {
    array.push_back(nums[i]);
    recursive(answer, array, nums, i + 1);
    array.pop_back();

    while (i + 1 < size && nums[i] == nums[i + 1]) i++;
  }
}
```

## 고생한 점
