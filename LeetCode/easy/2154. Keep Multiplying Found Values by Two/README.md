# 2154. Keep Multiplying Found Values by Two

[링크](https://leetcode.com/problems/keep-multiplying-found-values-by-two/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 원소의 갯수를 N이라 하자.

original이 배열 안에 없을 때 까지 이를 반복해야 한다.

이를 매번 순회를 통해서 original을 찾을 경우 O(N)의 시간 복잡도를 사용해야한다.

이를 최대 N번까지 반복할 수 있으므로 (original은 0 이상이므로) 모든 경우를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

정렬 혹은 hash set을 이용해 이를 최적화 할 수 있다.

정렬된 배열, hash set을 이용할 경우 O(1)의 시간 복잡도로 다음 original을 찾을 수 있다.

정렬을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

hash set을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬을 이용할 경우 별도의 공간 복잡도를 사용하지 않는다. O(1)

hash set을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(1)     |

original은 계속 2배씩 증가할것이다.

따라서 nums를 오름차순으로 정렬하고 앞에서부터 순차적으로 탐색할 경우,

기존에 탐색한 원소들은 자연스레 다음 후보군에서 빠지게 된다.

이를 이용해 구현하면 다음과 같다.

```cpp
int findFinalValue(vector<int>& nums, int original) {
  // sort to find next original in one pass
  sort(nums.begin(), nums.end());

  // iterate nums
  for (int& n : nums) {
    // if same, increase original
    if (n == original) original *= 2;
  }

  return original;
}
```

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      21      |    O(N)     |    O(N)     |

hash set에 모든 원소를 저장한다.

이후 original을 계속 증가시키며 hash set에 존재하는지를 판단한다.

```cpp
int findFinalValue(vector<int>& nums, int original) {
  // convert nums to hash set
  unordered_set<int> uniques(nums.begin(), nums.end());

  // increase original until not found
  while (uniques.count(original) > 0) {
    original *= 2;
  }

  return original;
}
```

## 고생한 점
