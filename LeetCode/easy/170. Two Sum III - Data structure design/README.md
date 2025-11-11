# 170. Two Sum III - Data structure design

[링크](https://leetcode.com/problems/two-sum-iii-data-structure-design/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

추가되는 숫자의 갯수를 N이라 하자.

hash map을 이용해 판단할 경우 O(N)의 시간 복잡도로 두 수의 합이 특정 값이 되는지 판단 가능하다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      65      |    O(N)     |    O(N)     |

```cpp
class TwoSum {
 private:
  unordered_map<long, int> count;

 public:
  TwoSum() {}

  void add(int number) { count[number]++; }

  bool find(int value) {
    if (value % 2 == 0) {
      if (count.count(value / 2) > 0 && count[value / 2] >= 2) return true;
    }

    for (auto [key, val] : count) {
      long remain = value - key;
      if (remain == key) continue;

      if (count.count(remain)) return true;
    }

    return false;
  }
};
```

## 고생한 점
