# 307. Range Sum Query - Mutable

[링크](https://leetcode.com/problems/range-sum-query-mutable/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

구간의 합을 매번 구할 경우 시간 복잡도는 O(N), 업데이트에 O(1)의 시간 복잡도가 소요된다.

이를 모든 쿼리(Q)에 대해 수행할 경우 최악의 경우 O(N \* Q)의 시간 복잡도가 소요되며 이는 제한시간 내에 불가능하다.

세그먼트 트리를 이용해 구간합을 최적화 할 수 있다.

이 경우 쿼리와 업데이트에 O(log_2(N))의 시간 복잡도를 사용하므로 O(Q \* log_2(N))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

세그먼트 트리를 생성하는데 O(N)의 공간이 필요하다.

### 세그먼트 트리

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     494      | O(log_2(N)) |    O(N)     |

세그먼트 트리는 구간에 대한 연산을 미리 구해놓고 업데이트마다 필요한 부분만 연산해 구간연산을 쉽게 구하는 방법이다.

배열의 각 값은 트리의 리프노드로, 루트 노드는 모든 값을 연산한 값으로 설정한다.

쿼리의 경우 range에 대해서 루트노드부터 순회하며 필요한 부분만 꺼내온다.

업데이트의 경우 range에 대해서 루트 노드부터 순회하며 필요한 부분만 업데이트한다.

세그먼트 트리를 다음과 같이 구현할 수 있다.

```cpp
struct SegmentTree {
  int size;
  vector<int> array;  // array value
  vector<int> tree;   // sumTree

  SegmentTree(vector<int> &nums) {
    size = nums.size();

    array = nums;
    tree.resize(size * 4);

    init(1, 0, size - 1);
  }

  int operation(int x, int y) {
    return x + y;
  }

  int init(int node, int left, int right) {
    // fit case
    if (left == right) {
      return tree[node] = array[left];
    }

    int mid = (left + right) / 2;

    int leftPart = init(node * 2, left, mid);
    int rightPart = init(node * 2 + 1, mid + 1, right);

    return tree[node] = operation(leftPart, rightPart);
  }

  void update(int node, int left, int right, int index, int value) {
    // out of bound
    if (index < left || index > right) return;

    // fit case
    if (left == right) {
      tree[node] = value;
      return;
    }

    int mid = (left + right) / 2;
    update(node * 2, left, mid, index, value);
    update(node * 2 + 1, mid + 1, right, index, value);

    int leftPart = tree[node * 2];
    int rightPart = tree[node * 2 + 1];
    tree[node] = operation(leftPart, rightPart);
  }

  void update(int index, int value) {
    update(1, 0, size - 1, index, value);
  }

  int query(int node, int left, int right, int queryLeft, int queryRight) {
    // out of bound
    if (queryRight < left || right < queryLeft) return 0;
    // queryRange is inner to range
    if (queryLeft <= left && right <= queryRight) return tree[node];

    int mid = (left + right) / 2;
    int leftPart = query(node * 2, left, mid, queryLeft, queryRight);
    int rightPart = query(node * 2 + 1, mid + 1, right, queryLeft, queryRight);

    return operation(leftPart, rightPart);
  }

  int query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }
};
```

이를 이용해 다음과 같이 구현할 수 있다.

```cpp
class NumArray {
 private:
  SegmentTree *segmentTree;

 public:
  NumArray(vector<int> &nums) {
    segmentTree = new SegmentTree(nums);
  }

  void update(int index, int val) {
    segmentTree->update(index, val);
  }

  int sumRange(int left, int right) {
    return segmentTree->query(left, right);
  }
};
```

## 고생한 점
