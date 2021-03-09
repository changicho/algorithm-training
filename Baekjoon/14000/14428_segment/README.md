# 14428. 수열과 쿼리 16

[링크](https://www.acmicpc.net/problem/14428)

| 난이도 | 정답률(\_%) | 시간 제한(초) |
| :----: | :---------: | :-----------: |
| Gold I |   55.793    |       2       |

## 설계

### 시간 복잡도

수열의 크기는 최대 100,000 이다.

매번 브루트포스로 해결하는 경우 시간 복잡도는 100,000^2 이므로 제한시간 내에 불가능하다.

따라서 세그먼트 트리를 이용해 업데이트와 쿼리의 시간복잡도를 줄인다.

### 공간 복잡도

index는 최대 100,000 까지이다. 이는 int형으로 충분하다.

### 세그먼트 트리

tree에 저장되는 값은 index 값이다.

query에서 범위를 벗어나는 경우를 처리하기 위해 arr 맨 마지막에 쓰래기 값을 넣고 그 index를 이용한다.

```cpp
struct SegmentTree {
  int size;
  vector<long long> arr;
  vector<int> tree;

  SegmentTree(vector<long long> array) {
    arr = array;
    size = array.size();

    arr.push_back(1e9 + 1);
    tree.resize(4 * size + 1);
    init(1, 0, size - 1);
  }

  inline int operation(int x, int y) {
    return arr[x] <= arr[y] ? x : y;
  }

  int init(int node, int start, int end) {
    if (start == end) {
      return tree[node] = start;
    }
    int mid = (start + end) / 2;

    return tree[node] = operation(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
  }

  void update(int node, int start, int end, int index) {
    if (index < start || index > end) {
      return;
    }
    tree[node] = operation(tree[node], index);

    if (start != end) {
      update(node * 2, start, (start + end) / 2, index);
      update(node * 2 + 1, (start + end) / 2 + 1, end, index);

      tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
    }
  }

  void update(int index, int value) {
    arr[index] = value;
    update(1, 0, size - 1, index);
  }

  int query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return size;
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return operation(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
  }

  int query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }
};
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      72      |       12       |

## 고생한 점
