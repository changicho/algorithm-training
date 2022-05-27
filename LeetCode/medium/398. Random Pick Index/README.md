# 398. Random Pick Index

[링크](https://leetcode.com/problems/random-pick-index/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

pick 메소드에서 각 경우마다 target을 찾고 해당 index들 중 random하게 고를 경우 O(N)의 시간 복잡도를 사용한다.

이를 빠르게 찾기 위해 hash map을 이용해 O(1)의 시간 복잡도로 target에 접근할 수 있게 하고 index를 random하게 반환한다.

이 경우 constructor에서 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     245      |    O(N)     |    O(N)     |

각 target에 대한 index 배열을 hash map으로 설정한다.

이후 pick 메소드를 호출할 때 index들 중 아무거나 반환한다.

```cpp
class Solution {
 private:
  unordered_map<int, queue<int>> val2index;

 public:
  Solution(vector<int>& nums) {
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      val2index[nums[i]].push(i);
    }
  }

  int pick(int target) {
    int idx = val2index[target].front();
    val2index[target].pop();
    val2index[target].push(idx);

    return idx;
  }
};
```

## 고생한 점
