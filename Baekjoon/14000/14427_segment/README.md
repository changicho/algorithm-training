# 14427. 수열과 쿼리 15

[링크](https://www.acmicpc.net/problem/14427)

| 난이도 | 정답률(\_%) |
| :----: | :---------: |
| Gold I |   62.974    |

## 설계

### 시간 복잡도

N의 크기는 100,000 이다.

수를 업데이트한 후 매번 최소를 검색하는 경우 N^2만큼의 시간복잡도가 소요되므로 완전탐색은 불가능하다.

따라서 세그먼트 트리를 이용해 시간복잡도를 줄여야 한다.

이 경우 쿼리의 최대 개수는 100,000개 이며, 세그먼트 트리를 생성할 때 시간복잡도는 logN 이므로

NlogN 번만에 해결할 수 있다.

### 공간 복잡도

수의 크기는 10^9 까지이다. 따라서 int형으로 충분하다.

### 세그먼트 트리

이진 트리를 이용해 각 부모 노드는 자식 노드들 중 가장 조건에 부합한 값을 가진다.

따라서 구간을 이분탐색해 원하는 구간의 값을 구할 수 있다.

```cpp
struct SegmentTree {
  int size;
  vector<int> arr;
  vector<int> tree;

  SegmentTree(vector<int> array) {
    size = array.size();

    arr.resize(size + 1);
    arr = array;
    tree.resize(size * 4 + 1);

    init(0, size - 1, 1);
  }

  int compare(int x, int y) {
    // 구현하면됨
  }

  int init(int start, int end, int node) {
    if (start == end) return tree[node] = start;
    int mid = (start + end) / 2;

    return tree[node] = compare(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
  }

  int update(int start, int end, int node, int index) {
    if (index < start || index > end || start == end) return tree[node];
    int mid = (start + end) / 2;

    return tree[node] = compare(update(start, mid, node * 2, index), update(mid + 1, end, node * 2 + 1, index));
  }

  void changeValue(int index, int value) {
    arr[index] = value;
    update(0, size - 1, 1, index);
  }

  int query(int left, int right, int index, int start, int end) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[index];

    int mid = (start + end) / 2;

    return compare(query(left, right, index * 2, start, mid), query(left, right, index * 2 + 1, mid + 1, end));
  }
};
```

이렇게 만들어진 트리는 index = 1이 최상단이며 2 index 가 왼쪽노드, 2 index + 1이 오른쪽 노드이다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      56      |       16       |

## 고생한 점
