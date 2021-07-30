# 260. Single Number III

[링크](https://leetcode.com/problems/single-number-iii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 모든 원소의 개수를 N이라 하자.

모든 원소를 순회하며 count할 경우 시간 복잡도는 O(N)이다.

비트마스킹을 이용해 xor한 값을 이용할 경우 한번 순회해 중복된 값들을 무시할 수 있으므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

모든 원소에 대해 count를 수행할 경우 공간 복잡도는 O(N)이다.

비트마스킹을 이용할 경우 O(1)의 공간 복잡도고 풀이 가능하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

hash map을 이용해 count를 진행하고, count가 1인 두 수를 찾는다.

```cpp
vector<int> singleNumber(vector<int>& nums) {
  unordered_map<int, int> um;

  for (int& num : nums) {
    um[num] += 1;
    if (um[num] == 2) um.erase(num);
  }

  vector<int> ret;
  for (auto pair : um) {
    ret.emplace_back(pair.first);
  }

  return ret;
}
```

### bit mask

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

우선 한번의 순회를 통회 모든 수에 대한 xor연산을 수행한 비트마스크를 구한다.

이후 두 숫자 A와 B의 차이를 구하기 위해 해당 비트마스크를 이용한다.

비트 마스크는 A와 B를 xor한 값이다.

이 비트마스크에 해당 연산을 수행할 경우 A와 B에서 다른 가장 마지막 비트를 찾을 수 있다.

```cpp
int diff = (bitmask & -bitmask);
// 혹은
int diff = (bitmask & (bitmask - 1)) ^ bitmask;
```

해당 비트와 and연산을 했을 때 A, B둘중 하나의 값에서만 해당 비트를 가지고 있다.

이를 이용해 A와 B를 구할 수 있다.

이 때 해당 diff를 구하는 연산을 할 때 overflow가 일어날 수 있으므로 long으로 선언한다.

여기서 accumulate를 이용해 모든 수에 대한 비트연산을 수행할 수 있다.

```cpp
long bitmask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
// 두 방법은 모두 같다.
long bitmask = 0;
for (int& num : nums) {
  diff ^= num;
}
```

```cpp
vector<int> singleNumber(vector<int>& nums) {
  long bitmask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
  // long diff = 0;
  // for (int& num : nums) {
  //   diff ^= num;
  // }
  int diff = (bitmask & -bitmask);

  vector<int> rets = {0, 0};
  for (int& num : nums) {
    if ((num & diff) == 0) {
      rets[0] ^= num;
    } else {
      rets[1] ^= num;
    }
  }
  return rets;
}
```

## 고생한 점
