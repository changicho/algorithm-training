# 136. Single Number

[링크](https://leetcode.com/problems/single-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기는 3 \* 10^4 이다.

시간 복잡도 O(N^2)의 방법을 사용할 경우 매우 크므로 제한시간 내에 불가능 할 수 있다.

따라서 다음과 같은 방법들을 사용한다.

- 정렬 : O(N \* log(N))
- set : O(N)
- xor : O(N)

### 공간 복잡도

각 경우별로 필요한 공간은 다음과 같다.

- 정렬 : O(N), 기존 배열을 이용
- set : O(N), N개의 공간이 필요함
- xor : O(1)

### 정렬

> 24ms

- 시간 복잡도 : O(N \* log(N))
- 공간 복잡도 : O(N)

숫자들을 임의의 순서대로 정렬한다.

현재 숫자가 index 번째라고 할 때 index - 1, index + 1 번째 숫자와 모두 다른 경우 이때가 정답이다.

주어지는 숫자 범위를 넘어서는 숫자를 양 끝에 추가해 index의 탐색을 일반화 한다.

```cpp
int singleNumber(vector<int>& nums) {
  nums.push_back(-30001);
  nums.push_back(30001);
  int size = nums.size();
  int answer = 0;
  sort(nums.begin(), nums.end());
  for (int i = 1; i < size - 1; i++) {
    if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) {
      answer = nums[i];
      break;
    }
  }

  return answer;
}
```

### set

> 32ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(N)

hash set을 이용하면 한번의 순회로 정답을 구할 수 있다.

그러나 이 경우 hash에 N개의 숫자들이 저장되어야 한다.

```cpp
int singleNumber(vector<int>& nums) {
  unordered_set<int> s;

  for (int num : nums) {
    if (s.find(num) != s.end()) {
      s.erase(num);
    } else {
      s.insert(num);
    }
  }

  return *s.begin();
}
```

### xor

> 16ms

- 시간 복잡도 : O(N)
- 공간 복잡도 : O(1)

xor 연산은 다음을 만족한다.

```cpp
a ^ a; // 0
a ^ 0; // a
0 ^ 0; // 0
(a ^ b) ^ c; // a ^ (b ^ c)
(a ^ a) ^ b; // b
(a ^ b) ^ a; // b
```

여기서 자기 자신과 xor을 하는 경우에는 0이 되기 때문에 nums의 모든 수에 대해서 xor을 수행할 경우 중복되지 않은 하나의 수만 남게 된다.

```cpp
int singleNumber(vector<int>& nums) {
  int answer = 0;
  for (int num : nums) {
    answer ^= num;
  }
  return answer;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      16      |

## 고생한 점
