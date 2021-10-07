# 442. Find All Duplicates in an Array

[링크](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

문제에서 O(N)의 시간 복잡도로 해결하는것을 요구했으므로 O(N)이내에 해결해야 한다.

한번의 순회를 통해 중복된 값들을 찾아낼 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

중복을 확인하기 위한 별도의 hash를 사용할 경우 O(N)의 공간이 추가로 필요하다.

입력받은 nums를 이용해 해결할 경우 O(1)의 공간을 사용한다.

정답은 최대 O(N)이 될 수 있으므로 이를 이용하면 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      92      |    O(N)     |    O(N)     |

hash set을 이용해 중복된 요소의 경우 정답에 삽입한다.

중복된 값들만 정답에 삽입하면 되므로 (순서는 상관없음)

hash set에 있는 값인 경우 정답으로 추가한다.

```cpp
vector<int> findDuplicates(vector<int>& nums) {
  unordered_set<int> us;

  vector<int> answer;
  for (int& num : nums) {
    if (us.count(num) == 0) {
      us.insert(num);
    } else {
      answer.emplace_back(num);
    }
  }

  return answer;
}
```

### visited array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      52      |    O(N)     |    O(N)     |

문제 조건에서 배열의 숫자들은 N이하임이 보장된다.

따라서 모든 숫자들은 배열의 index로 치환이 가능하다.

따라서 각 숫자들을 순회하며 해당 값에 해당하는 index의 요소를 변화시키고 이를 이용한다.

이전에 방문한 값을 나타내기 위해 값을 변화할 때 음수로 변환한다.

이 때 이전에 나온 숫자에 해당하는 index값이 음수인 경우 (이전에 방문함) 이를 정답에 추가한다.

즉 순회할 때 값들을 숫자가 아닌 index로 취급한다.

```cpp
vector<int> findDuplicates(vector<int>& nums) {
  vector<int> answer;

  for (int& num : nums) {
    int absolute = abs(num);

    if (nums[absolute - 1] < 0) {
      answer.push_back(absolute);
    }

    nums[absolute - 1] = -nums[absolute - 1];
  }
  return answer;
}
```

## 고생한 점
