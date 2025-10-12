# F - Clearance

[링크](https://atcoder.jp/contests/abc426/tasks/abc426_f)

| 난이도 |
| :----: |
|  525   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 갯수를 Q라 하자.

범위에 대한 값들을 갱신(뺄셈)하므로 세그먼트 트리(lazy propagation)를 사용한다.

이 경우 세그먼트 트리의 생성에 O(N \* log_2(N)), 쿼리를 수행하는데 O(Q \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

세그먼트 트리에 O(N)의 공간 복잡도를 사용한다.

정답에 O(Q)의 공간 복잡도를 사용한다.

### 세그먼트 트리 (lazy propagation)

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     1112     | O((N + Q) \* log_2(N)) |  O(N + Q)   |

각 쿼리마다 특정 범위의 값을 K만큼 빼야한다. 이 때 값이 0 미만이 되는 경우는 0이 되어야 한다. 각 쿼리마다 세그먼트 트리에서 실제 뺀 값을 반환해야 한다.

세그먼트 트리의 늦은 전파에서 실제 음수를 0으로 변화시켜도, propagation 과정에서 lazy 배열을 갱신시키기가 어려우므로 2개의 다른 세그먼트 트리를 사용한다.

각 세그먼트 트리는 다음과 같다.

- 특정 구간에서 양수인 값들의 갯수를 관리하는 세그먼트 트리 : countSegTree
- 특정 구간에서 가장 작은 값과 index를 관리하는 세그먼트 트리 : minSegTree

이를 이용해 각 쿼리마다 다음을 수행한다.

countSegTree를 이용해 현재 구간의 양수인 값들의 갯수를 세며, 여기에 K를 곱해 정답의 후보를 생성한다.

minSegTree의 구간에 실제 K를 빼준다.

이후 현재 구간의 minimum 중 음수가 존재하는 경우 해당 값만큼 정답을 보정해주며 해당 index에 해당하는 두 세그먼트 트리의 값을 갱신시킨다.

(countSegTree의 경우 해당 index를 0으로 바꿈, minSegTree의 경우 해당 index에 최대값 저장)

이를 현재 구간에서 minimum이 양수가 나올 때 까지 반복한다.

이를 모든 쿼리에 대해서 반복한다.

```cpp
typedef long long ll;

const ll INF = 4e18;

struct SegTree {
  const int NULL_VALUE = 0;
  int size;
  vector<int> tree;

  SegTree(vector<int> arr) {
    size = arr.size();
    tree.resize(size * 4);
    build(1, 0, size - 1, arr);
  }

  // initialize part
  void build(int node, int start, int end, vector<int>& arr) {
    if (start == end) {
      tree[node] = arr[start];
      return;
    }

    int mid = (start + end) / 2;
    build(node * 2, start, mid, arr);
    build(node * 2 + 1, mid + 1, end, arr);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  // query part
  int query(int left, int right) { return query(1, 0, size - 1, left, right); }

  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
      return NULL_VALUE;
    }
    if (ql <= l && r <= qr) {
      return tree[node];
    }

    int mid = (l + r) / 2;
    ll leftPart = query(node * 2, l, mid, ql, qr);
    ll rightPart = query(node * 2 + 1, mid + 1, r, ql, qr);
    return leftPart + rightPart;
  }

  // update part
  void update(int i, ll diff) { update(1, 0, size - 1, i, i, diff); }

  void update(int node, int l, int r, int ql, int qr, ll diff) {
    if (l > r || qr < l || r < ql) {
      return;
    }
    if (l == r) {
      tree[node] += diff;
      return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, diff);
    update(node * 2 + 1, mid + 1, r, ql, qr, diff);

    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }
};

struct LazySegTree {
  const ll NULL_VALUE = LLONG_MAX / 2;
  int size;
  vector<pair<ll, int>> tree;
  vector<ll> lazy;

  LazySegTree(vector<ll> arr) {
    size = arr.size();
    tree.resize(4 * size);
    lazy.resize(4 * size);

    build(arr, 1, 0, size - 1);
  }

  void build(vector<ll>& arr, int node, int l, int r) {
    if (l == r) {
      tree[node] = {arr[l], l};
      return;
    }

    int mid = (l + r) / 2;
    build(arr, node * 2, l, mid);
    build(arr, node * 2 + 1, mid + 1, r);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  void propagate(int node, int l, int r) {
    if (lazy[node] == 0) return;

    tree[node].first += lazy[node];
    if (l != r) {
      lazy[2 * node] += lazy[node];
      lazy[2 * node + 1] += lazy[node];
    }
    lazy[node] = 0;
  }

  void update(int left, int right, ll val) {
    update(1, 0, size - 1, left, right, val);
  }

  void update(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);

    if (l > r || l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
      lazy[node] += val;
      propagate(node, l, r);
      return;
    }

    int mid = (l + r) / 2;
    update(node * 2, l, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, r, ql, qr, val);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
  }

  pair<ll, int> query(int left, int right) {
    return query(1, 0, size - 1, left, right);
  }

  pair<ll, int> query(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);
    if (l > r || qr < l || ql > r) return {NULL_VALUE, -1};
    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    return min(query(node * 2, l, mid, ql, qr),
               query(node * 2 + 1, mid + 1, r, ql, qr));
  }
};

auto solution(int size, vector<ll>& nums, int qSize, vector<vector<ll>>& queries) {
  SegTree countSegTree(vector<int>(size, 1));
  LazySegTree minSegTree(nums);

  vector<ll> answer;
  for (vector<ll>& q : queries) {
    int left = q[0] - 1, right = q[1] - 1;
    ll diff = q[2];

    ll count = countSegTree.query(left, right) * diff;
    minSegTree.update(left, right, -diff);

    pair<ll, int> minimum = minSegTree.query(left, right);
    while (minimum.first < 0 && minimum.second != -1) {
      ll val = minimum.first;
      int index = minimum.second;

      count -= abs(val);

      minSegTree.update(index, index, INF - val);
      countSegTree.update(index, -1LL);

      minimum = minSegTree.query(left, right);
    }

    answer.push_back(count);
  }

  return answer;
}
```

## 고생한 점

기존 세그먼트 트리 (lazy propagation)을 사용하는 경우 전파단계에서 시간 초과 발생