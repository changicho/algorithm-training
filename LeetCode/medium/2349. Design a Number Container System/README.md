# 2349. Design a Number Container System

[링크](https://leetcode.com/problems/design-a-number-container-system/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

연산의 횟수를 N이라 하자.

각 경우마다 숫자에 해당하는 최소 index를 찾아야 한다.

각 숫자에 대한 값을 빠르게 찾기 위해 hash_map을 사용할 경우 각 연산마다 O(1)의 시간 복잡도가 필요하다.

이를 매번 검색할 경우 O(N^2)의 시간 복잡도를 사용한다.

우선순위 큐를 사용할 경우 O(N \* log_2(N))의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

각 수 마다의 자료를 저장하는데 O(N)의 공간 복잡도가 필요하다.

각 경우마다 index의 최소값을 찾기 위해 우선순위 큐를 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### hash map & heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      87      | O(N \* log_2(N)) |    O(N)     |

각 index에 해당하는 숫자를 관리하며, 각 숫자마다의 index들을 힙으로 관리한다.

현재 index의 수를 변경할 때 마다 해당 숫자에 대한 index를 갱신한다.

이후 해당 숫자에 대한 index를 찾을 때, 해당 숫자에 대한 index들을 힙에서 낮은 순으로 순회하며 해당 숫자가 아닌 경우 pop을 수행한다.

```cpp
class NumberContainers {
 private:
  unordered_map<int, priority_queue<int, vector<int>, greater<int>>> indexes;
  unordered_map<int, int> i2num;

 public:
  NumberContainers() {}

  void change(int index, int number) {
    i2num[index] = number;
    indexes[number].push(index);
  }

  int find(int number) {
    while (!indexes[number].empty() && i2num[indexes[number].top()] != number) {
      indexes[number].pop();
    }

    if (indexes[number].empty()) {
      return -1;
    }
    return indexes[number].top();
  }
};
```

## 고생한 점
