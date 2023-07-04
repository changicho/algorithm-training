# 137. Single Number II

[링크](https://leetcode.com/problems/single-number-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 숫자의 개수를 N이라 하자.

우선 모든 숫자를 순회해야 하므로 outer 시간 복잡도는 O(N)이다.

모든 숫자의 개수를 count하는 경우 시간 복잡도는 O(N)이다.

정렬을 이용할 경우 시간 복잡도는 O(N \* log_2(N))이다.

비트마스크를 이용할 경우 한번의 순회로 끝나므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 숫자의 개수를 count하는 경우 공간 복잡도는 O(N)이다.

정렬 혹은 비트마스크를 이용할 경우 별도의 공간이 필요하지 않으므로 공간 복잡도는 O(1)이다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

모든 숫자를 순회하며 hash map에 count를 증가시킨다.

이 때 hash set에 중복되지 않은 숫자만 남기고, 순회가 끝난 후에는 이 숫자를 반환한다.

```cpp
int singleNumber(vector<int>& nums) {
  unordered_map<int, int> m;
  unordered_set<int> s;

  for (int num : nums) {
    if (m[num] == 0) {
      m[num] += 1;
      s.insert(num);
    } else {
      s.erase(num);
    }
  }

  return *s.begin();
}
```

### bit mask

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

32개의 비트 각 자리수별로 각각 탐색하며, 모든 숫자를 한번씩 각 자리수별로 비교했을 때 3으로 나눴을 때 1번 나오는 비트를 정답에 추가한다.

이는 중복된 숫자가 3번씩 나오는것이 보장되기 때문에 각 자리별로 탐색할 경우, 유일한 하나의 숫자가 해당 자리(비트)에 존재한다면 count를 3으로 나눈 나머지는 1이 되기 때문이다.

```cpp
int singleNumber(vector<int>& nums) {
  int answer = 0;

  for (int i = 0; i < 32; i++) {
    int sum = 0;
    int mask = 1 << i;

    for (int num : nums) {
      if (num & mask) {
        sum++;
      }
    }

    if (sum % 3 == 1) {
      answer |= mask;
    }
  }

  return answer;
}
```

### bit operation

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

[설명 링크](https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers)

```cpp
int singleNumber(vector<int>& nums) {
  int one = 0, two = 0, three = 0;

  for (int num : nums) {
    two ^= one & num;
    one ^= num;

    three = ~(one & two);

    two &= three;
    one &= three;
  }

  return one;
}
```

혹은

```cpp
int singleNumber(vector<int>& nums) {
  int one = 0, two = 0, three = 0;

  for (int num : nums) {
    two |= one & num;
    one ^= num;

    three = one & two;

    one ^= three;
    two ^= three;
  }

  return one;
}
```

만약 중복된 숫자가 5번씩 나타나는 경우

```cpp
int singleNumber(vector<int>& nums) {
  int one = 0, two = 0, three = 0, four = 0;

  for (int num : nums) {
    three ^= two & one & num;
    two ^= one & num;
    one ^= num;

    four = ~(one & ~two & three);

    three &= four;
    two &= four;
    one &= four;
  }

  return one;
}
```

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      9       | O(N \* log_2(N)) |    O(N)     |

수를 정렬할 경우, 한번만 나오는 수는 양 옆의 두개의 수와 모두 다를것이다.

```cpp
int singleNumber(vector<int>& nums) {
  sort(nums.begin(), nums.end());

  int size = nums.size();

  for (int i = 0; i < size; i++) {
    bool leftDiff = false, rightDiff = false;
    if (i - 1 < 0) {
      leftDiff = true;
    } else {
      leftDiff = nums[i - 1] != nums[i];
    }
    if (i + 1 >= size) {
      rightDiff = true;
    } else {
      rightDiff = nums[i] != nums[i + 1];
    }

    if (leftDiff && rightDiff) {
      return nums[i];
    }
  }
  return 0;
}
```

## 고생한 점
