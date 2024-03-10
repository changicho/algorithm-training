# F - Second Largest Query

[링크](https://atcoder.jp/contests/abc343/tasks/abc343_f)

| 난이도 |
| :----: |
|  525   |

## 설계

### 시간 복잡도

배열 A의 크기를 N, 쿼리의 갯수를 Q라 하자.

각 쿼리마다 직접 구할 경우 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

세그먼트 트리를 이용해 각 구간마다의 답을 구할 경우 트리의 생성에 O(N \* log_2(N)), 각 쿼리마다 O(log_2(N))의 시간 복잡도가 소요된다.

따라서 총 O((N + Q) \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

세그먼트 트리에 O(N)의 공간 복잡도가 필요하다.

### 세그먼트 트리

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     710      | O(N + Q \* log_2(N)) |    O(N)     |

각 쿼리마다 업데이트와 구간의 답을 구하기 위해 세그먼트 트리를 사용한다.

이 때 각 구간의 두번째 큰 수의 빈도를 구하기 위해 구간마다 다음과 같은 값을 저장한다.

- 가장 큰 값
- 두번째로 큰 값
- 가장 큰 값의 빈도
- 두번째로 큰 값의 빈도

이를 이용해 X, Y 구간의 값을 다음과 같이 구할 수 있다.

- X와 Y의 가장 큰 값, 두번째로 큰 값을 비교하며 총 구간에서 가장 큰 값과 두번째로 큰 값을 구한다.
- 해당 값의 빈도를 X,Y를 이용해 구한다.

이는 X+Y 구간에서 가장 큰 값과 두번째로 큰 값은 X, Y 구간에의 가장 큰 값과 두번째로 큰 값만 후보가 되기 때문이다.

```cpp
struct Node {
  int val1, val2, count1, count2;
};

struct SegmentTree {
  const Node NULL_VALUE = {0, 0, 0, 0};
  int size;
  vector<Node> tree;

  SegmentTree(vector<int> &array) {
    size = array.size();

    tree.resize(size * 4);

    init(1, 0, size - 1, array);
  }

  // operation part
  Node operation(Node x, Node y) {
    map<int, int> kv;
    kv[x.val1] += x.count1;
    kv[x.val2] += x.count2;
    kv[y.val1] += y.count1;
    kv[y.val2] += y.count2;

    auto it = kv.end();
    it--;
    int val1 = it->first, count1 = it->second;
    it--;
    int val2 = it->first, count2 = it->second;
    return {val1, val2, count1, count2};
  }

  // initialize part
  void init(int node, int start, int end, vector<int> &array) {
    if (start == end) {
      tree[node] = Node({array[start], 0, 1, 0});
      return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid, array);
    init(node * 2 + 1, mid + 1, end, array);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }

  // query part
  Node query(int left, int right) { return query(1, 0, size - 1, left, right); }

  Node query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
      return NULL_VALUE;
    }
    if (left <= start && end <= right) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    Node leftPart = query(node * 2, start, mid, left, right);
    Node rightPart = query(node * 2 + 1, mid + 1, end, left, right);
    return operation(leftPart, rightPart);
  }

  // update part
  void update(int index, int val) { update(1, 0, size - 1, index, index, val); }

  void update(int node, int start, int end, int left, int right, int val) {
    if (right < start || end < left) {
      return;
    }
    if (start == end) {
      tree[node] = {val, 0, 1, 0};
      return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }
};

vector<int> solution(vector<int> &arr, vector<vector<int>> &queries) {
  vector<int> answer;

  SegmentTree segmentTree(arr);

  for (vector<int> &q : queries) {
    int a = q[0], b = q[1], c = q[2];
    if (a == 1) {
      segmentTree.update(b - 1, c);
    } else {
      Node result = segmentTree.query(b - 1, c - 1);

      answer.push_back(result.count2);
    }
  }

  return answer;
}
```

## 고생한 점
