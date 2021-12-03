# 1. Two Sum

[링크](https://leetcode.com/problems/two-sum/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 개수를 N이라 하자.

모든 원소를 순회해 정답이 될 수 있는 쌍을 찾는 경우 O(N^2)의 시간 복잡도를 사용한다.

만약 정렬 이후 이분탐색을 이용해 합이 target이 되는 경우를 찾을 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

hash map을 이용할 경우 한번의 순회를 통해 합이 target이 되는 경우를 찾을 수 있으므로 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

모든 원소를 순회하는 경우 별도의 저장 공간을 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

정렬을 이용할 경우 정렬 이후 원래 index의 순서가 뒤바뀌므로 index와 value를 같이 저장해 사용해야한다.

이를 저장할 O(N)의 공간이 필요하므로 O(N)의 공간 복잡도를 사용한다.

hash map을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     288      |   O(N^2)    |    O(1)     |

두 index first와 second를 순회하며 target이 되는 경우를 찾는다.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
  int size = nums.size();
  vector<int> answer = {0, 0};
  vector<pair<int, int>> array;

  for (int i = 0; i < size; i++) {
    array.push_back({nums[i], i});
  }

  sort(array.begin(), array.end());

  for (int i = 0; i < size; i++) {
    pair<int, int> cur = array[i];

    int value = cur.first;

    int left = i + 1, right = size;

    while (left < right) {
      int mid = left + (right - left) / 2;

      // lower case
      if (array[mid].first < target - value) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left >= size) continue;

    if (array[left].first + value == target) {
      answer = {cur.second, array[left].second};
      break;
    }
  }

  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      8       | O(N \* log_2(N)) |    O(N)     |

배열의 모든 원소에 대해서 다음 2가지 값을 가지는 데이터를 만들고 배열을 생성한다.

- index
- value

이후 해당 배열의 값들을 value에 대해서 오름차순으로 정렬한다.

이후 배열의 각 원소들을 순회하며 (target - value)의 값이 존재하는 지 검색한다.

이는 이분 탐색으로 구현이 가능하다. (정렬되어 있으므로)

이후 찾은 값의 index와 현재 index가 다른 경우 정답으로 반환한다.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
  int size = nums.size();
  vector<int> answer = {0, 0};
  vector<pair<int, int>> array;

  for (int i = 0; i < size; i++) {
    array.push_back({nums[i], i});
  }

  sort(array.begin(), array.end());

  for (int i = 0; i < size; i++) {
    pair<int, int> cur = array[i];

    int value = cur.first;

    int left = i + 1, right = size;

    while (left < right) {
      int mid = left + (right - left) / 2;

      // lower case
      if (array[mid].first < target - value) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    if (left >= size) continue;

    if (array[left].first + value == target) {
      answer = {cur.second, array[left].second};
      break;
    }
  }

  return answer;
}
```

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

다음과 같은 hash map을 생성한다.

- key : 값
- value : 마지막에 나온 index

배열의 각 원소를 순회한다.

이 때 target - value에 해당하는 key가 hash map에 존재하는 경우 현재 index와 해당 value를 정답으로 묶고 저장한다.

만약 없는 경우 hash map에 현재 index, value 쌍을 저장한다.

```cpp
vector<int> twoSum(vector<int>& nums, int target) {
  int size = nums.size();
  vector<int> answer = {0, 0};
  // hash_map<int, int> key : value of nums, value : index fo value of nums
  unordered_map<int, int> valueToIndex;

  for (int i = 0; i < size; i++) {
    // int first = nums[index];
    // int second = target - first
    // first + second = target
    int first = nums[i];
    int second = target - first;

    // if there are second in hash map
    if (valueToIndex.find(second) != valueToIndex.end()) {
      // answer = { index, hash_map[second] }
      answer[0] = i;
      answer[1] = valueToIndex[second];
      return answer;
    }

    // hash_map[first] = index;
    valueToIndex[first] = i;
  }

  return answer;
}
```

## 고생한 점
