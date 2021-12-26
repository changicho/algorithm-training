# 703. Kth Largest Element in a Stream

[링크](https://leetcode.com/problems/kth-largest-element-in-a-stream/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

삽입되는 모든 원소의 개수를 N, add연산의 개수를 M, 입력받은 수 k를 K라 하자.

매번 정렬을 수행할 경우 add연산에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

따라서 시간 복잡도는 O(M \* N \* log_2(N)) 이다.

K만큼의 크기를 가지는 힙을 이용할 경우 처음 원소를 저장하는데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 K번째가 될 수 있는 원소를 top으로 하는 min heap을 구성한 뒤 add연산이 있을 때마다 이를 갱신한다.

이 과정에 O(M \* log_2(K))의 시간 복잡도를 사용한다. 따라서 총 시간 복잡도는 O(N \* log_2(N) + M \* log_2(K)) 이다.

### 공간 복잡도

힙에 O(K)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      37      | O(N \* log_2(N) + M \* log_2(K)) |    O(K)     |

K개의 원소를 가지는 heap을 생성한다.

이 때 K번째로 큰 원소를 찾기 위해서 top에 가장 작은 숫자가 오는 min heap을 구성한다.

이는 새로운 수를 add할 때 top에 있는 숫자보다 큰 경우 이를 pop하고 새로 추가하면 새로운 K번째 큰 수를 구할 수 있기 때문이다.

이를 더 간소화하면 다음과 같다.

- 힙에 원소를 추가하고, K개보다 많이 있는 경우 K개까지 원소를 pop한다.
- 이는 add연산, constructor 모두 적용한다.

이를 구현하면 다음과 같다.

```cpp
class KthLargest {
 private:
  // store biggest k num
  priority_queue<int, vector<int>, greater<int>> minHeap;
  int k;

 public:
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for (int& num : nums) {
      minHeap.push(num);
    }

    while (minHeap.size() > k) {
      minHeap.pop();
    }
  }

  int add(int val) {
    minHeap.push(val);

    while (minHeap.size() > k) {
      minHeap.pop();
    }

    return minHeap.top();
  }
};
```

## 고생한 점
