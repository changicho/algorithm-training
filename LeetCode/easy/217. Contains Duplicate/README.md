# 217. Contains Duplicate

[링크](https://leetcode.com/problems/contains-duplicate/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

기존에 원소를 순환하며 이전에 중복되는지를 찾아야한다. 이 순환을 하는데 O(N)의 시간 복잡도가 필요하다.

정렬을 이용해 중복된 원소들을 인접하게 해서 중복을 판단할 경우 정렬에 O(N \* log(N))의 시간 복잡도가 소요된다.

hash set 을 이용할 경우 한번의 순회로만 중복을 판단할 수 있으므로 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정렬을 수행할 경우 별도의 공간이 필요하지 않다.

hash set을 이용할 경우 숫자를 저장하므로 O(N)만큼의 공간 복잡도가 필요하다.

### 해쉬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |    O(N)     |    O(N)     |

방문한 숫자들을 저장해 중복 여부를 판별할 수 있다.

```cpp
bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> s;
  for (int num : nums) {
    if (s.find(num) != s.end()) return true;
    s.insert(num);
  }

  return false;
}
```

### 정렬

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|      28      | O(N \* log(N)) |    O(1)     |

정렬을 이용해 같은 크기의 숫자를 인접시켜 중복을 판별할 수 있다.

```cpp
bool containsDuplicate(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; i++) {
    if (nums[i] == nums[i + 1]) return true;
  }

  return false;
}
```

## 고생한 점
