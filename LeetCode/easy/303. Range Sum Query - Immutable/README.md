# 303. Range Sum Query - Immutable

[링크](https://leetcode.com/problems/range-sum-query-immutable/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

원소의 개수를 N이라 하자.

배열의 range의 합을 구하는 데 브루트 포스를 사용할 경우 시간 복잡도는 O(N)이다.

부분합을 미리 구해 사용할 경우 시간 복잡도는 O(1) 이며 부분합을 구하는 데 O(N)의 시간 복잡도가 소요된다.

세그먼트 트리를 이용해 이를 최적화 할 수 있으며 이 때의 시간 복잡도는 O(log_2(N))이다.

이 때 초기에 세그먼트 트리를 생성하는 데 들어가는 시간 복잡도는 O(N \* log_2(N)) 이다.

### 공간 복잡도

부분합 배열과, 세그먼트 트리를 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### 부분합

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |    O(N)     |    O(N)     |

초기에 다음과 같은 부분합을 생성한다.

```cpp
sums[index]; // 0 ~ index - 1 번째 까지의 합
```

이를 이용해 left ~ right 구간의 부분 합을 구할 수 있다.

```cpp
sums[right + 1] - sums[left];
```

```cpp
class NumArray {
 private:
  vector<int> sums;

 public:
  NumArray(vector<int>& nums) {
    sums.push_back(0);
    for (int num : nums) {
      sums.push_back(sums.back() + num);
    }
  }

  int sumRange(int left, int right) {
    return sums[right + 1] - sums[left];
  }
};
```

### 세그먼트 트리

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      20      | O(N \* log_2(N)) |    O(N)     |

세그먼트 트리를 이용해 입력받은 배열의 부분합을 미리 구해놓는다.

이후 query마다 부분합을 이용해 값을 채운다.

```cpp
class NumArray {
 private:
  template <typename T>
  struct SegmentTree {
    int size;
    vector<T> arr;
    vector<T> tree;

    void init(vector<T> array) {
      size = array.size();

      arr = array;
      tree.resize(size * 4);

      init(1, 0, size - 1);
    }

    T operation(T x, T y) {
      return x + y;
    }

    int init(int node, int start, int end) {
      if (start == end) return tree[node] = arr[start];
      int mid = (start + end) / 2;

      return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
    }

    T query(int node, int start, int end, int left, int right) {
      if (right < start || end < left) return 0;
      if (left <= start && end <= right) return tree[node];

      int mid = (start + end) / 2;
      return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }

    T query(int left, int right) {
      return query(1, 0, size - 1, left, right);
    }
  };

  SegmentTree<int> segmentTree;

 public:
  NumArray(vector<int>& nums) {
    segmentTree.init(nums);
  }

  int sumRange(int left, int right) {
    return segmentTree.query(left, right);
  }
};
```

## 고생한 점
