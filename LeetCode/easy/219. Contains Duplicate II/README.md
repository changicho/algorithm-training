# 219. Contains Duplicate II

[링크](https://leetcode.com/problems/contains-duplicate-ii/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

같은 값이 있는지 비교하며 동시에 두 값의 index의 차이가 k 이하인지 검사해야한다.

브루트 포스 방법을 사용할 경우 O(N^2)의 시간 복잡도가 필요하며 N이 최대 10^5이므로 제한시간 내에 불가능하다.

같은 값들 끼리 묶었을 때 그 값들의 갯수를 M이라 하자.

거기서 index를 오름차순으로 정렬할 경우 index의 비교를 M번만 수행해 k 이하인지를 검사할 수 있다.

이를 모든 값들에 대해 수행할 경우 정렬에 O(N \* log_2(N))의 시간 복잡도가 필요하다.

이후 한번 순회를 통해 index들을 검사하는데 이에 O(N)의 시간 복잡도가 필요하다.

따라서 최종적으로 O(N \* log_2(N))의 시간 복잡도가 된다.

그 외에 hash set과 hash map을 이용하는 경우 한번의 순회를 통해 가까운 index들 끼리 비교가 가능하다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬시에 index들이 모두 다름이 보장되므로 stable하게 정렬할 필요가 없다.

정렬 시에는 최악의 경우 O(N)의 공간 복잡도가 필요하다.

정렬된 값들을 이용해 index들을 검사하므로 최종적으로 O(N)의 공간복잡도가 필요하다.

hash set과 hash map을 이용하는 경우 이전에 방문한 숫자들에 대한 값들을 저장한다. 따라서 이 경우에도 O(N)의 공간 복잡도가 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(N \* log_2(N)) |    O(N)     |

배열의 숫자들을 다음과 같은 값을 가지는 vector에 집어넣는다.

- 값
- index

이후 값에대해 먼저 정렬하고, 같은 값 내부에선 index에 따라 정렬한다.

이후 한번 순회하며 같은 값들 중에서 index의 차가 k 이하인 경우에 true를 반환한다.

이 때 같은 값들의 index의 비교는 정렬을 수행했기 때문에 인접한 두 값들의 차이가 최소인 경우들 이므로 한번의 순회로 k 이하인 경우를 찾을 수 있다.

```cpp
struct Number {
  int index, value;

  bool operator<(const Number& b) const {
    if (value != b.value) {
      return value < b.value;
    }
    return index < b.index;
  }
};

bool containsNearbyDuplicate(vector<int>& nums, int k) {
  vector<Number> numbers;
  int size = nums.size();
  for (int i = 0; i < size; i++) {
    numbers.push_back({i, nums[i]});
  }

  sort(numbers.begin(), numbers.end());

  for (int i = 0; i < size - 1; i++) {
    if (numbers[i].value != numbers[i + 1].value) continue;
    if (numbers[i + 1].index - numbers[i].index <= k) return true;
  }
  return false;
}
```

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(N)     |

현재 index에서 index - k - 1번째 까지 요소를 항상 set에 저장한다.

이후 순회하며 범위를 넘어가는 것들은 set에서 삭제하며, 현재 방문한 값이 set에 저장되어있는지 확인한다.

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  if (k == 0) return false;
  unordered_set<int> s;
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    if (s.find(nums[i]) != s.end()) return true;
    if (i >= k) {
      s.erase(nums[i - k]);
    }
    s.insert(nums[i]);
  }
  return false;
}
```

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(N)     |

set 방법과 유사하지만 삭제 연산을 수행하지 않는다.

값들을 순회하며 map에 현재 값의 index가 저장되어있는경우 (이전에 방문) 해당 index와 현재 index의 차이가 k이하인지 검사한다.

저장되어 있지 않은 경우 해당 값의 index를 현재 index로 갱신한다.

이 방법을 통해 값이 중복해서 나왔을 때 가장 가까운 index들 끼리 비교가 가능하다.

```cpp
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  unordered_map<int, int> m;
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k) {
      return true;
    }
    m[nums[i]] = i;
  }
  return false;
}
```

## 고생한 점
