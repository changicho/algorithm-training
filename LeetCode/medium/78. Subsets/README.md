# 78. Subsets

[링크](https://leetcode.com/problems/subsets/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 길이를 N이라고 할 때 모든 경우의 갯수는 2^N번이다.

subset을 생성할 때 시간복잡도는 O(N)이 소요되므로 중복을 제외한 subsets를 만드는 데 시간 복잡도는 O(N \* 2^N)이 소요된다.

### 공간 복잡도

하나의 subset을 임시로 만드는데 최대 O(N)의 공간 복잡도가 소요된다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(N \* 2^N) |    O(N)     |

재귀 호출에서 매 경우를 subset에 저장한다.

이는 매 경우 중복되지 않은 경우만 재귀호출로 넘기기 때문에 중복이 생기지 않기 때문이다.

```cpp
vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ret;
  vector<int> array;

  recursive(array, -1, nums, ret);
  return ret;
}

void recursive(vector<int> &array, int index, vector<int> &nums, vector<vector<int>> &answer) {
  answer.push_back(array);

  for (int i = index + 1; i < nums.size(); i++) {
    int num = nums[i];

    array.push_back(num);
    recursive(array, i, nums, answer);
    array.pop_back();
  }
}
```

### 비트마스킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(N \* 2^N) |    O(N)     |

결국 2^N개의 경우를 세야 하는 문제이며, 이는 비트마스킹으로 표현이 가능하다.

정답의 subset의 순서는 상관없으므로 비트마스킹을 이용해 모든 경우를 쉽게 탐색 가능하다.

```cpp
vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ret;

  int limit = pow(2, nums.size());

  for (int digit = 0; digit < limit; digit++) {
    vector<int> array;
    for (int i = 0; i < nums.size(); i++) {
      if (digit & (1 << i)) {
        array.push_back(nums[i]);
      }
    }
    ret.push_back(array);
  }

  return ret;
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       | O(N \* 2^N) |    O(N)     |

숫자를 순회하며 현재 숫자가 포함된 subset을 만들 때 이전 subset들에 현재 숫자를 추가하는 식으로 만들 수 있다.

```cpp
vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ret = {{}};

  for (int num : nums) {
    int size = ret.size();

    for (int i = 0; i < size; i++) {
      ret.push_back(ret[i]);
      ret.back().push_back(num);
    }
  }

  return ret;
}
```

## 고생한 점
