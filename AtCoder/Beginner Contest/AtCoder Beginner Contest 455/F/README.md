# F - Merge Slimes 2

[링크](https://atcoder.jp/contests/abc455/tasks/abc455_f)

| 난이도 |
| :----: |
|  525   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 갯수를 Q라 하자.

각 쿼리마다 직접 계산을 수행할 경우 O(N \* Q)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

세그먼트 트리의 늦은 전파(lazy propagate)를 이용해야 한다. 이 경우 생성에 O(N \* log_2(N)), 쿼리에 O(Q \* log_2(N))의 시간 복잡도를 사용한다.

이후 정답을 구할 때 부분배열의 어느 값부터 선택해도 비용은 동일하며 이를 빠르게 구하기 위해 제곱의 합, 합의 제곱을 이용할 수 있다.

따라서 총 시간 복잡도는 O((N + Q) \* log_2(N))이다.

### 공간 복잡도

세그먼트 트리에 O(N), 정답에 O(Q)의 공간 복잡도를 사용한다.

### 세그먼트 트리 & 나머지 역원

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     159      | O((N + Q) \* log_2(N)) |  O(N + Q)   |

특정 부분배열에서 문제 조건에 맞는 cost를 다음과 같이 구할 수 있다.

(부분배열의 두 값을 합치며, 비용에 두 값의 곱을 더한다. 이를 하나의 수가 남을때 까지 반복한다.)

- sum : 부분배열의 합
- sq : 부분배열의 원소들의 제곱의 합
- (sum^2 - sq) / 2

따라서 세그먼트 트리에 쿼리, 업데이트 시에 합과 제곱의 합을 모두 갱신한다.

이후 갱신한 구간에 대해 정답을 구할 때, MOD 연산이 들어가므로 페르마의 소정리를 이용한 역원을 사용해 구한다.

곱셈의 역원은 (MOD + 1) / 2 이며 최종 결과에 MOD를 수행한다.

```cpp
using ll = long long;

ll MOD = 998244353;

struct Node {
  ll sum = 0;
  ll sq = 0;
};

struct LazySegTree {
  int size;
  vector<Node> tree;
  vector<ll> lazy;

  LazySegTree(vector<ll>& arr) {
    size = arr.size();
    tree.resize(4 * size);
    lazy.resize(4 * size);
    build(arr, 1, 0, size - 1);
  }

  Node merge(const Node& a, const Node& b) {
    return {(a.sum + b.sum) % MOD, (a.sq + b.sq) % MOD};
  }

  void build(vector<ll>& arr, int node, int l, int r) {
    if (l == r) {
      tree[node].sum = arr[l] % MOD;
      tree[node].sq = (arr[l] * arr[l]) % MOD;
      return;
    }
    int mid = (l + r) / 2;
    build(arr, node * 2, l, mid);
    build(arr, node * 2 + 1, mid + 1, r);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  void propagate(int node, int l, int r) {
    if (lazy[node] == 0) return;

    ll x = lazy[node];
    ll len = (r - l + 1);

    tree[node].sq = (tree[node].sq + (2 * x % MOD) * tree[node].sum % MOD +
                     len % MOD * x % MOD * x % MOD) %
                    MOD;

    tree[node].sum = (tree[node].sum + len % MOD * x % MOD) % MOD;

    if (l != r) {
      lazy[node * 2] = (lazy[node * 2] + x) % MOD;
      lazy[node * 2 + 1] = (lazy[node * 2 + 1] + x) % MOD;
    }

    lazy[node] = 0;
  }

  void update(int l, int r, ll val) { _update(1, 0, size - 1, l, r, val); }

  void _update(int node, int l, int r, int ql, int qr, ll val) {
    propagate(node, l, r);

    if (r < ql || l > qr) return;

    if (ql <= l && r <= qr) {
      lazy[node] = (lazy[node] + val) % MOD;
      propagate(node, l, r);
      return;
    }

    int mid = (l + r) / 2;
    _update(node * 2, l, mid, ql, qr, val);
    _update(node * 2 + 1, mid + 1, r, ql, qr, val);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
  }

  Node query(int l, int r) { return _query(1, 0, size - 1, l, r); }

  Node _query(int node, int l, int r, int ql, int qr) {
    propagate(node, l, r);

    if (r < ql || l > qr) return Node();

    if (ql <= l && r <= qr) return tree[node];

    int mid = (l + r) / 2;
    return merge(_query(node * 2, l, mid, ql, qr),
                 _query(node * 2 + 1, mid + 1, r, ql, qr));
  }
};

ll getAnswer(ll sum, ll sq) {
  ll inv2 = (MOD + 1) / 2;

  ll res = (sum * sum) % MOD;
  res = (res - sq + MOD) % MOD;
  res = (res * inv2) % MOD;

  return res;
}

vector<ll> solution(int n, int qSize, vector<vector<int>>& queries) {
  vector<ll> nums(n + 1);

  LazySegTree seg(nums);

  vector<ll> answer;

  for (vector<int>& q : queries) {
    int l = q[0], r = q[1];
    long long num = q[2];

    seg.update(l, r, num);

    Node ret = seg.query(l, r);

    ll sum = ret.sum;
    ll sq = ret.sq;

    // sum^2 - sqSum / 2
    answer.push_back(getAnswer(sum, sq));
  }

  return answer;
}
```

## 고생한 점
