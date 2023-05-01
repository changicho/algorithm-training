# 2336. Smallest Number in Infinite Set

[링크](https://leetcode.com/problems/smallest-number-in-infinite-set/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

add되는 숫자들의 갯수를 N, pop되는 숫자들의 갯수를 M이라 하자.

pop마다 양의 정수들 중에서 가장 작은 수를 찾아야 한다.

이미 add된 값이 없는 경우 minimum을 이동시키며 찾을 수 있으며 이는 O(1)의 시간 복잡도를 사용한다.

add되는 수가 minimum보다 작은 경우는 별도로 저장해놔야한다. 이 때 add된 값이 가장 작은값이 될 수 있다.

이를 위해 BST set을 이용한다. 이 경우 삽입에 O(log_2(N))의 시간 복잡도를 사용한다.

pop의 경우 또한 O(log_2(N))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O((N + M) \* log_2(N)) 이다.

### 공간 복잡도

set을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### set

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|      84      | O((N + M) \* log_2(N)) |    O(N)     |

add되는 숫자가 없다고 가정하자.

이 경우 minimum은 1 부터 시작하며 pop 될때마다 1씩 증가하게 된다.

add되는 숫자들 중에서 현재 minimum 이상의 값들은 아직 pop되지 않은 숫자이므로 무시할 수 있다.

만약 현재 minimum보다 작은 숫자의 경우는 별도로 저장해놓아야한다.

이후 pop 연산시에 별도로 저장된 수가 있는 경우 해당 수 중 가장 작은 값을 이용한다.

이 때 minimum값은 감소하지 않으므로 set에는 항상 현재 minimum보다 작은 수들만 존재한다.

이를 위해 set을 사용한다.

```cpp
class SmallestInfiniteSet {
 private:
  int start = 1;
  set<int> numSet;

 public:
  SmallestInfiniteSet() {}

  int popSmallest() {
    if (numSet.empty()) {
      int ret = start;
      start++;
      return ret;
    }
    int minimum = *numSet.begin();
    numSet.erase(minimum);
    return minimum;
  }

  void addBack(int num) {
    if (num >= start) return;

    numSet.insert(num);
  }
};
```

## 고생한 점
